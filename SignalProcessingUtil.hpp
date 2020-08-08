#include <vector>
#include <iostream>
#include <complex>
#include <math.h>
#include <map>
#include <cmath>
#include <stdlib.h>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <ctime>

template < typename signalArraytype>
using  complexSignalVector_t  = std::vector <std::complex < signalArraytype >>;
template < typename signalArraytype>
using  signalVector_t   = std::complex < signalArraytype >;


template < typename signalArraytype>
class dsp {

private:
    double dummySignalFrequency; // Frequency of Signal.
    
    // Display all Log messages irrespective of the level.
    bool enableDebugLog = true;

    // This is a pointer to the main signal, which might of might not be stored on heap.
    complexSignalVector_t<signalArraytype> inputSignal;
    
    int    sample_width;    // Number of Samples to average over.
    double upperBound;      // Upper bound Percentage change from average sample.
    double lowerBound;      // Upper bound Percentage change from average sample.
    double avreagingStep;   // Number of samples to skip before taking a new average.
    double scalingFactor;   // Scale the filtered signal.
    double SginalVSft;      // Vertical Shift the filtered signal.
    
    double omega;           // 0.9000; // Omega Value.
    
public:

    void LOG ( std::string message , short level );

    dsp( const complexSignalVector_t<signalArraytype>& signal ); 
    dsp( const signalVector_t<signalArraytype>&        signal );
    dsp( const signalArraytype*       signal, int length  );

    complexSignalVector_t<signalArraytype> dsp <signalArraytype> :: dft ( const signalArraytype sweepDelta );

    // doubleVector_t  noiseFilter ();
    // complexVector_t dft ( complexVector_t signal );
    // doubleVector_t  dft ( doubleVector_t signal );
    // doubleVector_t dc_removal ();
};


