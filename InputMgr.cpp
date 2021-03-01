#include "DXUT.h"
#include "InputMgr.h"

bool InputMgr::AnyUp(BYTE key)
{
	for (size_t i = 0; i < 256; i++)
		if (Up(i))
			return true;
	return false;
}

bool InputMgr::AnyPress(BYTE key)
{
	for (size_t i = 0; i < 256; i++)
		if (Press(i))
			return true;
	return false;
}

bool InputMgr::AnyDown(BYTE key)
{
	for (size_t i = 0; i < 256; i++)
		if (Down(i))
			return true;
	return false;
}

bool InputMgr::Up(BYTE key)
{
	return !now[key] && prev[key];
}

bool InputMgr::Press(BYTE key)
{
	return now[key] && prev[key];
}

bool InputMgr::Down(BYTE key)
{
	return now[key] && !prev[key];
}

void InputMgr::Update()
{
	memcpy(prev, now, sizeof(now));

	for (size_t i = 0; i < 256; i++)
	{
		now[i] = false;
		if (GetAsyncKeyState(i))
			now[i] = true;
	}
}
