#include "../headers/transform.hpp"

#include <iostream>

namespace engine
{
	//Transform::Transform()
	//{
	//	position[0] = 0;
	//	position[1] = 0;
	//	position[2] = 0;
	//
	//	rotation[0] = 0;
	//	rotation[1] = 0;
	//	rotation[2] = 0;
	//
	//	scale[0] = 0;
	//	scale[1] = 0;
	//	scale[2] = 0;
	//}

	void Transform::awake()
	{
		std::cout << "Transform awake";
	}

	void Transform::start()
	{
		std::cout << "Transform start";
	}

	void Transform::update(float time)
	{
		std::cout << "Transform update";
	}


}