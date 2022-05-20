
#include "../Base/Page.h"
#ifndef H_HomePage
#define H_HomePage

class HomePage:public Page
{

private:
   
public:
    /* this constructor will pass its parameter to window base class */
    HomePage();
    ~HomePage()=default;
    /*
    Extract the top Widget which in this page is Gtk::Box from builder and return it into the caller    
    */
     Glib::RefPtr<Gtk::Box> GetTopWidget();
   
};



#endif