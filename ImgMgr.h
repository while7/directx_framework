#pragma once
struct Texture
{
	LPDIRECT3DTEXTURE9 p;
	D3DXIMAGE_INFO info;

	Texture(LPDIRECT3DTEXTURE9 p, D3DXIMAGE_INFO info)
		:p(p), info(info)
	{
	}

	void Render(V2 pos = CENTER, RECT rt = { 0,0,0,0 }, V2 size = { 1,1 }, float rot = 0, float depth = 0, D3DXCOLOR color = D3DCOLOR_XRGB(255, 255, 255), bool center = true);
	void Release();
};
class ImgMgr :
	public singletone<ImgMgr>
{
public:
	ImgMgr();
	~ImgMgr();

	void Init();

	void Begin();
	void End();

	Texture* Add(const string& key, const string& path);
	Texture* Find(const string& key);

	void Render(Texture* p, V2 pos = CENTER, RECT rt = { 0,0,0,0 }, V2 size = { 1,1 }, float rot = 0, float depth = 0, D3DXCOLOR color = D3DCOLOR_XRGB(255, 255, 255), bool center = true);
	void Write(const string& str, V2 pos = CENTER, float size = 50, D3DXCOLOR color = D3DCOLOR_XRGB(255, 255, 255), bool center = true);

	void Release();
	void Lost();
	void Reset();

	LPD3DXSPRITE sprite;
	LPD3DXFONT font;
	map<string, Texture*> textures;
};

#define IMG ImgMgr::Get()