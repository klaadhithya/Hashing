#include "hash.h"

//int size = 0;
int max = 10;


hashtable* init()
{
    int i;
    hashtable *array;
    array=(hashtable*)malloc(max*sizeof(hashtable));
    for (i = 0; i < max; i++)
    {
	array[i].flag = 0;
	array[i].data.key=-1;
	array[i].data.value=(char*)malloc(20*sizeof(char));
    }
    return array;
}

int hashcode(int key)
{
    return (key % max);
}

int insert(item x,hashtable *array)
{
    int key=x.key;
    int index = hashcode(key);
    int i = index;

    while (array[i].flag == 1)
    {
        if (array[i].data.key == key)
        {
            //printf("\n Key already exists, hence updating its value \n");
            //array[i].data->value = value;
            printf("Username already exists!!");
            return;
        }
        i = (i + 1) % max;
        if (i == index)
        {
            printf("\n Hash table is full, cannot insert any more item \n");
            return;
        }
    }
    array[i].flag = 1;
    array[i].data.key = x.key;
    strcpy(array[i].data.value,x.value);
    //size++;
    printf("\n Key (%d) has been inserted \n", key);
}

 /*void remove_element(int key)
{
    int index = hashcode(key);
    int  i = index;

    while (array[i].flag != 0)
    {

	if (array[i].flag == 1  &&  array[i].data->key == key )
        {


		array[i].flag =  2;
		array[i].data = NULL;
		size--;
		printf("\n Key (%d) has been removed \n", key);
		return;

	}
	i = (i + 1) % max;
	if (i == index)
        {
		break;
	}

    }

    printf("\n This key does not exist \n");
}
*/

int display(hashtable* array)
{
    int i;
    for (i = 0; i < max; i++)
    {
        int key = array[i].data.key;
        if (key==-1)
        {
            //printf("\n Array[%d] has no elements \n", i);
            //return-1;
        }
        else
        {
            printf("\n Array[%d] has elements -: \n  %d (key) and %s(value) \n", i,key,array[i].data.value);
        }
    }
}

char* find(int key,hashtable* array)
{
    int index = hashcode(key);
    int i = index;

    if(array[i].flag==0)
        return -1;

    while (array[i].flag == 1)
    {
        if (array[i].data.key == key)
        {
            return array[i].data.value;
        }
        i = (i + 1) % max;
        if (i == index)
        {
            //Not found
            return -1;
        }
    }

}


