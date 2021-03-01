#pragma once
#include "Obj.h"
class Obj;
class Col :
    public RECT
{
public:
    Col(Obj* p, V2 pos = CENTER, Tag tag = TAG_BEGIN, int damage = 0);
    ~Col() { ; };

    Obj* owner;
    V2 pos;
    Tag tag;
    int damage;
    bool flag;

    void SetRange(V2 pos, float w, float h);

    RECT GetRECT()
    {
        return { left,top,right,bottom };
    }
};

