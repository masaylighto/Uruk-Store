#include <gtkmm.h>
#include<iostream>
#ifndef H_Window
#define H_Window
/*
Base Class For Gtk Window
*/
class Window
{
private:
   //This Fill Will Hold The Builder Instance So We Can Extract Element From It
   Glib::RefPtr<Gtk::Builder> _Builder ;
   Gtk::Window*  _Window  ;
   /*
   read glade file 
   */
   void InitBuilder(std::string PathToGladeFile);
   /*
   extract window from builder
   */
   void ExtractWindow(std::string WindowName);
   
public:
    /*    
        the constructor will receive the path to the glade file then call the InitBuilder 
        also it will receive the name of the window and call Extract Window   
    */
    Window(std::string PathToGladeFile,std::string WindowName);
    ~Window();
    /*
    Extract Widget from Builder
    */
    template<class Widget> Glib::RefPtr<Widget> ExtractWidget (std::string WidgetName);
    /*
    show window
    */
    Gtk::Window* GetWindow();
};



#endif