#ifndef CC_SINGLETON_H
#define CC_SINGLETON_H

#include <memory>

template <class T>
class CcSingleton
{
  public:
    static T& GetInstance()
    {
        static Ston_ptr singleton(T::CreateInstance());
        return GetReference(singleton);
    }

  private:
    typedef std::unique_ptr<T> Ston_ptr;

    inline static T* CreateInstance()                  { return new T(); }
    inline static T& GetReference(const Ston_ptr& ptr) { return *ptr; }

  protected:
    CcSingleton() {}

  private:
    CcSingleton(const CcSingleton&)            = delete;
    CcSingleton& operator=(const CcSingleton&) = delete;
    CcSingleton(CcSingleton&&)                 = delete;
    CcSingleton& operator=(CcSingleton&&)      = delete;
};

#endif // CC_SINGLETON_H
