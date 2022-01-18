#include <component.hpp>
#include <Light.hpp>
#include <renderer_system.hpp>
#include <render_component.hpp>


namespace engine
{

	class Light_Component : public Render_Component
	{

		~Light_Component() = default;

	public:

		std::shared_ptr< glt::Light > light = nullptr;

		Light_Component(Entity* e, Renderer_System&);

		glt::Node& get_node() override
		{
			return *light;
		}
	};
}

