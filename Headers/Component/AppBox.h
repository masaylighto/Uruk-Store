#include "../Base/Component.h"
#include<iostream>
#include<string>


#ifndef H_AppBox
#define H_AppBox
/*
Base Class For Gtk Based Class That I Will make in this application
*/
class PackageCard:public Component
{
    private:
       Glib::RefPtr<Gtk::Label> _NameLabel;
       Glib::RefPtr<Gtk::TextView> _DescriptionLabel;
       Glib::RefPtr<Gtk::Button> _ShowBtn;
       Glib::RefPtr<Gtk::Box> _Container;
    /*
    Extract App Name from Builder
    */
    void ExtractNameLabel();
        /*
    Extract App Name from Builder
    */
    void ExtractDescriptionLabel();
    /*
    
    Extract Show Btn from Builder
    */
    void ExtractShowBtn();
      /*
    
    Extract Container from Builder
    */
    void ExtractContainer();
    public: 
    PackageCard();
    ~PackageCard();
    /*
    Set The Text On the Label That represent The app name
    */
    void SetName(std::string Name);
    /*
    Get The Top Widget in the Parsed Glade File
    */
    Glib::RefPtr<Gtk::Box> GetTopWidget();
    /*
    Set The Text On the Label That represent The Description
    */
    void SetDescription(std::string Name);
    //return the top widget through implicit conversation
    operator Gtk::Box * ()
    {
      return _Container.get();
    } 
    
};
#endif