#include "wifi.h"
#include "camera.h"
#include "nvs_flash.h"
#include "serial.h"
#include "freertos/FreeRTOS.h"

void app_main() {
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    serial_write("initializing wifi sta.\n");
    wifi_init_sta();

    serial_write("initializing camera.\n");
    camera_init();

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
