#ifndef __COMMONTEXT_H_INCLUDED__
#define __COMMONTEXT_H_INCLUDED__

#include "Main.h"
#include "DrawText.h"

class DrawTitle : public MyDrawTextLine {
public:
	DrawTitle(DecorationItem *decorationItem, const char *str);
};

class DrawSubtitle : public MyDrawText {
public:
	DrawSubtitle(DecorationItem *decorationItem, const char *str);
};

#endif