#include "Database/SqliteCurd.h"
#ifndef H_Startup
#define H_Startup
class Startup
{
private:
    /*open connection to database*/
    void InitDb();
    /*Update Database if Apt Get Packages Changed*/
    void EnsureDbUpdated();
    /*Update Database*/
    void UpdateDb();
    /*compare the database to apt cache file to check if database contain the latest package informations*/
    bool IsAptPackageChanged();
    /*Terminate the application if it doesn't have access to root privileges*/
    void EnsureSuperUserMode();

    
public:
    Startup();
    ~Startup()=default;
};
#endif
