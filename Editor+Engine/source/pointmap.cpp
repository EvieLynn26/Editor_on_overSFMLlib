#include "../include/pointmap.hpp"


Pointmap::Pointmap (const Vector2s _size, const Color& color) :
	pixels (new uint8_t[_size.x * _size.y * sizeof (Color)]),
	size (_size)
{
	Color *curr_pixel = reinterpret_cast<Color* > (pixels);
	for (int i = 0; i < size.x * size.y; ++i)
		curr_pixel[i] = color;

}

Pointmap::Pointmap (const uint16_t width, const uint16_t height, const Color& color) :
	pixels (new uint8_t[width * height * sizeof (Color)]),
	size (width, height)
{
	Color *curr_pixel = reinterpret_cast<Color* > (pixels);
	for (int i = 0; i < width * height; ++i)
		curr_pixel[i] = color;
}

Pointmap::~Pointmap ()
{
	delete[] pixels;
}

void Pointmap::set_pixel (const Vector2s point, const Color &color)
{
	*(reinterpret_cast<Color*> (pixels + (point.y * size.x + point.x) * sizeof (Color))) = color;
}

void Pointmap::set_pixel (const uint16_t x, const uint16_t y, const Color &color)
{
	*(reinterpret_cast<Color*> (pixels + (y * size.x + x) * sizeof (Color))) = color;
}

const Color &Pointmap::get_pixel (const Vector2s point) const
{
	return *(reinterpret_cast<Color*> (pixels + (point.y * size.x + point.x) * sizeof (Color)));
}

const Color &Pointmap::get_pixel (const uint16_t x, const uint16_t y) const
{
	return *(reinterpret_cast<Color*> (pixels + (y * size.x + x) * sizeof (Color)));
}

const Vector2s Pointmap::get_size () const
{
	return size;
}

const uint8_t* Pointmap::get_array () const
{
	return pixels;
}