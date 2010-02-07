/*
 * Jeff Shoulders and Robert Butler
 * hx86 working group
 *
 * These functions serve to wrap the existing Allegro
 * functions and provide an object oriented interface
 * to handle and manage bitmaps.
 */

#include "../../poleaxe.h"

//Used for making a new blank Bitmap object
bitmap::bitmap()
{
    width = 0;
    height = 0;
    Bpp = 0;
}


//Used for making a new blank Bitmap object with the specified bits per pixel
bitmap::bitmap(int Width, int Height, int Color)
{
    Bmp    = create_bitmap(Width, Height);
    Bpp    = Color;
    width  = Width;
    height = Height;
}


//Used for making a new blank Bitmap object using the default bits per pixel
bitmap::bitmap(int Width, int Height)
{
    Bmp    = create_bitmap(Width, Height);
    Bpp    = 24;                           //TODO: get bpp from sreen resolution
    width  = Width;
    height = Height;
}


//Used for making a new Bitmap obkject based upon the given Allegro BITMAP structure
bitmap::bitmap(BITMAP *Bmp)
{
    if(is_screen_bitmap(Bmp))
    {
        HXLOG("Creating a screen bitmap");
        this->Bmp = Bmp;
        this->width = SCREEN_W;
        this->height = SCREEN_H;
        return;
    }

    this->Bmp = create_bitmap(Bmp->w, Bmp->h);
    if(!this->Bmp)
    {
        HXERROR("Error creating bitmap.");
        return;
    }

    ::blit(Bmp, this->Bmp, 0, 0, 0, 0, Bmp->w, Bmp->h);

    width  = Bmp->w;
    height = Bmp->h;
}


//Used for creating a new Bitmap object and loading the existing image file into the Bitmap.
bitmap::bitmap(const std::string& File)
{
    this->Bmp = load_bitmap(File.c_str(), NULL);        //Use the allegro function to load a BITMAP from a file and setup our bitmap class

    //If loading an image from the file had failed...
    if(!this->Bmp)
    {
        char errorString[128];

        sprintf(errorString, "Error loading the Bitmap file %s and creating the Bitmap Object.", File.c_str());
        HXERROR(errorString);
        return;
    }

    //blit(this->Bmp, screen, 0, 0, 0, 0, 1024, 768);

    HXLOG("Loaded bitmap from file succesfully.");
    Width(Bmp->w);
    Height(Bmp->h);
}


//This constructor is used for creating a new Bitmap object as a subbitmap of an already existing  Bitmap
bitmap::bitmap(Bitmap parent, int X, int Y, int Width, int Height)
{
    this->Bmp = (parent->CreateSubBitmap(X, Y, Width, Height))->Bmp;
    width = Width;
    height = Height;
    Bpp = 24;
}


//Bitmap Deconstructor
bitmap::~bitmap()
{
    if(this->Bmp)
        destroy_bitmap(this->Bmp);

    SubContext.clear();
}


//Loads an image from a file
bool bitmap::LoadFromFile(const std::string& File)
{
    if(this->Bmp)
    {
        HXLOG("Bitmap already exists, destroying to load a new image.");
        destroy_bitmap(this->Bmp);
    }

    this->Bmp = load_bitmap(File.c_str(), NULL);

    if(!this->Bmp)                  //If loading an image from the file had failed...
    {
        HXERROR("Error loading the file and creating the Bitmap");
        return FALSE;
    }

    HXLOG("Loaded bitmap from file succesfully.");
    this->width = Bmp->w;
    this->height = Bmp->h;

    return TRUE;
}


//Saves a BITMAP to a file.
bool bitmap::SaveToFile(const std::string& File)
{
    HXLOG("Saving the Bitmap to a file");

    if(!this->Bmp)
    {
        HXERROR("Error: Bitmap does not exist.  Nothing to save!");
        return FALSE;
    }

    return (bool) (::save_bitmap(File.c_str(), this->Bmp, NULL));
}


//Creates a Sub Bitmap
//Bitmap bitmap::createSubBitmap

//This function blit (block image transfer) using the given source Bitmap object
void bitmap::Blit(Bitmap Src, int sourcex, int sourcey, int destx, int desty, int Width, int Height)
{
    blit(Src->Bmp, this->Bmp, sourcex, sourcey, destx, desty, Width, Height);
}


//This is the same as the above blit function, but it stretches the source across the destination
void bitmap::StretchBlit(Bitmap source, int sourcex, int sourcey, int sourcewidth, int sourceheight, int destx, int desty, int destwidth, int destheight)
{
    stretch_blit(source->Bmp, this->Bmp, sourcex, sourcey, sourcewidth, sourceheight, destx, desty, destwidth, destheight);
}


//Set Clip State
//used to turn clipping on or off on the bitmap
void bitmap::SetClipState(int state)
{
    set_clip_state(this->Bmp, state);
}


//Sets the clipping rectangle, or the area where drawing is allowed.
void bitmap::SetClipRect(int _x, int _y, int _w, int _h)
{
    set_clip_rect(this->Bmp, _x, _y, _w, _h);
}


