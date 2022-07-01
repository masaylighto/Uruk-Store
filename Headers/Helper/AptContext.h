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
#include <vector.tcc>
#include <string.h>
#include <ept/apt/apt.h>
#include<ept/debtags/debtags.h>
#include<ept/axi/axi.h>
#include<ept/utils/string.h>
#include<ept/utils/sys.h>
#include<ept/apt/recordparser.h>
#include <list>
#ifndef H_apt
#define H_apt
struct AptPkg
{
std::string Name;
std::string Section;
std::string Description;
};

typedef AptPkg PkgInfo;
//shorten the name space 
namespace apt = ept::apt;
//Hold Apt Get Method
class AptContext
{

    AptContext();   
    //vector that will hold all the packages Names
    std::vector<std::string> _Names;
    //vector that will hold all the packages Catagories
    std::vector<std::string> _Catagories;
    //vector that will hold all the packages information
    std::vector<PkgInfo> _Packages;  
    // will hold the state of parsing
    bool _IsParsingCompleted;    /*
    Parse The package Raw Data and return struct that hold the package info
    */
    PkgInfo ParseRawPackage(std::string  str);
    /*Parse all packages info */
    void ParsePackages();
    public:
    /*
    create and use class if no previous instance created    
    */
    static AptContext* Use();
    /*get all package names */ 
    const std::vector<std::string> GetNames();
    /*get vector that hold structs which contain the package information */
    const std::vector<PkgInfo> GetPackages();
    /*Get All Package Catagories  */
    const std::vector<std::string> GetCatagories();
    /*return boolean represent if the package data parsing completed*/
    const  bool IsParsingCompleted();
};

#endif