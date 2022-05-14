#include <gtkmm.h>

#ifndef H_Window
#define H_Window
/*
Base Class For Gtk Window
*/
class Window
{
private:
   //This Fill Will Hold The Builder Instance So We Can Extract Element From It
   Gtk::Builder _Builder ;
   Gtk::Window  _Window  ;
   void initBuilder(std::string PathToGladeFile);
   void initWindow();
public:
    Window(std::string PathToGladeFile);
    ~Window();
    void Show();
};



#endif