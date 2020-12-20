#ifndef _SFML_ENGINE_HPP_
#define _SFML_ENGINE_HPP_

#include <SFML/Graphics.hpp>
#include "event.hpp"
#include "vector2.hpp"
#include "color.hpp"
#include "pointmap.hpp"


class Engine
{
public:
	static sf::RenderWindow window;

	static void initialize (int width, int height, const char* window_header);
	static bool isWorking ();
	static void exit ();

	struct Set_of_events
	{
		Event::Event_type type;
		void(*Set) (Event &, sf::Event &);
	};

	static void do_nothing (Event &event, sf::Event &sf_event);
	static void Set_size (Event &event, sf::Event &sf_event);
	static void Set_mouse_move (Event &event, sf::Event &sf_event);
	static void Set_mouse_click (Event &event, sf::Event &sf_event);
	static void Set_mouse_wheel (Event &event, sf::Event &sf_event);

	static bool poll_event (Event &event);

	static void clear (const Color &col);
	static void display ();

	static Vector2s get_size ();

	class Texture
	{
	private:
		sf::Texture texture;
		
	public:
		Texture (const char* file_with_texture);

		void draw_sprite (const Vector2p pos);
		void draw_sprite (const Vector2p pos, const Vector2s size);
		Vector2s get_size ();
	};

	static void draw_rectangle (const Vector2p pos, const Vector2s size, const Color &col);
	static void draw_image (const Pointmap &image, const Vector2p pos);
};


#endif