#include<iostream>
#include<string>
#include <unistd.h>
#include <string>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <vector>
#include "Variety.h"
#include <filesystem>
#include <gtkmm.h>
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
    this function parse the string that represent the package information
    */
    static Package ParsePackage(const std::string & Info);
    /*
    Map KeyValue into Package
    */
    static void MapToPackage(Package & Pkg , const std::vector<std::string> KeyValue); 
    public:
    /*
    Read Apt Files and Get Data
    */
    static std::vector<Package> GetPackages();
    static std::vector<std::string> ExtractPackagesName(const std::vector<Package> & Packages);
};

#endif