
#include "Base/Page.h"
#include"Helper/GtkAutoComplete.h"
#include "Helper/AptContext.h"
#include "Component/AppBox.h"
#ifndef H_HomePage
#define H_HomePage

class HomePage:public Page
{

private:
    //represent the top widget in this page 
    Glib::RefPtr<Gtk::Box> _TopBox;
    Glib::RefPtr<Gtk::Entry> _SearchBar;
    //create instance of class apt
    AptContext* AptGet;
    AutoComplete _AutoComplete;
    /*
    the grid that hold cards that show some of the application that can be downloaded
    */
    Glib::RefPtr<Gtk::Grid> _AppGrid;
    /*  this vector Will Contain a list of all Card That will be created; */
    std::vector<PkgBox *> _PkgBoxVector; 
    //this variable will hold the Catagories Grid
    Glib::RefPtr<Gtk::Grid> _CatagoriesGrid;

    /*
    Set All Widget Attributes
    */
    void SetWidgetsAttributes();
    /*
    event that fired when keyboard Key Pressed on  SearchBar 
    */
    bool SearchKeyReleased(GdkEventKey* event );
    /*

    Extract The App Grid From The Builder
    */
    void ExtractAppGrid();
    /*   
     fill the application grid with application 
     Skip and Take for Pagination
     PartialMatchName Used To Filter Package By Name   
     */
    void FillPkgsGrid(const int Skip = 0,const int Take = 12 ,const std::string PartialMatchName="");
    /*create card that represent tha packages*/
    PkgBox * CreateCard(const PkgInfo & Pkg);
    void FillCatagoriesGrid();
    Gtk::Button* CreateCategoryLabel(std::string text);
    /* this method used to free the CreatePkgs */
    void FreePkgBoxVector();
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