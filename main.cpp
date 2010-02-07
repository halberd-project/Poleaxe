/*
 *
 *		The Poleaxe Graphics and Windowing system.
 *
 * Jeff Shoulders and Robert Butler
 * hx86 working group
 * loliniel@gmail.com
 * lighth7015@gmail.com
 *
 *	(c) 2010
 *
 */


#include "poleaxe.h"


int main(int argc, char **argv)
{
    PoleaxeManager = Manager(new manager());
    Alleg::Init();
    Mouse m = Mouse(new mouse());
    Keyboard k = Keyboard(new keyboard());
	Display disp = Display(new display());
	Timer t = Timer(new timer());
	disp->SetDisplayMode(840, 525, 32);
	Window w = Window(new window("test window", 10, 10, 300, 200, 0));
	PoleaxeManager->AddWindow(w);
	disp->SetBackground("background.bmp");
	w->Draw();
	PoleaxeManager->MessageLoop();
	return 0;
}
END_OF_MAIN()
