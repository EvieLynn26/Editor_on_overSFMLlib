#ifndef _EDITOR_HPP_
#define _EDITOR_HPP_

#include <vector>
#include "window.hpp"
#include "pointmap.hpp"
#include "event_system.hpp"


class Abstract_tool
{
public:
	virtual void apply (Pointmap& place_for_drawing, Vector2p pos_0, Vector2p pos_1) = 0;
};


class Brush : public Abstract_tool
{
public:
	void apply (Pointmap& place_for_drawing, Vector2p pos_0, Vector2p pos_1);
};



class Editor : public Rectangle_window, public Clickable
{
protected:
	enum {
		BRUSH,
		ERASER,
		TOOLS_NUM
	};

	Vector2p prev_pos;
	int curr_tool;
	std::vector<std::unique_ptr<Abstract_tool>> tools;
	Canvas canvas;
	bool applying;

public:
	Editor ();

	bool process_mouse_press   (const Event::Mouse_click& click);
	bool process_mouse_release (const Event::Mouse_click& click);
	bool process_mouse_move    (const Event::Mouse_move& move);
};


#endif 