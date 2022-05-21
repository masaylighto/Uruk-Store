#include"../../Headers/Helper/GtkAutoComplete.h"
    /*
    Create List That Used By Gtk::EntryCompletion
    */
    void AutoComplete::CreateAutoCompleteList(std::vector<std::string> List)
    {              
        AutoCompleteList = Gtk::ListStore::create(Row);
        for (int Index = 0; Index < List.size(); Index++)
        {
           //set the value to the first column ||  the auto complete model may hold more than one column so we specify which one we one
            AutoCompleteList->append()->set_value(0,List[Index]);
            
        }
    }
    /*
    Create Object That Used By Gtk::entry To Create Auto Complete Feature
    */
    void AutoComplete::CreateEntryCompletionObject()
    {
        EntryCompletion = Gtk::EntryCompletion::create();
        //set the model that hold the auto completion data
        EntryCompletion->set_model(AutoCompleteList);
        //set the column that will be used to auto complete || the auto complete model may hold more than one column so we specify which one we one
        EntryCompletion->set_text_column(Row.Name);
        //minimum length of character to show auto complete
        EntryCompletion->set_minimum_key_length(1);
        //is auto complete popup enabled 
        EntryCompletion->set_popup_completion(true);
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