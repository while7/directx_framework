#include "DXUT.h"
#include "Col.h"

Col::Col(Obj* p, V2 pos, Tag tag, int damage)
	:owner(p), pos(pos), tag(tag), damage(damage), flag(true)
{
	OBJ->Add(this);
}

void Col::SetRange(V2 pos, float w, float h)
{
}
