
#include "../Base/Page.h"
#include"../Helper/GtkAutoComplete.h"
#include"../Helper/Apt.h"
#include "../Component/AppBox.h"
#ifndef H_HomePage
#define H_HomePage

class HomePage:public Page
{

private:
    //represent the top widget in this page 
    Glib::RefPtr<Gtk::Box> _TopBox;
    Glib::RefPtr<Gtk::Entry> _SearchBar;
    std::vector<Package> AptPackages;
    AutoComplete _AutoComplete;
    /*
    the grid that hold cards that show some of the application that can be downloaded
    */
    Glib::RefPtr<Gtk::Grid> _AppGrid;
    /*    
        this vector Will Contain a list of all Card That will be created;
    */
    std::vector<AppBox *> CardList; 
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
     /*
    
    Extract The App Grid From The Builder
    */
    void ExtractAppGrid();
    /*
    
    fill the application grid with application
    */
    void FillAppGrid(std::vector<Package> Apps);
   AppBox * CreateCard(Package Pkg);
};



#endif