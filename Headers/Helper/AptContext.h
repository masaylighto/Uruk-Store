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
//shorten the name space 
namespace apt = ept::apt;
//Hold Apt Get Method
class AptContext
{

    AptContext();
     //vector that will hold all the packages information
    std::vector<std::string> _Names;
    std::vector<std::string> _Catagories;
    //vector that will hold all the packages Names
    std::vector<apt::RecordParser> _Packages;  
    /*
    get list of all files that hold the apt get package informations
    */
    std::vector<std::string> GetSourcesPaths();
        /*
    Get Packages info as string using libept
    */
     std::vector<std::string> GetRawPackages();

    /*
    Parse The packages and store their value in the class member variable
    */

    void ParsePackages();
    public:
    /*
    create and use class if no previous instance created    
    */
    static AptContext* Create();
    /*
    create and use class if and dispose any previous instance created    
    */
    static AptContext* CreateNew();
;
   const std::vector<std::string> GetNames();
   const std::vector<apt::RecordParser> GetPackages();
   const std::vector<std::string> GetCatagories();
};

#endif