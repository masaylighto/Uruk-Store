#include "Startup.h"

Startup::Startup()
{
    EnsureSuperUserMode();

}
//to be used in pthread
//the purpose of this function is to call use function from AptContext
//which cause the class to read and parse
//the information of apt package and we do it in threads to less the application starting app time
void *UseApt(void *)
{
    AptContext::Use();
    return 0;
}
void Startup::InitApt()
{
    pthread_t apt_thread;
    pthread_create(&apt_thread,nullptr,UseApt,0);
}

void Startup::EnsureSuperUserMode()
{
//Todo;
}