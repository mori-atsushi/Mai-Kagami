#include "Song.h"

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

//‹È–¼Žæ“¾
char *Song::GetSongTitle() {
	return title;
}

//‹È–¼Žæ“¾
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

SongPart::SongPart(const int flame, const char *name) {
	SongPart::flame = flame;
	SongPart::name = name;
}