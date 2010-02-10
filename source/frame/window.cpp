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


//Empty constructor
window::window()
{
}

//Constructor
window::window(const std::string& Caption, int Xp, int Yp, int Width, int Height, uint32_t Flags)
{
    //Copy the title
    title = Caption;
    BorderWidth = 5.5;
    x = Xp;
    y = Yp;
    width = Width;
    height = Height;
    buffer = Surface(new surface(Width + DROPSHADOW, Height + DROPSHADOW));
    buffer->Clear(0xFFFF);
    Moving = false;
    this->Flags = Flags;
    char str[128];
    sprintf(str, "Creating Window, x=%d, y=%d, w=%d, h=%d", Xp, Yp, Width, Height);
    LogMessage(str);
    msg_queue = MessageQueue(new messagequeue());
}


//Deconstructor
window::~window()
{
    //TODO
    //Add in code to clear things and delete any used memory
    //writing these commments probably used more time than I could have used just
    //writing the code itself.
}


void window::Draw()
{
    LogMessage("I am now in the drawing function.");
    buffer->Acquire();
    buffer->SetClipState(false);
    // Window frame: Inner
    buffer->DrawRect(0, 0, width, height, 0x000000);

    // Window frame: Outer
    buffer->DrawFilledRect(1, 1, width - 1, height - 1,  makecol(192, 192, 192));

    // Window frame: Outer
    buffer->DrawRect(BorderWidth, BorderWidth, width - BorderWidth, height - BorderWidth,  makecol(0, 0, 0));

    // Border Calculations
    int Border[] =
    {
        /// Left border
        width - (BorderWidth * 10),

        /// Right border
        BorderWidth + 1,

        /// Upper border
        width - (BorderWidth + 1),

        /// Lower border
        BorderWidth * 5,

        /// Uhh...
        BorderWidth * 4
    };

    /// Window frame: Outer
    buffer->DrawRect(0, BorderWidth * 5, width, height - (BorderWidth * 5),  makecol(0, 0, 0));

    /// Window frame: Outer
    buffer->DrawRect((BorderWidth * 5), 0, width - (BorderWidth * 5.2), height,  makecol(0, 0, 0));

    /// Window buttons
    buffer->DrawFilledRect(Border[0] + 1, Border[1], Border[2], Border[3], makecol(192, 192, 192));
    buffer->DrawRect(Border[0], BorderWidth, (width - Border[3]) - 2, Border[3], 0);

    /// 3-D effect for Minimize Button
    buffer->DrawVLine(Border[0] + 22, Border[1], Border[3], makecol(128, 128, 128));
    buffer->DrawVLine(Border[0] + 21, Border[1] + 1, Border[3], makecol(128, 128, 128));
    buffer->DrawHLine(Border[2] - 43, Border[1], Border[2] - 23, makecol(255, 255, 255));
    buffer->DrawHLine(Border[2] - 43, Border[1] * 4.1, Border[2] - 23, makecol(128, 128, 128));
    buffer->DrawHLine(Border[2] - 42, Border[1] * 3.9, Border[2] - 23, makecol(128, 128, 128));
    buffer->DrawVLine(Border[0] + 1, Border[1] + 1, Border[3] - 2, makecol(255, 255, 255));

    /// 3-D effect for Maximize button
    buffer->DrawVLine(Border[0] + 44, Border[1], Border[3], makecol(128, 128, 128));
    buffer->DrawVLine(Border[0] + 43, Border[1] + 1, Border[3], makecol(128, 128, 128));
    buffer->DrawHLine(Border[2] - 20, Border[1], Border[2] - 1, makecol(255, 255, 255));
    buffer->DrawHLine(Border[2] - 20, Border[1] * 4.1, Border[2] - 2, makecol(128, 128, 128));
    buffer->DrawHLine(Border[2] - 19, Border[1] * 3.9, Border[2] - 2, makecol(128, 128, 128));
    buffer->DrawVLine(Border[0] + 24, Border[1] + 1, Border[3] - 2, makecol(255, 255, 255));

    // Titlebar color
    buffer->DrawFilledRect(BorderWidth + 1, BorderWidth + 1, width - (BorderWidth * 10), BorderWidth * 5, makecol(0, 0, 128));

    buffer->DrawText(title, BorderWidth * 2, BorderWidth * 2,  makecol(255, 255, 255));

    // Client area color
    buffer->DrawFilledRect(BorderWidth + 1, BorderWidth * 5, width - (BorderWidth + 1), (height - BorderWidth) - 1,  makecol(255, 255, 255));

    buffer->DrawHLine(BorderWidth, BorderWidth * 5, width - BorderWidth,  makecol(0, 0, 0));
    buffer->SetClipState(true);
    buffer->Release();

    this->OnDraw();

    BITMAP *bmp = buffer->AllegroBitmap();
    LogMessage("%d, %d, %d, %d", x, y, width, height);
    acquire_screen();
    acquire_bitmap(bmp);
    blit(bmp, screen, 0, 0, x, y, width, height);
    release_bitmap(bmp);
    release_screen();
    //Crt.Blit(this->buffer, 0, 0, X(), Y(), width + 1, height + 1);
    //Crt.PageFlip();*/
    //HXLOG("Drawing window.");
    return;
}


