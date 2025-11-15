#include <stdio.h>
struct Node{
    char data;
    struct node *next;
    struct node *back;
};
void insertDll(){

}

int main(){
    struct node *dLL=(struct node *)malloc(sizeof(struct node));
    dLL->back = NULL;


    char arr[] = {'N','a','m','a','n','d','e','e','p'};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < sizeArr;i++){
        insertDll(arr[i]);
    }
        return 0;
}