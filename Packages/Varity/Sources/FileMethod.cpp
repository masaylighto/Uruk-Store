#include "../Headers/FileMethod.h"
std::string ReadFileText(const std::string & FilePath)
{
    // the code had been taken from https://stackoverflow.com/questions/2912520/read-file-contents-into-a-string-in-c
    // Streaming Class That Operate on Files
    std::ifstream File(FilePath);
    // std::istreambuf_iterator read the characters from basic stream buffer
    // we call the Range constructor of string  Which take (InputIterator first, InputIterator last)
    // as Paramater
    std::string FileContent(std::istreambuf_iterator<char>(File),{});
    return FileContent;
}