#include "Song.h"

//パート情報
SongPart::SongPart(const int flame, const char *name) {
	SongPart::flame = flame;
	strcpy_s(SongPart::name, sizeof(SongPart::name), name);

}

//フレーム数取得
int SongPart::GetFlame() {
	return flame;
}

//パート名取得
char *SongPart::GetName() {
	return name;
}

Song::Song(const int id, const char *title, const char *artist, const char *folder) {
	char cover[256], movie[256];
	strcpy_s(Song::title, sizeof(Song::title), title); //タイトル
	strcpy_s(Song::artist, sizeof(Song::artist), artist); //アーティスト
	strcpy_s(Song::folder, sizeof(Song::folder), folder); //フォルダ
	sprintf_s(cover, sizeof(cover), "song/%s/cover.jpg", folder); //カバー画像
	sprintf_s(music, sizeof(music), "song/%s/music.mp3", folder); //音楽
	sprintf_s(movie, sizeof(movie), "song/%s/movie.ogv", folder); //動画
	Song::id = id;
	n = new int();

	coverGraph = new MyDrawGraph(cover);
	danceMovie = new MyDrawMovie(movie);
}

//曲名取得
char *Song::GetSongTitle() {
	return title;
}

//曲名取得
char *Song::GetSongArtist() {
	return artist;
}

//現在の位置IDを取得
int Song::GetNow() {
	return *n;
}

//位置IDをセット
void Song::SetNow(const int n) {
	*Song::n = n;
}

//動画の再生スピードを変更
void Song::ChangeSpeed(int num) {
	const double s[6] = { 1.0, 0.9, 0.8, 0.7, 0.6, 0.5 };
	static int x = 0;
	if (num == 1 && x > 0) {
		x -= 1;
		danceMovie->ChangeSpeed(s[x]);
	}
	if (num == -1 && x < 5) {
		x += 1;
		danceMovie->ChangeSpeed(s[x]);
	}
}

//パート情報をロード
void Song::LoadPart() {
	char part[256];
	sprintf_s(part, sizeof(part), "song/%s/part.csv", folder);
	SetUseASyncLoadFlag(FALSE);
	int file = FileRead_open(part, FALSE);
	SetUseASyncLoadFlag(TRUE);
	char buf[256];
	int flame;
	songPartNum = 0;
	while (FileRead_scanf(file, "%d,%[^\n\r]", &flame, buf) != EOF) {
		songPart[songPartNum] = new SongPart(flame, buf);
		songPartNum++;
	}
}

//パート情報取得
SongPart *Song::GetPart(int num) {
	return songPart[num];
}

//パート数取得
int Song::GetPartNum() {
	return songPartNum;
}