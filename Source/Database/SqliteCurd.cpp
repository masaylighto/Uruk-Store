#include "Database/SqliteCurd.h"

SqliteCurd::SqliteCurd(std::string Path)
{
  if (SQLITE_OK!=sqlite3_open(Path.c_str(),&Db))
  {
    throw new std::runtime_error("couldn't open the file");
  }
    
}
SqliteCurd * SqliteCurd::Create(std::string Path)
{
    static SqliteCurd * instance;
    if (!instance)
    {
        instance = new SqliteCurd(Path);
    }    
    return instance;

}
/*
template <typename Type> Type SqliteCurd::FetchRow (std::string SqlQuery){

}
template <typename Type> Type SqliteCurd::FetchList (std::string SqlQuery){
    
}
template <typename Type> std::vector<Type> SqliteCurd::FetchRow (std::string SqlQuery){

}
template <typename Type> bool SqliteCurd::AddRow (std::string SqlQuery,std::vector<Type> Parameters){

}
template <typename Type> bool SqliteCurd::Delete (std::string SqlQuery,std::vector<Type> Parameters){

}
template <typename Type> bool SqliteCurd::Update (std::string SqlQuery,std::vector<Type> Parameters){


}*/