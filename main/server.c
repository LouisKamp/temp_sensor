#ifndef SERVER_INCLUDED
#define SERVER_INCLUDED

#include "esp_http_server.h"
#include "handlers.c"

static httpd_handle_t httpServerInstance = NULL;

static void startHttpServer(void)
{
    httpd_config_t httpServerConfiguration = HTTPD_DEFAULT_CONFIG();
    httpServerConfiguration.server_port = SERVER_PORT;
    if (httpd_start(&httpServerInstance, &httpServerConfiguration) == ESP_OK)
    {
        ESP_ERROR_CHECK(httpd_register_uri_handler(httpServerInstance, &readUri));
    }
}

static void stopHttpServer(void)
{
    if (httpServerInstance != NULL)
    {
        ESP_ERROR_CHECK(httpd_stop(httpServerInstance));
    }
}

#endif