#include "Database/SqliteCurd.h"

SqliteCurd::SqliteCurd(std::string Path)
{
  if (SQLITE_OK!=sqlite3_open(Path.c_str(),&Db))
  {
    std::ostringstream stringStream;
    stringStream<<"couldn't open the file "<<sqlite3_errmsg(Db);
    throw std::runtime_error(stringStream.str());
  }
    
}
SqliteCurd * SqliteCurd::Create(std::string Path)
{
    static SqliteCurd * Instance;
    if (!Instance)
    {
        if (Path.empty())
        { 
        
          throw  std::runtime_error("Please Call The Right Method To Construct Sqlite Db or Pass A valid Path");
        }        
        Instance = new SqliteCurd(Path);
    }    
    return Instance;

}
SqliteCurd * SqliteCurd::Use()
{
   
    return Create("");

}

std::vector<std::string> SqliteCurd::GetPackagesName ()
{
  std::vector<std::string> PackagesName;
  sqlite3_stmt* Stmt=Execute("Select Name from Packages");
  for (int index = 0; index <  sqlite3_column_count(Stmt); index++)
  {
    PackagesName.push_back((char*)sqlite3_column_text(Stmt,0));
  } 
  sqlite3_finalize(Stmt);
  return PackagesName;
}
/*
this method free Sql Parameters 
*/
sqlite3_stmt * SqliteCurd::Execute(const char * SqlQuery ,std::vector<std::string> & SqlParameters)
{
  sqlite3_stmt *Stmt =CreateStatement(SqlQuery);  
  BindParameters(Stmt,SqlParameters);
  auto Result=sqlite3_step(Stmt);
  if (SQLITE_DONE!=Result)
  { 
    std::ostringstream stringStream;
    stringStream<<"Failed To Execute Query "<<SqlQuery<<" Error "<<Result;
    throw std::runtime_error(stringStream.str());
  }
//  FreeStdVector(SqlParameters);
  return Stmt;

}
void SqliteCurd::FreeStdVector(std::vector<std::string> & Vec)
{
  for (int i = 0; i < Vec.size(); i++)
  {
    auto & item =Vec.at(i);
   
  }
  
  Vec.clear();
}
void  SqliteCurd::BindParameters(sqlite3_stmt * Stmt,std::vector<std::string> & SqlParameters)
{
  for (int index = 0; index < SqlParameters.size(); index++)
  {
    std::string & Parameter=SqlParameters.at(index);
     sqlite3_bind_text(Stmt ,index,Parameter.c_str(),Parameter.length(),nullptr);
  }
}
sqlite3_stmt * SqliteCurd::CreateStatement(const char * SqlQuery){
  //Object Pointer For prepared statement
  sqlite3_stmt *Stmt;
  //the part of our query that the prepare statement left it with no use
  const char* UnUsedPartSqlQuery;
  sqlite3_prepare(Db,SqlQuery,std::strlen(SqlQuery),&Stmt,&UnUsedPartSqlQuery); 
  return Stmt;

}
sqlite3_stmt * SqliteCurd::Execute(const char * SqlQuery)
{
  //Object Pointer For prepared statement
  sqlite3_stmt *Stmt =CreateStatement(SqlQuery); 
  auto Result=sqlite3_step(Stmt);
  if (SQLITE_DONE!=Result)
  { 
    std::ostringstream stringStream;
    stringStream<<"Failed To Execute Query "<<SqlQuery<<" Error "<<Result;
    throw std::runtime_error(stringStream.str());
  }
  return Stmt;

}
void SqliteCurd::DeletePackages()
{
 sqlite3_finalize(Execute("delete from Packages"));
}
void SqliteCurd::AddPackage (Package Pkg)
{

  std::vector<std::string>  SqlParameters;
  SqlParameters.push_back(Pkg.Name);
  SqlParameters.push_back(Pkg.Section);
  SqlParameters.push_back(Pkg.Version);
  SqlParameters.push_back(Pkg.Maintainer);
  Execute("Insert into Packages (Name,Section,Version,Maintainer) values (?,?,?,?),",SqlParameters);
}