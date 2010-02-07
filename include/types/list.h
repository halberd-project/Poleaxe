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


#ifndef __POL_LIST__
#define __POL_LIST__


#include "../../poleaxe.h"


class list //: public object    //for later...
{
    //protected:
    public:
        node *base, *i, *end;           //pointers to the start of the nodes, the iterator (i), and the end of the nodes.
        int num_nodes;

    //public:
                                                                list();
        virtual                                                 ~list();
        virtual bool                                            AddNode(Node *_node);
        virtual bool                                            DeleteNode();
        virtual int                                             NumberOfNodes();
        virtual void                                            Clear();
        virtual bool                                            Empty();
        virtual node                                            *Iterator();
        virtual node                                            *Base();
        virtual node                                            *End();
};


#endif      //__POL_LIST__
