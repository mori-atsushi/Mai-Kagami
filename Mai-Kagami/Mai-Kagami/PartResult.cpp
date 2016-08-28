#include "PartResult.h"

PartResult::PartResult(Font *font, Songs *songs, Touch *touch) {
	this->songs = songs;
	title = new MyDrawTextLine(font, "Ì“_Œ‹‰Ê", WIDTH * 0.5, HEIGHT * 0.15, 1, 60, WIDTH * 0.5, 4);
	button = new CircleButton2(font, touch, "ŽŸ‚Ö", 4);
}

void PartResult::Load() {
	song = songs->GetSong(songs->GetNowSong());
	song->coverGraph->Load();
	song->coverGraph->ChangePos(WIDTH * 0.3, HEIGHT * 0.26);
	song->drawSongTitle->ChangePos(WIDTH * 0.6, HEIGHT * 0.24);
}

int PartResult::Switch(const int scene) {
	return scene;
}

void PartResult::ContentUpdate() {
	if (nowScene == PART_RESULT_TOP)
		viewFlag = TRUE;
	else
		viewFlag = FALSE;
}

void PartResult::ContentView() {
	title->View();
	button->View();
	song->coverGraph->View();
	song->drawSongTitle->View();
}

PartResult::~PartResult() {
	delete title;
	delete button;
}