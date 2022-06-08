#include<string>
#include <fstream>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <cstring>

#ifndef H_FileMethod
#define H_FileMethod
 bool IsFileExist (const std::string& Name) ;
char * ReadFileText(const std::string & FilePath,int FileSize);
struct stat GetFileInfo(const std::string & FilePath);
#endif