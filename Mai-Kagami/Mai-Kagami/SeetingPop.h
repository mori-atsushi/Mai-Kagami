#ifndef __SETTINGPOP_H_INCLUDED__
#define __SETTINGPOP_H_INCLUDED__

#include "DxLib.h"
#include "DrawObject.h"

//ポップアップ用四角形（黒色半透明全画面）
class BlackBox : public MyDrawBox {
public:
	BlackBox();
	void View();
private:
};

#endif