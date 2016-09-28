#include "SongSelectCommon.h"

// �ȑI����ʃ^�C�g�����[�h
SongSelectTitle::SongSelectTitle(Font *font) {
	title = new DrawTitle(font, "");
	subTitle = new DrawSubtitle(font, "");
}

// �ȑI����ʃ^�C�g���v�Z
void SongSelectTitle::ContentUpdate() {
	static int lastScene = -100;
	if (lastScene != nowScene) {
		lastScene = nowScene;
		switch (nowScene)
		{
		case MODE:
			title->ChangeText("Mode Select");
			subTitle->SetViewFlag(FALSE);
			break;
		case OPTION1:
			title->ChangeText("Option");
			subTitle->ChangeText("�ʂ����K���[�h");
			subTitle->SetViewFlag(TRUE);
			subTitle->ChangeColor("Blue");
			break;
		case OPTION2:
		case OPTION2_PART:
		case OPTION2_SPEED:
			title->ChangeText("Option");
			subTitle->ChangeText("�������K���[�h");
			subTitle->SetViewFlag(TRUE);
			subTitle->ChangeColor("Yellow");
			break;
		default:
			title->ChangeText("Song Select");
			subTitle->SetViewFlag(FALSE);
			break;
		}
	}
}

// �ȑI����ʃ^�C�g���\��
void SongSelectTitle::ContentView() {
	title->View(); // �e�L�X�g�\��
	subTitle->View(); // �e�L�X�g�\��
}

SongSelectTitle::~SongSelectTitle() {
	delete title;
	delete subTitle;
}

// �ȑI����ʃJ�o�[�摜������
SongInformation::SongInformation(Font *font, Songs *songs, Touch *touch, User *user) {
	this->songs = songs;
	this->touch = touch;
	this->user = user;
	n = songs->GetSongNum();
	for (int i = 0; i < n; i++) {
		songCover[i] = new SongSelectCover(font, songs->GetSong(i), i);
		// songCover[i]->Change(0, n);  // Update�ɓ�����������v��Ȃ��Ȃ��� Jaity
	}

	float x = HEIGHT * 0.35;
	myDrawBox = new MyDrawBox(WIDTH * 0.5, HEIGHT * 0.5, 170, 1000);
	myDrawBox->SetAlpha(90); // �����x�w��
	grad[0] = new MyDrawGraph(WIDTH * 0.5, HEIGHT * 0.22-30, "img/grad1.png");
	grad[1] = new MyDrawGraph(WIDTH * 0.5, HEIGHT * 0.8, "img/grad2.png");
// 	box = new MyDrawGraph(WIDTH * 0.5, x, "img/box.png");
	songLast[0] = new MyDrawText(font, "�O��@�F --�_", WIDTH * 0.75, HEIGHT * 0.36, 0, 24); // �e�L�X�g������
	songLast[1] = new MyDrawText(font, "�O�X��F --�_", WIDTH * 0.75, HEIGHT * 0.385, 0, 24); // �e�L�X�g������
}


void SongInformation::Load() {
	songs->LoadHistory(user->GetUserId());
	for (int i = 0; i < 2; i++)
		grad[i]->Load();
	for (int i = 0; i < n; i++)
		songCover[i]->Load(n);
	nowSong = songCover[songs->GetNowSong()];
	nowSong->drawSongTitle->ChangePos(WIDTH * 0.79, HEIGHT * 0.3);
	viewFlag = TRUE;
}

void SongInformation::ContentUpdate() {
	int direct = 0;  // increase or decrease of IDs  Jaity
	static int lastScene = nowScene;
	int *last[2] = { new int(), new int() }; // ����ۑ��p

	switch (nowScene)
	{
	case MAIN:
		if (nowScene == lastScene) {
			// �{�^��0�������ꂽ��
			if(touch->Input2(0)) {
				direct = 1;  // Jaity
				for (int i = 0; i < n; i++) {
					songCover[i]->coverGraph->Reset();
					songCover[i]->coverWhite->Reset();
				}
			}

			// �{�^��2�������ꂽ��
			if(touch->Input2(2)) {
				direct = -1;  // Jaity
				for (int i = 0; i < n; i++) {
					songCover[i]->coverGraph->Reset();
					songCover[i]->coverWhite->Reset();
				}
			}
		}

		for (int i = 0; i < n; i++)
			songCover[i]->Update(direct, n);  // Update�Ɉ����ǉ� Jaity

		nowSong = songCover[songs->GetNowSong()];
		nowSong->drawSongTitle->ChangePos(WIDTH * 0.79, HEIGHT * 0.3);
		nowSong->songHistory->Get(last);
		for (int i = 0; i < 2; i++) {
			char str[256];
			char text[2][10] = { "�O��@", "�O�X��" };
			if (*last[i] == -1)
				sprintf_s(str, sizeof(str), "%s�F --�_", text[i]);
			else
				sprintf_s(str, sizeof(str), "%s�F%3d�_", text[i], *last[i]);
			songLast[i]->ChangeText(str);
		}

		if(lastScene == MODE)
			nowSong->danceMovie->Release();
		break;
	case MODE:
		if (lastScene != MODE) {
			if (lastScene == OPTION1) {
				nowSong->danceMovie->Seek(0);
			}
			else {
				nowSong->danceMovie->Load();
				nowSong->LoadPart();
				nowSong->danceMovie->ChangeSpeed(nowSong->danceMovie->GetSpeed());
			}
		}
		break;
	case OPTION1:
		if(lastScene != OPTION1)
			nowSong->danceMovie->Seek(0);
		break;
	}
	lastScene = nowScene;
}

// �ȑI����ʃJ�o�[�摜�\��
void SongInformation::ContentView() {
	nowSong->drawSongTitle->View();
	for (int i = 0; i < 2; i++) {
		songLast[i]->View();
	}
	switch (nowScene)
	{
	case BACK:
	case MAIN:
		myDrawBox->View();
// 		box->View();
		for (int i = 0; i < n; i++)
			songCover[i]->Draw(nowScene);
		for (int i = 0; i < 2; i++)
			grad[i]->View();
		break;
	case MODE:
	case OPTION1:
	case OPTION2:
	case OPTION2_PART:
	case OPTION2_SPEED:
		nowSong->Draw(nowScene);
		break;
	}
}

void SongInformation::Delete() {
	for (int i = 0; i < 2; i++)
		grad[i]->Release();
	for (int i = 0; i < n; i++)
		songCover[i]->Release();
	SubScene::Delete();
}

SongInformation::~SongInformation() {
// 	delete box;
	delete myDrawBox;
	for (int i = 0; i < n; i++)
		delete songCover[i];
	for (int i = 0; i < 2; i++) {
		delete grad[i];
	}
}