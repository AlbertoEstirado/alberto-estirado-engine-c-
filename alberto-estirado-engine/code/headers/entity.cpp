#include "../headers/entity.hpp"

namespace engine
{
	void Entity::update(float time)
	{
		for (size_t i = 0; i < componets.size(); i++)
		{
			componets[i].update(time);
		}
	}
}