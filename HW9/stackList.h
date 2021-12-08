#ifndef __STACK_LIST
#define __STACK_LIST

typedef struct stackNode{
  char pathDir[512];
  struct stackNode* next;
}stackNode;

void addNodeStk(stackNode** head,stackNode** tail,char* path){
  stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
  strcpy(newNode->pathDir,path);
  newNode->next = NULL;
  if(*head == NULL) *head = newNode;
  if(*tail != NULL) (*tail)->next = newNode;
  *tail=newNode;
}
void displayAllDir(stackNode* head){
  if(head == NULL){
    printf("there is no directory\n");
    return;
  }
  stackNode* ptr = head;
  while(ptr != NULL){
    printf("%s\n",ptr->pathDir);
    ptr=ptr->next;
  }
}
void destroyStackList(stackNode** head){
  stackNode* ptr = *head,*nextPtr = ptr->next;
  while(nextPtr != NULL){
    free(ptr);
    ptr=nextPtr;
    nextPtr=nextPtr->next;
  }
  free(ptr);
}

void pop(stackNode** head){
  stackNode* ptr = *head;
  *head=(*head)->next;
  free(ptr);
}

#endif