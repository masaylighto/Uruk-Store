
#include"../Headers/Pages/MainWindow.h"

int main(int argc,char ** argv){
   
   
    //Create Gtk Application
    auto App=Gtk::Application::create(argc,argv,"UrukStore");    
    //Create The Main Window Which
    MainWindow mainWindow("../Ui/Pages/MainWindow.glade","TopWindow"); 
    
    //Show The Main Window
    Glib::RefPtr<Gtk::Window> Window = mainWindow.GetWindow();
    App->run(*Window.get());
}
