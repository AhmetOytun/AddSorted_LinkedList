#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct node{
    int data;
    struct node *next;
};

struct node *head;

void add_sorted(int data);
void show();
void remove_data_from_list(int data);
void menu();

bool runs=true;

int main(){

    printf("### Choose an option ###\n");
    printf("REMEMBER: List is always going to be sorted.\n");

    do{
        menu();
    } while (runs);

    return 0;
}

void menu(){

    int choice;

    printf("1.Add data to the list\n");
    printf("2.Remove data from the list\n");
    printf("3.Show the list\n");

    printf("Press any other key for exit\n");

    scanf("%d",&choice);

    switch (choice){

        int data;

        case 1:
            printf("Insert the data that you want to add");
            scanf("%d", &data);
            add_sorted(data);
            system("clear");
            printf("Data has been added.\n");
            break;

        case 2:
            printf("Insert the data that you want to remove");
            scanf("%d", &data);
            system("clear");
            remove_data_from_list(data);
            break;

        case 3:
            system("clear");
            printf("Showing the list:\n");
            show();
            break;

        default:
            runs=false;
            return;
    }
}

void add_sorted(int data){
    if(head==NULL){
        head=malloc(sizeof(struct node));
        head->data=data;
        head->next=NULL;
    }else{
        struct node *prev=NULL;
        struct node *temp=head;
        struct node *curr=malloc(sizeof(struct node));

        curr->data=data;
        while(true){
            if(head->data>=data){
                curr->next=head;
                head=curr;
                break;
            }else{
                if(temp!=NULL && temp->data<data){
                    prev=temp;
                    temp=temp->next;
                }else{
                    prev->next=curr;
                    curr->next=temp;
                    break;
                }
            }
        }
    }
}

void show(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void remove_data_from_list(int data){
    struct node *curr=head;
    struct node *prev=NULL;

    while(curr!=NULL){
        if(curr->data==data){
            if(prev==NULL){
                head=curr->next;
                printf("Data has been removed\n");
                free(curr);
                return;
            }else {
                prev->next = curr->next;
                printf("Data has been removed\n");
                free(curr);
                return;
            }
        }
        prev=curr;
        curr=curr->next;
    }
    printf("Element is not in array\n");
}