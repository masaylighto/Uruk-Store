#include"../../Headers/Base/Component.h"
template<class Widget> Glib::RefPtr<Widget> Component::ExtractWidget (std::string WidgetName)
{
    //create Pointer to Receive Widget
   Widget* ExtractedWidget;
   //extract widget from the builder
   _Builder.get()->get_widget<Widget>(WidgetName.c_str(),ExtractedWidget);
   //set it inside of Smart Pointer Then return it
   return Glib::RefPtr<Widget>(ExtractedWidget);
}

void Component::InitBuilder(std::string PathToGladeFile){
   std::string GladeFileContent= ReadFileText(PathToGladeFile);
  _Builder = Gtk::Builder::create_from_string(GladeFileContent);
}
Component::Component(std::string PathToGladeFile)
{  
    InitBuilder(PathToGladeFile);
}
Glib::RefPtr<Gtk::Window> Component::ExtractWindow(std::string WindowName)
{
   return ExtractWidget<Gtk::Window>(WindowName);
}