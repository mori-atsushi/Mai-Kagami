#ifndef __SCENE_H_INCLUDED__
#define __SCENE_H_INCLUDED__

#include "DxLib.h"

//サブ場面定義
class SubScene {
public:
	int Switch(const int scene) { return scene; }; //場面の切り替え
	void Update() {}; //更新
	void View() {}; //表示
	void Load() {}; //ロード
	void Delete() {}; //削除
};

//場面定義
class Scene : public SubScene {
public:
	void Update(); //更新
	void View(); //表示
protected:
	void Load(); //ロード
	void Delete(); //削除
private:
	virtual void ContentLoad() = 0; //ロード詳細
	virtual void ContentView() = 0; //表示詳細
	virtual void ContentUpdate() = 0; //更新詳細
	virtual void ContentDelete() = 0; //削除詳細
	int loadFlag = 0; //ロード確認用（0：未ロード、1：ロード中、2：ロード完了）
};

#endif