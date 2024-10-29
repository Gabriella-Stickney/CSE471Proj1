#pragma once
class NoiseGate
{
public:
	NoiseGate(void);
	~NoiseGate(void);
	void Process(double* frameIn, double* frameOut);
	void XmlLoad(IXMLDOMNode* xml);

private:
	int m_threshold;
	double m_dry;
	double m_wet;
	double m_gateL;
	double m_gateR;
};

