#include "Helper/FileMethod.h"

#include<iostream>
char * ReadFileText(const std::string & FilePath,int FileSize)
{
    //this part of code doesn't need any type of comment ,it's just so obvious  
    int FileDescriptor=  open(FilePath.c_str(),O_RDONLY);
    if (FileDescriptor==-1)
    {
         throw std::ifstream::failure("Failed To load File "+FilePath);
    }
    //increase the size of the array ti add termination character
    char * FileContent = new char [FileSize+1];
    read(FileDescriptor,FileContent,FileSize);
    //read method don't add a termination  character at the end of string  
    FileContent[FileSize]='\0';
    close(FileDescriptor);
    return FileContent;
}
struct stat GetFileInfo(const std::string & FilePath)
{
    struct stat buffer;     
    //check if the file not exist 
    if((stat (FilePath.c_str(), &buffer) != 0))
    {
        throw std::ifstream::failure("Failed To Read File "+FilePath);
    }
    return buffer;
}
 bool IsFileExist (const std::string& FilePath) 
{
    struct stat buffer;     
    //check if the file not exist    
    return (stat (FilePath.c_str(), &buffer) != 0);
}