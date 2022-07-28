#ifndef HANDLERS_INCLUDED
#define HANDLERS_INCLUDED

#include "string.h"
#include "driver/gpio.h"
#include "esp_http_server.h"
#include "constants.c"
#include "esp_log.h"
#include "driver/adc.h"

static esp_err_t onHandler(httpd_req_t *httpRequest)
{
    ESP_LOGI("HANDLER", "This is the handler for the <%s> URI", httpRequest->uri);
    gpio_set_level(GPIO_OUTPUT_IO_2, 1);
    const char resp[] = "ON!";
    ESP_ERROR_CHECK(httpd_resp_send(httpRequest, resp, HTTPD_RESP_USE_STRLEN));
    return ESP_OK;
}

static esp_err_t offHandler(httpd_req_t *httpRequest)
{
    ESP_LOGI("HANDLER", "This is the handler for the <%s> URI", httpRequest->uri);
    gpio_set_level(GPIO_OUTPUT_IO_2, 0);
    const char resp[] = "OFF!";
    ESP_ERROR_CHECK(httpd_resp_send(httpRequest, resp, HTTPD_RESP_USE_STRLEN));
    return ESP_OK;
}

static esp_err_t readHandler(httpd_req_t *httpRequest)
{
    ESP_LOGI("HANDLER", "This is the handler for the <%s> URI", httpRequest->uri);

    char resp[80];

    uint16_t data;
    adc_read(&data);

    sprintf(resp, "VALUE: %i", data);

    ESP_LOGI("INFO", "VALUE: %i", data);

    ESP_ERROR_CHECK(httpd_resp_send(httpRequest, resp, HTTPD_RESP_USE_STRLEN));
    return ESP_OK;
}

static httpd_uri_t onUri = {
    .uri = "/on",
    .method = HTTP_POST,
    .handler = onHandler,
    .user_ctx = NULL,
};

static httpd_uri_t offUri = {
    .uri = "/off",
    .method = HTTP_POST,
    .handler = offHandler,
    .user_ctx = NULL,
};

static httpd_uri_t readUri = {
    .uri = "/read",
    .method = HTTP_GET,
    .handler = readHandler,
    .user_ctx = NULL,
};

#endif