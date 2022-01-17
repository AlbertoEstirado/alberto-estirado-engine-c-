#include <SDL.h>
#include <ciso646>
#include <iostream>

#include <kernel.hpp>
#include <scene.hpp>
#include <render.hpp>
#include <read_input.hpp>
#include <update.hpp>
#include <transform.hpp>
#include <Light.hpp>
#include <Cube.hpp>
#include <keyboardcontrol_component.hpp>

using namespace engine;
using namespace glt;

int main(int, char**)
{
    Window * window = new Window("engine", 800, 600);
    window->enable_vsync();

    //*********** TASKS
    Render* render = new Render(30, window);
    Read_input* read_input = new Read_input(10, window);
    Update* update = new Update(20);
    //***********

    Kernel::instance().initialization();

    //Window * window = new Window("engine", 800, 600);
    //window->enable_vsync();

    Scene* main_scene = new Scene("main_scene", *window);

    Scene_manager::instance().run_scene(main_scene);

    do
    {
        Kernel::instance().execute();

    } while (Kernel::instance().running);

    Kernel::instance().end();
    
    return 0;
}