
namespace engine
{
	class Component
	{
	protected:

		virtual ~Component() = default;

	public:

		virtual void update(float time) = 0;

	};


}