#include"Helper/AptContext.h"
std::vector<std::string> AptContext::GetRawPackages()
{
    apt::Apt Apt;
    std::vector<std::string> Pkgs;
    std::copy(Apt.recordBegin(), Apt.recordEnd(), std::back_inserter(Pkgs));
    return Pkgs;
}
void AptContext::ParsePackages(){
    
    //get  package information  as string
    std::vector<std::string> Pkgs = GetRawPackages();
    //temp list to hold catagories will be used to create a unique and sorted vector
    std::list<std::string> Catagories;
   
    //loop through them 
    for (std::string & Pkg : Pkgs)
    {
        try
        {   //parse the raw package info
            apt::RecordParser ParsedPkg(Pkg) ; 
            //app the package into the vector           
            _Packages.push_back(ParsedPkg);
            //add the name into the name vector and the category into the catagories list
            _Names.push_back(ParsedPkg.lookup("Package"));
            Catagories.push_back(ParsedPkg.lookup("Section"));
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
const std::vector<apt::RecordParser> AptContext::GetPackages()
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
