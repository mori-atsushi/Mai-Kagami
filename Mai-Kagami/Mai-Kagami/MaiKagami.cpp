#include "MaiKagami.h"

MaiKagami::MaiKagami() {
	scene = START; //ƒV[ƒ“‰Šú‰»
	login.Load();
}

//‘S‘Ì‚ÌŒvZ‚Æ•`‰æ
void MaiKagami::View() {
	//ŒvZ
	switch (scene) {
	case TOP:
		if(top.Load())
			scene = top.Update();
		break;
	case LOGIN:
		login.Update();
		scene = songSelect.Load();
		break;
	case SONG_SELECT:
		scene = songSelect.Update();
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
		songSelect.View();
		break;
	}
}