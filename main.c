#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
//Username Password Login
#include<string.h>

int main()
{
    int i,ch;char c,val[20];
    hashtable *a;
    a=init();
    item x;
    x.value=(char*)malloc(20*sizeof(char));
    char* y;
    y=(char*)malloc(20*sizeof(char));

    do
    {
        printf("Enter 1.Register user 2.Login 3.Display Hash Table 4.Exit:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter number of registrations to be done::");
            scanf("%d",&i);
            while(i--)
            {
                printf("Enter username:");scanf("%d",&x.key);
                printf("Enter password:");scanf("%s",x.value);
                insert(x,a);//display(a);
            }
            break;
        case 2:
            printf("Enter Username:");scanf("%d",&x.key);
            printf("Enter Password:");scanf("%s",val);
            y=find(x.key,a);
            if(strcmp(val,y)==0)
                printf("Login Success!!\n");
            else
                printf("Invalid Login!!\n");
            break;
        case 3:
            display(a);
            break;
        default:
            exit(0);
        }
        printf("Enter y to continue:");
        scanf(" %c",&c);
    }while(c=='y');

    return 0;
}
