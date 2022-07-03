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

    void ExtractNameLabel();

    void ExtractDescriptionLabel();

    void ExtractShowBtn();

    void ExtractContainer();
    public: 
    PackageCard();
    ~PackageCard();

    void SetName(std::string Name);

    Glib::RefPtr<Gtk::Box> GetTopWidget();

    void SetDescription(std::string Name);
    //return the top widget through implicit conversation
    operator Gtk::Box * ()
    {
      return _Container.get();
    } 

};
#endif