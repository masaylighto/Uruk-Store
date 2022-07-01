#include "../../Headers/Component/AppBox.h"

void PackageCard::ExtractNameLabel()
{
    _NameLabel = ExtractRefPtrWidget<Gtk::Label>("AppName");

}
void PackageCard::ExtractShowBtn()
{
  _ShowBtn = ExtractRefPtrWidget<Gtk::Button>("ShowBtn");

}
PackageCard::PackageCard():Component("Ui/Pages/AppBox.glade")
{
    ExtractNameLabel();
    ExtractShowBtn();
    ExtractDescriptionLabel();
    ExtractContainer();
}
 PackageCard::~PackageCard()
 {
    
    _NameLabel.release();
    _ShowBtn.release();
    _DescriptionLabel.release();
    _Container.release();
 
 }
void PackageCard::ExtractDescriptionLabel()
{
   _DescriptionLabel  =ExtractRefPtrWidget<Gtk::TextView>("Description");
}
void PackageCard::SetName(std::string Name)
{
    _NameLabel->set_text(Name);
}
void PackageCard::SetDescription(std::string Description)
{

   auto Buffer=  Gtk::TextBuffer::create();
   Buffer->set_text(Description);
    _DescriptionLabel->set_buffer(Buffer);
}
 void PackageCard::ExtractContainer(){

     _Container = ExtractRefPtrWidget<Gtk::Box>("AppBox");
 }
Glib::RefPtr<Gtk::Box> PackageCard::GetTopWidget()
{
    return _Container;
}
