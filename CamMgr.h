#pragma once
class CamMgr :
	public singletone<CamMgr>
{
public:
	CamMgr();
	~CamMgr() { ; };

	void Update();
	void Reset();
	void Apply();

	M pro, view;
	V2 pos, size;
	V3 scale;
};

#define CAM CamMgr::Get()