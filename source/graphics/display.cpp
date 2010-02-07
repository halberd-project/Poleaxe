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


#include "../../poleaxe.h"


display::display()
{
	this->mode = GFX_AUTODETECT_WINDOWED;
	this->width = 800;
	this->height = 600;
	this->bpp = 32;
	this->number_of_surfaces = 0;
	this->hsync = 0;
	this->vsync = 0;
	this->_screen = Surface(new surface());
	this->back = Surface(new surface());
	this->background_image = Surface(new surface());
	this->devCaps = null;
    LogMessage("Display initialized.");
}


display::~display()
{
    LogMessage("Display uninitialized.");
}


BOOL display::SetDisplayMode(WORD _width, WORD _height, BYTE _bpp)
{
    int error = 0;

    set_color_depth(_bpp);
    error = set_gfx_mode(this->mode, _width, _height, 0, 0);

    if(error != 0)
    {
        LogError("Error setting graphics resolution.");
        LogError("Allegro returned this error message: %s", allegro_error);
        return false;
    }

    this->back = Surface(new surface(_width, _height, _bpp));
    this->_screen = Surface(new surface(::screen));
    this->_screen->Acquire();
    this->_screen->ShowMouse();
    this->_screen->Release();

    this->width = _width;
    this->height = _height;
    this->bpp = _bpp;
    /*LogMessage("Screen resolution succesfully changed.");
    LogMessage("Display Width: %d", this->width);
    LogMessage("Display Height: %d", this->height);
    LogMessage("Display bits per pixel: %d", this->bpp);
    LogMessage("Display mode: %d",  this->mode);*/
    //queue a message stating that the gfx has been changed.
    QueueMessage(Message(new message(0, MSG_GFX_SCREEN_RES_CHANGED, MAKEDWORD(_width, _height), MAKEDWORD((WORD)_bpp, (WORD)this->mode), NULL)));

    return true;
}


BOOL display::SetDisplayMode(WORD _mode, WORD _width, WORD _height, BYTE _bpp)
{
    int error = 0;

    set_color_depth(_bpp);
    if((error = set_gfx_mode(_mode, _width, _height, 0, 0)) != 0)
    {
        LogError("Error setting graphics resolution.");
        LogError("Allegro returned this error message: %s", allegro_error);
        return false;
    }

    this->back = Surface(new surface(_width, _height, _bpp));
    this->_screen = Surface(new surface(::screen));
    acquire_screen();
    show_mouse(::screen);
    acquire_screen();
    this->mode = _mode;
    this->width = _width;
    this->height = _height;
    this->bpp = _bpp;
    LogMessage("Screen resolution succesfully changed.");

    return true;
}


void display::DisplayMode(WORD _mode)
{
	LogMessage("Display mode has been altered.");
	this->mode = _mode;
}


WORD display::DisplayMode()
{
	return this->mode;
}


WORD display::ScreenWidth()
{
	return this->width;
}


WORD display::ScreenHeight()
{
	return this->height;
}


BYTE display::ScreenBPP()
{
	return this->bpp;
}


void display::PageFlip()
{
    this->_screen->Blit(this->back, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
}


void display::ClearBackBuffer(DWORD _color)
{
    this->back->Clear(_color);
}


//Clears the screen to the specified color.
void display::ClearDisplayBuffer(DWORD _color)
{
    this->_screen->Clear(_color);
}


void display::Blit(Surface source, WORD sourcex, WORD sourcey, WORD destx, WORD desty, WORD _width, WORD _height)
{
    scare_mouse();
    this->_screen->Blit(source, sourcex, sourcey, destx, desty, _width, _height);
    unscare_mouse();
}


//Sets the background of the screen to the specified image
void display::SetBackground(const std::string& File)
{
    //char *file_name = File.c_str();
    LogMessage("Attempting to change the background.");
    this->background_image = Surface(new surface(File));
    if(this->background_image->Size() != 0)
        this->_screen->Blit(this->background_image, 0, 0, 0, 0, this->background_image->Width(), this->background_image->Height());
    else
        return;
}


//This function gets and returns an array of strings that contain all of the device's capabilities.
//Similiar in idea to the equivilent DirectX function.
Caps* display::DeviceCaps()
{
	return devCaps;
}
