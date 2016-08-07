#include "Songs.h"

Songs::Songs(Font *font) {
	n = 0;
	SetUseASyncLoadFlag(FALSE);
	int file = FileRead_open("song/song.csv", FALSE);
	SetUseASyncLoadFlag(TRUE);
	char buf[3][256];
	int id = 0;
	while (FileRead_scanf(file, "%d,%[^,\n\r],%[^,\n\r],%[^\n\r]", &id, buf[0], buf[1], buf[2]) != EOF) {
		song[n] = new Song(font, id, buf[1], buf[2], buf[0]);
		n++;
	}
	FileRead_close(file);
}

//‹È”æ“¾
int Songs::GetSongNum() {
	return n;
}

//‹Èæ“¾
Song *Songs::GetSong(int x) {
	return song[x];
}

//Œ»İ‘I‘ğ‚³‚ê‚Ä‚¢‚é‹Èæ“¾
int Songs::GetNowSong() {
	for (int i = 0; i < n; i++) {
		if (song[i]->GetNow() == 0)
			return i;
	}
	return 0;
}