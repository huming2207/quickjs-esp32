/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

#include "quickjs-libc.h"

const uint32_t qjsc_test_size = 103;

const uint8_t qjsc_test[103] = {
        0x01, 0x04, 0x0e, 0x63, 0x6f, 0x6e, 0x73, 0x6f,
        0x6c, 0x65, 0x06, 0x6c, 0x6f, 0x67, 0x4a, 0x68,
        0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x77, 0x6f, 0x72,
        0x6c, 0x64, 0x20, 0x66, 0x72, 0x6f, 0x6d, 0x20,
        0x45, 0x53, 0x50, 0x33, 0x32, 0x2c, 0x20, 0x77,
        0x69, 0x74, 0x68, 0x20, 0x51, 0x75, 0x69, 0x63,
        0x6b, 0x4a, 0x53, 0x21, 0x0e, 0x74, 0x65, 0x73,
        0x74, 0x2e, 0x6a, 0x73, 0x0e, 0x00, 0x06, 0x00,
        0xa0, 0x01, 0x00, 0x01, 0x00, 0x03, 0x00, 0x00,
        0x14, 0x01, 0xa2, 0x01, 0x00, 0x00, 0x00, 0x38,
        0xd1, 0x00, 0x00, 0x00, 0x42, 0xd2, 0x00, 0x00,
        0x00, 0x04, 0xd3, 0x00, 0x00, 0x00, 0x24, 0x01,
        0x00, 0xcc, 0x28, 0xa8, 0x03, 0x01, 0x00,
};


void app_main(void)
{
    /* Print chip information */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("This is %s chip with %d CPU cores, WiFi%s%s, ",
            CONFIG_IDF_TARGET,
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    printf("silicon revision %d, ", chip_info.revision);

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    printf("Minimum free heap size: %d bytes\n", esp_get_minimum_free_heap_size());


    JSRuntime *rt;
    JSContext *ctx;
    rt = JS_NewRuntime();
    js_std_init_handlers(rt);
    ctx = JS_NewContextRaw(rt);
    JS_SetModuleLoaderFunc(rt, NULL, js_module_loader, NULL);
    JS_AddIntrinsicBaseObjects(ctx);
    JS_AddIntrinsicDate(ctx);
    JS_AddIntrinsicEval(ctx);
    JS_AddIntrinsicStringNormalize(ctx);
    JS_AddIntrinsicRegExp(ctx);
    JS_AddIntrinsicJSON(ctx);
    JS_AddIntrinsicProxy(ctx);
    JS_AddIntrinsicMapSet(ctx);
    JS_AddIntrinsicTypedArrays(ctx);
    JS_AddIntrinsicPromise(ctx);
    js_std_add_helpers(ctx, 0, NULL);
    js_std_eval_binary(ctx, qjsc_test, qjsc_test_size, 0);
    js_std_loop(ctx);
    JS_FreeContext(ctx);
    JS_FreeRuntime(rt);


    vTaskDelay(portMAX_DELAY);
}
