
#include "ValueProvider.h"

struct TwoTimer {
  TwoTimer(ValueProvider* vp) : mVp(vp) { }
  int result();
  
  ValueProvider* mVp;
};

extern "C" int timestwo(ValueProvider* vp)
{
  TwoTimer t(vp);
  return t.result();
}

int TwoTimer::result()
{
  return mVp->getValue() * 2;
}