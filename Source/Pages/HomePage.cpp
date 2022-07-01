#include "Pages/HomePage.h"

HomePage::HomePage():Page("Ui/Pages/HomePage.glade")
{
   //extract widget from builder
   _TopBox    = ExtractRefPtrWidget<Gtk::Box>("TopBox");
   _SearchBar = ExtractRefPtrWidget<Gtk::Entry>("SearchBar");
    ExtractAppGrid(); 
  
    //Get Apt Get Packages and set them to a class member 
    AptGet =  AptContext::Use();
  
    while (!AptGet->IsParsingCompleted())
    {
        
    }

    FillCatagoriesGrid();

   

    //Set Widgets Attributes 
    SetWidgetsAttributes(); 
    //Fill App Grid With Them
    FillPkgsGrid(0,12);
};
Glib::RefPtr<Gtk::Box> HomePage::GetTopWidget(){
     return _TopBox;
}


void HomePage::SetWidgetsAttributes()
{
  _SearchBar->signal_key_release_event().connect(sigc::mem_fun(*this,&HomePage::SearchKeyReleased),false);
}

bool HomePage::SearchKeyReleased(GdkEventKey* event)
{
    FillPkgsGrid(0,12,_SearchBar->get_text());
  
    return true;
}
void HomePage::FreePkgBoxVector()
{
    //free vector of
    for (int index = (_PkgBoxVector.size())-1; index >=0 ; index--)
    {  
        _AppGrid->remove(*(_PkgBoxVector.at(index)->GetTopWidget().get()));
        delete _PkgBoxVector[index];
  
       
    }
    _PkgBoxVector.clear();
    
}
void HomePage::ExtractAppGrid()
{
    _AppGrid = ExtractRefPtrWidget<Gtk::Grid>("AppGrid");
}
void HomePage::FillPkgsGrid(const int Skip ,const int Take,const std::string PartialMatchName)
{ 
     //free any previously Created PkgBox 
    FreePkgBoxVector();

    const std::vector<PkgInfo> & Pkgs = AptGet->GetPackages(); 
     //to Specify Which Row, we gonna insert or card into ,we define the variable here 
    // so every 3 loop it gonna increase by 1 , cause we want only three column
    int Row=0;
    for(int Index=Skip; Row<Take && Index < Pkgs.size();Index++)
    {   
        const PkgInfo & Pkg=Pkgs[Index];
   
        if (Pkg.Name.find(PartialMatchName)==-1 && PartialMatchName!="")
        {
            continue;
        }
        Row++;    
        PkgBox* Card=CreateCard(Pkg);
        //We Save it Into A global Variable (it will be usefully in many case like de allocating the object)       
        _PkgBoxVector.push_back(Card);
        //the class PkgBox is a holder class that hold the widgets,
        //and here we get to top widget that contain the rest of the widget in the glade file
        auto BoxWidget=Card->GetTopWidget().get();     
       _AppGrid->attach(*(BoxWidget),0,Row);
       
        //increase the cols so the next object will be in the next col
    }
}
PkgBox * HomePage::CreateCard(const PkgInfo & Pkg)
{
   //Class That Represent the Cards
   PkgBox* Box = new PkgBox();   
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

Gtk::Button* HomePage::CreateCategoryBtn(std::string text) 
{

        Gtk::Button * Btn =new Gtk::Button();     
        Btn->set_label(text);
        Btn->set_hexpand(false);
        Btn->set_vexpand(true);
 
        Btn->set_size_request(100,40);
        Btn->set_margin_top(10);
        Btn->set_margin_bottom(10);
       // Btn->set_alignment(Gtk::Align::ALIGN_CENTER,Gtk::Align::ALIGN_CENTER);
        auto Context= Btn->get_style_context();
        Context->add_class("Bg-White");
        Context->add_class("Rounded");
        Context->add_class("Border-none");
        Context->add_class("OnClick");
        Context->add_class("Noshadow");
        return Btn;
}
HomePage::~HomePage()
{
      FreePkgBoxVector();
}