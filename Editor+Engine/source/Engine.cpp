#include "../include/Engine.hpp"


sf::RenderWindow Engine::window (sf::VideoMode (500, 500), "Temp", sf::Style::Default); // global, for not being deleted after func finished


void Engine::initialize (int width, int height, const char* window_header)
{
	window.create (sf::VideoMode (width, height), window_header);

	return;
}

bool Engine::isWorking ()
{
	return window.isOpen ();
}

void Engine::exit ()
{
	window.close ();

	return;
}


void  Engine::do_nothing (Event &event, sf::Event &sf_event)
{}

void  Engine::Set_size (Event &event, sf::Event &sf_event)
{
	event.size.width = sf_event.size.width;
	event.size.height = sf_event.size.height;
}

void  Engine::Set_mouse_move (Event &event, sf::Event &sf_event)
{
	event.mouse_move.x = sf_event.mouseMove.x;
	event.mouse_move.y = sf_event.mouseMove.y;
}

void  Engine::Set_mouse_click (Event &event, sf::Event &sf_event)
{
	event.mouse_click.button = (Mouse::Button) sf_event.mouseButton.button;
	event.mouse_click.x = sf_event.mouseButton.x;
	event.mouse_click.y = sf_event.mouseButton.y;
}

void  Engine::Set_mouse_wheel (Event &event, sf::Event &sf_event)
{
	event.mouse_wheel.delta = sf_event.mouseWheel.delta;
	event.mouse_wheel.x = sf_event.mouseWheel.x;
	event.mouse_wheel.y = sf_event.mouseWheel.y;
}


bool  Engine::poll_event (Event &event)
{
	const static Set_of_events Event_Set[] = {
		{Event::Closed, do_nothing},
		{Event::Resized, Set_size},
		{Event::Unfocused, do_nothing},
		{Event::Focused, do_nothing},
		{Event::Text_entered, do_nothing},
		{Event::Key_pressed, do_nothing},
		{Event::Key_released, do_nothing},
		{Event::Mouse_wheel_moved, Set_mouse_wheel},
		{Event::Unused_event, do_nothing},
		{Event::Mouse_pressed, Set_mouse_click},
		{Event::Mouse_released, Set_mouse_click},
		{Event::Mouse_moved, Set_mouse_move},
		{Event::Mouse_went_in, do_nothing},
		{Event::Mouse_went_out, do_nothing},
		{Event::Unused_event, do_nothing}
	};

	sf::Event sf_event;
	if (window.pollEvent (sf_event))
	{
		event.type = Event_Set[sf_event.type].type;
		Event_Set[sf_event.type].Set (event, sf_event);
		return true;
	}

	return false;
}

void Engine::display ()
{
	window.display ();
}

void Engine::clear (const Color &col)
{
	window.clear (sf::Color (col.r, col.g, col.b, col.a));
}


Vector2s Engine::get_size ()
{
	sf::Vector2u size = window.getSize ();
	return Vector2s (size.x, size.y);
}


 Engine::Texture::Texture (const char* file_with_texture)
{
	texture.loadFromFile (file_with_texture);
}


void Engine::Texture::draw_sprite (const Vector2p pos)
{
	sf::Sprite temp_sprite (texture);
	temp_sprite.setPosition (pos.x, pos.y);
	window.draw (temp_sprite);
}


void Engine::Texture::draw_sprite (const Vector2p pos, const Vector2s size)
{
	sf::Sprite temp_sprite (texture);
	temp_sprite.setPosition (pos.x, pos.y);
	temp_sprite.setScale ((float) size.x / texture.getSize ().x, (float) size.y / texture.getSize ().y);
	window.draw (temp_sprite);
}


Vector2s Engine::Texture::get_size ()
{
	sf::Vector2u size = texture.getSize ();
	return Vector2s (size.x, size.y);
}


void Engine::draw_rectangle (const Vector2p pos, const Vector2s size, const Color &col)
{
	sf::RectangleShape rect (sf::Vector2f (size.x, size.y));
	rect.setPosition (pos.x, pos.y);
	rect.setFillColor (sf::Color (col.r, col.g, col.b, col.a));

	window.draw (rect);
}


void Engine::draw_image (const Pointmap& image, const Vector2p pos)
{
	sf::Texture texture;
	texture.create (image.get_size ().x, image.get_size ().y);
	texture.update (image.get_array ());
	sf::Sprite sprite (texture);
	sprite.setPosition (pos.x, pos.y);
	window.draw (sprite);
}