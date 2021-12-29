#include <SDL.h>
#include <ciso646>
#include <iostream>

#include "../headers/kernel.hpp"
#include "../headers/scene.hpp"
#include "../headers/render.hpp"
#include "../headers/read_input.hpp"
#include "../headers/update.hpp"

using namespace engine;

int main(int, char**)
{
    Scene* main_scene = new Scene("main_scene");

    Render* render = new Render(30);
    Read_input* read_input = new Read_input(10);
    Update* update = new Update(20);

    Kernel::instance().initialization();
    do
    {
        Kernel::instance().execute();
    } while (not Kernel::instance().window->exit);

    Kernel::instance().end();
    
    return 0;
}