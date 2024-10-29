#pragma once
#include "AudioNode.h"
class CAR :
	public CAudioNode
{
public:
	CAR();
	~CAR();
private:
	double m_duration;
	double m_time;
	double m_attack;
	double m_release;
	CAudioNode* m_source;
public:
	void SetSource(CAudioNode* const &source) { m_source = source; }
	void SetDuration(double d) { m_duration = d; }
	virtual void Start();
	virtual bool Generate();
	double Duration() { return m_duration; }
	void SetAttack(double at) { m_attack = at; }

	double Attack() { return m_attack; }

	void SetRelease(double rl) { m_release = rl; }

	double Release() { return m_release; }
};

