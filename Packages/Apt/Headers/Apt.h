#include<iostream>
#include<string>
#include <unistd.h>
#include <string>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <vector>
#include "../../Varity/Headers/FileMethod.h"
#include "../../Varity/Headers/StringMethod.h"
#include <filesystem>

#ifndef H_Apt
#define H_Apt
struct Package
{
    std::string Name;
    std::string Version;
    std::string Maintainer;
    std::string Section;
};
//Hold Apt Get Method
class Apt
{
   
    /*
    get list of all files that hold the apt get package informations
    */
    static std::vector<std::string> GetSourcesPaths();
    /*
    get packages information stored in the specified  source file
    and add them to the Packages Vector That Passed As Paramater
    */
    static void GetSourcePackages(std::vector<Package> & Packages,std::string Path);

    /*
    Map KeyValue into Package
    */
    static void MapToPackage(Package & Pkg , std::string & Key,std::string & Value);
    public:
    /*
    Read Apt Files and Get Data
    */
    static std::vector<Package> GetPackages();
};

#endif