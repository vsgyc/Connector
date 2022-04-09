#pragma once

#include <windows.h>
#include <afxstr.h>
#include "Connerctor.h"

#define MAXKEY 100	//最大连点数量
#define MAXTYPE 20	//最大连点类型数

//ConnerctorState
#define CS_OPERATION	0x01	//连点进行中
#define CS_SUSPEN		0x02	//连点停止中

//ConnerctedKeyType
#define TE_MOUSECLICK	0x03	//鼠标点击
#define TE_MOUSEMOVE	0x04	//鼠标移动
#define TE_STRING		0x05	//连点字符
#define TE_HOTKEY		0x06	//连点热键
#define TE_SLEEP		0x07	//连点暂停
#define TE_EMPTY		0x08	//连点空

#define ERROR			0xff	//用户输入或运行错误

typedef int State;		//记录此时状态
typedef int Type;		//记录连点类型
typedef int Content;	//记录连点内容
typedef int Time;		//记录时间

struct ConnerctedKey {
	Type KeyType;			//连点键的类型
	Content KeyContent1;	//连点内容的第一个值（坐标x，热键ID）
	Content KeyContent2;	//连点内容的第二个值（坐标y，热键内容）
};

struct ConnerctorInfo {
	//可写入磁盘
	ConnerctedKey connerctedKey[MAXKEY];	//每次连点的内容 从一计数
	Time time;								//连点间隔
	Time RandomScale;						//随机刻度时间
	int KeyQuantity;						//连点数量
	//不可写入磁盘
	State ConnerctorState;					//连点状态
};