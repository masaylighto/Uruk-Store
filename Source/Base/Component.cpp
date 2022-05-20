#include"../../Headers/Base/Component.h"



void Component::LoadGladeFile(std::string PathToGladeFile){
   std::string GladeFileContent= ReadFileText(PathToGladeFile);
  _Builder = Gtk::Builder::create_from_string(GladeFileContent);
}
Component::Component(std::string PathToGladeFile)
{   
    //Load The Glade File
    LoadGladeFile(PathToGladeFile);
}
