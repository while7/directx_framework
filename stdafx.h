#pragma once
#pragma comment (lib,"dsound.lib")
#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <functional>

using namespace std;
using V2 = D3DXVECTOR2;
using V3 = D3DXVECTOR3;
using M = D3DXMATRIX;

const int WINX = 1280;
const int WINY = 720;
const V2 CENTER = { WINX / 2,WINY / 2 };
static bool WIN = true;

static float time_scale = 1;

enum Tag
{
	TAG_BEGIN = -1,
	UI,
	MOUSE,
	P,
	PATK,
	E,
	EATK,
	TAG_END,
};

#define DEVICE DXUTGetD3D9Device()
#define DT DXUTGetElapsedTime() * time_scale
#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif // _DEBUG

#include "SDKsound.h"
#include "SDKwavefile.h"

#include "singletone.h"
#include "CamMgr.h"
#include "ImgMgr.h"
#include "ObjMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "InputMgr.h"
#include "TimeMgr.h"

