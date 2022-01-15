#include <component.hpp>
#include <Camera.hpp>
#include <renderer_system.hpp>


namespace engine
{
	class Camera_Component : public Component
	{

		~Camera_Component() = default;

	public:

		std::shared_ptr< glt::Camera > camera = nullptr;

		Camera_Component(Entity* e, Renderer_System&);
	};
}

