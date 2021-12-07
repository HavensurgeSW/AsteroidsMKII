#include "Manager/manager.h"
using namespace MK2;

int main()
{
    Manager* Asteroids = new Manager();
    Asteroids->loop();
    delete Asteroids;

}