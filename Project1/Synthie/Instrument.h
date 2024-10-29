#pragma once
#include "AudioNode.h"
#include "Note.h"
#include <AR.h>
class CInstrument :
	public CAudioNode
{
public:
	CInstrument();
	CInstrument(double);
	virtual ~CInstrument();
	virtual void SetNote(CNote *note) = 0;
	virtual void SetDuration(double d) { m_ar.SetDuration(d); }
	double Duration() { return m_ar.Duration(); }
	CAR m_ar;
};

