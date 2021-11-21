#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include "gengem.c"
#define n 4

int xMoves[4] = {0,0,-1,1};
int yMoves[4] = {-1,1,0,0};
int goal[n][n] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
typedef struct node{
  int puzzle[n][n];
  int f,g,h;
  struct node* next,*prev;
  int prevXpos,prevYpos,currXpos,currYpos;
}node;

node* p_front = NULL;
node* front =NULL,*rear = NULL;

node* result = NULL;

bool search(node*); //function signature

void getH(node* puzzle){
  int total = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      switch (puzzle->puzzle[i][j]){
        case 1: total += (abs(0-i) + abs(0-j));
            break;
        case 2: total += (abs(0-i) + abs(1-j));
            break;
        case 3: total += (abs(0-i) + abs(2-j));
             break;
        case 4: total += (abs(0-i) + abs(3-j));
            break;
        case 5: total += (abs(1-i) + abs(0-j));
            break;
        case 6: total += (abs(1-i) + abs(1-j));
            break;
        case 7: total += (abs(1-i) + abs(2-j));
            break;
        case 8: total += (abs(1-i) + abs(3-j));
            break; 
	case 9: total += (abs(2-i) + abs(0-j));
            break;
        case 10: total += (abs(2-i) + abs(1-j));
            break;
        case 11: total += (abs(2-i) + abs(2-j));
             break;
        case 12: total += (abs(2-i) + abs(3-j));
            break;
        case 13: total += (abs(3-i) + abs(0-j));
            break;
        case 14: total += (abs(3-i) + abs(1-j));
            break;
        case 15: total += (abs(3-i) + abs(2-j));
            break;
        case 0: total += (abs(3-i) + abs(3-j));
            break;
        }
    }
  }
  puzzle->h = total;
}

void pEnqueue(node* parent,int nextXpos,int nextYpos){
  node* newNode = (node*) malloc(sizeof(node));
  //filling out newNode
  newNode->prevXpos = parent->currXpos;
  newNode->prevYpos = parent->currYpos;
  newNode->currXpos = nextXpos;
  newNode->currYpos = nextYpos;
  newNode->g = parent->g + 1;
  newNode->prev = parent;
  newNode->next = NULL;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      newNode->puzzle[i][j] = parent->puzzle[i][j];
  }
  int x = newNode->puzzle[nextXpos][nextYpos];
  newNode->puzzle[nextXpos][nextYpos]=0;
  newNode->puzzle[newNode->prevXpos][newNode->prevYpos] = x;
  getH(newNode);
  newNode->f = newNode->g + newNode->h;
  if(newNode->h == 0){
    result = newNode;
    return;
  }
  //check if this node is already visited before enqueueing it
  if(search(newNode)){
    free(newNode);
    return;
  }
  // enqueue this node in sorted way
  if(p_front == NULL)
    p_front = newNode;
  else{
    if(p_front->f > newNode->f){
      newNode->next = p_front;
      p_front = newNode;
    }
    else{
      node* ptr = p_front;
      node* nextPtr = ptr->next;
      bool isAdded = false;
      while(nextPtr != NULL){
        if(nextPtr->f >= newNode->f){
          ptr->next = newNode;
          newNode->next = nextPtr;
          isAdded = true;
          break;
        }
        else{
          ptr = nextPtr;
          nextPtr=nextPtr->next;
        }
      }
      if(!isAdded)
        ptr->next = newNode;
    }
  }
}
//enqueue visited node into a closed list;

void enqueue(node* visitedNode){
  if(front == NULL)
    front = visitedNode;
  if(rear != NULL) rear->next = visitedNode;
  rear = visitedNode;
}

//dequeue from the priority_queue list

