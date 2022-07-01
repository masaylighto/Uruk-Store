#include"../../Headers/Pages/MainWindow.h"


MainWindow::MainWindow(std::string PathToGladeFile,std::string WindowName):Window(PathToGladeFile,WindowName)
{
    InitPagesFrame();
    LoadHomePage();
    CreateCustomHeaderBar();
    SetWindowSize(1000,600);
}
void MainWindow::LoadHomePage()
{
    //show the main page of the store
    _HomePage = std::shared_ptr<HomePage>(new HomePage());
    _PagesFrame.get()->add(*(*_HomePage));
}

void MainWindow::InitPagesFrame()
{
    //get the _frame from gtk Builder
    _PagesFrame = ExtractRefPtrWidget<Gtk::Frame>("PagesFrame");
}

 void MainWindow::CreateCustomHeaderBar()
{
     //add custom title bar and make it transparent
     Gtk::HeaderBar HeaderBar;
     HeaderBar.get_style_context()->add_class("bg-Trans");
     SetCustomTitleBar(HeaderBar);
}