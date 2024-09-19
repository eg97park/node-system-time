#include <assert.h>
#include <node_api.h>
#include <uv.h>

static napi_value GetCurrentTime(napi_env env, napi_callback_info info) {

  uv_timespec64_t tspec;
  int result = uv_clock_gettime(UV_CLOCK_REALTIME, &tspec);
  assert(result == 0);

  napi_value ts;
  napi_status status = napi_create_bigint_uint64(env, tspec.tv_sec * 1000000000 + tspec.tv_nsec, &ts);
  assert(status == napi_ok);
  
  return ts;
}

#define DECLARE_NAPI_METHOD(name, func)                                        \
  { name, 0, func, 0, 0, 0, napi_default, 0 }

static napi_value Init(napi_env env, napi_value exports) {
  napi_status status;
  napi_property_descriptor desc = DECLARE_NAPI_METHOD("getCurrentTime", GetCurrentTime);
  status = napi_define_properties(env, exports, 1, &desc);
  assert(status == napi_ok);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
