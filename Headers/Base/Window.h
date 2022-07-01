#include <gtkmm.h>
#include "Component.h"
#include<iostream>
#include<string>
#include "Helper/FileMethod.h"
#ifndef H_Window
#define H_Window
/*
Base Class For Gtk Window
*/
class Window:public Component
{
private:

   Glib::RefPtr<Gtk::Window>  _Window  ;

   
public:
    /*    
        the constructor will receive the path to the glade file then call the LoadGladeFile 
        also it will receive the name of the window and call Extract Window   
    */
   
     Window(std::string PathToGladeFile,std::string WindowName);
    ~Window()=default;
 
    /*
    show window
    */
    Glib::RefPtr<Gtk::Window>  GetWindow();
    bool LoadCssFile(std::string PathToCssFile);
    void SetCustomTitleBar(Gtk::HeaderBar & TitleBar);
    void SetWindowSize(const int width,const int height);
      //return the top widget through implicit conversation
   
};



#endif