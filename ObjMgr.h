#pragma once
#include "Obj.h"
class ObjMgr :
	public singletone<ObjMgr>
{
public:
	ObjMgr();
	~ObjMgr();

	void Update();
	void ColChk(Col* p);
	void Render();
	void Release();

	void Add(Obj* p, const string& key);
	void Add(Col* p) { col_list.emplace_back(p); }
	Obj* Find(const string& key);

	void Clear();
	bool IsMapOut(Obj* p);

	map<string, Obj*> objs;
	list<Col*> col_list;
	bool col_layer[TAG_END][TAG_END];
};

#define OBJ ObjMgr::Get()