#include"../../Headers/Pages/HomePage.h"

HomePage::HomePage():Page("Ui/Pages/HomePage.glade")
{
   _TopBox    = ExtractRefPtrWidget<Gtk::Box>("TopBox");
   _SearchBar = ExtractRefPtrWidget<Gtk::Entry>("SearchBar");
    SetWidgetsAttributes(); 
};
Glib::RefPtr<Gtk::Box> HomePage::GetTopWidget(){
     return _TopBox;
}
void HomePage::SetWidgetsAttributes(){
  
   _AutoComplete.Init( GetAptPackages(-1));
   _SearchBar->set_completion(_AutoComplete.GetAutoCompleteObject());
}
void HomePage::SearchEntryKeyPressed( ){
std::cout<<"Hi";
}
