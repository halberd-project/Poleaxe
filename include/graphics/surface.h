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

#ifndef __POL_SURFACE__
#define __POL_SURFACE__

#include "../../poleaxe.h"


class surface : public object
{
     protected:
        /*
         *  Protected variables and data types
         *  for the surface class
         */
        BITMAP* Bmp;
        vector<Surface> SubContext;

        WORD width, height;
        WORD Bpp;
        DWORD bitmapsize;


     public:
        /*
         *  Constructors and Deconstructors
         *  for the surface class
         *
         */
        surface();
        surface(WORD Width, WORD Height, WORD Color);
        surface(WORD W, WORD H);             //Use the bpp of the current screen resolution
        surface(BITMAP *bmp);
        surface(const std::string& fileName);
        surface(Surface Parent, WORD X, WORD Y, WORD W, WORD H);
        ~surface();


        /*
         *  Drawing primitives
         *  for the surface class
         *
         */
        void PutPixel(WORD _x, WORD _y, WORD clr);
        WORD GetPixel(WORD _x, WORD _y);
        void DrawLine(WORD x1, WORD y1, WORD x2, WORD y2, WORD clr);
        void DrawHLine(WORD x1, WORD y, WORD x2, WORD clr);
        void DrawVLine(WORD x, WORD y1, WORD y2, WORD clr);
        void FillRect(WORD x1, WORD y1, WORD x2, WORD y2, WORD clr);
        void Clear(WORD clr);
        void DrawRect(WORD x1, WORD y1, WORD x2, WORD y2, WORD clr);
        void DrawFilledRect(WORD x1, WORD y1, WORD x2, WORD y2, WORD clr);
        void DrawText(const std::string& Text, WORD Xp, WORD Yp);
        void DrawText(const std::string& Text, WORD Xp, WORD Yp, WORD Color);
        void DrawCircle(WORD x, WORD y, WORD r, WORD clr);
        void DrawFilledCircle(WORD x, WORD y, WORD r, WORD clr);


        /*
         *  Property control functions
         *  for the surface class
         */
        WORD Width();
        void Width(WORD _width);
        WORD Height();
        void Height(WORD _height);
        void Resize();
        void RecalcSize(WORD Width, WORD Height);
        void SetClipState(WORD state);
        void SetClipRect(WORD _x, WORD _y, WORD _w, WORD _h);
        int BitsPerPixel();
        void BitsPerPixel(int _bpp);
        int ColorDepth();
        void ColorDepth(int _bpp);
        DWORD Size();       //returns the size in bytes.

        /*
         *
         *  Blitting and sizing, and image loading functions
         *  for the surface class
         *
         */
        Surface CreateSubSurface(WORD _x, WORD _h, WORD _width, WORD _height);
        bool IsSubSurface();
        bool LoadFromFile(const std::string& File);
        bool SaveToFile(const std::string& File);
        void Destroy();
        void BlitSize();
        void BlitSize(WORD _width, WORD _height);
        void Blit(Surface source, WORD sourcex, WORD sourcey, WORD destx, WORD desty, WORD _width, WORD _height);
        void StretchBlit(Surface source, WORD sourcex, WORD sourcey, WORD sourcewidth, WORD sourceheight, WORD destx, WORD desty, WORD destwidth, WORD destheight);
        BITMAP *AllegroBitmap();		//returns the plain allegro bitmap structure for lower level interaction with the allegro library.
        void ShowMouse();
        void HideMouse();
        inline void Acquire()
        {
            acquire_bitmap(this->Bmp);
        }

        inline void Release()
        {
            release_bitmap(this->Bmp);
        }

};


 #endif
