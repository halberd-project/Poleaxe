/*
 * Jeff Shoulders and Robert Butler
 * hx86 working group
 *
 */

#ifndef __HXBITMAP__
#define __HXBITMAP__

#include <allegro.h>

//I think i'd like to phase this out

class bitmap;
typedef boost::shared_ptr<bitmap> Bitmap;


class bitmap
{
     //protected:
     public:
        /*
         *  Protected variables and data types
         *  for the Bitmap class
         */
        BITMAP* Bmp;
        vector<Bitmap> SubContext;

        int width, height;
        int Bpp;


     //public:
        /*
         *  Constructors and Deconstructors
         *  for the Bitmap class
         *
         */
        bitmap();
        bitmap(int W, int H, int Colors);
        bitmap(int W, int H);             //Use the bpp of the current screen resolution
        bitmap(BITMAP *bmp);
        bitmap(const std::string& fileName);
        bitmap(Bitmap Parent, int X, int Y, int W, int H);
        ~bitmap();


        /*
         *  Drawing primitives
         *  for the Bitmap class
         *
         */
        void PutPixel(int _x, int _y, int clr);
        int GetPixel(int _x, int _y);
        void DrawLine(int x1, int y1, int x2, int y2, int clr);
        void DrawHLine(int x1, int y, int x2, int clr);
        void DrawVLine(int x, int y1, int y2, int clr);
        void FillRect(int x1, int y1, int x2, int y2, int clr);
        void Clear(int clr);
        void DrawRect(int x1, int y1, int x2, int y2, int clr);
        void DrawFilledRect(int x1, int y1, int x2, int y2, int clr);
        void DrawText(const std::string& Text, int Xp, int Yp);
        void DrawText(const std::string& Text, int Xp, int Yp, int Color);
        void DrawCircle(int x, int y, int r, int clr);
        void DrawFilledCircle(int x, int y, int r, int clr);


        /*
         *  Property control functions
         *  for the Bitmap class
         */
        int Width();
        void Width(int _width);
        int Height();
        void Height(int _height);
        void Resize();
        void RecalcSize(int Width, int Height);
        void SetClipState(int state);
        void SetClipRect(int _x, int _y, int _w, int _h);

        /*
         *
         *  Blitting and sizing, and image loading functions
         *  for the Bitmap class
         *
         */
        Bitmap CreateSubBitmap(int _x, int _h, int _width, int _height);
        bool IsSubBitmap();
        bool LoadFromFile(const std::string& File);
        bool SaveToFile(const std::string& File);
        void BlitSize();
        void BlitSize(int _width, int _height);
        void Blit(Bitmap source, int sourcex, int sourcey, int destx, int desty, int _width, int _height);
        void StretchBlit(Bitmap Src, int sourcex, int sourcey, int sourcewidth, int sourceheight, int destx, int desty, int destwidth, int destheight);
 };


 #endif
