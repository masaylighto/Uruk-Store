#include "Pages/HomePage.h"

HomePage::HomePage():Page("Ui/Pages/HomePage.glade")
{
   //extract widget from builder
   _TopBox    = ExtractRefPtrWidget<Gtk::Box>("TopBox");
   _SearchBar = ExtractRefPtrWidget<Gtk::Entry>("SearchBar");
    ExtractAppGrid(); 
    //Get Apt Get Packages and set them to a class member 
    AptGet =  AptContext::Use();
    //AptGet Run in a thread and after this line we gonna use its data
    //so we check and wait till its finish parsing data
    while (!AptGet->IsParsingCompleted());
    //Set Widgets Attributes 
    SetWidgetsAttributes(); 
    //Fill App Grid With Them
    FillPackagesGrid(0,12);
    //fill Catagories Grid
    FillCatagoriesGrid();
};

void HomePage::SetWidgetsAttributes()
{
  _SearchBar->signal_key_release_event().connect(sigc::mem_fun(*this,&HomePage::SearchKeyReleased),false);
}

bool HomePage::SearchKeyReleased(GdkEventKey* event)
{
    FillPackagesGrid(0,12,_SearchBar->get_text());
  
    return true;
}
void HomePage::ClearPackagesGrid() 
{
    //free vector of
    for (int index = (_PackageCardVector.size())-1; index >=0 ; index--)
    {  
        PackageCard * pkg=  _PackageCardVector[index];
        _PackagesGrid->remove(*(*pkg));        
        delete pkg;
    }
    _PackageCardVector.clear();
    
}
void HomePage::ExtractAppGrid()
{
    _PackagesGrid = ExtractRefPtrWidget<Gtk::Grid>("AppGrid");
}
void HomePage::FillPackagesGrid(const int Skip ,const int Take,const std::string PartialMatchName) 
{ 
     //free any previously Created PackageCard 
    ClearPackagesGrid();

    const std::vector<PkgInfo> & Packages = AptGet->GetPackages(); 
     //to Specify Which Row, we gonna insert or card into ,we define the variable here 
    // so every 3 loop it gonna increase by 1 , cause we want only three column
    int Row=0;
    for(int Index=Skip; Row<Take && Index < Packages.size();Index++)
    {   
        const PkgInfo & Pkg=Packages[Index];
   
        if (Pkg.Name.find(PartialMatchName)==-1 && PartialMatchName!="")
        {
            continue;
        }
        Row++;    
        PackageCard* Card = CreateCard(Pkg);
        //We Save it Into A global Variable (it will be usefully in many case like de allocating the object)       
        _PackageCardVector.push_back(Card);
        //the class PackageCard is a holder class that hold the widgets            
       _PackagesGrid->attach(*(*Card),0,Row);
       
        //increase the cols so the next object will be in the next col
    }
}
PackageCard * HomePage::CreateCard(const PkgInfo & Pkg)
{
   //Class That Represent the Cards
   PackageCard* Box = new PackageCard();   
   //set the Name of The Box
   Box->SetName(Pkg.Name);
   Box->SetDescription(Pkg.Description);
   return Box;
}
void HomePage::FillCatagoriesGrid()
{
    _CatagoriesGrid = ExtractRefPtrWidget<Gtk::Grid>("CatagoriesGrid");
    std::map<std::string,std::string> Categories = AptGet->GetCatagories(); 
    int Index=0;   
    for( std::map<std::string,std::string>::iterator Category = Categories.begin(); Category != Categories.end(); Category++,Index++ )
    {
         const std::string CategoryName=Category->first;
        _CatagoriesGrid->insert_row(Index);
        _CatagoriesGrid->attach(*CreateCategoryBtn(CategoryName),0,Index);
    }
    _CatagoriesGrid->show_all_children();
}

Gtk::CheckButton* HomePage::CreateCategoryBtn(std::string text) 
{

        Gtk::CheckButton * Btn =new Gtk::CheckButton();     
        Btn->set_label(text);
        Btn->set_hexpand(false);
        Btn->set_vexpand(true);
 
        Btn->set_size_request(100,40);
        Btn->set_margin_top(10);
        Btn->set_margin_bottom(10);
      //  Btn->set_property_value("")
        auto Context= Btn->get_style_context();
        Context->add_class("Bg-White");
        Context->add_class("Rounded");
        Context->add_class("Border-none");
        Context->add_class("OnClick");
        Context->add_class("Noshadow");
        Context->add_class("IsChecked");
        Context->add_class("hiddenIndicator");
        return Btn;
}
HomePage::~HomePage()
{
    ClearPackagesGrid();
    _TopBox.release();
    _PackagesGrid.release();
    _CatagoriesGrid.release();
}