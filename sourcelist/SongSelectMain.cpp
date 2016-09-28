#include "SongSelectMain.h"

SongSelect::SongSelect(Font *font, Touch *touch, Songs *songs, User *user) {
	songSelectTitle = new SongSelectTitle(font); // �ȑI����ʃ^�C�g��������
	songSelectButton = new SongSelectButton(font, touch);
	songInformation = new SongInformation(font, songs, touch, user); // �I�𒆂̋ȏ�����
	songSelectPop = new SongSelectPop(font, touch);
	modeSelectButton = new ModeSelectButton(font, touch); // ���[�h�I���{�^��������
	throughOptionButton = new ThroughOptionButton(font, songs, touch); // �ʂ����K�I�v�V�����{�^��������
	partOptionButton = new PartOptionButton(font, songs, touch); // �������K�I�v�V�����{�^��������
}

// �ȑI����ʃ��[�h
void SongSelect::ContentLoad() {
	songInformation->Load(); // �J�o�[�摜���[�h
	songSelectTitle->Load(); // �^�C�g�����[�h
	songSelectPop->Load();	 // �I���p�|�b�v�A�b�v���[�h
	songSelectButton->Load(); // �ȑI���{�^�����[�h
	modeSelectButton->Load(); // ���[�h�I���{�^�����[�h
	throughOptionButton->Load(); // �ʂ����K�I�v�V������ʃ{�^�����[�h
	partOptionButton->Load(); // �������K�I�v�V������ʃ{�^�����[�h
}

void SongSelect::SetScene(const int scene) {
	this->scene = scene;
}

// �ȑI����ʏ�ʐ؂�ւ�
MainScene SongSelect::Switch(const MainScene scene) {
	switch (this->scene)
	{
	case BACK:
		this->scene = songSelectPop->Switch(this->scene);
		break;
	case MAIN:
		this->scene = songSelectButton->Switch(this->scene);
		break;
	case MODE:
		this->scene = modeSelectButton->Switch(this->scene);
		break;
	case OPTION1:
		this->scene = throughOptionButton->Switch(this->scene);
		break;
	case OPTION2:
	case OPTION2_PART:
	case OPTION2_SPEED:
		this->scene = partOptionButton->Switch(this->scene);
		break;
	}

	switch (this->scene)
	{
	case BACK_TOP:
		Delete();
		return TOP;
	case NEXT1:
		Delete();
		return THROUGH;
	case NEXT2:
		Delete();
		return PART;
	default:
		return SONG_SELECT;
	}
}

// �ȑI����ʌv�Z
void SongSelect::ContentUpdate() {
	if (nowScene == SONG_SELECT) {
		Load();
		songInformation->Update(scene);
		songSelectTitle->Update(scene);
		songSelectPop->Update(scene);
		songSelectButton->Update(scene);
		modeSelectButton->Update(scene);
		throughOptionButton->Update(scene);
		partOptionButton->Update(scene);
	}
}

// �ȑI����ʕ\��
void SongSelect::ContentView() {
	songInformation->View(); // �J�o�[�\��
	songSelectTitle->View(); // �^�C�g���\��
	songSelectPop->View(); // �I���p�|�b�v�A�b�v�\��
	songSelectButton->View(); // �ȑI���{�^���\��
	modeSelectButton->View(); // ���[�h�I���{�^���\��
	throughOptionButton->View(); // �ʂ����K�I�v�V������ʃ{�^���\��
	partOptionButton->View(); // �������K�I�v�V������ʃ{�^���\��
}

void SongSelect::ContentDelete() {
	songInformation->Delete(); // �J�o�[�폜
	songSelectTitle->Delete(); // �^�C�g���폜
	songSelectPop->Delete();	 // �I���p�|�b�v�A�b�v�폜
	songSelectButton->Delete(); // �ȑI���{�^���폜
	modeSelectButton->Delete(); // ���[�h�I���{�^���폜
	throughOptionButton->Delete(); // �ʂ����K�I�v�V������ʃ{�^���폜
	partOptionButton->Delete(); // �������K�I�v�V������ʃ{�^���폜
}

SongSelect::~SongSelect() {
	delete songInformation;
	delete songSelectButton;
	delete songSelectTitle;
	delete songSelectPop;
	delete throughOptionButton;
	delete partOptionButton;
}