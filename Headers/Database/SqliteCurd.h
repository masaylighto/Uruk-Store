#include<string>
#include <vector>
#include<string>
#include <vector>
#include "Helper/Apt.h"
#include <stdexcept>
#include <cstring>
#include <sqlite3.h>

#ifndef H_SqliteCurd
#define H_SqliteCurd

class SqliteCurd
{
  
    SqliteCurd(std::string Path);
    SqliteCurd()=default;
    sqlite3 * Db;
    /*
    this method create static instance of the class and return it, this method can be used instead of constructing the class every time
    */
   
  
   
    sqlite3_stmt * Execute(const char * SqlQuery ,std::vector<std::string> & SqlParameters);
    sqlite3_stmt * Execute(const char * SqlQuery);
    sqlite3_stmt * CreateStatement(const char * SqlQuery );
    void FreeStdVector(std::vector<std::string> & Vec);
    void BindParameters(sqlite3_stmt * Stmt,std::vector<std::string> & SqlParameters);
    public :
    static SqliteCurd * Create(std::string Path);
    static SqliteCurd * Use();
    std::vector<std::string> GetPackagesName ();
    void DeletePackages ();
    void AddPackage (Package Pkg);
    
};
#endif