#include "stdafx.h"
#include "CWavetable.h"
#include "Notes.h"
#include <string>

using namespace std;

CWavetable::CWavetable()
{
}

void CWavetable::Start()
{
    m_waveform.SetSampleRate(GetSampleRate());
    m_waveform.Start();
    m_time = 0;
    m_ar.SetSource(&m_waveform);
    m_ar.SetSampleRate(GetSampleRate());

    m_ar.SetAttack(m_waveform.Attack());
    m_ar.SetRelease(m_waveform.Release());

    m_ar.Start();
}

bool CWavetable::Generate()
{
    m_waveform.Generate();
    bool valid = m_ar.Generate();

    m_frame[0] = m_ar.Frame(0);
    m_frame[1] = m_ar.Frame(1);

    m_time += GetSamplePeriod();
    return valid;
}

void CWavetable::SetNote(CNote* note)
{
    CComPtr<IXMLDOMNamedNodeMap> attributes;
    note->Node()->get_attributes(&attributes);
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

        if (name == "duration")
        {
            value.ChangeType(VT_R8);
            SetDuration((value.dblVal) * (60.0 / m_bpm));
            m_waveform.SetDuration((value.dblVal) * (60.0 / m_bpm));
        }
        else if (name == "note")
        {
            wstring noteName(value.bstrVal, SysStringLen(value.bstrVal));
            m_waveform.LoadSampleIntoTable(m_waveform.GetSampleIdFromNote(noteName), 0);
            m_waveform.SetNextNote(99);
        }
        else if (name == "gliss")
        {
            wstring noteName(value.bstrVal, SysStringLen(value.bstrVal));
            m_waveform.LoadSampleIntoTable(m_waveform.GetSampleIdFromNote(noteName), 1);
        }
    }
}