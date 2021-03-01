#include "DXUT.h"
#include "ImgMgr.h"

void Texture::Render(V2 pos, RECT rt, V2 size, float rot, float depth, D3DXCOLOR color, bool center)
{
	IMG->Render(this, pos, rt, size, rot, depth, color, center);
}

void Texture::Release()
{
	SAFE_RELEASE(p);
}

ImgMgr::ImgMgr()
	:sprite(nullptr), font(nullptr)
{
	Init();

	D3DXCreateSprite(DEVICE, &sprite);
}

ImgMgr::~ImgMgr()
{
	Release();
}

void ImgMgr::Init()
{
}

void ImgMgr::Begin()
{
	sprite->Begin(1 << 4 | 1 << 2 | 1 << 6);
}

void ImgMgr::End()
{
	sprite->End();
}

Texture* ImgMgr::Add(const string& key, const string& path)
{
	auto find = textures.find(key);
	if (find == textures.end())
	{
		LPDIRECT3DTEXTURE9 p;
		D3DXIMAGE_INFO info;
		
		char str[256];
		sprintf(str, "./Resource/image/%s.png", path.c_str());

		if (D3DXCreateTextureFromFileExA(DEVICE, str, (UINT)-2, (UINT)-2, 0, 0, (D3DFORMAT)0, (D3DPOOL)1, (UINT)-1, (UINT)-1, 0, &info, nullptr, &p) == S_OK)
		{
			Texture* text = new Texture(p, info);
			textures[key] = text;
			return text;
		}
		return nullptr;
	}
	return find->second;
}

Texture* ImgMgr::Find(const string& key)
{
	auto find = textures.find(key);
	if (find != textures.end())
		return find->second;
	return nullptr;
}

void ImgMgr::Render(Texture* p, V2 pos, RECT rt, V2 size, float rot, float depth, D3DXCOLOR color, bool center)
{
	if (p)
	{
		M mat;
		V2 cpos = { 0,0 };
		RECT* prt = &rt;

		if (rt.right == 0 && rt.left == 0 && rt.bottom == 0 && rt.top == 0)
			prt = nullptr;

		if (center)
			cpos = { (float)p->info.Width / 2,(float)p->info.Height / 2 };

		pos -= cpos;

		D3DXMatrixTransformation2D(&mat, &cpos, 0, &size, &cpos, rot, &pos);
		mat._43 = depth;
		sprite->SetTransform(&mat);
		sprite->Draw(p->p, prt, nullptr, nullptr, color);
	}
}

void ImgMgr::Write(const string& str, V2 pos, float size, D3DXCOLOR color, bool center)
{
	M mat;
	float x = pos.x;
	float y = pos.y;

	if (center)
	{
		x -= size * (str.size() * 0.25);
		y -= size / 2;
	}

	D3DXMatrixTranslation(&mat, x, y, 0);
	sprite->SetTransform(&mat);
	D3DXCreateFontA(DEVICE, size, 0, center ? 0 : 10, 1, 0, 129, 0, 0, 0, "Fixedsys", &font);
	font->DrawTextA(sprite, str.c_str(), str.size(), nullptr, DT_NOCLIP, color);
	SAFE_RELEASE(font);
}

void ImgMgr::Release()
{
	for (auto& iter : textures)
	{
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}
	textures.clear();
	sprite->Release();
}

void ImgMgr::Lost()
{
	sprite->OnLostDevice();
}

void ImgMgr::Reset()
{
	sprite->OnResetDevice();
}
