#include "DXUT.h"
#include "MainGame.h"

void MainGame::Init()
{
	OBJ->Add(new Player, "player");
}

void MainGame::Update()
{
	CAM->Update();
	SCENE->Update();
	OBJ->Update();
	INPUT->Update();
	TIME->Update();
}

void MainGame::Render()
{
	CAM->Apply();
	IMG->Begin();
	SCENE->Render();
	OBJ->Render();
	IMG->End();
}

void MainGame::Release()
{
	CamMgr::Del();
	ImgMgr::Del();
	ObjMgr::Del();
	TimeMgr::Del();
	SceneMgr::Del();
	SoundMgr::Del();
	InputMgr::Del();
}

void MainGame::Lost()
{
	IMG->Lost();
}

void MainGame::Reset()
{
	IMG->Reset();
}
