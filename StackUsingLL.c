#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *CreateNode(int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> link = NULL;
    return new_node;
}

struct node *Push(struct node *head, struct node *new_node){
    if(head == NULL){
        head = new_node;
    }
    else {
        struct node *temp = head;
        while((*temp).link != NULL){
            temp = (*temp).link;
        }
        (*temp).link = new_node;
    }
    return head;
}

struct node *Pop(struct node *head){
    struct node *temp = head;
    if(head == NULL){
        printf("The stack is empty !!!");
    }
    else {
        while(temp -> link != NULL){
            if((temp ->link)->link == NULL)break;
            temp = temp -> link;
        }
        printf("The element to be poped is  : %d \n", (temp->link)->data);
        temp -> link = NULL;
        if(temp == head){
            head = NULL;
        }
    }
    return head;

}

struct node *View(struct node *head){
    if(head == NULL){
        return head;
    }
    View(head -> link);
    printf("%d -> ", head -> data);
}

void main(){
    int ch, data, t;
    struct node *head = NULL;
    while(1){
        printf("Enter the option 1. Push 2. Pop 3. View 4. Exit \n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the data to push :\n");
                scanf("%d", &data);
                struct node *new_node = CreateNode(data);
                head = Push(head, new_node);
                break;
            case 2: 
                head = Pop(head);
                break;
            case 3: ;
                struct node *temp = View(head);
                break;
            default:
                printf("Wrong options !!");
                break;
        }
        printf("Enter 1 to continue and 0 to exit : \n");
        scanf("%d", &t);
        if(t == 0)break;
    }
}