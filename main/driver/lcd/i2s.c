#include "driver/gpio.h"
#include "driver/i2s.h"

#include "esp_err.h"

#include "iot_i2s_lcd.h"
#include "i2s_lcd_com.h"

#include "error.h"
#include "i2s.h"
#include "lcd.h"
#include "utils.h"

static const char *TAG = "lcd_i2s";

#ifdef CONFIG_IDF_TARGET_ESP32S2
#define DEFAULT_I2S_NUM I2S_NUM_0
#else
#define DEFAULT_I2S_NUM I2S_NUM_1
#endif

#define HANDLE(d) ((i2s_lcd_handle_t)(d->handle))

esp_err_t lcd_i2s_init(lcd_dev_t *dev) {
    ARG_CHECK(dev != NULL, ERR_PARAM_NULL);
    ARG_CHECK(dev->config.data_width == 8, "data_width must be 8");
    ARG_CHECK(dev->config.ws_io_num != GPIO_NUM_NC, "ws_io_num is GPIO_NUM_NC");
    ARG_CHECK(dev->config.rs_io_num != GPIO_NUM_NC, "rs_io_num is GPIO_NUM_NC");

    dev->handle = NULL;

    // Setup the GPIOs as general purpose outputs.
    uint64_t mask = 0;
    if (dev->config.rst_io_num != GPIO_NUM_NC) {
        gpio_pad_select_gpio(dev->config.rst_io_num);
        mask |= BIT64(dev->config.rst_io_num);
    }
    if (dev->config.rd_io_num != GPIO_NUM_NC) {
        gpio_pad_select_gpio(dev->config.rd_io_num);
        mask |= BIT64(dev->config.rd_io_num);
    }
    if (mask) {
        const gpio_config_t conf = {
                .pin_bit_mask = mask,
                .mode = GPIO_MODE_OUTPUT,
                .pull_up_en = GPIO_PULLUP_DISABLE,
                .pull_down_en = GPIO_PULLDOWN_DISABLE,
                .intr_type = GPIO_INTR_DISABLE,
        };
        ESP_ERROR_CHECK(gpio_config(&conf));
    }

    i2s_lcd_config_t *lcd_conf = calloc(1, sizeof(i2s_lcd_config_t));
    lcd_conf->data_width = dev->config.data_width;
    for (int i = 0; i < lcd_conf->data_width; ++i) {
        ARG_CHECK(dev->config.data_io_num[i] != GPIO_NUM_NC, "dev->config.data_io_num is GPIO_NUM_NC");
        lcd_conf->data_io_num[i] = dev->config.data_io_num[i];
    }
    lcd_conf->ws_io_num = dev->config.ws_io_num;
    lcd_conf->rs_io_num = dev->config.rs_io_num;
    i2s_lcd_handle_t handle = iot_i2s_lcd_pin_cfg(DEFAULT_I2S_NUM, lcd_conf);
    if (handle == NULL) {
        SAFE_FREE(lcd_conf);
        return ESP_ERR_INVALID_ARG;
    }

    // Fix the clock. It needs to be at least 3 for 8 bits to work properly.
    I2S_LL_GET_HW(DEFAULT_I2S_NUM)->clkm_conf.clk_en = 0;
    I2S_LL_GET_HW(DEFAULT_I2S_NUM)->clkm_conf.clkm_div_num = 4;
    I2S_LL_GET_HW(DEFAULT_I2S_NUM)->clkm_conf.clk_en = 1;

    dev->handle = handle;
    return ESP_OK;
}

inline void lcd_i2s_write_data16(const lcd_dev_t *dev, uint16_t data) {
    ARG_ERROR_CHECK(dev != NULL, ERR_PARAM_NULL);

    iot_i2s_lcd_write_data(HANDLE(dev), data);
}

inline void lcd_i2s_write_datan(const lcd_dev_t *dev, const uint16_t *buf, size_t len) {
    ARG_ERROR_CHECK(dev != NULL, ERR_PARAM_NULL);
    ARG_ERROR_CHECK(buf != NULL, ERR_PARAM_NULL);
    ARG_ERROR_CHECK(len > 0, ERR_PARAM_LE_ZERO);
    LLOG(TAG, "[%s] buf: %p len: %2d", __FUNCTION__, buf, len);

    iot_i2s_lcd_write(HANDLE(dev), (uint16_t *) buf, len);
}
