#ifndef _POINTMAP_HPP_
#define _POINTMAP_HPP_

#include <vector>
#include "vector2.hpp"
#include "color.hpp"

class Pointmap
{
private:
	uint8_t* pixels;
	Vector2s size;

public:
	Pointmap (const Vector2s _size, const Color &color);
	Pointmap (const uint16_t width, const uint16_t height, const Color &color);
	~Pointmap ();

	void set_pixel (const Vector2s point, const Color &color);
	void set_pixel (const uint16_t x, const uint16_t y, const Color &color);

	const Color& get_pixel (const Vector2s point) const;
	const Color& get_pixel (const uint16_t x, const uint16_t y) const;

	const Vector2s get_size () const;

	const uint8_t* get_array () const;
};


#endif