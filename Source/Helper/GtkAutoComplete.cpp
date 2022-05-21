#include"../../Headers/Helper/GtkAutoComplete.h"
    /*
    Create List That Used By Gtk::EntryCompletion
    */
    void AutoComplete::CreateAutoCompleteList(std::vector<std::string> List)
    {              
        AutoCompleteList = Gtk::ListStore::create(Row);
        for (int Index = 0; Index < List.size(); Index++)
        {
            Gtk::TreeModel::Row row=  *(AutoCompleteList->append());
            row->set_value(0,List[Index]);
        }
    }
    /*
    Create Object That Used By Gtk::entry To Create Auto Complete Feature
    */
    void AutoComplete::CreateEntryCompletionObject()
    {
        EntryCompletion =   Gtk::EntryCompletion::create();
        EntryCompletion->set_model(AutoCompleteList);
    }
    Glib::RefPtr<Gtk::EntryCompletion> AutoComplete::GetAutoCompleteObject()
    {
        return EntryCompletion;
    }

    void AutoComplete::Init(std::vector<std::string> List)
    {

            CreateAutoCompleteList(List);
            CreateEntryCompletionObject();
    }