#include "ThroughDetail.h"

ThroughDetail::ThroughDetail(Font *font) {
	title = new DrawTitle(font, "Ì“_Œ‹‰Ê");
	button = new CircleButton2(font, "ŽŸ‚Ö", 4);
}

void ThroughDetail::View() {
	title->View();
	button->View();
}

ThroughDetail::~ThroughDetail() {
	delete title;
	delete button;
}