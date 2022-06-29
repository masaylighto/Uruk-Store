#include"../../Headers/Pages/MainWindow.h"


MainWindow::MainWindow(std::string PathToGladeFile,std::string WindowName):Window(PathToGladeFile,WindowName)
{
    InitPagesFrame();
    LoadHomePage();
    InitHeaderBar();
    SetWindowSize(1000,600);
}
void MainWindow::LoadHomePage()
{
    //create instance from HomePage
    _HomePage = std::shared_ptr<HomePage>( new HomePage());
    //Get The TopWidget From HomePage And Insert It into _PagesFrame So It the Page Will Be Displayed
    auto Box= _HomePage.get()->GetTopWidget().get();
    _PagesFrame.get()->add(*Box);
}

void MainWindow::InitPagesFrame()
{
    _PagesFrame = ExtractRefPtrWidget<Gtk::Frame>("PagesFrame");
}

 void MainWindow::InitHeaderBar()
{
     Gtk::HeaderBar headerbar;
     headerbar.get_style_context()->add_class("bg-Trans");
     SetCustomTitleBar(headerbar);
}