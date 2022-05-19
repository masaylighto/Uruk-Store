#include <gtkmm.h>
#include<iostream>
#include "../Helper/Variety.h"
#ifndef H_Page
#define H_Page
class page
{
private:
    //This Fill Will Hold The Builder Instance So We Can Extract Element From It
   Glib::RefPtr<Gtk::Builder> _Builder ;
   Glib::RefPtr<Gtk::Widget>  _TopWidget  ;
public:
    page(/* args */);
    ~page();
};



#endif