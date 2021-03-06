#pragma once
#include "Scene.h"
class SceneMgr :
	public singletone<SceneMgr>
{
public:
	SceneMgr() { ; };
	~SceneMgr();

	void Add(Scene* p, const string& key);
	void Set(const string& key);

	void Update();
	void Render();

	map<string, Scene*> scenes;
	Scene* now = nullptr;
};

#define SCENE SceneMgr::Get()