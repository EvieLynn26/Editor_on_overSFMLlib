#include "Editor+Engine/include/button.hpp"
#include "Editor+Engine/include/color.hpp"
#include "Editor+Engine/include/editor.hpp"
#include "Editor+Engine/include/event.hpp"
#include "Editor+Engine/include/event_system.hpp"
#include "Editor+Engine/include/pointmap.hpp"
#include "Editor+Engine/include/vector2.hpp"
#include "Editor+Engine/include/window.hpp"


int main ()
{
	Engine::initialize(1280, 720, "Paint, pls");
	Editor my_paint = {};

	Engine::Texture test_texture("test_texture");

	//Texture_button Brush ({{"Editor+Engine/brush.png"},{"graphics/brush.png"},{"graphics/brush.png"}}, {0, 0});
	
	while (Engine::isWorking ())
	{
		Event event;
		bool window_closed = 0;
		while (Engine::poll_event (event))
		{
			switch (event.type)
			{
				case Event::Closed:
					Engine::exit ();
					window_closed = 1;
					break;

				case Event::Mouse_pressed:
					for (int i = 0; i < Event_system::mouse_press_queue.size(); ++i)
						Event_system::mouse_press_queue[i]->process_mouse_press (event.mouse_click);
						
					break;

				case Event::Mouse_moved:
					for (int i = 0; i < Event_system::mouse_move_queue.size(); ++i)
						Event_system::mouse_move_queue[i]->process_mouse_move (event.mouse_move);
					
					break;

				case Event::Mouse_released:
					for (int i = 0; i < Event_system::mouse_release_queue.size(); ++i)
						Event_system::mouse_release_queue[i]->process_mouse_release (event.mouse_click);
				
					break;
			}
		}
		
		if (!window_closed) 
		{
			Engine::clear (Color::White);

			Event_system::draw_frame ();

			Engine::display ();
		}
	}

	return 0;
}
