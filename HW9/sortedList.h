#ifndef __SORTED_LIST
#define __SORTED_LIST
#include<string.h>
#include<stdbool.h>
static int count = 0;

typedef struct node {
  char pathName[1024];
  long int size;
  struct node* next;
}node;


void addNode(node** head,const char* path,long int s){
  //generating a new node
  count++;
  node* newNode = (node*) malloc(sizeof(node));
  newNode->size = s;
  strcpy(newNode->pathName,path);
  newNode->next = NULL;

  // sorting it
  if(*head == NULL) *head = newNode;
  else{
    if((*head)->size > s){
      newNode->next = *head;
      *head = newNode;
    }
    else{
      node* ptr = *head,*nextPtr = ptr->next;
      bool found = false;
      while(nextPtr != NULL){
        if(nextPtr->size >s){
          ptr->next = newNode;
          newNode->next = nextPtr;
          found = true;
          break;
        }
        ptr = nextPtr;
        nextPtr = nextPtr->next;
      }
      if(!found) ptr->next = newNode;
    }
  }
}

void displayList(node* head){
  if(head == NULL) printf("The list is empty\n");
  else{
    node* ptr = head;
    while(ptr != NULL){
      printf("%lu\t\t%s\n",ptr->size,ptr->pathName);
      ptr=ptr->next;
    }
  }
}

void destroyList(node** head){
  if(*head == NULL) return;
  node* ptr = *head,*nextPtr = ptr->next;
  while(nextPtr != NULL){
    free(ptr);
    ptr = nextPtr;
    nextPtr = nextPtr->next;
  }
  free(ptr);
}
#endif
