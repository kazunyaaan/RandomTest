#include <iostream>
#include "CmRandom.h"
#include "CmDistribution.h"

int main()
{
    const int N = 5;
    volatile double sum = 0.0;

    CmMTRandomEngine&         mt = CmMTRandomEngine::GetInstance();
    CmDeviceRandomEngine& device = CmDeviceRandomEngine::GetInstance();

    CmDistribution<Normal> v; // 正規乱数
    //CmDistribution<Uniform> v; // 一様乱数

    for (int n = 0; n < N; ++n)
    {
        double r = v(mt);
        sum += r;
        printf("%5d\t %f\n", n, r);
    }

    return 0;
}

