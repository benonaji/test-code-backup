// Define.h
// 这里定义所使用到的反应器
// 尽管有些事情并不那么容易，但是它并不是不可战胜的，关键在与内心是否愿意战胜它。
// add by freeeyes
// 2008-12-23

#ifndef _ACEREACTORMANAGER_H
#define _ACEREACTORMANAGER_H

#include "define.h"

#include "ace/Synch_Traits.h"
#include "ace/Reactor.h"
#include "ace/Select_Reactor.h"
#include "ace/TP_Reactor.h"
#include "ace/WFMO_Reactor.h"
#include "ace/Dev_Poll_Reactor.h"
#include "ace/Task.h"
#include "ace/Singleton.h"

#include <map>

using namespace std;

enum
{
	Reactor_Select    = 0x01,
	Reactor_TP        = 0x02,
	Reactor_WFMO      = 0x03,
	Reactor_DEV_POLL  = 0x04,

};

//反应器对象
class CAceReactor : public ACE_Task<ACE_MT_SYNCH>
{
public:
	CAceReactor();
	~CAceReactor();

	void Close();

	bool Init(int nReactorType, int nThreadCount);
	const char* GetError();
	int GetThreadCount();
	int GetReactorType();
	ACE_Reactor* GetReactor();

	bool Start();
	bool Stop();

	virtual int open(void *args = 0);
	virtual int svc(void);

	void   SetReactorID(uint32 u4ReactorID);
	uint32 GetReactorID();

private:
	ACE_Reactor* m_pReactor;
	int          m_nReactorType;
	int          m_nThreadCount;
	char         m_szError[MAX_BUFF_500];
	bool         m_blRun;          //反应器是否在运行
	uint32       m_u4ReactorID;    //反应器的编号
};

class CAceReactorManager
{
public:
	CAceReactorManager(void);
	~CAceReactorManager(void);

	bool AddNewReactor(int nReactorID, int nReactorType = Reactor_Select, int nThreadCount = 1);
	void Close();
	const char* GetError();

	bool StartReactor();
	bool StartReactorDefault();
	bool StopReactor();

	CAceReactor* GetAceReactor(int nReactorID);
	ACE_Reactor* GetAce_Reactor(int nReactorID);

private:
	typedef map<int, CAceReactor*> mapAceReactor;
	mapAceReactor m_mapAceReactor;
	char          m_szError[MAX_BUFF_500];
};

typedef ACE_Singleton<CAceReactorManager, ACE_Null_Mutex> App_ReactorManager;

#endif