//Drawing function for a basic window
void window::OnDraw()
{
    return;
}


//refreshwindow
void window::OnHwndPaint(Rect *R)
{
 //   if(R == NULL)
  //      Crt.Blit(this->buffer, 0, 0, X(), Y(), Width()+DROPSHADOW, Height()+DROPSHADOW);
}


//
int window::Width()
{
    return this->width;
}


//
void window::Width(int _width)
{
    width = _width;
}


//
int window::Height()
{
    return this->height;
}


//
void window::Height(int _height)
{
    height = _height;
}


//
int window::X()
{
    return this->x;
}


//
void window::X(int _x)
{
    this->x = _x;
}


//
int window::Y()
{
    return this->y;
}


//
void window::Y(int _y)
{
    this->y = _y;
}


//isInisde
//Used to determine if the given point is inside this window
bool window::isInside(int _x, int _y)
{
    if((_x > this->x) && (_x < (this->width + this->x)) && (_y > this->y) && (_y < (this->y + this->height)))
    {
        HXLOG("isInside returning true.");
        return true;
    }

    return false;
}


string window::Title()
{
    return title;
}


void window::Title(string _title)
{
    title = _title;
    return;
}


//onMouseDown
void window::OnMouseDown(int _x, int _y, short buttons)
{
    if((buttons == MOUSE_FLAG_LEFT_DOWN) && (_y < 20))     //Check if the mouse click is in the 'title bar' so that we can start dragging the window
    {
        Moving = !(Moving);
        prevx = x + _x;
        prevy = y + _y;
        HXLOG("Moving the Windows is toggled");
    }
    else if(buttons)
    {
        this->buffer->DrawFilledCircle(_x, _y, 32, 0x00000000);
        OnHwndPaint(NULL);
    }
}


void window::OnMouseUp(int _x, int _y, short buttons)
{
    prevx = 0;
    prevy = 0;

    if(_y < 20)
        Moving = !(Moving);
    else if(buttons)
    {
        this->buffer->DrawFilledCircle(_x, _y, 32, 0x00000000);
        OnHwndPaint(NULL);
    }
}


void window::OnMouseMove(int Xp, int Yp)
{
    if(Moving == true)
    {
        this->x += (Xp - prevx);
        this->y += (Yp - prevy);
        prevx = Xp;
        prevy = Yp;

        OnHwndPaint(NULL);
    }
}


HANDLE window::Handle()
{
    return this->handle;
}


void window::Handle(HANDLE _handle)
{
    this->handle = _handle;
    return;
}


void window::Enqueue(Message m)
{
    msg_queue->Enqueue(m);

    return;
}

Window CreateHwnd(const std::string& Caption, int X, int Y, int W, int H, int WFlags)
{
    Window Hwnd(new window(Caption, X, Y, W, H, WFlags));
    //EventLoop.RegisterHwnd(Hwnd);

    return Hwnd;
}
