#ifndef _EVENT_SYSTEM_HPP_
#define _EVENT_SYSTEM_HPP_

class Event_system;
class Drawable;
class Clickable;

#include <vector>
#include "Engine.hpp"


class Event_system
{
public:
	static std::vector<Drawable*>  window_ptrs_for_drawing;
	static std::vector<Clickable*> mouse_press_queue;
	static std::vector<Clickable*> mouse_release_queue;
	static std::vector<Clickable*> mouse_move_queue;

	static void draw_frame ();
};


class Drawable
{
public:
	Drawable ();

	virtual void redraw () = 0;
};


class Clickable
{
public:
	Clickable ();

	virtual bool process_mouse_press   (const Event::Mouse_click &click) = 0;
	virtual bool process_mouse_move    (const Event::Mouse_move &move) = 0;
	virtual bool process_mouse_release (const Event::Mouse_click &click) = 0;
};

#endif 