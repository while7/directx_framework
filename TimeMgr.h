#pragma once
struct Timer
{
public:
	Timer(float time) { Set(time); }
	~Timer() { ; };

	void Set(float time) { set_time = time; cur_time = time; flag = false; }
	void Start() { flag = true; }

	void Update();

	float cur_time = 0;
	float set_time = 0;
	bool flag = false;
};
struct StopWatch
{
public:
	StopWatch() { Reset(); };
	~StopWatch() { ; };

	void Reset() { cur_time = 0; laps.clear(); flag = false; }
	void Start() { flag = true; }
	void Lap() { laps.emplace_back(cur_time); }
	void Stop() { flag = false; }

	void Update();

	list<float> laps;

	float cur_time = 0;
	bool flag = false;
};
class TimeMgr :
	public singletone<TimeMgr>
{
public:
	TimeMgr() { ; };
	~TimeMgr();

	void Update();

	Timer* CreateTimer(float time);
	StopWatch* CreateStopWatch();

	list<Timer*> timer_list;
	list<StopWatch*> stop_watch_list;
};

#define TIME TimeMgr::Get()