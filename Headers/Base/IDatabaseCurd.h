#include<string>
#include <vector>
#include <sqlite3.h>
#include <sqlite3ext.h>
#ifndef H_IDatabaseCurd
#define H_IDatabaseCurd
class IDatabaseCurd
{
private:

public:
    template <typename Type> Type FetchRow (std::string SqlQuery);
    template <typename Type> Type FetchList (std::string SqlQuery);
    template <typename Type> std::vector<Type> FetchRow (std::string SqlQuery);
    template <typename Type> bool AddRow (std::string SqlQuery,std::vector<Type> Parameters);
    template <typename Type> bool Delete (std::string SqlQuery,std::vector<Type> Parameters);
    template <typename Type> bool Update (std::string SqlQuery,std::vector<Type> Parameters);
};



#endif