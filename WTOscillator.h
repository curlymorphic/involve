#ifndef WTOSCILLATOR_H
#define WTOSCILLATOR_H

#include "AudioMath.h"
#include "AudioProcess.h"

///
/// \brief The WTWaveShape enum
///The Diffrent Wave Tables.
enum WTWaveShape { WT_SINE, WT_TRIANGLE, WT_SQUARE, WT_SAW,  WT_USER, WT_WAVESHAPECOUNT };


///
/// \brief The WTOscillator class
///A Wave Table oscillator , all wave tables are 1024 samples
/// Sine Square Saw and Triangle generated using addith synthasys, with 5 harmonics
/// These wont alias when played at c8, but will sound flat for bass notes
///
///
class WTOscillator : public AudioProcess
{
public:

	const int TABLE_LEN = 1024;
	WTOscillator( qint64 sampleRate );
	~WTOscillator();

	///
	/// \brief tick
	/// \return
	///Returns the next sample

	sample_t tick();

	///
	/// \brief tick
	/// \param frame
	/// places the next sample in frame, as a stereo signal
	void tick( sampleFrame *frame );

	///
	/// \brief setFrequency
	/// \param freq
	/// sets the frequency. limited to 32.7 - 4186   c1 - c8
	void setFrequency( float freq );

	///
	/// \brief setShape
	/// \param shape
	///Sets the wave table to use
	void setShape( WTWaveShape shape );

	///
	/// \brief setUserShape
	/// \param table
	/// sets the wavetable to use, the table must be 1024 samples
	void setUserShape( float *table );

protected:
	///
	/// \brief m_index
	/// The current into into the table
	float m_index;
	///
	/// \brief m_increment
	///The ammount to increase the index by each frame, this is set in setFrequency
	float m_increment;

	///
	/// \brief m_currentTable
	///pointer to the currently selected table;
	sample_t *m_currentTable;

	///
	/// \brief SineTable
	/// the calculated Sine Wave Table
	sample_t *sineTable;
	///
	/// \brief SquareTable
	///the calculated Square Wave Table
	sample_t *squareTable;
	///
	/// \brief TriTable
	/// the calculated Triangle Wave Table
	sample_t *triTable;
	///
	/// \brief SawTable
	/// the calculated Saw tooth Wave Table
	sample_t *sawTable;



private:

	void generateSineTable( qint64 bands );
	void generateSawTable( qint64 bands );
	void generateTriTable( qint64 bands );
	void generateSquareTable( qint64 bands );

};

#endif // WTOSCILLATOR_H