void pDequeue(node* visitedNode){
  node* ptr = NULL;
  if(visitedNode == p_front){
    p_front = p_front->next;
    visitedNode->next = NULL;
    enqueue(visitedNode); // insert it into closed list;
  }
  else{
    node* ptr = p_front;
    node* nextPtr = ptr->next;
    while(nextPtr != NULL){
      if(nextPtr == visitedNode){
        ptr->next = nextPtr->next;
        visitedNode->next = NULL;
        enqueue(visitedNode);
        break;
      }
      else{
        ptr=nextPtr;
        nextPtr = nextPtr->next;
      }
    }
  }
}
bool compare(node* x,node* y){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      if(x->puzzle[i][j] != y->puzzle[i][j])
        return false;
  }
  return true;
}
bool search(node* currentNode){
  node* pPtr = p_front,*ptr=front;
  while(pPtr != NULL || ptr!= NULL){
    if(pPtr != NULL && ptr != NULL){
      if(compare(currentNode,pPtr) || compare(currentNode,ptr))
        return true;
      else {
        pPtr=pPtr->next;
        ptr = ptr->next;
      }
    }
    else if(pPtr != NULL && ptr == NULL){
      if(compare(currentNode,pPtr))
        return true;
      else 
        pPtr=pPtr->next;
    }
    else if(pPtr == NULL && ptr != NULL){
      if(compare(currentNode,ptr))
        return true;
      else 
        ptr=ptr->next;
    }
  }
  return false;
}

void display(node* currentNode){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      printf("%3d",currentNode->puzzle[i][j]);
    printf("\n");
  }
}
bool isEmpty(){
  if(p_front == NULL)
    return true;
  else return false;
}
bool isValid(node* currentNode,int nextXMove,int nextYMove){
    if((nextXMove >= 0 && nextXMove < n) && (nextYMove >= 0 && nextYMove < n) && (nextXMove != currentNode->prevXpos || nextYMove != currentNode->prevYpos))
        return true;
    else return false;
}
void solvePuzzle(node* startState){
  pEnqueue(startState,startState->currXpos,startState->currYpos);
  int count = 0;
  while(!isEmpty()){
    node* ptr = p_front;
    for(int i=0;i<4;i++){
      int newXpos = ptr->currXpos +  xMoves[i];
      int newYpos = ptr->currYpos +  yMoves[i];
      if(isValid(ptr,newXpos,newYpos))
        pEnqueue(ptr,newXpos,newYpos);
      if(result != NULL) return;
           count++;
    }
    if(count%10000 == 0) printf("%d\n",count/10000);
    pDequeue(ptr);
  }
}
void destroy(){
  if(p_front != NULL){
    node* ptr = p_front,*nextPtr= ptr->next;
    while(nextPtr != NULL){
      free(ptr);
      ptr=nextPtr;
      nextPtr= nextPtr->next;
    }
  }
  if(front != NULL){
    node* ptr = front,*nextPtr= ptr->next;
    while(nextPtr != NULL){
      free(ptr);
      ptr=nextPtr;
      nextPtr= nextPtr->next;
    }
  }
}
void displayAllSteps(node* ptr){
  if(ptr == NULL)
  return;
  displayAllSteps(ptr->prev);
  if(ptr->prev != NULL){
    display(ptr);
    printf("************\n");
  }
}
/*
void initiateStartState(char** argv,node* startState){
  int index = 1;
  for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
        int element = atoi(argv[index++]);
        startState->puzzle[i][j] = element;
	if(element == 0){
	  startState->currXpos = i;startState->prevXpos = i;
	  startState->currYpos = j;startState->prevYpos = j;
        }
     }
  }
  startState->g = 0;
  getH(startState);
  startState->prev = NULL;
  startState->next = NULL;
}*/
int main(int argc,char** argv){
  node startState; 
  struct gengemNode* ptr =  getInitialState(argc,argv);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      startState.puzzle[i][j] = ptr->tiles[i][j];
      if(ptr->tiles[i][j] == 0){
	      startState.currXpos = i;startState.prevXpos = i;
	      startState.currYpos = j;startState.prevYpos = j;
      }
    }
  }
  startState.g = 0;
  getH(&startState);
  startState.prev = NULL;
  startState.next = NULL;
  //initiateStartState(argv,&startState);
 // display(&startState);
  solvePuzzle(&startState);
  if(result != NULL){
    printf("Congratulations : \n");
   // display(result);
    printf("The steps : \n");
    displayAllSteps(result);
  }
  destroy();
return 0;
}
