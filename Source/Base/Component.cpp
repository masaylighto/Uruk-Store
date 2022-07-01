#include"../../Headers/Base/Component.h"



void Component::LoadGladeFile(std::string PathToGladeFile)
{
    if(IsFileExist(PathToGladeFile))
    {
        throw std::ifstream::failure("Failed to load "+PathToGladeFile); 
    }
  _Builder = Gtk::Builder::create_from_file(PathToGladeFile);
}
Component::Component(std::string PathToGladeFile)
{   
    //Load The Glade File
    LoadGladeFile(PathToGladeFile);
}
Component::~Component(){

    _Builder.release();
}