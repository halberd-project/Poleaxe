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

//Used for making a new blank surface object
surface::surface()
{
    bitmapsize = 0;
    Bmp = NULL;
    width = 0;
    height = 0;
    Bpp = 0;
}


//Used for making a new blank surface object with the specified bits per pixel
surface::surface(WORD Width, WORD Height, WORD Color)
{
    Bmp    = create_bitmap(Width, Height);
    Bpp    = Color;
    width  = Width;
    height = Height;
    bitmapsize = 1;
}


//Used for making a new blank surface object using the default bits per pixel
surface::surface(WORD Width, WORD Height)
{
    bitmapsize = 0;
    Bmp    = create_bitmap(Width, Height);
    Bpp    = 24;                           //TODO: get bpp from sreen resolution
    width  = Width;
    height = Height;
    bitmapsize = 1;
}


//Used for making a new surface object based upon the given Allegro surface structure
surface::surface(BITMAP *ArgBmp)
{
    if(is_screen_bitmap(ArgBmp))
    {
        this->Bmp = ArgBmp;
        this->width = SCREEN_W;
        this->height = SCREEN_H;
        this->Bpp = bitmap_color_depth(ArgBmp);
        LogMessage("Creating a new surface based on the screen.");
        return;
    }

    this->Bmp = create_bitmap(ArgBmp->w, ArgBmp->h);
    if(!this->Bmp)
    {
        LogError("Error creating surface.");
        return;
    }

    ::blit(ArgBmp, this->Bmp, 0, 0, 0, 0, ArgBmp->w, ArgBmp->h);

    this->width  = ArgBmp->w;
    this->height = ArgBmp->h;
    this->Bpp = bitmap_color_depth(ArgBmp);
}


//Used for creating a new surface object and loading the existing image file into the surface.
surface::surface(const std::string& File)
{
    bool value;
    bitmapsize = 0;

    value = LoadFromFile(File);
    if(value == false)
    {
        LogError("There was an error while tying to load %s.", File.c_str());
        return;
    }
}


//This constructor is used for creating a new surface object as a subbitmap of an already existing  Bitmap
surface::surface(Surface parent, WORD X, WORD Y, WORD Width, WORD Height)
{
    this->Bmp = (parent->CreateSubSurface(X, Y, Width, Height))->Bmp;
    width = Width;
    height = Height;
    Bpp = 24;
}


//surface Deconstructor
surface::~surface()
{
    SubContext.clear();
}


void surface::Destroy()
{
    if(this->Bmp)
        destroy_bitmap(this->Bmp);
}


//Loads an image from a file
bool surface::LoadFromFile(const std::string& File)
{
    if(this->Bmp)
    {
        LogMessage("Surface already exists, destroying to load a new image.");
        destroy_bitmap(this->Bmp);
    }

    this->Bmp = load_bitmap(File.c_str(), NULL);

    if(!this->Bmp)                  //If loading an image from the file had failed...
    {
        LogError("Error loading the file and creating the surface.");
        return FALSE;
    }

    LogMessage("Loaded surface from file succesfully.");
    this->width = Bmp->w;
    this->height = Bmp->h;
    this->Bpp = bitmap_color_depth(Bmp);
    this->bitmapsize = (width * height * Bpp);

    return TRUE;
}


//Saves a surface to a file.
bool surface::SaveToFile(const std::string& File)
{
    LogMessage("Saving the surface to a file");

    if(!this->Bmp)
    {
        LogError("Error: surface does not exist.  Nothing to save!");
        return FALSE;
    }

    return (bool) (::save_bitmap(File.c_str(), this->Bmp, NULL));
}


//Creates a Sub Bitmap
//surface surface::createSubsurface

//This function blit (block image transfer) using the given source surface object
void surface::Blit(Surface source, WORD sourcex, WORD sourcey, WORD destx, WORD desty, WORD Width, WORD Height)
{
    source->Acquire();
    Acquire();
    blit(source->Bmp, this->Bmp, sourcex, sourcey, destx, desty, Width, Height);
    Release();
    source->Release();
}


//This is the same as the above blit function, but it stretches the source across the destination
void surface::StretchBlit(Surface source, WORD sourcex, WORD sourcey, WORD sourcewidth, WORD sourceheight, WORD destx, WORD desty, WORD destwidth, WORD destheight)
{
    source->Acquire();
    Acquire();
    stretch_blit(source->Bmp, this->Bmp, sourcex, sourcey, sourcewidth, sourceheight, destx, desty, destwidth, destheight);
    Release();
    source->Release();
}


//Set Clip State
//used to turn clipping on or off on the surface
void surface::SetClipState(WORD state)
{
    set_clip_state(this->Bmp, state);
}


//Sets the clipping rectangle, or the area where drawing is allowed.
void surface::SetClipRect(WORD _x, WORD _y, WORD _w, WORD _h)
{
    set_clip_rect(this->Bmp, _x, _y, _w, _h);
}


//Creates a sub surface off of the current surface
Surface surface::CreateSubSurface(WORD X, WORD Y, WORD Width, WORD Height)
{

    SubContext.push_back(Surface( new surface ));
    Surface pSurface = SubContext[ SubContext.size() - 1 ];

    pSurface->Bmp = ::create_sub_bitmap(this->Bmp, X, Y, Width, Height);
    pSurface->Width(Width);
    pSurface->Height(Height);
    blit(this->Bmp, pSurface->Bmp, X, Y, 0, 0, Width, Height);
    return pSurface;
}


