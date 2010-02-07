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


#ifndef __POL_DISPLAY__
#define __POL_DISPLAY__


#include "../../poleaxe.h"


//Display Class
class display : public object
{
	protected:
        BYTE 									bpp;
        BYTE									number_of_surfaces;
        BYTE									refresh_rate;
        float									hsync, vsync;
        WORD									width, height;
        WORD									mode;				//fullscreen, windowded...  defaults to fullscreen
 		Surface 								_screen;
        Surface 								back;
        Surface                                 background_image;
        Caps                                   *devCaps;

	public:
 										       display();
 										       ~display();

        BOOL 									SetDisplayMode(WORD _width, WORD _height, BYTE _bpp);
        BOOL									SetDisplayMode(WORD _mode, WORD _width, WORD _height, BYTE _bpp);
        BOOL 									SetDisplayBpp(BYTE _bpp);
        WORD									DisplayMode();
        void									DisplayMode(WORD _mode);
        void									PageFlip();
        void									ClearBackBuffer(DWORD Color);
        void									ClearDisplayBuffer(DWORD Color);
        void									SetBackground(const std::string& File);
        void									SetBackground(Surface bmp);
        void									Blit(Surface Src, WORD Src_X, WORD Src_Y, WORD Dst_X, WORD Dst_Y, WORD Width, WORD Height);
        void									InvalidateRect(Rect *R);
        DWORD				 					FocusWindowHandle();
        Surface 								BackBuffer();
        Surface 								ScreenBuffer();
		//get capabilities for the display device.  similiar function in Direct X
		//the Caps structure has a name and a value variable to hold the various capabilities and
		//functions that are supported by the video card.
        Caps                                   *DeviceCaps();
        //does what they sound like they does.
        WORD									ScreenWidth();
        WORD									ScreenHeight();
        BYTE									ScreenBPP();
};


//initializes the main graphics system and returns a pointer to a class containing information about the main display
int 											SetDisplayMode(WORD Width, WORD Height, BYTE Bpp);
Surface 										DrawingSurface(HANDLE WinHandle);           //Gets proper surface based on the window.
int												ScreenWidth();
int												ScreenHeight();
int												ScreenBitsPerPixel();

#endif				//__POL_DISPLAY__
