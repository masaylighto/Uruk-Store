#include <gtkmm.h>
#include<iostream>
#include<string>
#include"../Helper/Variety.h"
#ifndef H_Component
#define H_Component
/*
Base Class For Gtk Window
*/
class Component
{
private:
   //This Fill Will Hold The Builder Instance So We Can Extract Element From It
   Glib::RefPtr<Gtk::Builder> _Builder ;
   /*
   read glade file 
   */
    
   void InitBuilder(std::string PathToGladeFile);

   
public:
    /*    
        the constructor will receive the path to the glade file then call the InitBuilder            
    */
    Component(std::string PathToGladeFile);
    ~Component()=default;
    /*
    Extract Widget from Builder
    */

    template<class Widget> Glib::RefPtr<Widget> ExtractWidget (std::string WidgetName);
    Glib::RefPtr<Gtk::Window> ExtractWindow(std::string WindowName);
  
    
};



#endif