#pragma once
class Compression
{
public:
	Compression(void);
	~Compression(void);

	void Process(double* frameIn, double* frameOut);
	void XmlLoad(IXMLDOMNode* xml);

private:
	int m_threshold;
	double m_wet;
	double m_dry;
	double m_gateL;
	double m_gateR;
	double m_ratio;
};