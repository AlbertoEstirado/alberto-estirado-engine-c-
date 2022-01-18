#include <component.hpp>
#include <Camera.hpp>
#include <renderer_system.hpp>
#include <render_component.hpp>


namespace engine
{
	class Camera_Component : public Render_Component
	{

		~Camera_Component() = default;

	public:

		std::shared_ptr< glt::Camera > camera = nullptr;

		Camera_Component(Entity* e, Renderer_System&);

		glt::Node& get_node() override
		{
			return *camera;
		}
	};
}

