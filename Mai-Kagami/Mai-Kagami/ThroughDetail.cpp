#include "ThroughDetail.h"

ThroughDetail::ThroughDetail(Font *font) {
	title = new MyDrawTextLine(font, "Ì“_Œ‹‰Ê", WIDTH * 0.5, HEIGHT * 0.5, 1, 40, WIDTH * 0.5, 4);
}

void ThroughDetail::View() {
	title->View();
}

ThroughDetail::~ThroughDetail() {
	delete title;
}