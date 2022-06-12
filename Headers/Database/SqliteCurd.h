#include<string>
#include <vector>
#include<string>
#include <vector>
#include <sqlite3.h>
#include <stdexcept>
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
    static SqliteCurd * Create(std::string Path);
    public :
    template <typename Type> Type FetchRow (std::string SqlQuery);
    template <typename Type> Type FetchList (std::string SqlQuery);
    template <typename Type> std::vector<Type> FetchRow (std::string SqlQuery);
    template <typename Type> bool AddRow (std::string SqlQuery,std::vector<Type> Parameters);
    template <typename Type> bool Delete (std::string SqlQuery,std::vector<Type> Parameters);
    template <typename Type> bool Update (std::string SqlQuery,std::vector<Type> Parameters);
};
#endif