#ifndef __SCENE_H_INCLUDED__
#define __SCENE_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"

//サブ場面定義
class SubScene {
public:
	void Update(const int scene); //更新
	void View(); //表示
	void Load(); //ロード
	void Delete(); //削除
	boolean CheckView(); //表示中かどうか確認する(TRUE:表示中、FALSE：非表示中)
protected:
	int nowScene;
	boolean viewFlag = FALSE; //表示用フラグ(TRUE:表示、FALSE：非表示)
	virtual void ContentView() = 0; //表示詳細
	virtual void ContentUpdate() = 0; //更新詳細
};

//場面定義
class Scene : public SubScene {
protected:
	void Load(); //ロード
	void Delete(); //削除
private:
	virtual void ContentLoad() = 0; //ロード詳細
	virtual void ContentDelete() = 0; //削除詳細
	int loadFlag = 0; //ロード確認用（0：未ロード、1：ロード中、2：ロード完了）
};

#endif