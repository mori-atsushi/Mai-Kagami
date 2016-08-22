#ifndef __LOGIN_H_INCLUDED__
#define __LOGIN_H_INCLUDED__

//ð
class SongHistory {
public:
	void Set(const int history[2]); //ðZbg
	void Get(int *history[2]); //ðæ¾
private:
	int history[2] = {-1, -1}; //ÈID,
};

//OC
class Login {
public:
	Login();
	void LoadHistory(const char *userId); //ð[h
	void GetHistory(const int songId, int *history[2]); //ðæ¾
	~Login();
private:
	SongHistory *songHistory[256];
};

#endif