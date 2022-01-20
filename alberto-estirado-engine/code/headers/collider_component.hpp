/**
*
* @author Alberto Estirado L�pez
*
* Distributed under the Boost Software License, version  1.0
* See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
*
* @date 26/01/2022
*
* estiradoalberto@gmail.com
*/

#pragma once

#include <component.hpp>


namespace engine
{
	class Collider_Component: public Component
	{
	public:
		enum Type
		{
			STATIC,
			DYNAMIC
		};

		Type type;


		//virtual void on_collider_enter(Collider_Component* other) = 0;
	};

}
