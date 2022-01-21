/**
*
* @author Alberto Estirado López
*
* Distributed under the Boost Software License, version  1.0
* See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
*
* @date 26/01/2022
*
* estiradoalberto@gmail.com
*/


namespace engine
{
	class Box_Collider_Component;

	struct Collision_Handler
	{
		virtual void on_colision(Box_Collider_Component& a, Box_Collider_Component& b) = 0;
	};
}