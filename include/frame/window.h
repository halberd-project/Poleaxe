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

#ifndef __POL_WINDOW__
#define __POL_WINDOW__


#define DROPSHADOW                                  3


//Window position default macros.  These can be used to let the window manager decide suitable coordinates.
#define POL_DEFAULT_POS                             -1


//Window styles,  These are to go in the 'flag' field
#define POL_STDWINDOW                               0x0001
#define POL_DIALOGBOX                               0x0002
#define POL_MDI                                     0x0004


//Window flags
#define POL_RESIZABLE                               0x0001
#define POL_HSCROLL                                 0x0002
#define POL_VSCROLL                                 0x0004


//Window class
 class window : public object
 {
     protected:
        HANDLE         handle;
        MessageQueue    mq;
        std::string      title;
        int x, y, width, height;
        int draw_offset_x, draw_offset_y;
        long int z;                             //This is the z-index of the Window, or how deep it is in relation to other windows
        int prevx, prevy;
        int              Flags;
        Surface           buffer, back;
        bool             Moving;
        int              TitleBarSize;
        float BorderWidth;
        MessageQueue msg_queue;

     public:
        window();
        window(const std::string& Caption, int X, int Y, int H, int W, uint32_t Opts);
        ~window();

        void Draw();
        void OnDraw();
        void OnMouseEnter();
        void OnMouseLeave();
        void OnMouseDown(int _x, int _y, short buttons);                        //Local coordinates
        void OnMouseUp(int _x, int _y, short buttons);
        void OnMouseMove(int _x, int _y);
        void OnHwndPaint(RECT* R);
        void X(int _x);
        int X();
        void Y(int _y);
        int Y();
        void Width(int _width);
        int Width();
        void Height(int _height);
        int Height();
        long int Z();
        void Z(long int _z);
        HANDLE Handle();
        void Handle(HANDLE _handle);
        bool isInside(int _x, int _y);
        bool isInside(Rect *r);
        string Title();
        void Title(string _title);
        void Enqueue(Message m);
 };


 #endif
