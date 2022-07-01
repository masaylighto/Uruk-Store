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
    _HomePage = std::shared_ptr<HomePage>(new HomePage());
    _PagesFrame.get()->add(*(*_HomePage));
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