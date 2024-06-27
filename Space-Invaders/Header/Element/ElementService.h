#pragma once

namespace Element
{
	class ElementService
	{
	private:
	public:
		ElementService();
		virtual ~ElementService();

		void initialize();
		void update();
		void render();

	};
}