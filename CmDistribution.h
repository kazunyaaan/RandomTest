#ifndef CM_DISTRIBUTION_H
#define CM_DISTRIBUTION_H

#include "CmRandomEngine.h"

enum DistributionMethod
{
    // Method
    Raw                 = 0,  // Uniform random [0,1)
    BoxMuller           = 1,  // Box-Muller's method
    CentralLimitTheorem = 2,  // CentralLimitTheorem

    // Uniform
    Uniform = Raw,
    
    // Normal (Default: Box-Muller's method)
    Normal  = BoxMuller,
};

template<DistributionMethod>
class CmDistribution
{
  public:
    template<class T>double operator()(CmRandomEngine<T>& engine);
};

template class CmDistribution<Raw>;
template class CmDistribution<BoxMuller>;
template class CmDistribution<CentralLimitTheorem>;

template<> template<class T>
double CmDistribution<Raw>::operator()(CmRandomEngine<T>& engine)
{
    return engine.c0o1();
}

template<> template<class T>
double CmDistribution<BoxMuller>::operator()(CmRandomEngine<T>& engine)
{
    double alpha = engine.o0c1();   // (0,1] 
    double beta  = engine.c0o1();   // [0,1)

    return sqrt(-2.0*log(alpha)) * cos(2.0*M_PI*beta);
}

template<> template<class T>
double CmDistribution<CentralLimitTheorem>::operator()(CmRandomEngine<T>& engine)
{
    return engine.o0o1() + engine.o0o1() + engine.o0o1() + engine.o0o1() + engine.o0o1() + engine.o0o1()
         + engine.o0o1() + engine.o0o1() + engine.o0o1() + engine.o0o1() + engine.o0o1() + engine.o0o1() - 6.0;
}

#endif // CM_DISTRIBUTION_H
