#include <stdlib.h>
#include <stdlib.h>  /* abs */
#include "nan.h"

using namespace node;

namespace {

NAN_METHOD(ArrayAbs) {
  int *arr = reinterpret_cast<int *>(Buffer::Data(info[0].As<v8::Object>()));
  uint32_t length = Nan::To<uint32_t>(info[1]).FromJust();
  for (uint32_t i = 0; i < length; i++) {
    *(arr + i) = abs(arr[i]);
  }
}

NAN_MODULE_INIT(Initialize) {
  Nan::SetMethod(target, "arrayAbs", ArrayAbs);
}

} // anonymous namespace

NODE_MODULE(native_tests, Initialize);
