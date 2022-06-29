#include "../../Headers/Component/AppBox.h"

void AppBox::ExtractNameLabel()
{
    _NameLabel = ExtractRefPtrWidget<Gtk::Label>("AppName");

}
void AppBox::ExtractShowBtn()
{
  _ShowBtn = ExtractRefPtrWidget<Gtk::Button>("ShowBtn");

}
AppBox::AppBox():Component("Ui/Pages/AppBox.glade")
{
    ExtractNameLabel();
    ExtractShowBtn();
    ExtractDescriptionLabel();
    ExtractContainer();
}
void AppBox::ExtractDescriptionLabel()
{
   _DescriptionLabel  =ExtractRefPtrWidget<Gtk::TextView>("Description");
}
void AppBox::SetName(std::string Name)
{
    _NameLabel->set_text(Name);
}
void AppBox::SetDescription(std::string Description)
{

   auto Buffer=  Gtk::TextBuffer::create();
   Buffer->set_text(Description);
    _DescriptionLabel->set_buffer(Buffer);
}
 void AppBox::ExtractContainer(){

     _Container = ExtractRefPtrWidget<Gtk::Box>("AppBox");
 }
Glib::RefPtr<Gtk::Box> AppBox::GetTopWidget()
{
    return _Container;
}