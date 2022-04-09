#pragma once

#include <windows.h>
#include <afxstr.h>
#include "Connerctor.h"

#define MAXKEY 100	//�����������
#define MAXTYPE 20	//�������������

//ConnerctorState
#define CS_OPERATION	0x01	//���������
#define CS_SUSPEN		0x02	//����ֹͣ��

//ConnerctedKeyType
#define TE_MOUSECLICK	0x03	//�����
#define TE_MOUSEMOVE	0x04	//����ƶ�
#define TE_STRING		0x05	//�����ַ�
#define TE_HOTKEY		0x06	//�����ȼ�
#define TE_SLEEP		0x07	//������ͣ
#define TE_EMPTY		0x08	//�����

#define ERROR			0xff	//�û���������д���

typedef int State;		//��¼��ʱ״̬
typedef int Type;		//��¼��������
typedef int Content;	//��¼��������
typedef int Time;		//��¼ʱ��

struct ConnerctedKey {
	Type KeyType;			//�����������
	Content KeyContent1;	//�������ݵĵ�һ��ֵ������x���ȼ�ID��
	Content KeyContent2;	//�������ݵĵڶ���ֵ������y���ȼ����ݣ�
};

struct ConnerctorInfo {
	//��д�����
	ConnerctedKey connerctedKey[MAXKEY];	//ÿ����������� ��һ����
	Time time;								//������
	Time RandomScale;						//����̶�ʱ��
	int KeyQuantity;						//��������
	//����д�����
	State ConnerctorState;					//����״̬
};