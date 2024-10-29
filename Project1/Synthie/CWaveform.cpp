#include "stdafx.h"
#include "CWaveform.h"
#include "audio/DirSoundSource.h"
#include <algorithm>

using namespace std;

CWaveform::CWaveform()
{
	PrepareFileList();

	for (int i = 0; i < m_fileList.size(); i++)
	{
		m_LookupTable.push_back(vector<short>());
	}
}

void CWaveform::PrepareFileList()
{
	int n = 0;
	for (int i = 1; i < 5; i++)
	{
		for (auto note : m_noteList)
		{
			std::wstring filename = L"WaveNotes/wavetable_";
			if (n < 10)
			{
				filename += L"0";
			}
			filename += to_wstring(n) + L"_" + note + to_wstring(i) + L".wav";

			m_fileList.push_back(filename);
			n++;
		}
	}
}

void CWaveform::LoadSampleIntoTable(int noteId, int type)
{
	if ((noteId < 0) || (noteId > 47))
		return;

	if (m_LookupTable[noteId].size() > 0)
		return;

	if (type == 0)
	{
		m_noteToPlay = noteId;
	}
	else if (type == 1)
	{
		m_nextNote = noteId;
	}

	CDirSoundSource audioin;

	if (!audioin.Open(m_fileList[noteId].c_str()))
		return;

	for (int i = 0; i < audioin.NumSampleFrames(); i++)
	{
		short audio[2];

		audioin.ReadFrame(audio);

		m_LookupTable[noteId].push_back(audio[0]);
	}

	audioin.Close();
}

int CWaveform::GetSampleIdFromNote(std::wstring note)
{
	int octave = note[note.size() - 1] - '0';
	wstring name = note.substr(0, note.size() - 1);

	int noteNum = 0;
	if ((note.size() == 3) && (note[1] == '#'))
	{
		noteNum = distance(m_noteListAlt.begin(),
			find(m_noteListAlt.begin(), m_noteListAlt.end(), name));
	}
	else
	{
		noteNum = distance(m_noteList.begin(),
			find(m_noteList.begin(), m_noteList.end(), name));
	}

	return (12 * (octave - 1)) + noteNum;
}

void CWaveform::Start()
{
	m_time = 0;
	m_loopNum = 0;
	m_amp = 0.5;
}

bool CWaveform::Generate()
{
	double glissDiff = ((m_nextNote >= 0) && (m_nextNote <= 47)) ? m_nextNote - m_noteToPlay : 0;

	double glissTime = m_time + ((LoopEnd() - LoopStart()) * (m_loopNum + 1));
	double glissCoeff = glissTime / m_duration;
	if (glissCoeff > 1)
		glissCoeff = 1;

	int glissAmount = int(glissDiff * glissCoeff);
	int sample = m_noteToPlay + glissAmount;

	LoadSampleIntoTable(sample, 2);
	int const i = m_frameIndex % m_LookupTable[sample].size();
	m_frame[0] = double(m_LookupTable[sample][i]) / 65535.0;
	m_frame[0] *= m_amp;
	m_frame[1] = m_frame[0];

	m_frameIndex++;
	m_time += GetSamplePeriod();
	if ((m_time < (m_duration - Release())) && (m_time >= LoopEnd()))
	{
		m_time = LoopStart();
		m_frameIndex = int(LoopStart() / GetSamplePeriod());
		m_loopNum++;
	}

	return true;
}
