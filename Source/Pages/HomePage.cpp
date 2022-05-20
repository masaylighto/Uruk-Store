#include"../../Headers/Pages/HomePage.h"

HomePage::HomePage():Page("../Ui/Pages/HomePage.glade")
{

};
Glib::RefPtr<Gtk::Box> HomePage::GetTopWidget()
{

    return ExtractWidget<Gtk::Box>("TopBox");
}