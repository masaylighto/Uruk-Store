#include"../../Headers/Base/Window.h"


Window::Window(std::string PathToGladeFile,std::string WindowName):Component(PathToGladeFile)
{  
    _Window = ExtractRefPtrWidget<Gtk::Window>(WindowName);

}
void Window::SetCustomTitleBar(Gtk::HeaderBar & TitleBar)
{
_Window->set_titlebar(TitleBar);
}
void Window::SetWindowSize(const int Width,const int Height){
    _Window->set_size_request(Width,Height);
}
bool Window::LoadCssFile(std::string PathToCssFile)
{
    try
    {
        auto Css = Gtk::CssProvider::create();  
        Css->load_from_path(PathToCssFile);
        Gtk::StyleContext::add_provider_for_screen
        (
            Gdk::Screen::get_default(), 
            Css,
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

Glib::RefPtr<Gtk::Window> Window::GetWindow()
{
    return _Window;
}

