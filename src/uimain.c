#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  List *history = init_history();
  
  while(1){
    printf("Press 't' to create a tokenizer Press 'h' to view history Press 'q' to quit\n");
    char input[5];
    fgets(input,5, stdin);

    switch(input[0]){

    case 't':
      printf("Enter a sentence to tokenize: ");
      char userInput[100];
      fgets(userInput,100,stdin);
      char **tokens = tokenize(userInput);

      print_tokens(tokens);
      add_history(history,userInput);
      print_history(history);
      break;

    case 'h':
      print_history(history);
      free_history(history);
      break;

    case 'q':
      printf("Good-Bye!!!");
      return 0;

    default:
      printf("Invalid input try again!!");
      break;
    }
  }
  
  
}
