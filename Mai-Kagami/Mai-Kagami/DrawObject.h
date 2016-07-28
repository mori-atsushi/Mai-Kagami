#ifndef __DRAWOBJECT_H_INCLUDED__
#define __DRAWOBJECT_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"
#include "Draw.h"

//‰~ŠÖŒW
class MyDrawCircle : public Draw, public Color{
public:
	MyDrawCircle(const float x, const float y, const float radius, const char *colorName = "Blue"); //‰~‰Šú‰»i“h‚è‚Â‚Ô‚µ‚ ‚èj
	MyDrawCircle(const float x, const float y, const float radius, const float width, const char *colorName = "Blue"); //‰~‰Šú‰»i“h‚è‚Â‚Ô‚µ‚È‚µj
	void View();
private:
	float r, w; //”¼ŒaAü‚Ì‘¾‚³
};

//³OŠpŒ`ŠÖŒW
class MyDrawTriangle : public Draw, public Color {
public:
	MyDrawTriangle(const float x, const float y, const float width, const int direction, const char *colorName = "Blue");
	void View(); //•\¦
private:
	int d;
	float w;
};

//lŠpŒ`ŠÖŒW
class MyDrawBox : public Draw, public Color {
public:
	MyDrawBox(const float x, const float y, const float width, const float height, const char *colorName = "White"); //lŠpŒ`‰Šú‰»i“h‚è‚Â‚Ô‚µ‚ ‚èj
	MyDrawBox(const float x, const float y, const float width, const float height, const float line, const char *colorName = "Blue"); //lŠpŒ`‰Šú‰»i“h‚è‚Â‚Ô‚µ‚È‚µj
	void View();
private:
	float w, h, l; //•A‚‚³Aü‚Ì‘¾‚³
};

#endif