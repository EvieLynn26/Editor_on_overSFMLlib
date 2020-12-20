#include "../include/event_system.hpp"


std::vector<Drawable* > Event_system::window_ptrs_for_drawing;
std::vector<Clickable* > Event_system::mouse_press_queue;
std::vector<Clickable* > Event_system::mouse_release_queue;
std::vector<Clickable* > Event_system::mouse_move_queue;


Clickable::Clickable ()
{
	Event_system::mouse_press_queue.push_back (this);
	Event_system::mouse_move_queue.push_back (this);
	Event_system::mouse_release_queue.push_back (this);
}


Drawable::Drawable ()
{
	Event_system::window_ptrs_for_drawing.push_back (this);
}


void Event_system::draw_frame ()
{
	for (int i = 0; i < window_ptrs_for_drawing.size(); ++i)
		window_ptrs_for_drawing[i]->redraw ();
}

