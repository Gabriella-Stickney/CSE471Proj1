#include "stdafx.h"
#include "Chorus.h"
#include <cmath>


Chorus::Chorus(void)
{
	m_delay = 0;
	m_dry = 0;
	m_wet = 0;
	m_modulationRange = 0;
	m_modulationRate = 0;
	m_wrloc = 0;
	m_sampleRate = 0;

	m_queueL.resize(200000);
	m_queueR.resize(200000);
}


Chorus::~Chorus(void)
{
}

void Chorus::Process(double* frameIn, double* frameOut)
{
	double delayVariance = (m_modulationRange * m_delay) * sin(2 * PI * m_modulationRate);
	double newDelay = m_delay + delayVariance;

	m_wrloc = (m_wrloc + 1) % 200000;
	m_queueL[m_wrloc] = frameIn[0];
	m_queueR[m_wrloc] = frameIn[1];

	int delayLength = int((newDelay * m_sampleRate + 0.5)) * 2;
	int rdloc = (m_wrloc + 200000 - delayLength) % 200000;

	frameOut[0] = frameIn[0] / 2 + m_queueL[rdloc] / 2;
	frameOut[0] *= m_wet;
	frameOut[1] = frameIn[1] / 2 + m_queueR[rdloc] / 2;
	frameOut[1] *= m_wet;

	frameOut[0] += frameIn[0] * m_dry;
	frameOut[1] += frameIn[1] * m_dry;
}

void Chorus::XmlLoad(IXMLDOMNode* xml)
{
	CComPtr<IXMLDOMNamedNodeMap> attributes;
	xml->get_attributes(&attributes);
	long len;
	attributes->get_length(&len);

	for (int i = 0; i < len; i++)
	{
		CComPtr<IXMLDOMNode> attrib;
		attributes->get_item(i, &attrib);

		CComBSTR name;
		attrib->get_nodeName(&name);

		CComVariant value;
		attrib->get_nodeValue(&value);

		if (name == "delay")
		{
			value.ChangeType(VT_R8);
			m_delay = value.dblVal;
		}
		else if (name == "wet")
		{
			value.ChangeType(VT_R8);
			m_wet = value.dblVal;
		}
		else if (name == "dry")
		{
			value.ChangeType(VT_R8);
			m_dry = value.dblVal;
		}
		else if (name == "range")
		{
			value.ChangeType(VT_R8);
			m_modulationRange = value.dblVal;
		}
		else if (name == "rate")
		{
			value.ChangeType(VT_R8);
			m_modulationRate = value.dblVal;
		}
	}
}