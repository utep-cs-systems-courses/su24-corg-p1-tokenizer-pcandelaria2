#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c){
  if(c == '\t' || c == ' '){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if(c == '\t' || c == ' '){
    return 0;
  }
  return 1; 
}

char *token_start(char *str){ 
  while(!non_space_char(*str)){
    if(*str == '\0'){
	return str;
      }
    str++;
  }
  return str;
}

char *token_terminator(char *token){
  if(!non_space_char(*token)){
    return token;
  }
  else{
    while(non_space_char(*token)){
      token++;
    }
    return token;
  }
}

int count_tokens(char *str){
  if ((str!=NULL) && (str[0] == '\0'))
    {
      return 0;
    }
  int count = 1;
  while(*str++)
    {
      if (*str == ' ')
	{
	  count++;
	}
    }
  return count;
}

char *copy_str(char *inStr, short len){
  char *str_copy = (char*)malloc((len+1) * sizeof(char));
  int i;
  for(i = 0; i < len; i++){
    str_copy[i] = inStr[i];
  }
  str_copy[len] = '\0';
  return str_copy;
}

char **tokenize(char *str){
  int count = count_tokens(str);
  int len;
  char **tokens = malloc((count + 1) * sizeof(char *));
  char *start = str;

  int i;
  for(i = 0; i < count;i++){
    start = token_start(start);//start of current token
    len = token_terminator(start)-start;//get length of current token
    tokens[i] = copy_str(start,len);//placing copy of current token at index i of tokens
    start = token_terminator(start);//get end of current token
  }
  tokens[count] = 0;// add zero to the end of our tokenizer
  return tokens;
}

void print_tokens(char **tokens){
  int i = 0;
  while(tokens[i] != 0){
    printf("Token[%d]-%s \n",i,tokens[i]);
    i++;
  }
}

void free_tokens(char** tokens){
  int i = 0;
  while(tokens[i] != 0){
    free(tokens[i]);
    i++;
  }
  free(tokens);

}
