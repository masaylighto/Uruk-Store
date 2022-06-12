#include<string>
#include <vector>
#include "../Base/IDatabaseCurd.h"
#ifndef H_SqliteCurd
#define H_SqliteCurd
class SqliteCurd:public IDatabaseCurd
{
    sqlite3 * Db;
};
#endif