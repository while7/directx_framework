#include "DXUT.h"
#include "SceneMgr.h"

SceneMgr::~SceneMgr()
{
	if (now)
		now->Release();
	for (auto& iter : scenes)
		SAFE_DELETE(iter.second);
	scenes.clear();
}

void SceneMgr::Add(Scene* p, const string& key)
{
	if (p && scenes.find(key) == scenes.end())
		scenes[key] = p;
}

void SceneMgr::Set(const string& key)
{
	auto find = scenes.find(key);
	if (find != scenes.end())
	{
		now->Release();
		OBJ->Clear();
		now = find->second;
		now->Init();
	}
}

void SceneMgr::Update()
{
	if (now)
		now->Update();
}

void SceneMgr::Render()
{
	if (now)
		now->Render();
}
