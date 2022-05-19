#include"../Headers/Helper/Apt.h"
#include"../Headers/Pages/MainWindow.h"

int main(int argc,char ** argv){
    
    //Create Gtk Application
    auto App=Gtk::Application::create(argc,argv,"UrukStore");    
    //Create The Main Window 
    MainWindow MainWindowObject("../Ui/Pages/MainWindow.glade","TopWindow"); 
    //load Css File
    MainWindowObject.LoadCssFile("../Ui/Assets/Css/MainWindow.css");
    //Show The Main Window
    Glib::RefPtr<Gtk::Window> Window = MainWindowObject.GetWindow();
    //show the window
    App->run(*Window.get());
}
