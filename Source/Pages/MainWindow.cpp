#include"../../Headers/Pages/MainWindow.h"


MainWindow::MainWindow(std::string PathToGladeFile,std::string WindowName):Window(PathToGladeFile,WindowName)
{
    InitPagesFrame();
    LoadHomePage();
    InitCatagoriesGrid();
    InitHeaderBar();
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
void MainWindow::InitCatagoriesGrid()
{
    _CatagoriesGrid = ExtractRefPtrWidget<Gtk::Grid>("CatagoriesGrid");
    const std::vector<std::string> Catagories = AptContext::Create()->GetCatagories(); 

    for(int Index=0; Index < Catagories.size();Index++)
    {   
        _CatagoriesGrid->insert_row(Index);
        _CatagoriesGrid->attach(*CreateCategoryLabel(Catagories[Index]),0,Index);

    }
    _CatagoriesGrid->show_all_children();
}

Gtk::Button* MainWindow::CreateCategoryLabel(std::string text) 
{

        Gtk::Button * Btn =new Gtk::Button();     
        Btn->set_label(text);
        Btn->set_hexpand(false);
        Btn->set_vexpand(true);
 
        Btn->set_size_request(100,40);
        Btn->set_margin_top(10);
        Btn->set_margin_bottom(10);
        Btn->set_alignment(Gtk::Align::ALIGN_CENTER,Gtk::Align::ALIGN_CENTER);
        auto Context= Btn->get_style_context();
        Context->add_class("Bg-White");
        Context->add_class("Rounded");
        Context->add_class("Border-none");
        Context->add_class("OnClick");
        Context->add_class("Noshadow");
        return Btn;
}
 void MainWindow::InitHeaderBar()
{
     Gtk::HeaderBar headerbar;
     headerbar.get_style_context()->add_class("bg-Trans");
     SetCustomTitleBar(headerbar);
}