#include "DXUT.h"
#include "Time.h"

void Timer::Update()
{
	if (flag)
	{
		cur_time -= DT;
		if (cur_time <= 0)
		{
			cur_time = set_time;
			flag = false;
		}
	}
}

TimeMgr::~TimeMgr()
{
	for (auto& iter : timer_list)
		SAFE_DELETE(iter);
	for (auto& iter : stop_watch_list)
		SAFE_DELETE(iter);
	timer_list.clear();
	stop_watch_list.clear();
}

void TimeMgr::Update()
{
	for (auto& iter : timer_list)
	{
		if (!iter) { timer_list.remove(iter); }
		else { iter->Update(); }
	}
	for (auto& iter : stop_watch_list)
	{
		if (!iter) { stop_watch_list.remove(iter); }
		else { iter->Update(); }
	}
}

Timer* TimeMgr::CreateTimer(float time)
{
	Timer* timer = new Timer(time);
	timer_list.emplace_back(timer);
	return timer;
}

StopWatch* TimeMgr::CreateStopWatch()
{
	StopWatch* stop_watch = new StopWatch;
	stop_watch_list.emplace_back(stop_watch);
	return stop_watch;
}

void StopWatch::Update()
{
	if (flag)
		cur_time += DT;
}
