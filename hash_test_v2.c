#include "hash.h"

int main()
{
	struct hash *my_hash, *my_hash2;
	int x;

	/* Testing Hash with Linked List items */

	struct list_t *root, *root2, *root3;
    int a=43,b=63,c=99,d=70,e=25,f=17,g=57,h=69,i=111,j=120,k=70,l=73,m=75;

    root = list_init();
    root2 = list_init();
    root3 = list_init();

	root = list_remove_rear(root);
    root = list_remove_any(root,&k);
    root = list_remove_front(root);

    list_insert_rear(root, &a);
    list_insert_rear(root, &b);
    
    root = list_insert_after(root,&c,3);
    list_insert_rear(root, &d);
    
    root = list_insert_front(root, &e);
    root = list_insert_front(root, &f);
    
    list_insert_rear(root, &g);
    root = list_remove_front(root);
    
    list_insert_rear(root, &h);
    
    root = list_insert_after(root,&i,5);
    root = list_insert_after(root,&j,120);
    
    root = list_remove_any(root,&k);

    root = list_remove_front(root);
    list_insert_rear(root, &l);
    root = list_remove_any(root,&l);

    list_insert_rear(root, &m);
    
    
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    root = list_remove_rear(root);
    
	my_hash = hash_init("list");

	hash_insert(my_hash, "key1", root);
	hash_insert(my_hash, "key2", root2);
	hash_insert(my_hash, "key3", root3);

	printf("%s\n",my_hash->hash_type);

	char* s_val = "key2";
	char* r_val = hash_get(my_hash, s_val);
	printf("%s - %s\n", s_val, r_val);
	hash_iterate(my_hash);
	hash_destroy(my_hash);

	/* Testing Hash with Binary Tree items */

	struct node *root_node = NULL, *root_node2 = NULL, *root_node3 = NULL;

	root_node = insert(root_node,5,NULL);
    root_node = delete_node(root_node,5);
    root_node = insert(root_node,7,NULL);
    root_node = insert(root_node,3,NULL);
    root_node = insert(root_node,6,NULL);
    root_node = insert(root_node,9,NULL);
    root_node = insert(root_node,12,NULL);
    root_node = insert(root_node,1,NULL);
    print_preorder(root_node);
    root_node = delete_node(root_node,7);

    my_hash2 = hash_init("tree");
	hash_insert(my_hash2, "key1", root_node);
	hash_insert(my_hash2, "key2", root_node2);
	hash_insert(my_hash2, "key3", root_node3);

	hash_iterate(my_hash2);
	hash_destroy(my_hash2);

	return 0;
}