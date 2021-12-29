#include <vector>

#include "component.hpp"

namespace engine
{
	class Entity
	{
	public:

		std::vector<Component> componets;

		void update(float time);

	};
}