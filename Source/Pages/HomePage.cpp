#include "Pages/HomePage.h"

HomePage::HomePage():Page("Ui/Pages/HomePage.glade")
{
    ExtractWidgets(); 
    //AptGet Run in a thread and after this line we gonna use its data
    EnsureAptFinishParsing();
    SetWidgetsAttributes(); 
    FillCatagoriesGrid();
    InitSelectedCategoriesMap();
    FillPackagesGrid(0,12);
}
void HomePage::EnsureAptFinishParsing()
{
    //AptGet Run in a thread and after this line we gonna use its data
    //check and wait till its finish parsing data
    while (!AptGet->IsParsingCompleted());
}
void HomePage::SetWidgetsAttributes()
{
  _SearchBar->signal_key_release_event().connect(sigc::mem_fun(*this,&HomePage::SearchKeyReleased),false);
}

bool HomePage::SearchKeyReleased(GdkEventKey* event)
{
    _SearchBarText=_SearchBar->get_text();
    FillPackagesGrid(0,12);  
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
void HomePage::ExtractWidgets()
{
   _TopBox    = ExtractRefPtrWidget<Gtk::Box>("TopBox");
   _SearchBar = ExtractRefPtrWidget<Gtk::Entry>("SearchBar");
   _CatagoriesGrid = ExtractRefPtrWidget<Gtk::Grid>("CatagoriesGrid");
   _PackagesGrid   = ExtractRefPtrWidget<Gtk::Grid>("AppGrid");
}
const bool HomePage::DoesPkgPassFilter(const PkgInfo & Pkg)
{
    const bool IsNameMatch=Pkg.Name.find(_SearchBarText)!=-1 || _SearchBarText=="";
    bool IsCatagoriesMatch =false;  
    //check if the "" key have the value of true
    if (_SelectedCategories["all"])
    {
       return IsNameMatch && true;
    }
    
    for( std::map<std::string,bool>::iterator Category = _SelectedCategories.begin(); Category != _SelectedCategories.end(); Category++ )
    {
       
       if (Pkg.Section.find(Category->first)!=-1)
       {
         IsCatagoriesMatch=Category->second;
         break;
       }    
    }
    return IsNameMatch && IsCatagoriesMatch;
}
void HomePage::FillPackagesGrid(const int Skip ,const int Take) 
{ 
     //free any previously Created PackageCard 
    ClearPackagesGrid();

    const std::vector<PkgInfo> & Packages = AptGet->GetPackages(); 
    for(int Row=0,Index=Skip; Row<Take && Index < Packages.size();Index++)
    {   
        try
        {        
            const PkgInfo & Pkg=Packages[Index];
            if (!DoesPkgPassFilter(Pkg))
            {    
                 continue;
            }
            Row++;    
            PackageCard* Card = CreateCard(Pkg);
            //We Save it Into A global Variable (it will be usefully in many case like de allocating the object)       
            _PackageCardVector.push_back(Card);      
            _PackagesGrid->attach(*(*Card),0,Row);        
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
PackageCard * HomePage::CreateCard(const PkgInfo & Pkg)
{
   //Class That Represent the Cards
   PackageCard* Box = new PackageCard();   
   Box->SetName(Pkg.Name);
   Box->SetDescription(Pkg.Description);
   return Box;
}
void HomePage::InitSelectedCategoriesMap()
{   
    std::map<std::string,std::string> Categories = AptGet->GetCatagories(); 
    for( std::map<std::string,std::string>::iterator Category = Categories.begin(); Category != Categories.end(); Category++)
    {
            _SelectedCategories[Category->second]=false;
    }
    //set all to be true by default
    _SelectedCategories["all"]=true;
}

void HomePage::FillCatagoriesGrid()
{
    
    std::map<std::string,std::string> Categories = AptGet->GetCatagories(); 
    int Index=0;   
    for( std::map<std::string,std::string>::iterator Category = Categories.begin(); Category != Categories.end(); Category++,Index++ )
    {        
         const std::string CategoryName=Category->first;        
        _CatagoriesGrid->insert_row(Index);
         Gtk::CheckButton* CategoryCheckBtn=CreateCategoryCheckBtn(CategoryName);         
        _CatagoriesGrid->attach(*CategoryCheckBtn,0,Index);  
         CatagoriesButtons.push_back(CategoryCheckBtn);
    }
    _CatagoriesGrid->show_all_children();
}

Gtk::CheckButton* HomePage::CreateCategoryCheckBtn(const std::string & text) 
{

        Gtk::CheckButton * Btn =new Gtk::CheckButton();     
        Btn->set_label(text);
        Btn->set_hexpand(false);
        Btn->set_vexpand(true); 
        Btn->set_size_request(100,40);
        Btn->set_margin_top(10);
        Btn->set_margin_bottom(10);
        if(text=="All")
        {
        Btn->set_active(true);
        }
        //style the CheckButton
        auto Context= Btn->get_style_context();
        Context->add_class("Bg-White");
        Context->add_class("Rounded");
        Context->add_class("Border-none");
        Context->add_class("OnClick");
        Context->add_class("Noshadow");
        Context->add_class("IsChecked");
        Context->add_class("hiddenIndicator");
        auto Event= sigc::mem_fun(*this,&HomePage::ToggleCategoryBtn);
        Btn->signal_toggled().connect(Event,false);
        return Btn;
}
void HomePage::ToggleCategoryBtn()
{

    SetSelectedCatagoriesIntoMap();
    FillPackagesGrid(0,12);
}
HomePage::~HomePage()
{
    ClearPackagesGrid();
    _TopBox.release();
    _PackagesGrid.release();
    _CatagoriesGrid.release();    
    for (int index = 0; index < CatagoriesButtons.size(); index++)
    {
        CatagoriesButtons[index]->unreference();
    }
    CatagoriesButtons.clear();
}

void HomePage::SetSelectedCatagoriesIntoMap()
{
 for (int i = 0; i < CatagoriesButtons.size(); i++)
 {
    const Gtk::CheckButton * CategoryBtn = CatagoriesButtons[i];
    const std::string & CategoryBtnText  = CategoryBtn->get_label();
    const std::string & RealName         = AptGet->GetCategoryRealName(CategoryBtnText);
   _SelectedCategories[RealName]         = CategoryBtn->get_active();
 }
}