#include "SongSelectMain.h"

SongSelect::SongSelect(Font *font, Touch *touch, Songs *songs) {
	songSelectTitle = new SongSelectTitle(font); //曲選択画面タイトル初期化
	songSelectButton = new SongSelectButton(font, touch);
	songInformation = new SongInformation(font, songs, touch); //選択中の曲初期化
	songSelectPop = new SongSelectPop(font, touch);
	modeSelectButton = new ModeSelectButton(font, touch); //モード選択ボタン初期化
	throughOptionButton = new ThroughOptionButton(font, songs, touch); //通し練習オプションボタン初期化
}

//曲選択画面ロード
void SongSelect::ContentLoad() {
	songInformation->Load(); //カバー画像ロード
	songSelectTitle->Load(); //タイトルロード
	songSelectPop->Load();	 //終了用ポップアップロード
	songSelectButton->Load(); //曲選択ボタンロード
	modeSelectButton->Load(); //モード選択ボタンロード
	throughOptionButton->Load(); //オプション画面ボタンロード
	scene = MAIN;
}

//曲選択画面場面切り替え
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
	}

	switch (this->scene)
	{
	case BACK_TOP:
		Delete();
		return TOP;
	case NEXT:
		Delete();
		return THROUGH;
	default:
		return SONG_SELECT;
	}
}

//曲選択画面計算
void SongSelect::ContentUpdate() {
	if (nowScene == SONG_SELECT) {
		Load();
		songInformation->Update(scene);
		songSelectTitle->Update(scene);
		songSelectPop->Update(scene);
		songSelectButton->Update(scene);
		modeSelectButton->Update(scene);
		throughOptionButton->Update(scene);
	}
}

//曲選択画面表示
void SongSelect::ContentView() {
	songInformation->View(); //カバー表示
	songSelectTitle->View(); //タイトル表示
	songSelectPop->View(); //終了用ポップアップ表示
	songSelectButton->View(); //曲選択ボタン表示
	modeSelectButton->View(); //モード選択ボタン表示
	throughOptionButton->View(); //オプション画面ボタン表示
}

void SongSelect::ContentDelete() {
	songInformation->Delete(); //カバー削除
	songSelectTitle->Delete(); //タイトル削除
	songSelectPop->Delete();	 //終了用ポップアップ削除
	songSelectButton->Delete(); //曲選択ボタン削除
	modeSelectButton->Delete(); //モード選択ボタン削除
	throughOptionButton->Delete(); //オプション画面ボタン削除
}

SongSelect::~SongSelect() {
	delete songInformation;
	delete songSelectButton;
	delete songSelectTitle;
	delete songSelectPop;
	delete throughOptionButton;
}