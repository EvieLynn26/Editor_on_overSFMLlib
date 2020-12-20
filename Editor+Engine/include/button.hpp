#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_


#include "window.hpp"
#include "event_system.hpp"


class Abstract_button : public Window, public Clickable
{
public:
	Abstract_button (const Vector2p pos);
};


class Rectangle_button : public Abstract_button
{
private:
	Vector2s size;
	Color *curr_color;
	Color color;

public:
	Rectangle_button (const Color &c, const Vector2p pos, const Vector2s sz);

	virtual void redraw ();
	virtual bool process_mouse_press   (const Event::Mouse_click &click);
	virtual bool process_mouse_release (const Event::Mouse_click &click);

	bool contains (int x, int y);

	bool pressed ();

	void set_size (const Vector2s sz);
	const Vector2s get_size ();
};


class Texture_button : public Abstract_button
{
private:
	Vector2s size;
	Engine::Texture *curr_texture;
	Engine::Texture texture;

public:
	Texture_button (const Engine::Texture &_texture, const Vector2p pos = Vector2p ());

	virtual void redraw ();
	virtual bool process_mouse_press   (const Event::Mouse_click &click);
	virtual bool process_mouse_release (const Event::Mouse_click &click);

	bool contains (int x, int y);

	bool pressed ();

	void set_size (const Vector2s sz);
	const Vector2s get_size ();
};

#endif