#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_


class Abstract_window;
class Window;
class Rectangle_window;
class Texture_window;
class Canvas;


#include <vector>
#include "vector2.hpp"
#include "event.hpp"
#include "event_system.hpp"
#include "color.hpp"
#include "pointmap.hpp"


class Window : public Drawable
{
protected:
	Vector2p pos;

public:
	Window (Vector2p _pos);
	Window (int16_t x, int16_t y);

	const Vector2p &get_position () const;
	void set_position (const Vector2p _pos);
	void set_position (const int16_t x, const int16_t y);
};


class Rectangle_window : public Window
{
protected:
	Vector2s size;
	Color color;

public:
	Rectangle_window (const Vector2p _pos, const Vector2s _size, const Color &_color = Color::White);

	const Vector2s& get_size ();
	const Color& get_color ();
	void set_size (const Vector2s size);
	void set_color (const Color &color);
	bool contains (const Vector2p point);
	bool contains (int x, int y);

	virtual void redraw ();
};


class Texture_window : public Window
{
private:
	Engine::Texture texture;

public:
	Texture_window (const char* file_with_texture, const Vector2p _pos);

	virtual void redraw ();

	void draw ();

	const Vector2s get_size ();
};


class Canvas : public Rectangle_window
{
public:
	Pointmap image;

	Canvas (const Vector2p pos, const Vector2s size, const Color& color = Color::White);

	virtual void redraw ();

	friend class Editor;
};

#endif 