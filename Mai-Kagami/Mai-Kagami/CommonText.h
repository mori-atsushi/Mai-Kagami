#ifndef __COMMONTEXT_H_INCLUDED__
#define __COMMONTEXT_H_INCLUDED__

#include "Main.h"
#include "DrawText.h"

class DrawTitle : public MyDrawTextLine {
public:
	DrawTitle(Font *font, const char *str);
};

class DrawSubtitle : public MyDrawText {
public:
	DrawSubtitle(Font *font, const char *str);
};

#endif