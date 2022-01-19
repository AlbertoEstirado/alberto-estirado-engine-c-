#include <collider_component.hpp>


namespace engine
{
	class Box_Collider_Component : public Collider_Component
	{
	public:
	
		float x, y, with, height;

		Box_Collider_Component(Entity* e ,float, float, Type t);

		//void im_colliding_with(Collider_Component*) override;
	};

}