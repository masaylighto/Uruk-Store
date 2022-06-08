#include<iostream>
#include<string>
#include <unistd.h>
#include <string>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <vector>
#include "Helper/FileMethod.h"
#include "Helper/StringMethod.h"
#include <filesystem>

#ifndef H_apt
#define H_apt
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

    Apt();
     //vector that will hold all the packages information
    std::vector<std::string> Names;
    //vector that will hold all the packages Names
    std::vector<Package> Packages;  
    /*
    get list of all files that hold the apt get package informations
    */
    std::vector<std::string> GetSourcesPaths();
    /*
    get packages information stored in the specified  source file
    and add them to the Packages Vector That Passed As Paramater
    */
     void GetSourcePackages(std::string Path);

    /*
    Map KeyValue into Package
    */
     void MapToPackage(Package & Pkg , std::string & Key,std::string & Value);

    /*
    Read Apt Files and Get Data
    */
    void ReadPackages();
    public:
    /*
    create and use class if no previous instance created    
    */
    static Apt* Create();
    /*
    create and use class if and dispose any previous instance created    
    */
    static Apt* CreateNew();
    std::vector<std::string> GetNames();
    std::vector<Package> GetPackages();
    
};

#endif