#ifndef hash_h
#define hash_h
//Linear Probing

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int key;
    char* value;
}item;

typedef struct
{
    int flag;
    item data;
}hashtable;

hashtable* init();
int hashcode(int key);
int insert(item ,hashtable*);
int display(hashtable*);
char* find(int key,hashtable*);

#endif
