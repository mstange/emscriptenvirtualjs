extern "C" {

int emscripten_bind_ValueProvider__getValue_p0(ValueProvider * self) {
  return self->getValue();
}

int emscripten_extern_ConstValueProvider_getValue(void*);

}

class ConstValueProvider : public ValueProvider {
public:
  ConstValueProvider() {}
  virtual int getValue() {
    return emscripten_extern_ConstValueProvider_getValue(this);
  }
};

extern "C" {

void* emscripten_construct_ConstValueProvider() { return new ConstValueProvider(); }

}


#include <stdio.h>

struct EmscriptenEnsurer
{
  EmscriptenEnsurer() {
    // Actually use the binding functions, so DFE will not eliminate them
    // FIXME: A negative side effect of this is that they take up space in FUNCTION_TABLE
    int sum = 0;
    void *seen = (void*)emscripten_bind_ValueProvider__getValue_p0;
    printf("(%d)\n", sum);
  }
};

EmscriptenEnsurer emscriptenEnsurer;
