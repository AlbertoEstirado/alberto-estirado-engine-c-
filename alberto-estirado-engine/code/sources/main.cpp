#include <SDL.h>
#include <ciso646>
#include <iostream>

#include <kernel.hpp>
#include <scene.hpp>
#include <render.hpp>
#include <read_input.hpp>
#include <update.hpp>
#include <transform.hpp>


using namespace engine;

int main(int, char**)
{
    //*********** TASKS
    Render* render = new Render(30);
    Read_input* read_input = new Read_input(10);
    Update* update = new Update(20);
    //***********

    Kernel::instance().initialization();


    Scene* main_scene = new Scene("main_scene", *Kernel::instance().window);
    //Transform* player_transform = new Transform();
    //Entity* player = new Entity("player", player_transform);
    //Renderer * player_renderer = new Renderer("../../assets/sphere.obj")
    //player->add_component(player_renderer);

    //main_scene->add_entity(player);


    Scene_manager::instance().run_scene(main_scene);

    do
    {
        Kernel::instance().execute();
    } while (not Kernel::instance().window->exit);

    Kernel::instance().end();
    
    return 0;
}