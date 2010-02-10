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
 *
 *      The Poleaxe grapical user interface and utility functions is a library developed primarily to
 *  for the Halber operating system under development.  The entire structure is a hierarchy of objects,
 *  functions and utlities designed to make a simple to use, and simple to program desktop enviroment
 *  for all of those involved in the project.
 *
 */


#ifndef __POLEAXE__
#define __POLEAXE__


#ifdef POL32_LEAN_AND_MEAN
//because I can
#endif


//namespaces, general c++ libs, boost, etc...
#include <allegro.h>
#include <iostream>
#include <string>
#include <queue>
#include <deque>
//#include <list>
#include <vector>
#include <boost/shared_ptr.hpp>
//#include <boost/intrusive/list.hpp>

using namespace std;
using namespace boost;


//general C
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <malloc.h>


//general data types
#include "./include/base/types.h"
#include "./include/base/object.h"
#include "./include/base/api.h"
#include "./include/tinyxml/tinyxml.h"


//math
#include "./include/math/constants.h"
#include "./include/math/types.h"
#include "./include/math/vector.h"
#include "./include/math/matrix.h"
#include "./include/math/misc.h"


//system
#include "./include/system/config.h"
#include "./include/system/debug.h"
#include "./include/system/element.h"
#include "./include/system/log.h"
#include "./include/system/manager.h"
#include "./include/system/timer.h"


//frame
#include "./include/frame/frame.h"
#include "./include/frame/window.h"
#include "./include/frame/dialogbox.h"


//communication
#include "./include/communication/message.h"


//graphics
#include "./include/graphics/allegro.h"
#include "./include/graphics/surface.h"
#include "./include/graphics/display.h"
#include "./include/graphics/bitmap.h"


//input
#include "./include/input/keyboard.h"
#include "./include/input/mouse.h"


//types
#include "./include/types/list.h"
#include "./include/types/node.h"
#include "./include/types/messagequeue.h"


#endif
