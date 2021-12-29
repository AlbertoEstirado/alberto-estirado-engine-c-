#include <SDL.h>
#include <ciso646>
#include <iostream>

#include "../headers/kernel.hpp"
#include "../headers/scene.hpp"

using namespace engine;

int main(int, char**)
{
    Scene* main_scene = new Scene("main_scene");

    Kernel::instance().initialization();
    do
    {
        Kernel::instance().execute();
    } while (not Kernel::instance().window->exit);

    Kernel::instance().end();
    
    return 0;
}