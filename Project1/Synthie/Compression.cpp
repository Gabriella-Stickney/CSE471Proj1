#include "stdafx.h"
#include "Compression.h"

Compression::Compression(void)
{
	m_threshold = 0;
	m_wet = 0;
	m_dry = 1;
	m_gateL = 1;
	m_gateR = 1;
	m_ratio = 1;
}


Compression::~Compression(void)
{
}

void Compression::Process(double* frameIn, double* frameOut)
{
	if (frameIn[0] > m_threshold || frameIn[0] < -m_threshold)
	{
		double difference = frameIn[0] - m_threshold;
		double compressedFrame = (difference / m_ratio) + m_threshold;
		frameOut[0] = m_dry * frameIn[0] + m_wet * compressedFrame;
	}
	else
	{
		frameOut[0] = frameIn[0];
	}

	if (frameIn[1] > m_threshold || frameIn[1] < -m_threshold)
	{
		double difference = frameIn[1] - m_threshold;
		double compressedFrame = (difference / m_ratio) + m_threshold;
		frameOut[1] = m_dry * frameIn[1] + m_wet * compressedFrame;
	}
	else
	{
		frameOut[1] = frameIn[1];
	}
}

void Compression::XmlLoad(IXMLDOMNode* xml)
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

		if (name == "threshold")
		{
			value.ChangeType(VT_I4);
			m_threshold = value.intVal;
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
		else if (name == "ratio")
		{
			value.ChangeType(VT_R8);
			m_ratio = value.dblVal;
		}
	}
}