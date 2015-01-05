#ifndef CM_RANDOM_ENGINE_H
#define CM_RANDOM_ENGINE_H

template <class T>
class CmRandomEngine
{
  public:
    double c0o1() { return derived().c0o1(); }
    double o0c1() { return derived().o0c1(); }
    double o0o1() { return derived().o0o1(); }
    double c1o2() { return derived().c1o2(); }
  
  protected:
    T& derived() { return static_cast<T&>(*this); }
};

#endif // CM_RANDOM_ENGINE_H
