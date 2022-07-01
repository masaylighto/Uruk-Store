#include "../../Headers/Component/AppBox.h"

void PkgBox::ExtractNameLabel()
{
    _NameLabel = ExtractRefPtrWidget<Gtk::Label>("AppName");

}
void PkgBox::ExtractShowBtn()
{
  _ShowBtn = ExtractRefPtrWidget<Gtk::Button>("ShowBtn");

}
PkgBox::PkgBox():Component("Ui/Pages/AppBox.glade")
{
    ExtractNameLabel();
    ExtractShowBtn();
    ExtractDescriptionLabel();
    ExtractContainer();
}
void PkgBox::ExtractDescriptionLabel()
{
   _DescriptionLabel  =ExtractRefPtrWidget<Gtk::TextView>("Description");
}
void PkgBox::SetName(std::string Name)
{
    _NameLabel->set_text(Name);
}
void PkgBox::SetDescription(std::string Description)
{

   auto Buffer=  Gtk::TextBuffer::create();
   Buffer->set_text(Description);
    _DescriptionLabel->set_buffer(Buffer);
}
 void PkgBox::ExtractContainer(){

     _Container = ExtractRefPtrWidget<Gtk::Box>("AppBox");
 }
Glib::RefPtr<Gtk::Box> PkgBox::GetTopWidget()
{
    return _Container;
}
