
#include "../Base/Page.h"
#include"../Helper/GtkAutoComplete.h"
#include"../Helper/Apt.h"
#ifndef H_HomePage
#define H_HomePage

class HomePage:public Page
{

private:
    //represent the top widget in this page 
    Glib::RefPtr<Gtk::Box> _TopBox;
    Glib::RefPtr<Gtk::Entry> _SearchBar;
    AutoComplete _AutoComplete;
public:
    /* this constructor will pass its parameter to window base class */
    HomePage();
    ~HomePage()=default;
    /*
    Extract the top Widget which in this page is Gtk::Box from builder and return it into the caller    
    */
  
     Glib::RefPtr<Gtk::Box> GetTopWidget();
     /*
     Set All Widget Attributes
     */
     void SetWidgetsAttributes();
     /*
     event that fired when keyboard Key Pressed on  SearchBar 
     */
     void SearchEntryKeyPressed( );
 
};



#endif