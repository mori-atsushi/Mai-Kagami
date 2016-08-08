#ifndef __THROUGHRESULT_H_INCLUDED__
#define __THROUGHRESULT_H_INCLUDED__

#include "DxLib.h"
#include "DrawText.h"
#include "Font.h"

class ThroughResult {
public:
	ThroughResult(Font *font);
	void View();
	~ThroughResult();
private:
	MyDrawTextLine *title;
};

#endif