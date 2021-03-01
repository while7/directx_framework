#include "DXUT.h"
#include "ObjMgr.h"

ObjMgr::ObjMgr()
	:col_layer
	{
	//   1,2,3,4,5,6
		{0,1,0,0,0,0}, //1  UI,
		{0,0,0,0,0,0}, //2  MOUSE,
		{0,0,0,0,0,1}, //3  P,
		{0,0,0,0,0,0}, //4  PATK,
		{0,0,0,1,0,0}, //5  E,
		{0,0,0,0,0,0}, //6  EATK,
	}
{
}

ObjMgr::~ObjMgr()
{
	for (auto& iter : objs)
	{
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}
	objs.clear();
}

void ObjMgr::Update()
{
	for (auto& iter = objs.begin(); iter != objs.end(); ++iter)
	{
		if (!iter->second || iter->second->flag || IsMapOut(iter->second))
		{
			col_list.remove(iter->second->main_col);
			iter->second->Release();
			SAFE_DELETE(iter->second);
			iter = objs.erase(iter);
		}
		else
		{
			iter->second->Update();
		}
	}
	for (auto& iter : col_list)
		ColChk(iter);
}

void ObjMgr::ColChk(Col* p)
{
	for (auto& iter : col_list)
	{
		if (!iter) { col_list.remove(iter); }
		else if (!iter->flag || !p->flag) { ; }
		else if (col_layer[iter->tag][p->tag])
		{
			RECT rt;
			if (IntersectRect(&rt, &iter->GetRECT(), &p->GetRECT()))
				iter->owner->Stay(p);
			else
				iter->owner->Exit(p);
		}
	}
}

void ObjMgr::Render()
{
	for (auto& iter : objs)
		iter.second->Render();
}

void ObjMgr::Release()
{
	for (auto& iter : objs)
		iter.second->Release();
}

void ObjMgr::Add(Obj* p, const string& key)
{
	if (p && objs.find(key) == objs.end())
	{
		p->Init();
		objs[key] = p;
	}
}

Obj* ObjMgr::Find(const string& key)
{
	auto find = objs.find(key);
	if (find != objs.end())
		return find->second;
	return nullptr;
}

void ObjMgr::Clear()
{
	for (auto& iter : objs)
		iter.second->flag = true;
}

bool ObjMgr::IsMapOut(Obj* p)
{
	if (p)
		return (p->pos.x < 0 || p->pos.x > WINX ||
			p->pos.y < 0 || p->pos.y > WINY);
	return false;
}
