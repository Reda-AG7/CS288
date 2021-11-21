#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



typedef struct node{
	int data;
	struct node* next;
}node;

void addNode(node** head,node** tail){
	int i = 1,x=0;
	while(true) {
		printf("input data for node %d :",i++);
		if(scanf("%d",&x) == EOF) break;
		node* newNode = (node*) malloc(sizeof(node));
		newNode->data = x;
		newNode->next = NULL;
		if(*head == NULL) *head = newNode;
		if(*tail != NULL) (*tail)->next = newNode;
		*tail = newNode; 
	}
	printf("\n");
}
void reverseList(node** head,node** tail){
	if(*head == NULL || (*head)->next == NULL) return;
	else{
		node* prevPtr=NULL,*ptr=*head,*nextPtr = ptr->next;
		*tail = *head;
		while(nextPtr != NULL){
			ptr->next = prevPtr;
			prevPtr = ptr;
			ptr=nextPtr;
			nextPtr = nextPtr->next;
		}
		ptr->next = prevPtr;
		*head = ptr;
	}
}
void destroyList(node* head){
	if(head != NULL){
		node* ptr = head;
		node* nextPtr = ptr->next;
		while(nextPtr != NULL){
			free(ptr);
			ptr = nextPtr;
			nextPtr = nextPtr->next;
		}
		free(ptr);
	}
}
void displayList(node* head){
	if(head != NULL){
		node* ptr =  head;
		while(ptr != NULL){
			printf("data = %d\n",ptr->data);
			ptr=ptr->next;
		}
	}
}
int main(){
	node* head=NULL,*tail=NULL;  
	addNode(&head,&tail);
	printf("\n\ndata entered in the list : \n");
	displayList(head);
	printf("\n**********************\n");
	reverseList(&head,&tail);
	printf("the list in reverse : \n");
	displayList(head);
	destroyList(head);

return  0;
}
