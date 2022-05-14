#include"../../Headers/Base/Window.h"
Window::Window(std::string PathToGladeFile)
{
_Builder = Gtk::Builder::create_from_file(PathToGladeFile);

}