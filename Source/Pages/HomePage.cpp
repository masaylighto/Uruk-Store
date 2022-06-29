#include "Pages/HomePage.h"

HomePage::HomePage():Page("Ui/Pages/HomePage.glade")
{
   //extract widget from builder
   _TopBox    = ExtractRefPtrWidget<Gtk::Box>("TopBox");
   _SearchBar = ExtractRefPtrWidget<Gtk::Entry>("SearchBar");
    ExtractAppGrid(); 
    //Get Apt Get Packages and set them to a class member 
    AptGet =  AptContext::Create();
    InitCatagoriesGrid();

   

    //Set Widgets Attributes 
    SetWidgetsAttributes(); 
    //Fill App Grid With Them
    FillAppGrid(AptGet->GetPackages());
};
Glib::RefPtr<Gtk::Box> HomePage::GetTopWidget(){
     return _TopBox;
}
void HomePage::SetWidgetsAttributes(){
    //Create Auto Complete Object for the Search bar
   _AutoComplete.Init( AptGet->GetNames());
    //Set The Auto Complete Into Search Bar
   _SearchBar->set_completion(_AutoComplete.GetAutoCompleteObject());
}
void HomePage::SearchEntryKeyPressed( ){
std::cout<<"Hi";
}

void HomePage::ExtractAppGrid()
{
    _AppGrid = ExtractRefPtrWidget<Gtk::Grid>("AppGrid");
}
void HomePage::FillAppGrid(const std::vector<apt::RecordParser> & Apps)
{ 
      //to Specify Which Row, we gonna insert or card into ,we define the variable here 
    // so every 3 loop it gonna increase by 1 , cause we want only three column
    int Row=0;

      for(int Index=0; Index<12 && Index < Apps.size();Index++)
    {   
       const apt::RecordParser Pkg=Apps[Index];
   
        AppBox* Card=CreateCard(Pkg);
        //We Save it Into A global Variable (it will be usefully in many case like de allocating the object)       
        CardList.push_back(Card);
        //the class AppBox is a holder class that hold the widgets,
        //and here we get to top widget that contain the rest of the widget in the glade file
        auto BoxWidget=Card->GetTopWidget().get();
        //we insert the top widget into the Grid
        _AppGrid->insert_row(Index);
       _AppGrid->attach(*(BoxWidget),0,Index);
        //increase the cols so the next object will be in the next col
   
     }
   
}
AppBox * HomePage::CreateCard(const apt::RecordParser & Pkg)
{
   //Class That Represent the Cards
   AppBox* Box = new AppBox();   
   //set the Name of The Box
   Box->SetName(Pkg.lookup("Package"));
   Box->SetDescription(Pkg.lookup("Description"));
   return Box;
}
void HomePage::InitCatagoriesGrid()
{
    _CatagoriesGrid = ExtractRefPtrWidget<Gtk::Grid>("CatagoriesGrid");
    const std::vector<std::string> Catagories = AptGet->GetCatagories(); 

    for(int Index=0; Index < Catagories.size();Index++)
    {   
        _CatagoriesGrid->insert_row(Index);
        _CatagoriesGrid->attach(*CreateCategoryLabel(Catagories[Index]),0,Index);

    }
    _CatagoriesGrid->show_all_children();
}

Gtk::Button* HomePage::CreateCategoryLabel(std::string text) 
{

        Gtk::Button * Btn =new Gtk::Button();     
        Btn->set_label(text);
        Btn->set_hexpand(false);
        Btn->set_vexpand(true);
 
        Btn->set_size_request(100,40);
        Btn->set_margin_top(10);
        Btn->set_margin_bottom(10);
        Btn->set_alignment(Gtk::Align::ALIGN_CENTER,Gtk::Align::ALIGN_CENTER);
        auto Context= Btn->get_style_context();
        Context->add_class("Bg-White");
        Context->add_class("Rounded");
        Context->add_class("Border-none");
        Context->add_class("OnClick");
        Context->add_class("Noshadow");
        return Btn;
}