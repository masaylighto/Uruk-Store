#include"Helper/AptContext.h"

std::vector<std::string> AptContext::GetSourcesPaths()
{   
    // a List of All Sources  Files
    std::vector<std::string> SourcesPath;
    //loop through all files inside /var/lib/apt/lists/ which is the folder that contains the source file
    for (const auto & File : std::filesystem::directory_iterator("/var/lib/apt/lists/"))
    {   
            //get the path from the File information
            const std::string & Path = File.path().string();
            //if the file doesn't have deb or .gz in its name 
            //then the file is a source files
            if  (Path.find("deb")!=-1 && Path.find(".gz")==-1 )
            {
                SourcesPath.push_back(Path);
            }

    }
    return SourcesPath;
}

void AptContext::GetSourcePackages(std::string Path)
{
 //creating two variable one will hold the key, and one will hold the value  
 std::string  Key,Value;
 //store the package information of the current loop to add it into the packages vector  
 Package  PkgInfo;
 //store the current character in the loop to minimize dereferencing time
 char CurrentChar;   
 for (const  char & CurrentChar:Path)
 {
    //check if the current char is \n so we know that we are reading new package info 
    //set it into the IsNewLine to check for \n repetition 
    if (CurrentChar=='\n')
    {   
        //map the package key and value into the package struct    
        MapToPackage(PkgInfo,Key,Value);
        //reset the value
        Value="";
        continue;
    }
    //if the CurrentChar is : then we are now reading the value if not then we are reading the info of the key
    //key: value 
    if (CurrentChar==':')
    {
        //we set the value value into the key cause we used the value var to collect the character in the loop
        Key =  Value;
        //we reset the value of Value var preparing to store the value in the key:Value 
        Value.clear();
        
        continue;
    }      
    //store the current character in the Value
    Value+=CurrentChar;
 }
    //add the information of the previous package into the packages vector
    Packages.push_back(PkgInfo);
   

}
void AptContext::MapToPackage(Package & Pkg , std::string & Key,std::string & Value)
{
    
    if (Key=="Package")
    {
         Pkg.Name=Value.substr(1,Value.length());
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

void AptContext::ReadPackages(){
    
     
    ept::apt::Apt Apt;
    std::vector<std::string> Pkgs;
    std::copy(Apt.recordBegin(), Apt.recordEnd(), std::back_inserter(Pkgs));

    //loop through them 
    for (std::string & Pkg : Pkgs)
    {
        try
        {
                
            //Package information of the specfied source file and insert them info Packages Vector 
            GetSourcePackages(Pkg); 
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
      
         
    }
 
}
std::vector<std::string> AptContext::GetNames()
{
    return Names;
}
std::vector<Package> AptContext::GetPackages()
{
    return Packages;
}

AptContext::AptContext()
{
    ReadPackages();
}
//to make sure we using the same instance across the application 
AptContext* AptContext::Create()
{
    static AptContext * instance;
    if (!instance)
    {
        instance = new AptContext();
    }    
    return instance;
}
