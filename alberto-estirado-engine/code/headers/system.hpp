#include <task.hpp>
#include <vector>
#include <component.hpp>
#include <scene_manager.hpp>

namespace engine 
{
	class System : public Task
	{
	public:

		Scene* scene;

		std::vector<Component*> components;

		System() = default;

		void initialize(){}
		void run(float time);
		void end(){}

		//virtual ~System() = 0;

		void add_component(Component*);
	};
}