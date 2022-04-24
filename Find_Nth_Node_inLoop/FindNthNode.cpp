#include<stdio.h>
#include<stdlib.h>
//structure of a node
struct node{
   int data;
   struct node *next;
}*head,*temp;
int count=0;
//function for inserting nodes into a list
void insert(int val){
   struct node* newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = val;
   newnode->next = NULL;
   if(head == NULL){
      head = newnode;
      temp = head;
      count++;
   } else {
      temp->next=newnode;
      temp=temp->next;
      count++;
   }
}
//function for displaying a list
void display(){
   if(head==NULL)
      printf("no node ");
   else {
      temp=head;
      while(temp!=NULL) {
         printf("%d ",temp->data);
         temp=temp->next;
      }
   }
}
//function for finding 3rd node from the last of a linked list
void last(int n){
   int i;
   temp=head;
   for(i=0;i<count-n;i++){
      temp=temp->next;
   }
   printf("\n%drd node from the end of linked list is : %d" ,n,temp->data);
}
int main(){
   //creating list
   struct node* head = NULL;
   int n=3;
   //inserting elements into a list
   insert(0);
   insert(1);
   insert(2);
   insert(3);
   insert(1);
//    insert(5);
//    insert(6);
   //displaying the list
   printf("\nlinked list is : ");
   display();
   //calling function for finding nth element in a list from last
   last(n);
   return 0;
}