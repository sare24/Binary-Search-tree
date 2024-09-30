#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
  int key; 
  struct Node *right;
  struct Node *left;                                 
}Node;

Node* createTree();
Node* insert(Node *t, int key);
void PrintTree( Node *t, int level);
void freeTree(Node* t);


int main(){
printf("please Enter the number of nodes: ");
int nodeNum;
scanf("%d", &nodeNum);
Node *t = NULL;
 for(int i = 0; i < nodeNum; i++){
  printf("Enter a new value: ");
  int value;
  scanf("%d", &value);
  t = insert(t, value);
 }
  PrintTree(t, 0);
  freeTree(t);

return 0;
}

 Node* createTree(){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode -> right = NULL;
  newNode -> left = NULL;
 return newNode;
}
Node* insert(Node *t, int key){
  Node* myTree;
  if(t != NULL){
   if(key < t -> key ){
      t -> left = insert(t -> left, key);
    }
    else if(key > t -> key){
    t -> right = insert(t->right, key);
    }
    else{
      printf("You can't insert a number that already exist");
    }
   
  }
  else{
   t = createTree();
   t -> key = key;
  }  
     return t; 

  
  
}
void PrintTree(Node *t, int level){
    if(t != NULL){
      if(level % 4 == 0){ printf("{");} 
      else if(level % 4 == 1){printf("[");}
      else if(level % 4 == 2){printf("(");}
      else if(level % 4 == 3){printf("<");}
      PrintTree(t -> left, level+1);
      printf("%d", t->key);
      PrintTree(t->right, level+1);
       if(level % 4 == 0){ printf("}");} 
      else if(level % 4 == 1){printf("]");}
      else if(level % 4 == 2){printf(")");}
      else if(level % 4 == 3){printf(">");}
    
     
      
    }
}
void freeTree(Node* t){
  if(t!= NULL){
    freeTree(t->left);
    freeTree(t->right);
    free(t);
  }
}