//IsSubsurface
//returns true if the surface object is a sub surface
bool surface::IsSubSurface()
{
    HXLOG("IsSubsurface");
    if(this->Bmp != NULL)
    {
        char str[128];
        sprintf(str, "w = %d, h = %d", Bmp->w, Bmp->h);
        LogMessage(str);
        LogMessage("Bmp does not equal null");
    }
    if(is_sub_bitmap(this->Bmp))
    {
        LogMessage("Bitmap is a sub bitmap");
    }
    //return (this->Bmp != NULL) ? is_sub_bitmap(this->Bmp) : false;
    return false;
}


//Draws a line on the surface with the given coordinates
void surface::DrawLine(WORD x1, WORD y1, WORD x2, WORD y2, WORD clr)
{
    line(this->Bmp, x1, y1, x2, y2, clr);
}


//Draws a horizontal line on the surface which is quick than the standard line algorithm in the Allegro libraries
void surface::DrawHLine(WORD x1, WORD y, WORD x2, WORD clr)
{
    hline(this->Bmp, x1, y, x2, clr);
}


//Draws a vertical line on the surface which is quick than the standard line algorithm in the Allegro libraries
void surface::DrawVLine(WORD x, WORD y1, WORD y2, WORD clr)
{
    vline(this->Bmp, x, y1, y2, clr);
}


//Fills a rectangle on the surface using the given color
void surface::FillRect(WORD x1, WORD y1, WORD x2, WORD y2, WORD clr)
{
    rectfill(this->Bmp, x1, y1, x2, y2, clr);
}


//Clears the surface to the given color
void surface::Clear(WORD clr)
{
    if(!this->Bmp)
    {
        LogError("surface does not exist");
        return;
    }

    clear_to_color(this->Bmp, clr);
}


//Plots a pixel on the surface with the given x and y coordinates
void surface::PutPixel(WORD X, WORD Y, WORD Color)
{
    ::putpixel(this->Bmp, X, Y, Color);
}


//Gets the colur of the pixel at the given coordinates
WORD surface::GetPixel(WORD X, WORD Y)
{
    return getpixel(this->Bmp, X, Y);
}


//Sets the Width
void surface::Width(WORD Width)
{
    width = Width;
    this->Resize();
}


//Returns the Width
WORD surface::Width()
{
    return width;
}


//Sets the Height
void surface::Height(WORD Height)
{
    height = Height;
    this->Resize();
}


//Returns the Height
WORD surface::Height()
{
    return height;
}


//Used if Width() and Height() have been called, and will resize the surface object apportiatley
void surface::Resize()
{
    WORD ow, oh;
    ow = this->Bmp->w;
    oh = this->Bmp->h;

    BITMAP *temp = create_bitmap(width, height);
    if(!temp)
    {
        LogError("Error creating surface");
        return;
    }

    ::blit(this->Bmp, temp, 0, 0, 0, 0, this->Bmp->w, this->Bmp->h);

    destroy_bitmap(this->Bmp);
    this->Bmp = create_bitmap(width, height);
    ::stretch_blit(temp, this->Bmp, 0, 0, width, height, 0, 0, ow, oh);
    destroy_bitmap(temp);
}


void surface::RecalcSize(WORD Width, WORD Height)
{
    width = Width;
    height = Height;
    this->Resize();
}


void surface::DrawRect(WORD x1, WORD y1, WORD x2, WORD y2, WORD clr)
{
    ::rect(this->Bmp, x1, y1, x2, y2, clr);
}


void surface::DrawFilledRect(WORD x1, WORD y1, WORD x2, WORD y2, WORD clr)
{
    ::rectfill(this->Bmp, x1, y1, x2, y2, clr);
}


void surface::DrawText(const std::string& Text, WORD Xp, WORD Yp, WORD Color)
{
    ::textout_ex(this->Bmp, font, Text.c_str(), Xp, Yp, Color, -1);
}


void surface::DrawText(const std::string& Text, WORD Xp, WORD Yp)
{
    ::textout_ex(this->Bmp, font, Text.c_str(), Xp, Yp, 0x000000, -1);
}


void surface::DrawCircle(WORD x, WORD y, WORD r, WORD clr)
{
    ::circle(this->Bmp, x, y, r, clr);
}


void surface::DrawFilledCircle(WORD x, WORD y, WORD r, WORD clr)
{
    ::circlefill(this->Bmp, x, y, r, clr);
}


BITMAP *surface::AllegroBitmap()
{
    return this->Bmp;
}


void surface::ShowMouse()
{
    show_mouse(this->Bmp);
}


void surface::HideMouse()
{
    scare_mouse();
}


int surface::BitsPerPixel()
{
    return Bpp;
}


void surface::BitsPerPixel(int _bpp)
{
    Bpp = _bpp;
    return;
}


//same as BitsPerPixel
int surface::ColorDepth()
{
    return Bpp;
}


void surface::ColorDepth(int _bpp)
{
    Bpp = _bpp;
    return;
}


//calculates and returns the size in bytes of the bitmap
DWORD surface::Size()
{
    bitmapsize = (width * height * Bpp);
    return bitmapsize;
}
