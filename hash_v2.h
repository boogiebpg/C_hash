#ifndef HASH_H_
#define HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "../C_linked_list/linked_list.h"
#include "../C_binary_tree/binary_tree.h"

#define HASH_SIZE 128

struct hash {
	char *hash_type;
	char *arr1[HASH_SIZE];
	void *arr2[HASH_SIZE];
};

struct hash* hash_init(char* hash_type);
void destroy_list_or_tree(char* hash_type, void* element);
void hash_insert(struct hash *my_hash, char* key, void* value);
void hash_delete(struct hash *my_hash, char* key);
void* hash_get(struct hash *my_hash, char* key);
int hash_search_free_place(struct hash *my_hash);
void hash_iterate(struct hash *my_hash);
void hash_destroy(struct hash *my_hash);
static unsigned int hash_from_str(const char *str);

#endif