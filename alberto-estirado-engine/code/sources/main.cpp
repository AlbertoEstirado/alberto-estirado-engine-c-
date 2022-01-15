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


using namespace engine;
using namespace glt;

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

    //std::shared_ptr< Model > cube(new Model);
    //cube->add(std::shared_ptr< Drawable >(new Cube), Material::default_material());
    //std::shared_ptr< Light > light(new Light);
    //std::shared_ptr< Camera > camera(new Camera(20.f, 1.f, 50.f, 1.f));
    //std::shared_ptr< Model  > bunny(new Model_Obj("../../assets/stanford-bunny.obj"));

    //main_scene->renderer_system->render_node->add("camera", camera);
    //main_scene->renderer_system->render_node->add("light", light);
    //main_scene->renderer_system->render_node->add("cube", bunny);

    //main_scene->renderer_system->render_node->get("camera")->translate(Vector3(0.f, 0.f, 5.f));
    //main_scene->renderer_system->render_node->get("light")->translate(Vector3(10.f, 10.f, 10.f));

    Scene_manager::instance().run_scene(main_scene);

    do
    {
        Kernel::instance().execute();
    } while (not Kernel::instance().window->exit);

    Kernel::instance().end();
    
    return 0;
}