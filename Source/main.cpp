#include"../Headers/Pages/MainWindow.h"
#include "Startup.h"

#include <iostream>

int main(int argc,char ** argv)
{ 
  
      //startup routine 
    Startup();
    //Create Gtk Application
    auto App=Gtk::Application::create(argc,argv,"Uruk.Store"); 
   
    //Create The Main Window 
    MainWindow MainWindowObject("Ui/Pages/MainWindow.glade","TopWindow"); 
    
    //load Css File
    MainWindowObject.LoadCssFile("Ui/Assets/Css/MainWindow.css");
    //Show The Main Window
    Glib::RefPtr<Gtk::Window> Window = MainWindowObject.GetWindow();
    //show the window     
    App->run(*Window.get());
    
}
