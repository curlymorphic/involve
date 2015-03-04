#ifndef ANALYSER_H
#define ANALYSER_H

#include "AudioProcess.h"

///
/// \brief The Analyser class
///first prototype of dft class
/// only analyses left channel
/// duplicats output on both channels
///
class Analyser : public AudioProcess
{
public:
	Analyser( int maxSize = 100000, int sampleRate = 44100 );
	~Analyser();

	///
	/// \brief dft
	/// \param in
	/// \param out
	/// \param n
	///
	void dft( float *in, float *out, int n );

	///
	/// \brief idft
	/// \param in
	/// \param out
	/// \param n
	///
	void idft( float *in, float *out, int n );

	float *bands() const
	{
		return m_bands;
	}

	int bandCount() const
	{
		return m_bandCount;
	}

	virtual void tick()
	{

	}

	virtual void processAudio( sampleFrame *buffer, int len );

	void analyseAudio( sampleFrame *buffer, int len );




private:

	float* m_bands;
	float *m_audioBuffer;
	int  m_bandCount;
	float **m_sinTable;
	float **m_cosTable;
};

#endif // ANALYSER_H
