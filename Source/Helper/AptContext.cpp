#include"Helper/AptContext.h"
#include<map>


PkgInfo AptContext::ParseRawPackage(std::string  RawPkg)
{  
    std::istringstream StringStream(RawPkg);
    std::string Line;
    std::string Key;
    std::string Value;
    PkgInfo PkgAttributes;
    int SeperatorPosition=0;
    while (getline(StringStream, Line))
    {     
        SeperatorPosition=Line.find_first_of(':',0)+1;
        Key   = Line.substr(0, SeperatorPosition-1);   
        Value = Line.substr(SeperatorPosition, Line.length()-SeperatorPosition);
        PkgAttributes[Key] = Value;
    }
return PkgAttributes;
}

void AptContext::ParsePackages(){
    
 
    //temp list to hold catagories will be used to create a unique and sorted vector
    std::list<std::string> Catagories;
    apt::Apt Apt;
    for(apt::Apt::RecordIterator Pkg= Apt.recordBegin();Pkg!=Apt.recordEnd();++Pkg)
    {   
        try
        {   //parse the raw package info
            PkgInfo AptPkg =  ParseRawPackage(*Pkg);
      
            // app the package into the vector           
             _Packages.push_back(AptPkg);
            //add the name into the name vector and the category into the catagories list
            _Names.push_back(AptPkg["Package"]);
             Catagories.push_back(AptPkg["Section"]);
  
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
      
         
    }
    //sort the list then use unique to get a list with out duplicated value
    Catagories.sort();
    Catagories.unique();
    //fill the class member catagories vector with the Catagories list
    for (auto Category = Catagories.begin(); Category != Catagories.end(); ++Category)
    {
        _Catagories.push_back(*Category);
    }
    
}
const std::vector<std::string> AptContext::GetCatagories()
{
    return _Catagories;
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
    ParsePackages();
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
