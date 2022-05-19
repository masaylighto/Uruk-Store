#include<string>
#include <fstream>
#include<vector>
#ifndef H_Variety
#define H_Variety

std::string ReadFileText(std::string FilePath);
std::vector<std::string> SplitString(std::string OriginalString,char delimiter);
#endif