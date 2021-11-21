#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
	int data;
	struct node* next;
}node;

void addNode(node** head, node** tail,int* count) {
	int i = 1, x = 0;
	while (true) {
		printf("input data for node %d :", i++);
		if (scanf("%d",&x)== EOF) break;
		node* newNode = (node*) malloc(sizeof(node));
		newNode->data = x;
		newNode->next = NULL;
		(*count)++;
		if (*head == NULL) *head = newNode;
		if (*tail != NULL) (*tail)->next = newNode;
		*tail = newNode;
	}
	printf("\n");
}
void bubbleSort(node** head, node** tail,int count) {
	if (count <= 1) return;
	else {
		node* newTail = NULL;
		for (int pass = 0; pass < count; pass++) {
			node* prevPtr = NULL, * ptr = *head, * nextPtr = ptr->next;
			bool flag = false;
			while (nextPtr != newTail) {
				if (ptr->data > nextPtr->data) {
					if (prevPtr == NULL) {
						ptr->next = nextPtr->next;
						nextPtr->next = ptr;
						*head = nextPtr;
					}
					else {
						node* temp = nextPtr->next;
						prevPtr->next = nextPtr;
						nextPtr->next = ptr;
						ptr->next = temp;
					}
					prevPtr = nextPtr;
					nextPtr = ptr->next;
					flag = true;
				}
				else {
					prevPtr = ptr; ptr = nextPtr; 
					nextPtr = nextPtr->next;
				}
			}
			newTail = ptr;
			if (newTail->next == NULL) *tail = newTail;
			if (!flag) 
				break;
		}
	}
}
void destroyList(node* head) {
	if (head != NULL) {
		node* ptr = head;
		node* nextPtr = ptr->next;
		while (nextPtr != NULL) {
			free(ptr);
			ptr = nextPtr;
			nextPtr = nextPtr->next;
		}
		free(ptr);
	}
}
void displayList(node* head) {
	if (head != NULL) {
		node* ptr = head;
		while (ptr != NULL) {
			printf("data = %d\n", ptr->data);
			ptr = ptr->next;
		}
	}
}
int main() {
	node* head = NULL, * tail = NULL;
	int count = 0;
	addNode(&head, &tail,&count);
	printf("\n\ndata entered in the list : \n");
	displayList(head);
	printf("\n**********************\n");
	printf("%d\n", count);
	bubbleSort(&head, &tail,count);
	printf("the list sorted : \n");
	displayList(head);
	destroyList(head);

	return  0;
}
