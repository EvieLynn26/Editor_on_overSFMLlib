#include "../include/button.hpp"

Abstract_button::Abstract_button (const Vector2p pos) :
	Window (pos)
{}

Rectangle_button::Rectangle_button (const Color &c, const Vector2p pos, const Vector2s sz) :
	Abstract_button (pos),
	size (sz),
	color (c)
{
	curr_color = &color;
}

void Rectangle_button::redraw ()
{
	Engine::draw_rectangle (pos, size, *curr_color);
}

bool Rectangle_button::process_mouse_press (const Event::Mouse_click &click)
{
	if (contains (click.x, click.y))
	{
		curr_color = &color;
		return true;
	}

	return false;
}

bool Rectangle_button::process_mouse_release (const Event::Mouse_click &click)
{
	if (pressed ())
	{
		if (contains (click.x, click.y))
			curr_color = &color;
		return true;
	}

	return false;
}

bool Rectangle_button::contains (int x, int y)
{
	return (pos.x < x && x < (pos.x + size.x) && pos.y < y && y < (pos.y + size.y));
}

bool Rectangle_button::pressed ()
{
	return curr_color == &color;
}


void Rectangle_button::set_size (const Vector2s sz)
{
	size = sz;
}

const Vector2s Rectangle_button::get_size ()
{
	return size;
}


Texture_button::Texture_button (const Engine::Texture &_texture, const Vector2p pos) :
	Abstract_button (pos),
	texture (_texture)
{
	curr_texture = &texture;
	size = curr_texture->get_size ();
}

void Texture_button::redraw ()
{
	curr_texture->draw_sprite (pos, size);
}

bool Texture_button::process_mouse_press (const Event::Mouse_click &click)
{
	if (contains (click.x, click.y))
	{
		curr_texture = &texture;
		return true;
	}

	return false;
}

bool Texture_button::process_mouse_release (const Event::Mouse_click &click)
{
	if (pressed ())
	{
		if (contains (click.x, click.y))
			curr_texture = &texture;
		
		return true;
	}

	return false;
}

bool Texture_button::contains (int x, int y)
{
	return (pos.x < x && x < (pos.x + size.x) && pos.y < y && y < (pos.y + size.y));
}

bool Texture_button::pressed ()
{
	return curr_texture == &texture;
}


void Texture_button::set_size (const Vector2s sz)
{
	size = sz;
}

const Vector2s Texture_button::get_size ()
{
	return size;
}
