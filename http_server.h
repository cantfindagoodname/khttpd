#ifndef KHTTPD_HTTP_SERVER_H
#define KHTTPD_HTTP_SERVER_H

#include <linux/workqueue.h>
#include <net/sock.h>

struct http_server_param {
    struct socket *listen_socket;
};

struct khttpd_daemon {
    bool is_stopped;
    struct list_head worker;
};

struct fastservice {
    struct socket *socket;
    struct work_struct work_item;
    struct list_head list;
};

extern int http_server_daemon(void *arg);

#endif
