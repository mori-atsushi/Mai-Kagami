#include "Nfc.h"
#include "Main.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

#define PORT 9999		// �|�[�g�ԍ�
#define IP "127.0.0.1"	// IP�ԍ�(���[�J���z�X�g) 

void strReplace(std::string& str, const std::string& from, const std::string& to);

void Nfc::Init() 
{
	WSADATA data;
	WSAStartup(MAKEWORD(2, 0), &data);
}

char* Nfc::GetId()
{
	if (CheckHitKey(KEY_INPUT_S)) // S�L�[�i�X�L�b�v�j�������ꂽ��
		return "daichi";
	if (!NFC_FLAG) // NFC_FLAG��false��������
		return "\0";

	// �ڑ��Ɏ��s�����Ƃ��̃G���[����
	// �܂�nfc�Ď������߂Ă���1�b�Ԃ̊Ԃ�0��Ԃ�
	calledCont++;
	if (!Connect(IP, PORT) || calledCont < 10) {
		return "\0";
	}

	int recvsize;					// ��M�f�[�^��
	char recvMessage[5] = {"\0"};	// ��M�o�b�t�@
	char data[256] = { "\0" };		// ��M����ID���i�[����ϐ�
	char* p1 = data;				// ���ۂ�return����f�[�^

	// ��M
	// tcp/ip�ʐM�ł�4�o�C�g���Ƒ��M�����
	// �܂����M���������ł͊��S�Ɏ�M����Ă��Ȃ��\��������
	// �Ȃ̂ŉ��x����M���ꂽ���m�F���邱�Ƃɂ���Ċ��S�Ɏ�M������
	while (true) {
		RECVSTATUS status = Recv(
			recvMessage,		// ��M�f�[�^�i�[�p�̔z�� 
			sizeof(recvsize),	// ��M�f�[�^��
			&recvsize);			// ��M�f�[�^���̃|�C���^

		switch (status) {
		// �f�[�^�����Ă��Ȃ��Ƃ�
		case RECV_STILL:
			continue;
		// ����
		case RECV_SUCCESSED:
			strcat_s(data, sizeof(data), recvMessage);
			for (int i = 0; i < 5; i++) {
				recvMessage[i] = '\0';
			}
			continue;
		// �ؒfor�G���[
		case RECV_FAILED:
			break;
		}

		break;
	}

	// ���䕶���̍폜
	// ���������炷���߂Ƀf�[�^������Ƃ��̂ݒ��ׂ�
	if (data[0] != '\0') {
		// �����񂪃i���ɂȂ邩�z��͈͓̔��Ń��[�v
		// �m�F����Ă��鐧�䕶����stx(0x02),\r(0x0a),\n(0x0d)
		for (int i = 0; *(p1 + i) == '\0' || i < 256; i++) {
			// �܂�stx�̍폜������
			// ����͕����ɂ��̂ŃA�h���X��1�C���N�������g����
			if (*(p1 + i) == 0x02) {
				p1++;
			}
			// �c�����폜
			// ����͕����ɂ��̂Ńi���ŏ㏑������
			if (*(p1 + i) == 0x0a || *(p1 + i) == 0x0d)  {
				*(p1 + i) = '\0';
			}
		}
	}

	return p1;
}

// �ڑ�
bool Nfc::Connect(const char* Ip, u_short Port)
{
	// sockaddr_in �\���̂̃Z�b�g
	struct sockaddr_in dstAddr;
	memset(&dstAddr, 0, sizeof(dstAddr));
	dstAddr.sin_port = htons(Port);
	dstAddr.sin_family = AF_INET;
	dstAddr.sin_addr.s_addr = inet_addr(Ip);

	// �\�P�b�g�̐���
	m_DstSocket = socket(AF_INET, SOCK_STREAM, 0);

	// �ڑ�
	if (connect(m_DstSocket, (struct sockaddr *) & dstAddr, sizeof(dstAddr))
		== SOCKET_ERROR) {
		return false;
	}
	// �\�P�b�g��񓯊����[�h�ɂ���
	u_long val = 1;
	ioctlsocket(m_DstSocket, FIONBIO, &val);
	return true;
}

// ��M
RECVSTATUS Nfc::Recv(char* pData, int DataSize, int *pRecvSize) 
{
	int n = recv(m_DstSocket, pData, DataSize, 0);
	if (n < 1) {
		// �f�[�^�����Ă��Ȃ�
		if (WSAGetLastError() == WSAEWOULDBLOCK) {
			return RECV_STILL;
		// �ؒfor�G���[
		} else {
			return RECV_FAILED;
		}
	}
	*pRecvSize = n;	// ��M�f�[�^���擾
	return RECV_SUCCESSED;
}

void Nfc::reset_calledCont() { calledCont = 0; }

/**
* �����񒆂��當������������ĕʂ̕�����ɒu������
* @param str  : �u���Ώۂ̕�����B�㏑����܂��B
* @param from : ����������
* @param to   : �u����̕�����
*/
void strReplace(std::string& str, const std::string& from, const std::string& to) {
	std::string::size_type pos = 0;
	while (pos = str.find(from, pos), pos != std::string::npos) {
		str.replace(pos, from.length(), to);
		pos += to.length();
	}
}