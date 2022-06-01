#include"../../Headers/Pages/HomePage.h"

HomePage::HomePage():Page("Ui/Pages/HomePage.glade")
{
   //extract widget from builder
   _TopBox    = ExtractRefPtrWidget<Gtk::Box>("TopBox");
   _SearchBar = ExtractRefPtrWidget<Gtk::Entry>("SearchBar");
    ExtractAppGrid(); 
    //Get Apt Get Packages and set them to a class member 
    AptPackages=Apt::GetPackages();
   //Set Widgets Attributes 
    SetWidgetsAttributes(); 
    //Fill App Grid With Them
    FillAppGrid(AptPackages);
};
Glib::RefPtr<Gtk::Box> HomePage::GetTopWidget(){
     return _TopBox;
}
void HomePage::SetWidgetsAttributes(){
   //Extract All Packages Name from Packages Vector
    std::vector<std::string> PackagesName= Apt::ExtractPackagesName(AptPackages);
    //Create Auto Complete Object for the Search bar
   _AutoComplete.Init( PackagesName);
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
void HomePage::FillAppGrid(std::vector<Package> Apps)
{ 
      //to Specify Which Row, we gonna insert or card into ,we define the variable here 
    // so every 3 loop it gonna increase by 1 , cause we want only three column
    int Row=0;
    int Cols=0;
    for(int Index=0; Index<6 && Index < Apps.size();Index++)
    {   
       const Package Pkg=Apps[Index];
        //here we try to maintain only the col in the grid
        if (Index%3==0)
        {   //if we fill the three cols then go to the next row
            Row++;            
            //reset the col of index%3 so only 3 col will be in any Row
            Cols=0;
        } 
        AppBox* Card=CreateCard(Pkg);
        //We Save it Into A global Variable (it will be usefully in many case like de allocating the object)       
        CardList.push_back(Card);
        //the class AppBox is a holder class that hold the widgets,
        //and here we get to top widget that contain the rest of the widget in the glade file
        auto BoxWidget=Card->GetTopWidget().get();
        //we insert the top widget into the Grid
       _AppGrid->attach(*(BoxWidget),Cols,Row);
        //increase the cols so the next object will be in the next col
        Cols++;
     }
   
}
AppBox * HomePage::CreateCard(Package Pkg)
{
   //Class That Represent the Cards
   AppBox* Box = new AppBox();   
   //set the Name of The Box
   Box->SetName(Pkg.Name);
   return Box;
}