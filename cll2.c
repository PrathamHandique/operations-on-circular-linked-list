//*************************************************************************************8*******************************************************
//*****************************************operations on circular linked list******************************************************************
#include<stdio.h>
#include<stdlib.h>
struct node{
     int data;
     struct node *next;
};
void linkedlisttraversal(struct node *head){
    struct node *ptr=head;
    do{
        printf("Element is %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
struct node * insertatfirst(struct node *head,int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}
struct node * insertatend(struct node *head,int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    p=ptr;
    return p;
};
struct node * insertatpos(struct node *head,int data,int index){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p=head;
    int i=1;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    }
struct node* delfrombeg(struct node *head){
    struct node *ptr=head;
   while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=head->next;
    free(head);
    head=ptr->next;
    return head;

}
struct node* delfromend(struct node *head){
    struct node *ptr=head;
    struct node *q=head->next;
   while(q->next!=head){
        ptr=ptr->next;
        q=q->next;
    }
    ptr->next=q->next;
    free(q);
    }
struct node*delatpos(struct node*head,int index){
     struct node *p=head;
     struct node *q=head->next;
    int i=1;
    while(i!=index-1){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);

}

int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=fourth;
    fourth->data=4;
    fourth->next=head;
    // printf("circular linked list before insertion\n");
    linkedlisttraversal(head);
    /*head = insertatfirst(head, 10);
    head = insertatfirst(head, 20);
    head = insertatfirst(head, 30);
    insertatend(head,5);
    insertatpos(head,8,5);
    printf("circular linked list after insertion\n");
    printf("circular linked list after deletion\n");
    //head=delfrombeg(head);
    delfromend(head);*/
    delatpos(head,3);


    linkedlisttraversal(head);
    return 0;


}
