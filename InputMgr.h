#pragma once
class InputMgr :
	public singletone<InputMgr>
{
public:
	InputMgr() { ; };
	~InputMgr() { ; };

	bool AnyUp(BYTE key);
	bool AnyPress(BYTE key);
	bool AnyDown(BYTE key);

	bool Up(BYTE key);
	bool Press(BYTE key);
	bool Down(BYTE key);

	void Update();

	bool now[256];
	bool prev[256];
};

#define INPUT InputMgr::Get()