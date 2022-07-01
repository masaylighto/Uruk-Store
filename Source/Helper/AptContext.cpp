#include"Helper/AptContext.h"
#include<map>


PkgInfo AptContext::ParseRawPackage(std::string  RawPkg)
{   //convert string to string stream to read it line by line
    std::istringstream StringStream(RawPkg);
    //variable to hold the current line we are reading
    std::string Line;
    //the package information orginized as Package attribute name: Package attribute value
    //ex Package: gcc
    //so we create two variable to hold the information key and value
    std::string Key;
    std::string Value;
    //struct to hold all parsed pkg info
    PkgInfo PkgAttributes;
    // store the postion of : to split the Attributes into key and value
    int SeperatorPosition=0;
    //reading the string stream line by line
    while (getline(StringStream, Line))
    {   
        //get the : postion and add 1 cause after the seperator there will be an empty space and we want to skip it  
        SeperatorPosition=Line.find_first_of(':',0)+1;
        //get the key
        Key   = Line.substr(0, SeperatorPosition-1);
        // we dont want every package attributes but only its name and section and description
        // the key for the name is "Package" so we use word "package"
        //we substring the line to extract the value and set it into its field int the struct
        if (Key=="Package" )
        {
            Value = Line.substr(SeperatorPosition, Line.length()-SeperatorPosition);
            PkgAttributes.Name=Value;
            continue;
        }
         if (Key=="Section")
        {
            Value = Line.substr(SeperatorPosition, Line.length()-SeperatorPosition);
            PkgAttributes.Section=Value;
            continue;
        }
         if (Key=="Description")
        {
            Value = Line.substr(SeperatorPosition, Line.length()-SeperatorPosition);
            PkgAttributes.Description=Value;
            continue;
        }   
        
    
    }
    return PkgAttributes;
}

void AptContext::ParsePackages()
{ 
    //temp list to hold catagories will be used to create a unique and sorted vector
    std::list<std::string> Catagories;
    //create instance of the lebept apt binding
    apt::Apt Apt;
    //iterate through every package
    for(apt::Apt::RecordIterator Pkg= Apt.recordBegin();Pkg!=Apt.recordEnd();++Pkg)
    {   
        try
        {   pthread_t thread;
             //parse the raw package info
            PkgInfo AptPkg =  ParseRawPackage(*Pkg);      
            // app the package into the vector           
             _Packages.push_back(AptPkg);
            //add the name into the name vector and the category into the catagories list
            _Names.push_back(AptPkg.Name);
  
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
      
         
    }

    _IsParsingCompleted=true;
}
const std::map<std::string,std::string> AptContext::GetCatagories()
{
    return _CatagoriesAliasMap;
}
const std::vector<std::string> AptContext::GetNames()
{
    return _Names;
}
const std::vector<PkgInfo> AptContext::GetPackages()
{
    return _Packages;
}

AptContext::AptContext()
{
    //when class instanced parse all package 
    ParsePackages();
}

//to make sure we using the same instance across the application 
AptContext* AptContext::Use()
{
    //to create a singleton
    //we create static pointer so every time we call this method the pointer will be the same
    //we check  if it null or not if its null then this the first time we call this function
    //and so we create a new instance of the class and assign it to the pointer
    //if its not null then and as the pointer is static then we previously called the method
    //and there is already created instance so no need to recreate it 
    static AptContext * instance;
    if (!instance)
    {
        instance = new AptContext();
    }    
    return instance;
}
const  bool AptContext::IsParsingCompleted()
{
    return _IsParsingCompleted;
}