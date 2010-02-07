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


#ifndef __TYPES__
#define __TYPES__


//Handles
#define HANDLE										long
#define SUCCEEDED(hr)       						(long(hr) >= 0)
#define FAILED(hr)          						(long(ht) < 0)
#define HRESULT                                     long


//data types
#define BYTE										char
#define WORD										short int
#define DWORD										long int
#define QWORD										long long
#define UBYTE										unsigned byte
#define UWORD										unsigned short int
#define UDWORD										unsigned long int
#define UQWORD										unsigned long long
#define USHORT										unsigned short
#define ULONG										unsigned long
#define BOOL                                        bool


//retrieve different parts of a variable
#define LONIBBLE(n)									(0x0f & n)
#define HINIBBLE(n)									((0xf0 & n) >> 4)
#define LOBYTE(n)									(0x00ff & n)
#define HIBYTE(n)									((0xff00 & n) >> 8)
#define LOWORD(n)									(0x0000ffff & n)
#define HIWORD(n)									((0xffff0000 & n) >> 16)
#define LODWORD(n)									(0x00000000ffffffff & n)
#define HIDWORD(n)									((0xffffffff00000000 & n) >> 32)

#define MAKEWORD(n1, n2)							((n1 << 8) | n2)
#define MAKEDWORD(n1, n2)							((n1 << 16) | n2)


class object;
typedef boost::shared_ptr<object> Object;

class control;
typedef boost::shared_ptr<control> Control;

class frame;
typedef boost::shared_ptr<frame> Frame;

class panel;
typedef boost::shared_ptr<panel> Panel;

class window;
typedef boost::shared_ptr<window> Window;

class dialogbox;
typedef boost::shared_ptr<dialogbox> DialogBox;

class keyboard;
typedef boost::shared_ptr<keyboard> Keyboard;

class mouse;
typedef boost::shared_ptr<mouse> Mouse;

class surface;
typedef boost::shared_ptr<surface> Surface;

class message;
typedef boost::shared_ptr<message> Message;

class display;
typedef boost::shared_ptr<display> Display;

class log;
typedef boost::shared_ptr<log> Log;

class manager;
typedef boost::shared_ptr<manager> Manager;

class messagehandler;
typedef boost::shared_ptr<messagehandler> MessageHandler;

class list;
typedef boost::shared_ptr<list> List;

class messagequeue;
typedef boost::shared_ptr<messagequeue> MessageQueue;

class node;
typedef boost::shared_ptr<node> Node;

class timer;
typedef boost::shared_ptr<timer> Timer;


//Global variables. :(
extern Manager      PoleaxeManager;



#endif			//__TYPES__
