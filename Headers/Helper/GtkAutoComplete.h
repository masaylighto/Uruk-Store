#include<gtkmm.h>
#include<vector>
#include<string>
#ifndef H_GtkAutoComplete
#define H_GtkAutoComplete
class AutoComplete
{

     private:
     //used to create Holder for the Rows that will represent the entry in auto complete
     Glib::RefPtr<Gtk::ListStore> AutoCompleteList;
     //Create The Object That Will Offer The AutoComplete Feature
     Glib::RefPtr<Gtk::EntryCompletion> EntryCompletion;
     //Class That Represent The AutoComplete Row that will show in the entry or what ever will make use of the autocomplete feature
     class ModelColumns : public Gtk::TreeModel::ColumnRecord
     {
          public:     
          //Create the widgets that will show on the Row
           Gtk::TreeModelColumn<Glib::ustring> Name;
          //Add The Widget to the Row
           ModelColumns() {  add(Name); }
     };
     //The Row Object That Will Represent how the autocomplete entry will be
     ModelColumns Row;

     /*
     Create List That Used By Gtk::EntryCompletion from Vector
     */
     void CreateAutoCompleteList(std::vector<std::string> List);
     /*
     Create Object That Used By Gtk::entry To Create Auto Complete Feature
     */
     void CreateEntryCompletionObject();
     public:
     //initilize data etc..
     void Init(std::vector<std::string> List);
     Glib::RefPtr<Gtk::EntryCompletion> GetAutoCompleteObject();
};
#endif