#ifndef __SONGSELECTMAIN_H_INCLUDED__
#define __SONGSELECTMAIN_H_INCLUDED__

#include <thread>
#include <Windows.h>
#include "DxLib.h"
#include "Main.h"
#include "ModeSelect.h"
#include "Draw.h"
#include "Touch.h"
#include "Song.h"
#include "Songs.h"
#include "Font.h"
#include "SongSelectCommon.h"
#include "SongSelect.h"
#include "SongSelectDefine.h"
#include "ThroughOption.h"

//曲選択画面関係
class SongSelect {
public:
	SongSelect(Font *font, Songs *songs);
	int Update();
	void View();
private:
	Font *f;
	SongSelectTitle *songSelectTitle; //曲選択画面タイトル
	SongSelectCover *songSelectCover; //選択中の曲
	SongSelectButton *songSelectButton; //ボタン関係
	SongSelectPop *songSelectPop; //終了用ポップアップ
	ModeSelectButton *modeSelectButton; //モード選択ボタン
	ThroughOptionButton *throughOptionButton; //通し練習オプションボタン
	Touch *touch; //サイドタッチパネル
	int scene;
	int loadFlag;
	void Load();
	void Delete();
	~SongSelect();
};

#endif