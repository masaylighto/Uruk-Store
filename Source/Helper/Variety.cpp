#include"../../Headers/Helper/Variety.h"
std::string ReadFileText(std::string FilePath)
{
    std::ifstream File(FilePath);
    std::string str((std::istreambuf_iterator<char>(File)),std::istreambuf_iterator<char>());
    return str;
}