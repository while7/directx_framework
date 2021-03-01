#include "DXUT.h"
#include "SoundMgr.h"

void Sound::Play(bool loop)
{
    SOUND->Play(this, loop);
}

void Sound::Copy()
{
    SOUND->Copy(this);
}

void Sound::Stop()
{
    SOUND->Stop(this);
}

SoundMgr::SoundMgr()
{
    mgr = new CSoundManager;
    mgr->Initialize(DXUTGetHWND(), 2);
}

SoundMgr::~SoundMgr()
{
    for (auto& iter : sounds)
        SAFE_DELETE(iter.second);
    sounds.clear();
    SAFE_DELETE(mgr);
}

Sound* SoundMgr::Add(const string& key, const wstring& path)
{
    auto find = sounds.find(key);
    if (find == sounds.end())
    {
        wchar_t wstr[256];
        swprintf(wstr, L"./Resource/sound/%s.wav", path.c_str());
        CSound* csound;
        mgr->Create(&csound, wstr);
        Sound* sound = new Sound(csound);
        sounds[key] = sound;
        return sound;
    }
    return find->second;
}

Sound* SoundMgr::Find(const string& key)
{
    auto find = sounds.find(key);
    if (find == sounds.end())
        return find->second;
    return nullptr;
}

void SoundMgr::Play(Sound* p, bool loop)
{
    if (p)
        p->p->Play(0, loop);
}

void SoundMgr::Copy(Sound* p)
{
    if (p)
    {
        LPDIRECTSOUNDBUFFER buf;
        mgr->GetDirectSound()->DuplicateSoundBuffer(p->p->GetBuffer(0), &buf);
        buf->SetCurrentPosition(0);
        buf->Play(0, 0, 0);
    }
}

void SoundMgr::Stop(Sound* p)
{
    if (p)
        p->p->Stop();
}
