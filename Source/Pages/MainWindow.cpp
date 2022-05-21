#include"../../Headers/Pages/MainWindow.h"


MainWindow::MainWindow(std::string PathToGladeFile,std::string WindowName):Window(PathToGladeFile,WindowName)
{
    InitPagesFrame();
    LoadHomePage();
    ExtractAppGrid();   
    FillAppGrid(GetAptPackages(-1));
};
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
void MainWindow::ExtractAppGrid()
{
    _AppGrid = ExtractRefPtrWidget<Gtk::Grid>("AppGrid");
}
void MainWindow::FillAppGrid(std::vector<std::string> Apps)
{ 
      //to Specify Which Row, we gonna insert or card into ,we define the variable here 
    // so every 3 loop it gonna increase by 1 , cause we want only three column
    int Row=0;
    int Cols=0;
    for(int Index=0; Index<6 && Index < Apps.size();Index++)
    {   
        //here we try to maintain only the col in the grid
        if (Index%3==0)
        {   //if we fill the three cols then go to the next row
            Row++;            
            //reset the col of index%3 so only 3 col will be in any Row
            Cols=0;
        } 
        //Class That Represent the Cards
        AppBox* Box = new AppBox();     
        //We Save it Into A global Variable (it will be usefully in many case like de allocating the object)       
        CardList.push_back(Box);
        //set the Name of The Box
        Box->SetName(Apps[Index]);
        //the class AppBox is a holder class that hold the widgets,
        //and here we get to top widget that contain the rest of the widget in the glade file
        auto BoxWidget=Box->GetTopWidget().get();
        //we insert the top widget into the Grid
       _AppGrid->attach(*(BoxWidget),Cols,Row);
        //increase the cols so the next object will be in the next col
        Cols++;
     }
}