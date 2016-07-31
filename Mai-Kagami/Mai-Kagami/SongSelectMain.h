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

//曲選択画面関係
class SongSelect {
public:
	SongSelect(Font *font, Touch *touch, Songs *songs);
	int Update();
	void View();
	~SongSelect();
private:
	Font *f;
	SongSelectTitle *songSelectTitle; //曲選択画面タイトル
	SongInformation *songInformation; //選択中の曲
	SongSelectButton *songSelectButton; //ボタン関係
	SongSelectPop *songSelectPop; //終了用ポップアップ
	ModeSelectButton *modeSelectButton; //モード選択ボタン
	ThroughOptionButton *throughOptionButton; //通し練習オプションボタン
	Touch *touch; //サイドタッチパネル
	int scene;
	int loadFlag;
	void Load();
	void Delete();
};

#endif