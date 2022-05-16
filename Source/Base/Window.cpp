#include"../../Headers/Base/Window.h"
#include <fstream>

Window::Window(std::string PathToGladeFile,std::string WindowName)
{
    InitBuilder(PathToGladeFile);
    ExtractWindow(WindowName);
}
void Window::InitBuilder(std::string PathToGladeFile){
  
     _Builder = Gtk::Builder::create_from_file(PathToGladeFile);
  
}
void Window::ExtractWindow(std::string WindowName)
{
   _Builder.get()->get_widget<Gtk::Window>(WindowName.c_str(),_Window);
}
Gtk::Window* Window::GetWindow()
{
    return _Window;
}
template<class Widget> Glib::RefPtr<Widget> Window::ExtractWidget (std::string WidgetName)
{
  Glib::RefPtr<Widget> ExtractedWidget ;
 _Builder.get()->get_widget<Gtk::Window>(WidgetName.c_str(),ExtractedWidget);
  return ExtractedWidget;
}
Window::~Window()
{
    delete _Window;
}