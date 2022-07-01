#include<thread>
#include "Helper/AptContext.h"
#ifndef H_Startup
#define H_Startup
class Startup
{
private:
  
    /*Terminate the application if it doesn't have access to root privileges*/
    void EnsureSuperUserMode();
    void InitApt();
    
public:
    Startup();
    ~Startup()=default;
};
#endif
