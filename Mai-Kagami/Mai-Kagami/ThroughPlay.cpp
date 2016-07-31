#include "ThroughPlay.h"

ThroughPlay::ThroughPlay(Song *song) {
	ThroughPlay::song = song;
}

void ThroughPlay::View() {
	song->danceMovie->ChangeEx(2.4);
	song->danceMovie->ChangePos(WIDTH * 0.5, HEIGHT * 0.5);
	song->danceMovie->View();
}

ThroughPlay::~ThroughPlay() {

}