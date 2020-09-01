#include <esp_system.h>
#include <cutils.h>

#include "esp_api.h"

static JSValue js_esp_get_free_heap_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
    return JS_NewUint32(ctx, esp_get_free_heap_size());
}

static JSValue js_esp_get_free_internal_heap_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
    return JS_NewUint32(ctx, esp_get_free_internal_heap_size());
}

static JSValue js_esp_get_minimum_free_heap_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
    return JS_NewUint32(ctx, esp_get_minimum_free_heap_size());
}

static JSValue js_esp_get_idf_version(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
    return JS_NewString(ctx, esp_get_idf_version());
}

static JSValue js_esp_random(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
    return JS_NewUint32(ctx, esp_random());
}

static JSCFunctionListEntry js_esp_funcs[] = {
        JS_CFUNC_DEF("getFreeHeap", 0, js_esp_get_free_heap_size),
        JS_CFUNC_DEF("getFreeInternalHeap", 0, js_esp_get_free_internal_heap_size),
        JS_CFUNC_DEF("getMinFreeHeap", 0, js_esp_get_minimum_free_heap_size),
        JS_CFUNC_DEF("idfVersion", 0, js_esp_get_idf_version),
        JS_CFUNC_DEF("random", 0, js_esp_random),
};

static const JSCFunctionListEntry js_esp_obj[] = {
        JS_OBJECT_DEF("ESP", js_esp_funcs, countof(js_esp_funcs), JS_PROP_WRITABLE | JS_PROP_CONFIGURABLE ),
};

void esp_api_init(JSContext *ctx)
{
    JS_SetPropertyFunctionList(ctx, JS_GetGlobalObject(ctx), js_esp_obj, countof(js_esp_obj));
}
