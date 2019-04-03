#ifndef _RESTCONF_UCI_H
#define _RESTCONF_UCI_H

#include <stddef.h>
#include <uci.h>
#include "generated/yang.h"

/**
 * A structure to represent the path to an UCI object
 */
struct uci_path {
  char *package;
  char *section;
  char *section_type;
  char *option;
  int where;
  int index;
};

struct uci_where {
  struct uci_path *path;
  map_str2str *key_value;
  int key_value_length;
};

#define INIT_UCI_PATH() \
  { "", "", "", "", 0, 0 }

int uci_read_option(char *path, char *buffer, size_t size);
char **uci_read_list(char *path);
int uci_path_exists(char *path);
int uci_index_where(struct uci_where *where);
int uci_write_option(char *path, const char *value);
int uci_write_list(char *path, const char *value);
int uci_list_length(struct uci_path *path);
struct uci_section *uci_add_section_anon(char *package_name, char *type);
int uci_add_section_named(char *package_name, const char *type, char *name);

#endif  //_YANG_UCI_H