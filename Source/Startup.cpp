#include "Startup.h"
void Startup::InitDb(){
    try
    {
           SqliteCurd::Create("UrukStore.db");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(-1);
    }
    

}
void Startup::UpdateDb()
{
    //we remove all the existing packages
    SqliteCurd::Use()->DeletePackages();
    //get all the packages info from Apt
    //and insert them one by one into Sqlite
    for (auto &Pkg : Apt::Create()->GetPackages())
    {
       SqliteCurd::Use()->AddPackage(Pkg); 
    }
}
Startup::Startup()
{
    EnsureSuperUserMode();
    InitDb();    
    EnsureDbUpdated();   
}

void Startup::EnsureDbUpdated()
{
    if(IsAptPackageChanged())
    {
       UpdateDb();
    }
    
   
}

bool Startup::IsAptPackageChanged()
{
    return true;
}

void Startup::EnsureSuperUserMode()
{
//Todo;
}