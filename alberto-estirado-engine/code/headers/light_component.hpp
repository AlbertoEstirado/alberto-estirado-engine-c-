#include <component.hpp>
#include <Light.hpp>
#include <renderer_system.hpp>


namespace engine
{
	class Light_Component : public Component
	{

		~Light_Component() = default;

	public:

		std::shared_ptr< glt::Light > light = nullptr;

		Light_Component(Entity* e, Renderer_System&);
	};
}

