#ifndef HTTP_SERVER_H_
#define HTTP_SERVER_H_

#include "HttpService.h"

#define DEFAULT_HTTP_PORT   80
typedef struct http_server_s {
    int port;
    int worker_processes;
    HttpService* service;
//private:
    int listenfd;

#ifdef __cplusplus
    http_server_s() {
        port = DEFAULT_HTTP_PORT;
        worker_processes = 0;
        service = NULL;
        listenfd = -1;
    }
#endif
} http_server_t;

/*
#include "http_server.h"

void http_api_hello(HttpRequest* req, HttpResponse* res) {
    res->body = "hello";
}

int main() {
    HttpService service;
    service.AddApi("/hello", http_api_hello);

    http_server_t server;
    server.port = 8080;
    server.worker_processes = 4;
    server.service = &service;
    http_server_run(&server);
    return 0;
}
 */
int http_server_run(http_server_t* server, int wait = 1);

#endif