#ifndef __SCENE_H_INCLUDED__
#define __SCENE_H_INCLUDED__

#include "DxLib.h"

//場面定義
class Scene {
public:
	int Update(const int scene); //更新
	void View(); //表示
protected:
	void Load(); //ロード
	void Delete(); //削除
private:
	virtual void ContentLoad() = 0;
	virtual void ContentView() = 0;
	virtual int ContentUpdate() = 0;
	virtual void ContentDelete() = 0;
	int loadFlag = 0; //ロード確認用（0：未ロード、1：ロード中、2：ロード完了）
};

#endif