//Creates a sub Bitmap off of the current Bitmap
Bitmap bitmap::CreateSubBitmap(int X, int Y, int Width,int Height)
{

    SubContext.push_back(Bitmap( new bitmap ));
    Bitmap pBitmap = SubContext[ SubContext.size() - 1 ];

    pBitmap->Bmp = ::create_sub_bitmap(this->Bmp, X, Y, Width, Height);
    pBitmap->Width(Width);
    pBitmap->Height(Height);
    blit(this->Bmp, pBitmap->Bmp, X, Y, 0, 0, Width, Height);
    return pBitmap;
}


//IsSubBitmap
//returns true if the bitmap object is a sub bitmap
bool bitmap::IsSubBitmap()
{
    HXLOG("IsSubBitmap");
    if(this->Bmp != NULL)
    {
        char str[128];
        sprintf(str, "w = %d, h = %d", Bmp->w, Bmp->h);
        HXLOG(str);
        HXLOG("Bmp does not equal null");
    }
    if(is_sub_bitmap(this->Bmp))
    {
        HXLOG("Bitmap is a sub bitmap");
    }
    //return (this->Bmp != NULL) ? is_sub_bitmap(this->Bmp) : false;
    return false;
}


//Draws a line on the bitmap with the given coordinates
void bitmap::DrawLine(int x1, int y1, int x2, int y2, int clr)
{
    line(this->Bmp, x1, y1, x2, y2, clr);
}


//Draws a horizontal line on the bitmap which is quick than the standard line algorithm in the Allegro libraries
void bitmap::DrawHLine(int x1, int y, int x2, int clr)
{
    hline(this->Bmp, x1, y, x2, clr);
}


//Draws a vertical line on the bitmap which is quick than the standard line algorithm in the Allegro libraries
void bitmap::DrawVLine(int x, int y1, int y2, int clr)
{
    vline(this->Bmp, x, y1, y2, clr);
}


//Fills a rectangle on the bitmap using the given color
void bitmap::FillRect(int x1, int y1, int x2, int y2, int clr)
{
    rectfill(this->Bmp, x1, y1, x2, y2, clr);
}


//Clears the bitmap to the given color
void bitmap::Clear(int clr)
{
    if(!this->Bmp)
    {
        HXERROR("Bitmap does not exist");
        return;
    }

    clear_to_color(this->Bmp, clr);
}


//Plots a pixel on the Bitmap with the given x and y coordinates
void bitmap::PutPixel(int X, int Y, int Color)
{
    ::putpixel(this->Bmp, X, Y, Color);
}


//Gets the colur of the pixel at the given coordinates
int bitmap::GetPixel(int X, int Y)
{
    return getpixel(this->Bmp, X, Y);
}


//Sets the Width
void bitmap::Width(int Width)
{
    width = Width;
    this->Resize();
}


//Returns the Width
int bitmap::Width()
{
    return width;
}


//Sets the Height
void bitmap::Height(int Height)
{
    height = Height;
    this->Resize();
}


//Returns the Height
int bitmap::Height()
{
    return height;
}


//Used if Width() and Height() have been called, and will resize the bitmap object apportiatley
void bitmap::Resize()
{
    int ow, oh;
    ow = this->Bmp->w;
    oh = this->Bmp->h;

    BITMAP *temp = create_bitmap(width, height);
    if(!temp)
    {
        HXERROR("Error creating bitmap");
        return;
    }

    ::blit(this->Bmp, temp, 0, 0, 0, 0, this->Bmp->w, this->Bmp->h);

    destroy_bitmap(this->Bmp);
    this->Bmp = create_bitmap(width, height);
    ::stretch_blit(temp, this->Bmp, 0, 0, width, height, 0, 0, ow, oh);
    destroy_bitmap(temp);
}

void bitmap::RecalcSize(int Width, int Height)
{
    width = Width;
    height = Height;
    this->Resize();
}


void bitmap::DrawRect(int x1, int y1, int x2, int y2, int clr)
{
    ::rect(this->Bmp, x1, y1, x2, y2, clr);
}

void bitmap::DrawFilledRect(int x1, int y1, int x2, int y2, int clr)
{
    ::rectfill(this->Bmp, x1, y1, x2, y2, clr);
}

void bitmap::DrawText(const std::string& Text, int Xp, int Yp, int Color)
{
    ::textout_ex(this->Bmp, font, Text.c_str(), Xp, Yp, Color, -1);
}

void bitmap::DrawText(const std::string& Text, int Xp, int Yp)
{
    ::textout_ex(this->Bmp, font, Text.c_str(), Xp, Yp, 0x000000, -1);
}

void bitmap::DrawCircle(int x, int y, int r, int clr)
{
    ::circle(this->Bmp, x, y, r, clr);
}

void bitmap::DrawFilledCircle(int x, int y, int r, int clr)
{
    ::circlefill(this->Bmp, x, y, r, clr);
}
