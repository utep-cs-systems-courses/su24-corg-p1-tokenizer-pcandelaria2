#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"


List* init_history(){
  List *history = malloc(sizeof(List));
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str){
  Item* curr;
  curr = list -> root;
  int count = 1;
  
  if(list->root == NULL){
    list->root = (Item*)malloc(sizeof(Item));
    list->root->id = 0;
    list->root->str = str;
    list->root->next = NULL;

  }
  else{
    while(curr->next != NULL){
      count++;
      curr = curr ->next;
    }
    curr->next = malloc(sizeof(Item));
    curr->next->id = count;
    curr->next->str = str;
    curr->next->next = NULL;
  }
}

char *get_history(List *list, int id){
  Item* curr = list->root;
  while (curr != NULL)
    {
      if (curr->id == id)
	{
	  return curr->str;
	}
      curr = curr->next;
    }
}

void print_history(List *list){
  Item *curr = list->root;
  while(curr != NULL){
    printf("%d.- %s", curr->id, curr->str);
      curr = curr->next;
    }
}

void free_history(List *list){
  Item *curr = list->root;
  while (curr != NULL)
    {
      free(curr);
      curr = curr->next;
    }
  free(list);
}
