#ifndef __SONGSELECTMAIN_H_INCLUDED__
#define __SONGSELECTMAIN_H_INCLUDED__

#include "DxLib.h"
#include "ModeSelect.h"
#include "Touch.h"
#include "SongSelectCover.h"
#include "Songs.h"
#include "Font.h"
#include "SongSelectCommon.h"
#include "SongSelect.h"
#include "SongSelectDefine.h"
#include "ThroughOption.h"
#include "Scene.h"

//曲選択画面関係
class SongSelect : public Scene{
public:
	SongSelect(Font *font, Touch *touch, Songs *songs);
	int Switch();
	~SongSelect();
private:
	SongSelectTitle *songSelectTitle; //曲選択画面タイトル
	SongInformation *songInformation; //選択中の曲
	SongSelectButton *songSelectButton; //ボタン関係
	SongSelectPop *songSelectPop; //終了用ポップアップ
	ModeSelectButton *modeSelectButton; //モード選択ボタン
	ThroughOptionButton *throughOptionButton; //通し練習オプションボタン
	Touch *touch; //サイドタッチパネル
	int scene;
	void ContentLoad();
	void ContentUpdate();
	void ContentView();
	void ContentDelete();
};

#endif