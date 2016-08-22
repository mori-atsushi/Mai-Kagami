#include "Nfc.h"
#include <stdio.h>
#include<iostream>
#include<fstream>

#define PORT 9999		//�|�[�g�ԍ�
#define IP "127.0.0.1"	//IP�ԍ�(���[�J���z�X�g) 

void Nfc::Init() 
{
	WSADATA data;
	WSAStartup(MAKEWORD(2, 0), &data);
}

char* Nfc::GetId()
{
	int recvsize;				//��M�f�[�^��
	char recvMessage[5] = {};	//��M�o�b�t�@
	char data[256] = "\0";		//��M����ID���i�[����ϐ�
	int result = 0;				//ID��int�^�ɃL���X�g��������
	int cont = 0;

	//�Ăяo���ꂽ�񐔂��J�E���g
	calledCont++;

	//�ڑ��Ɏ��s�����Ƃ��̃G���[����
	//�܂�nfc�Ď������߂Ă���1�b�Ԃ̊Ԃ�0��Ԃ�
	if (!Connect(IP, PORT) || calledCont < 10) {
		printfDx("%d ", calledCont);
		return data;
	}

	//��M
	//tcp/ip�ʐM�ł�4�o�C�g���Ƒ��M�����
	//�܂����M���������ł͊��S�Ɏ�M����Ă��Ȃ��\��������
	//�Ȃ̂ŉ��x����M���ꂽ���m�F���邱�Ƃɂ���Ċ��S�Ɏ�M������
	while (true) {
		RECVSTATUS status = Recv(
			recvMessage,		//��M�f�[�^�i�[�p�̔z�� 
			sizeof(recvsize),	//��M�f�[�^��
			&recvsize);			//��M�f�[�^���̃|�C���^

		switch (status) {
		//�f�[�^�����Ă��Ȃ��Ƃ�
		case RECV_STILL:
			printfDx("0 ");
			continue;
		//����
		case RECV_SUCCESSED:
			printfDx("1 ");
			strcat_s(data, sizeof(data), recvMessage);
			printfDx(data);
			continue;
		//�ؒfor�G���[
		case RECV_FAILED:
			printfDx("2 ");
			break;
		}
		break;
	}

	return data;
}

//�ڑ�
bool Nfc::Connect(const char* Ip, u_short Port)
{
	//sockaddr_in �\���̂̃Z�b�g
	struct sockaddr_in dstAddr;
	memset(&dstAddr, 0, sizeof(dstAddr));
	dstAddr.sin_port = htons(Port);
	dstAddr.sin_family = AF_INET;
	dstAddr.sin_addr.s_addr = inet_addr(Ip);

	//�\�P�b�g�̐���
	m_DstSocket = socket(AF_INET, SOCK_STREAM, 0);

	//�ڑ�
	if (connect(m_DstSocket, (struct sockaddr *) & dstAddr, sizeof(dstAddr))
		== SOCKET_ERROR) {
		return false;
	}
	//�\�P�b�g��񓯊����[�h�ɂ���
	u_long val = 1;
	ioctlsocket(m_DstSocket, FIONBIO, &val);
	return true;
}

//��M
RECVSTATUS Nfc::Recv(char* pData, int DataSize, int *pRecvSize) 
{
	int n = recv(m_DstSocket, pData, DataSize, 0);
	if (n < 1) {
		//�f�[�^�����Ă��Ȃ�
		if (WSAGetLastError() == WSAEWOULDBLOCK) {
			return RECV_STILL;
		//�ؒfor�G���[
		} else {
			return RECV_FAILED;
		}
	}
	*pRecvSize = n;	//��M�f�[�^���擾
	return RECV_SUCCESSED;
}

void Nfc::reset_calledCont() { calledCont = 0; }