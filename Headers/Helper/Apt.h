#include<iostream>
#include <unistd.h>
#include <string>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <vector>
#include "Variety.h"
#ifndef H_Apt
#define H_Apt
/*
Execute Shell Command And Read The output using Pipe
*/
std::string ExecuteAndRead(std::string command);
/*
execute "apt-cache pkgnames  | head -n {count}" and return the output -1 will return all"
*/
std::vector<std::string> GetAptPackages(int Count);
/*
execute "apt-cache show {PackageName}"" and return the output
*/
std::string GetAptPackagesInfo(std::string PackageName);
#endif