#include <stdio.h>
#include <stdlib.h>

//creating structure for storing node data;
struct node{
    int data;
    struct node *link;
};

struct node *CreateNewNode(int data){
    //allocating memory using malloc;
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
    //dereferencing the pointer to update the value;
	(*new_node).data = data;
    (*new_node).link = NULL;
    return new_node;
}

struct node *InsertNode(struct node *new_node, struct node *head){
    if(head == NULL){
        head = new_node;
    }
    else {
        struct node *temp = head;
        //we should use (*temp).link != NULL and should not use temp != NULL;
        while((*temp).link != NULL){
            temp = (*temp).link;
        }
        (*temp).link = new_node;
    }
    return head;
}

struct node *InsertNodeMiddle(struct node *new_node, int pos, struct node *head, int len){
    int cnt = 0;
    struct node* temp = head;
    if(pos == 1){
        (*new_node).link = (*head).link;
        (*head).link = new_node;
        return head;
    }
    //traverse till the postion then do the operation;
    while(cnt < pos){
        if(cnt > len){
            printf("Not a valid position to insert :(\n");
            return head;
        }
        temp = (*temp).link;
        cnt++;
    }
    printf("%d\n", (*temp).data);
    (*new_node).link = (*temp).link;
    (*temp).link = new_node;
}

struct node *DeleteNode(int pos, struct node* head){
    int cnt = 0;
    if(head == NULL)return head;
    if(pos == 1){
        head = (*head).link;
        return head;
    }
    struct node *temp = head;
    while(cnt != pos - 2){
        temp = (*temp).link;
    }
    (*temp).link =  (*(*temp).link).link;
    return head;
}

int LenghtOfLinkedList(struct node *head){
    int count = 0;
    struct node *temp = head;
    while((*temp).link != NULL){
        temp = (*temp).link;
        count++;
    }
    return count;
}
void traverse(struct node *head){
    int i = 0;
    struct node *temp = head;
    while(temp != NULL){
        printf("node %d: %d\n", i, (*temp).data);
        temp = (*temp).link;
        ++i;
    }
}

void main(){
    int ch, cnt , n, data, pos, len;
    struct node *head = NULL;
    while(1){
        printf("Enter the option : ");
        scanf("%d", &ch);
        switch(ch){
            case 1: 
                printf("Enter the number of nodes :");
                scanf("%d", &n);
                while(n--){
                    printf("Enter the data for the node : ");
                    scanf("%d", &data);
                    struct node *new_node = CreateNewNode(data);
                    head = InsertNode(new_node, head);
                }
                break;
            case 2:
                printf("Enter the data and position to insert: \n");
                scanf("%d%d", &data, &pos);
                struct node *new_node = CreateNewNode(data);
                len = LenghtOfLinkedList(head);
                head = InsertNodeMiddle(new_node, pos, head, len);
                break;
            case 3:
                printf("Enter the node position to be deleted :\n");
                scanf("%d", &pos);
                head = DeleteNode(pos, head);
            case 4:
                traverse(head);
                break;
            default:
                printf("please enter a valid option");
                break;
        }
        printf("To continue press 0 or else press 1 to continue \n");
        scanf("%d", &cnt);
        if(cnt == 0)break;
    }
	
}