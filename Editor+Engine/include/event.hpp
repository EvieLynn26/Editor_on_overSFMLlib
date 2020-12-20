#ifndef _EVENT_HPP_
#define _EVENT_HPP_


struct Mouse
{
	enum Button
	{
		Left,
		Right,
	};
};


struct Keyboard
{
	enum Key
	{
		Left,
		Right,
		Up,
		Down
	};
};


struct Event
{
	enum Event_type
	{
		Closed,
		Resized,
		Unfocused,
		Focused,
		Text_entered,
		Key_pressed,
		Key_released,
		Mouse_wheel_moved,
		Mouse_pressed,
		Mouse_released,
		Mouse_moved,
		Mouse_went_in,
		Mouse_went_out,
		Unused_event
	};

	Event_type type;


	struct Size
	{
		unsigned int width;  
		unsigned int height; 
	};

	struct Key
	{
		Keyboard::Key code;    
		bool alt;     
		bool control; 
		bool shift;   
		bool system;  
	};

	struct Text
	{
		uint32_t unicode; 
	};

	struct Mouse_move
	{
		int x; // [X position of the mouse pointer, relative to the left of the owner window]

		int y; 
	};

	struct Mouse_click
	{
		Mouse::Button button;
		int           x;      
		int           y;      
	};

	struct Mouse_wheel
	{
		int delta; 
		int x;     
		int y;     
	};


	union
	{
		Size             size;              
		Key              key;               
		Text             text;              
		Mouse_move       mouse_move;         
		Mouse_click      mouse_click;       
		Mouse_wheel      mouse_wheel;        
	};
};


#endif