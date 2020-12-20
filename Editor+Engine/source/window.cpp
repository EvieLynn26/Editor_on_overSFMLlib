#include "../include/window.hpp"


Window::Window (Vector2p _pos) :
	pos (_pos)
{}

Window::Window (int16_t x, int16_t y) :
	pos (x, y)
{}

const Vector2p &Window::get_position () const
{
	return pos;
}

void Window::set_position (const Vector2p _pos)
{
	pos = _pos;
}

void Window::set_position (const int16_t x, const int16_t y)
{
	pos = {x, y};
}

Rectangle_window::Rectangle_window (const Vector2p _pos, const Vector2s _size, const Color &_color) :
		Window (_pos),
		size (_size),
		color (_color)
{}

void Rectangle_window::redraw ()
{
	Engine::draw_rectangle (pos, size, color);
}

const Vector2s &Rectangle_window::get_size ()
{
	return size;
}


const Color &Rectangle_window::get_color ()
{
	return color;
}

void Rectangle_window::set_size (const Vector2s s)
{
	size = s;
}

void Rectangle_window::set_color (const Color& c)
{
	color = c;
}

bool Rectangle_window::contains (const Vector2p point)
{
	return (pos.x < point.x && point.x < (pos.x + size.x) && pos.y < point.y && point.y < (pos.y + size.y));
}

bool Rectangle_window::contains (int x, int y)
{
	return (pos.x < x && x < (pos.x + size.x) && pos.y < y && y < (pos.y + size.y));
}

Texture_window::Texture_window (const char* file_with_texture, const Vector2p _pos) :
	Window (_pos),
	texture (file_with_texture)
{}

void Texture_window::redraw ()
{
	texture.draw_sprite (pos);
}

void Texture_window::draw ()
{
	texture.draw_sprite (get_position ());
}

const Vector2s Texture_window::get_size ()
{
	return texture.get_size ();
}

Canvas::Canvas (const Vector2p pos, const Vector2s size, const Color &color) :
	Rectangle_window (pos, size, color),
	image (size, color)
{}

void Canvas::redraw ()
{
	Engine::draw_image (image, pos);
}
