#ifndef HANDLERS_INCLUDED
#define HANDLERS_INCLUDED

#include "string.h"
#include "driver/gpio.h"
#include "esp_http_server.h"
#include "constants.c"
#include "esp_log.h"
#include "driver/adc.h"
#include "math.h"

const double v = 3.3;
const double r_2 = 10000;
const double zero_C_in_K = 273.15;
double get_temp_in_C()
{
    uint16_t data;
    adc_read(&data);

    double v_r2 = ((double)data / 1023) * v;
    double r_1 = (v - v_r2) * (r_2 / v_r2);

    double T_k = 0.1265625000e11 / (0.1366695684e8 + 0.3125000000e7 * log(r_1));
    double T_c = T_k - zero_C_in_K;

    return T_c;
}

static esp_err_t readHandler(httpd_req_t *httpRequest)
{
    ESP_LOGI("HANDLER", "This is the handler for the <%s> URI", httpRequest->uri);

    char resp[80];
    double T_c = get_temp_in_C();

    sprintf(resp, "VALUE: %i C", (int)(T_c));

    ESP_ERROR_CHECK(httpd_resp_send(httpRequest, resp, HTTPD_RESP_USE_STRLEN));
    return ESP_OK;
}

static httpd_uri_t readUri = {
    .uri = "/readTemp",
    .method = HTTP_GET,
    .handler = readHandler,
    .user_ctx = NULL,
};

#endif