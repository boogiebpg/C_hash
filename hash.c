#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define HASH_SIZE 10

struct hash {
	unsigned int count;
	char *arr1[HASH_SIZE];
	char *arr2[HASH_SIZE];
};

struct hash* hash_init()
{
	struct hash *my_hash = malloc( sizeof(struct hash) );
	int c = 0;
	while (c < HASH_SIZE)
	{
		my_hash->arr1[c]=NULL;
		my_hash->arr2[c]=NULL;
		c++;
	}
	return my_hash;
}

void insert(struct hash *my_hash, char* key, char* value)
{
	int index;
	index = get_index(my_hash, key);
	if (index == -1)
	{
		index = search_free_place(my_hash);
	}
	if (index != -1)
	{
		my_hash->arr1[index]=key;
		my_hash->arr2[index]=value;
	}
}

void delete(struct hash *my_hash, char* key)
{
	int index = search_free_place(my_hash);
	if (index != -1)
	{
		my_hash->arr1[index]=NULL;
		my_hash->arr2[index]=NULL;
	}
}

char* get(struct hash *my_hash, char* key)
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

int get_index(struct hash *my_hash, char* key)
{
	int c = 0;
	while (c < HASH_SIZE)
	{
		if (my_hash->arr1[c] == key)
		{
			return c;
		}
		++c;
	}
	return -1;
}

int search_free_place(struct hash *my_hash)
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

void iterate(struct hash *my_hash)
{
	int c = 0;
	while (c < HASH_SIZE)
	{
		if (my_hash->arr1[c] != NULL)
		{
			printf("%s - %s\n", my_hash->arr1[c], my_hash->arr2[c]);
		}
		++c;
	}
}

void destroy(struct hash *my_hash)
{
	free(my_hash);
}

int main()
{
	struct hash *my_hash;

	my_hash = hash_init();
	insert(my_hash, "key1", "value1");
	insert(my_hash, "key2", "value2");
	insert(my_hash, "key2", "value3");
	//char* s_val = "key2";
	//char* r_val = get(my_hash, s_val);
	//printf("%s - %s\n", s_val, r_val);
	iterate(my_hash);
	destroy(my_hash);

	return 0;
}