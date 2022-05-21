#include <gtkmm.h>

#include<iostream>
#include<string>
#include"../Helper/Variety.h"

#ifndef H_Component
#define H_Component
/*
Base Class For Gtk Based Class That I Will make in this application
*/
class Component
{
private:
   //This Fill Will Hold The Builder Instance So We Can Extract Element From It
   Glib::RefPtr<Gtk::Builder> _Builder ;

   
   /*
   read glade file into Gtk::Builder
   */
    
   void LoadGladeFile(std::string PathToGladeFile);

   
public:
    /*    
        the constructor will receive the path to the glade file then call the LoadGladeFile            
    */
    Component(std::string PathToGladeFile);
    ~Component()=default;
  
    //I'm very sure that declaring function body inside header is a very ugly thing
    //but give me a chance to explain before you hang me, Your Honor.
    //this is a template function, and the compiler need to see the implementation so it could generate code for all specializations.
    template<class Widget>  Glib::RefPtr<Widget> ExtractRefPtrWidget (std::string WidgetName) 
    {
         
        //create Pointer to Receive Widget
        Widget* ExtractedWidget;
        //extract widget from the builder
        _Builder.get()->get_widget<Widget>(WidgetName.c_str(),ExtractedWidget);
        //set it inside of Smart Pointer Then return it
        return Glib::RefPtr<Widget>(ExtractedWidget);
    }
   
    //I'm very sure that declaring function body inside header is a very ugly thing
    //but give me a chance to explain before you hang me, Your Honor.
    //this is a template function, and the compiler need to see the implementation so it could generate code for all specializations.
    template<class Widget>  Widget* ExtractWidget (std::string WidgetName) 
    {
         
        //create Pointer to Receive Widget
        Widget* ExtractedWidget;
        //extract widget from the builder
        _Builder.get()->get_widget<Widget>(WidgetName.c_str(),ExtractedWidget);
        //set it inside of Smart Pointer Then return it
        return ExtractedWidget;
    }
  
};

#endif