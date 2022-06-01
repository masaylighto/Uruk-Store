#include <memory>
#include "../Base/Window.h"
#include "HomePage.h"

#ifndef H_MainWindow
#define H_MainWindow

class MainWindow:public Window
{

private:
    //this variable will hold the Widget that will hold the different Pages
    Glib::RefPtr<Gtk::Frame> _PagesFrame;
    /*
    the first page in the application 
    */
    std::shared_ptr<HomePage> _HomePage;

 
public:
    /* this constructor will pass its parameter to window base class */
    MainWindow(std::string PathToGladeFile,std::string WindowName);
    ~MainWindow()=default;
    /*
        this function will load the first Page In The Application
        which contain the search for application 
    */  
    void LoadHomePage();
    /*
     Extract The Pages Frame From The Builder
     and Store into the PagesFrame Global Variable
    */
    void InitPagesFrame();

};



#endif