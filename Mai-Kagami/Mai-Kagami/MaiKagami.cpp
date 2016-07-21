#include "MaiKagami.h"

MaiKagami::MaiKagami() {
	scene = START; //ƒV[ƒ“‰Šú‰»
}

void MaiKagami::View() {
	//ŒvZ
	switch (scene) {
	case TOP:
		scene = top.Update();
		break;
	case LOGIN:
		login.Update();
//		scene = songSelect.Load();
		break;
	}

	//•`‰æ
	switch (scene) {
	case TOP:
		top.View();
		break;
	case LOGIN:
		login.View();
		break;
	case SONG_SELECT:
		break;
	}
}