#include "Songs.h"

Songs::Songs() {
	n = 0;
	SetUseASyncLoadFlag(FALSE);
	int file = FileRead_open("song/song.csv", FALSE);
	SetUseASyncLoadFlag(TRUE);
	char buf[3][256];
	int id = 0;
	while (FileRead_scanf(file, "%d,%[^,\n\r],%[^,\n\r],%[^\n\r]", &id, buf[0], buf[1], buf[2]) != EOF) {
		song[n] = new Song(id, buf[1], buf[2], buf[0]);
		n++;
	}
	FileRead_close(file);
}

//曲数取得
int Songs::GetSongNum() {
	return n;
}

//曲取得
Song *Songs::GetSong(int x) {
	return song[x];
}
Song::Song(const int id, const char *title, const char *artist, const char *folder) {
	char cover[256], movie[256];
	strcpy_s(Song::title, sizeof(Song::title), title);
	strcpy_s(Song::artist, sizeof(Song::artist), artist);
	sprintf_s(cover, sizeof(cover), "song/%s/cover.jpg", folder);
	sprintf_s(music, sizeof(music), "song/%s/music.mp3", folder);
	sprintf_s(movie, sizeof(movie), "song/%s/movie.ogv", folder);
	Song::id = id;

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

//カバー画像取得
MyDrawGraph *Song::GetSongCover() {
	return coverGraph;
}

//動画取得
MyDrawMovie *Song::GetSongMovie() {
	return danceMovie;
}