#include<string>
#include <fstream>
#include<vector>
#include<iostream>
#include<string>
#include <unistd.h>
#include <string>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <vector>
#include <filesystem>
#ifndef H_Variety
#define H_Variety

std::string ReadFileText(const std::string & FilePath);
std::vector<std::string> SplitString(const std::string & OriginalString,const std::string & Delimiter);
/*
Execute Shell Command And Read The output using Pipe
*/
static std::string ExecuteAndRead(const std::string & Command);
#endif