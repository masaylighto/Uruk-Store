#include"../Headers/Apt.h"

std::vector<std::string> Apt::GetSourcesPaths()
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

void Apt::GetSourcePackages(std::vector<Package> & Packages,std::string Path)
{
   //this algorithm work as follow
   //the packages information inside files are structured as follow
   //key:value
   //key:value
   //
   //key:value
   //key:value
   //explanation the package information consist of the info name (key) a colon then the info(value)
   //between every package there is an empty line
   //so what we gonna do ? the next
   //creating two variable one will hold the key, and one will hold the value  
   std::string  Key,Value;
    //getting the file information or exactly getting the file size    
   int FileSize = GetFileInfo(Path).st_size; 
   //reading the whole file
   char* SourceFileContent =  ReadFileText(Path,FileSize); 
   //as there is an empty line between every two packages which represent by \n character
   //and as every package info end up with \n cause every info take a line
   //so to indicate start reading new package information
   //we need to check if we read two \n and that why we Created This Variable IsNewLine
   //we will store it true if we in the current loop encounter \n so in the next loop if we encounter it 
   //again then we will know that we are started reading the information of the next package
   bool IsNewLine=false; 
   //store the package information of the current loop to add it into the packages vector  
   Package  PkgInfo; 
   //store the current character in the loop to minimize dereferencing time     
   char CurrentChar;
   //we loop through pointer arithmetics to get rid of indexing time                
   for (char * IndexingChar = SourceFileContent; * IndexingChar ; IndexingChar++)
   {    
        //store the value of the character in the current iteration
        CurrentChar=*IndexingChar; 
        //we check if the IsNewLine is set to true and the  CurrentChar equal to \n then 
        //this is the second \n so we are now reading new package info
        if (IsNewLine&&(CurrentChar=='\n'))
        {
            //add the information of the previous package into the packages vector
            Packages.push_back(PkgInfo);
            
            //set new pointer to prepare for reading the next package
            PkgInfo= {};
            continue;
        }
        //check if the current char is \n so we know that we are reading new package info 
        //set it into the IsNewLine to check for \n repetition 
        if (IsNewLine=(CurrentChar=='\n'))
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
   
  
   free(SourceFileContent);
}
void Apt::MapToPackage(Package & Pkg , std::string & Key,std::string & Value)
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

std::vector<Package> Apt::GetPackages(){
    //vector that will hold all the packages information
    std::vector<Package> Packages;
    //Get All Source Files
    std::vector<std::string> Paths = GetSourcesPaths();
   
    //loop through them 
    for (std::string & Path : Paths)
    {
        try
        {
                
            //Package information of the specfied source file and insert them info Packages Vector 
            GetSourcePackages(Packages,Path); 
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
      
         
    }
    // return the packages
    return Packages;
}
