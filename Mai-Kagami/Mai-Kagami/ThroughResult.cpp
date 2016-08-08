#include "ThroughResult.h"

ThroughResult::ThroughResult(Font *font) {
	title = new MyDrawTextLine(font, "Ì“_Œ‹‰Ê", WIDTH * 0.5, HEIGHT * 0.2, 1, 60, WIDTH * 0.5, 4);
}

void ThroughResult::View() {
	title->View();
}

ThroughResult::~ThroughResult() {
	delete title;
}