#ifndef __LOGIN_H_INCLUDED__
#define __LOGIN_H_INCLUDED__

//履歴
class SongHistory {
public:
	void Set(const int history[2]); //履歴セット
	void Get(int *history[2]); //履歴取得
private:
	int history[2] = {-1, -1}; //曲ID,
};

//ログイン
class Login {
public:
	Login();
	void LoadHistory(const char *userId); //履歴ロード
	void GetHistory(const int songId, int *history[2]); //履歴取得
	~Login();
private:
	SongHistory *songHistory[256];
};

#endif