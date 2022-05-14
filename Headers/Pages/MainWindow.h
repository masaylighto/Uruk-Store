
#include "../Base/Window.h"
#ifndef H_MainWindow
#define H_MainWindow

class MainWindow:public Window
{

private:
   
public:
    /* this constructor will pass its parameter to window base class */
    MainWindow(std::string PathToGladeFile);
    ~MainWindow(){

        
    };
   
};



#endif