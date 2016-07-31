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

//�Ȑ��擾
int Songs::GetSongNum() {
	return n;
}

//�Ȏ擾
Song *Songs::GetSong(int x) {
	return song[x];
}

//���ݑI������Ă���Ȏ擾
int Songs::GetNowSong() {
	for (int i = 0; i < n; i++) {
		if (song[i]->GetNow() == 0) {
			return i;
		}
	}
}

Song::Song(const int id, const char *title, const char *artist, const char *folder) {
	char cover[256], movie[256];
	strcpy_s(Song::title, sizeof(Song::title), title);
	strcpy_s(Song::artist, sizeof(Song::artist), artist);
	sprintf_s(cover, sizeof(cover), "song/%s/cover.jpg", folder);
	sprintf_s(music, sizeof(music), "song/%s/music.mp3", folder);
	sprintf_s(movie, sizeof(movie), "song/%s/movie.ogv", folder);
	Song::id = id;
	n = new int();

	coverGraph = new MyDrawGraph(cover);
	danceMovie = new MyDrawMovie(movie);
}

//�Ȗ��擾
char *Song::GetSongTitle() {
	return title;
}

//�Ȗ��擾
char *Song::GetSongArtist() {
	return artist;
}

int Song::GetNow() {
	return *n;
}

void Song::SetNow(const int n) {
	*Song::n = n;
}

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