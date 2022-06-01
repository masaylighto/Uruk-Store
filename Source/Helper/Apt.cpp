#include"../../Headers/Helper/Apt.h"

std::vector<std::string> Apt::GetSourcesPaths()
{   
    // a List of All Sources  Files
    std::vector<std::string> SourcesPath;
    //loop through all files inside /var/lib/apt/lists/ which is the folder that contains the source file
    for (const auto & File : std::filesystem::directory_iterator("/var/lib/apt/lists/"))
    {   
            //get the path from the File information
            const std::string Path =File.path().string();
            //if the file doesn't have deb or .gz in its name 
            //then the file is a source files
            if  (Path.find("deb")!=-1 && Path.find(".gz")==-1 )
            {
                SourcesPath.push_back(Path);
            }

    }
    return SourcesPath;
}
Package Apt::ParsePackage(const std::string & Info)
{
  ;
    Package Pkg;
    //the package info will come as string , its information separated through lines example
    //package: zzzeeksphinx
    //Binary: python3-zzzeeksphinx
    //Version: 1.1.6-1
    //Maintainer: Debian Python Team <team+python@tracker.debian.org>
    // as you see, so we split the string into lines
    const std::vector<std::string> Lines = SplitString(Info,"\n");
    //loop on every line
    for (int Index = 0; Index < Lines.size(); Index++)
    {    //Get the line   
         const std::string & Line =  Lines[Index];
         if (!Line.find(":")==-1)
         {
             continue;
         }
         
         //every line will look like this  Package: zzzeeksphinx  so we split on : and in this way the name and the value is separated    
         const std::vector<std::string> KeyValue = SplitString(Line,": ");
         // as the Line Value should be like this  Package: zzzeeksphinx
         //and we separated  with :
         //then if the count of the KeyValue isn't two then Separation proccess failed 
         //we skip this iteration 
         if (KeyValue.size()!=2)
         {
             continue;
         }
         
         //we check the name and according to it we store the values into Package Member Variables
         MapToPackage(Pkg,KeyValue);
    }   
    return Pkg;
}
void Apt::GetSourcePackages(std::vector<Package> & Packages,std::string Path)
{

    //read the sources file content as string
    std::string SourceFileContent =  ReadFileText(Path);
    // the package and there information separated from each other with a empty line
    // so we use \n\n you may wander why two \n if it was one empty line 
    //simply cause the last line of the package will normally end with \n it self
    //then come the empty line which is \n so there is two \n
    std::vector<std::string> PackagesInfo = SplitString(SourceFileContent,"\n\n");
    //loop through all the package string
    for (std::string & PackageInfo : PackagesInfo)
    {
        //parse them and add them into the Parsed Package Vector
        Packages.push_back(ParsePackage(PackageInfo));
    } 
    
}
void Apt::MapToPackage(Package & Pkg , const std::vector<std::string> KeyValue)
{
    const std::string & Key =KeyValue.at(0);
    const std::string & Value =KeyValue.at(1);
    if (Key=="Package")
    {
         Pkg.Name=Value;
    }
    else if (Key=="Version")
    {
         Pkg.Version=Value;
    }
    else if (Key=="Maintainer")
    {
         Pkg.Maintainer=Value;
    }
    else if (Key=="Section")
    {
         Pkg.Section=Value;
    }
}

std::vector<Package> Apt::GetPackages(){
    //vector that will hold all the packages information
    std::vector<Package> Packages;
    //Get All Source Files
    std::vector<std::string>Paths = GetSourcesPaths();
    //loop through them 
    for (std::string & Path : Paths)
    {
        //Package information of the specfied source file and insert them info Packages Vector 
        GetSourcePackages(Packages,Path);
    }
    // return the packages
    return Packages;
}
std::vector<std::string> Apt::ExtractPackagesName(const std::vector<Package> & Packages)
{
    std::vector<std::string> PackagesName;
    for (const Package  & pkg : Packages )
    {
        PackagesName.push_back(pkg.Name);
    }
    return PackagesName;
}