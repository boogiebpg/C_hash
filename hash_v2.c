#include "hash.h"

struct hash* hash_init(char *hash_type)
{
	struct hash *my_hash = malloc( sizeof(struct hash) );
	
	int c = 0;
	while (c < HASH_SIZE)
	{
		my_hash->arr1[c]=NULL;
		my_hash->arr2[c]=NULL;
		c++;
	}
	my_hash->hash_type = hash_type;

	return my_hash;
}

void destroy_list_or_tree(char* hash_type, void* element)
{
	// free old linked_list from slot
		if ( !strncmp(hash_type, "list", 4) )
			list_destroy(element);
		// free old binary_tree from slot
		else if ( !strncmp(hash_type, "tree", 4) )
			destroy_tree(element);
}

void hash_insert(struct hash *my_hash, char* key, void* value)
{
	int index;
	index = hash_from_str(key);
	// found needed slot for insertion, it used
	if (index != -1)
	{
		//destroy_list_or_tree(my_hash->hash_type, my_hash->arr2[index]);
		my_hash->arr1[index]=key;
		my_hash->arr2[index]=value;
	}
	// not found needed slot in used ones, search in free slots
	else
	{
		index = hash_search_free_place(my_hash);
	}
}

void hash_delete(struct hash *my_hash, char* key)
{
	int index = hash_search_free_place(my_hash);
	if (index != -1)
	{
		my_hash->arr1[index]=NULL;
		destroy_list_or_tree(my_hash->hash_type, my_hash->arr2[index]);
	}
}

void* hash_get(struct hash *my_hash, char* key)
{
	int c = 0;
	while (c < HASH_SIZE)
	{
		if (my_hash->arr1[c] == key)
		{
			return my_hash->arr2[c];
		}
		++c;
	}
	return NULL;
}

int hash_search_free_place(struct hash *my_hash)
{
	int c = 0;
	while (c < HASH_SIZE)
	{
		if (my_hash->arr1[c] == NULL)
		{
			return c;
		}
		++c;
	}
	return -1;
}

void hash_iterate(struct hash *my_hash)
{
	int c;
	for (c = 0; c < HASH_SIZE; c++)
	{
		if (my_hash->arr1[c] != NULL)
		{
			if ( !strncmp(my_hash->hash_type, "list", 4) )
				printf("%s - [list]\n", my_hash->arr1[c]);
			else if ( !strncmp(my_hash->hash_type, "tree", 4) )
				printf("%s - [tree]\n", my_hash->arr1[c]);
		}
	}
}

static unsigned int hash_from_str(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++) {
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	hash = hash % HASH_SIZE;
	return hash;
}

void hash_destroy(struct hash *my_hash)
{
	int c;
	for (c = 0; c < HASH_SIZE; c++)
	{
		if (my_hash->arr1[c] != NULL)
		{
			destroy_list_or_tree(my_hash->hash_type, my_hash->arr2[c]);
		}
	}
	free(my_hash);
}
