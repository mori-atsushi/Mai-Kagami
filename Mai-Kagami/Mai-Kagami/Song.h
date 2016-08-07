#ifndef __SONG_H_INCLUDED__
#define __SONG_H_INCLUDED__

#include "DxLib.h"
#include "Draw.h"
#include "DrawGraph.h"
#include "DrawText.h"
#include "Font.h"

//曲名、アーティスト情報
class DrawSongTitle : public Draw {
public:
	DrawSongTitle(Font *font, const char *title, const char *artist);
	void ChangePos(const float x, const float y);
	void View();
	~DrawSongTitle();
private:
	MyDrawTextLine *songTitle; //曲名表示
	MyDrawText *songArtist; //アーティスト表示
};

//パート情報
class SongPart {
public:
	SongPart(const int flame, const char *name);
	int GetFlame(); //フレーム数取得
	char *GetName(); //パート名取得
private:
	int flame;
	char name[256]; //文字
};

class Song {
public:
	Song(Font *font, const int id, const char *title, const char *artist, const char *folder);
	int GetNow(); //現在の位置IDを取得
	void SetNow(const int n); //位置IDをセット
	void ChangeSpeed(int num); //動画の再生速度変更
	void LoadPart(); //パート情報ロード
	SongPart *GetPart(int num); //パート情報取得
	int GetPartNum(); //パート数取得
	DrawSongTitle *drawSongTitle; //曲名、アーティスト表示
	MyDrawGraph *coverGraph; //カバー画像
	MyDrawMovie *danceMovie; //動画
protected:
	char music[256], folder[256]; //音楽ファイル、フォルダ
private:
	int id, *n, songPartNum; //ID、現在の番号, 曲数
	SongPart *songPart[256];
};

#endif