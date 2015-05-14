class Button
{
	static unsigned int defaultImage;
	int sprite;
	//0 = nothing; 1 = mouse_over; 2 = mouse_down; 3 = pressed
	int state = 0;
	bool mouseOver = false;
public:
	void setup();
	void update();
	bool IsPressed();
};