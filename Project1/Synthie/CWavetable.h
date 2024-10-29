#pragma once
#include "Instrument.h"
#include "CWaveform.h"

class CWavetable : public CInstrument
{
public:
	CWavetable();

	virtual void Start();
	virtual bool Generate();

	void SetNote(CNote* note);
private:
	CWaveform m_waveform;
	double m_time;
};