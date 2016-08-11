#ifndef __THROUGHDETAIL_H_INCLUDED__
#define __THROUGHDETAIL_H_INCLUDED__

#include "DxLib.h"
#include "DrawText.h"

class ThroughDetail {
public:
	ThroughDetail(Font *font);
	void View();
	~ThroughDetail();
private:
	MyDrawTextLine *title;
};

#endif