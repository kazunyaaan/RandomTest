#ifndef CM_RANDOM_H
#define CM_RANDOM_H

#include <cstdint>
#include <cmath>
#include <random>
#include "dSFMT.h"
#include "CmRandomEngine.h"
#include "CcSingleton.h"

class CmMTRandomEngine : public CmRandomEngine<CmMTRandomEngine>, public CcSingleton<CmMTRandomEngine>
{
  private:
    friend class CcSingleton<CmMTRandomEngine>;
	CmMTRandomEngine() { dsfmt_init_gen_rand(&m_dsfmt, 0); }

  public:
	void InitSeed(const uint32_t& seed) { dsfmt_init_gen_rand(&m_dsfmt, seed); }
    double c0o1() { return dsfmt_genrand_close_open  (&m_dsfmt); }
    double o0c1() { return dsfmt_genrand_open_close  (&m_dsfmt); }
    double o0o1() { return dsfmt_genrand_open_open   (&m_dsfmt); }
    double c1o2() { return dsfmt_genrand_close1_open2(&m_dsfmt); }

  private:
	dsfmt_t m_dsfmt;
};

class CmDeviceRandomEngine : public CmRandomEngine<CmDeviceRandomEngine>, public CcSingleton<CmDeviceRandomEngine>
{
  private:
    friend class CcSingleton<CmDeviceRandomEngine>;
	CmDeviceRandomEngine() : m_c0o1(0.0,1.0) {}

  public:
    double c0o1() { return m_c0o1(m_rnd); }
    double o0c1() { return 1.0 - c0o1(); }
    //double o0o1() { return 1.0/0.0; }
    //double c1o2() { return 1.0/0.0; }

  private:
	std::random_device m_rnd;
    std::uniform_real_distribution<double> m_c0o1;
};

#endif // CM_RANDOM_H
