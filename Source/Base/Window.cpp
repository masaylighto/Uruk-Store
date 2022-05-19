#include"../../Headers/Base/Window.h"


Window::Window(std::string PathToGladeFile,std::string WindowName)
{  
    
    InitBuilder(PathToGladeFile);
    ExtractWindow(WindowName);

}

bool Window::LoadCssFile(std::string PathToCssFile)
{
    try
    {
        auto Css = Gtk::CssProvider::create();

        Css->load_from_data(ReadFileText(PathToCssFile));

        Gtk::StyleContext::add_provider_for_screen(
            Gdk::Screen::get_default(), Css,
            GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
        );
    }
    catch(const Gtk::CssProviderError error)
    {
        std::cerr << "Failed to load style:" <<error.code() << std::endl;
        return false;
    }
    return true;
}

void Window::InitBuilder(std::string PathToGladeFile){
   
   std::string GladeFileContent= ReadFileText(PathToGladeFile);
  _Builder = Gtk::Builder::create_from_string(GladeFileContent);
    
}
void Window::ExtractWindow(std::string WindowName)
{
    _Window = ExtractWidget<Gtk::Window>(WindowName);
}
Glib::RefPtr<Gtk::Window> Window::GetWindow()
{
    return _Window;
}
template<class Widget> Glib::RefPtr<Widget> Window::ExtractWidget (std::string WidgetName)
{
    //create Pointer to Receive Widget
   Widget* ExtractedWidget;
   //extract widget from the builder
   _Builder.get()->get_widget<Widget>(WidgetName.c_str(),ExtractedWidget);
   //set it inside of Smart Pointer Then return it
   return Glib::RefPtr<Widget>(ExtractedWidget);
}
Window::~Window()
{
   
}