#ifndef _HTTP_H
#define _HTTP_H

#include <stddef.h>
#include "cgi.h"

int badrequest(struct cgi_context *ctx);
int notfound(struct cgi_context *ctx);
int forbidden(struct cgi_context *ctx);
int notacceptable(struct cgi_context *ctx);
int internal_server_error(struct cgi_context *ctx);

void content_type_json();
void headers_end();

char **path2vec(char *path, char *identifier);
char *str_dup(const char *c);
char *strn_dup(const char *c, size_t to);

#endif