#ifndef __SERIAL_H_INCLUDED__
#define __SERIAL_H_INCLUDED__

#include "DxLib.h"

class Serial {
public:
	Serial();
	char *GetData();
	~Serial();
private:
	HANDLE serialPort;
	bool Ret;
};


#endif