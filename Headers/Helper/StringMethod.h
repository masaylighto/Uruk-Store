#include<string>
#include<vector>
#include <iostream>
#ifndef H_StringMethod
#define H_StringMethod
std::vector<std::string>  SplitString(const std::string & OriginalString,const std::string & Delimiter);
/*
check if a   string is exist within another string
OriginalString is the full string that we want to check if it contain some string
PartialString the string we want to check if it exist
StartIndex the index in  OriginalString , which we gonna start checking if it does contain the PartialString
*/
inline bool IsPartialStringExist(const std::string & OriginalString,const std::string & PartialString ,const int StartIndex);
#endif