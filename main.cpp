#include <stdio.h>
#include <iostream>

using namespace std;

void swap(int *a, int *b){
	if(*a != *b){
		*a = *a ^ *b;
		*b = *a ^ *b;
		*a = *a ^ *b;
	}
}

/* a node of the linked list */
struct node
{
    int data;
    //存下一個node的記憶體位址,
    //這個pointer的形態是node
    struct node *next;
};

void init(struct node *head){
    head = NULL;
}

// A utility function to find last node of linked list
struct node *lastNode(node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}

/* Function to insert a node at the beginging of the Doubly Linked List */
struct node *push(struct node* head, int new_data)
{
    //malloc / calloc 回傳的形態都是 (void *)
    //所以不論哪種形態回傳的時候都需要type casting
    //(struct node*) 或者 (int *) 通通要
    struct node *tmp = (struct node*)malloc(sizeof(struct node));

    if(tmp == NULL){
        //malloc失敗
        exit(0);
    }
    //malloc成功
    tmp->data = new_data;
    tmp->next = head;
    //pointer = pointer
    //把tmp所在的記憶體位址指定給head這個pointer
    head = tmp;
    return head;
}

// A utility function to print contents of arr
void display(struct node* head)
{
    struct node *current;
    
    current = head;
    if(current!= NULL)
    {
        printf("Stack: ");
        do
        {
            printf("%d ",current->data);
            current = current->next;
        }
        while (current!= NULL);
        printf("\n");
    }
    else
    {
        printf("The Stack is empty\n");
    }
 
}



int main(int argc, const char * argv[])
{

    struct node *head = NULL;
    int size, element;
    int counter = 0;
    printf("Enter the number of stack elements:");
    scanf("%d",&size);

    init(head);

    while(counter < size){
        printf("Enter a number to push into the stack:");
        scanf("%d",&element);
        head = push(head, element);
        display(head);
        counter++;
    }

    return 0;
}