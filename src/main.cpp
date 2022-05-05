#include <Interface.h>

int main()
{
start:
    int cyb = interface_welcome();
    if (cyb == Record)
    {
        if (inetrface_record() == Goback)
            goto start;
    }
    else if (cyb == Search)
    {
        if (interface_search() == Goback)
            goto start;
    }
    else if (cyb == Delete)
    {
        if (interface_delete())
            goto start;
    }
    else if (cyb = Exit)
    {
        exitSystem();
    }
    return 0;
}
