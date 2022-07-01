
#include "Base/Page.h"
#include "Helper/AptContext.h"
#include "Component/AppBox.h"
#ifndef H_HomePage
#define H_HomePage
#define NoGCOptimization __attribute__((optimize("O0")))  
class HomePage:public Page
{

private:
    //represent the top widget in this page 
    Glib::RefPtr<Gtk::Box> _TopBox;
    Glib::RefPtr<Gtk::Entry> _SearchBar;
    //create instance of class apt
    AptContext* AptGet;
    /* the grid that hold cards that show some of the application that can be downloaded */
    Glib::RefPtr<Gtk::Grid> _PackagesGrid;
    /*  this vector Will Contain a list of all Card That will be created; */
    std::vector<PackageCard *> _PackageCardVector; 
    //this variable will hold the Catagories Grid
    Glib::RefPtr<Gtk::Grid> _CatagoriesGrid;
    /* Set All Widget Attributes */
    void SetWidgetsAttributes();
    /* event that fired when keyboard Key Released from SearchBar */
    bool SearchKeyReleased(GdkEventKey* event );
    /* Extract The App Grid From The Builder */
    void ExtractAppGrid();
     /*   
     fill the application grid with application 
     Skip and Take for Pagination
     PartialMatchName Used To Filter Package By Name   
     */
    void NoGCOptimization FillPackagesGrid(const int Skip = 0,const int Take = 12 ,const std::string PartialMatchName="") ;
    /*create card that represent tha packages*/
    PackageCard * CreateCard(const PkgInfo & Pkg);
    void FillCatagoriesGrid();
    Gtk::Button* CreateCategoryBtn(std::string text);
    /* this method used to free the CreatePkgs */
    void NoGCOptimization ClearPackagesGrid();
public:
    /* this constructor will pass its parameter to window base class */
    HomePage();
    ~HomePage();
    /* Extract the top Widget which in this page is Gtk::Box from builder and return it into the caller  */
    Glib::RefPtr<Gtk::Box> GetTopWidget();
     //return the top widget through implicit conversation
    operator Gtk::Box* () { return _TopBox.get(); } 
};



#endif