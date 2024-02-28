#ifndef _TOKENIZER_
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */

/* cPointer points to the char. If the char is a white space
   character, return -1 (a non-zero), else return 0*/

int space_char(char c){
  char *cPointer = &c;
  if(*cPointer == ' '){
    return -1;
  }
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */

/* cPointer points to the char. if cPointer is a non-whitespace
   character return -1, else return 0.*/

int non_space_char(char c){
  char *cPointer = &c;
  if(*cPointer != ' '){
    return -1;
  }
  return 0;
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */

/* The while loop serves to traverse the entire string. For example (Diana Azul Onti)
   "While the pointer does not reach the end of the string (\0 is considered the end
   of the string), there is an if statement. If the pointer *str points to a whitespace,
   then it means it has reached the end of the token. For example (Diana ). If it has
   reached the end of the token, traverse one more time. For example (Diana A). Now
   in our example *str is pointing to the first character of the next token. Thus we return
   str */

char *token_start(char *str){
  while(*str != '\0'){
    if(*str == ' '){
      str++;
      return str;
    }
    str++;
  }
  char *ptrZeroTerminated = 0;
  return ptrZeroTerminated;
} 

/* Returns a pointer terminator char following *token */

/* We initialize the pointer terminator (char terminator = '\0')
   We point at the terminator. While the token is not at the end,
   if a char from the token is a whitespace, then we have reached the end 
   of the token thus we return the pointer terminator. If the if statement
   is false (if *token, so a char, is not a whitespace) then continue traversing by
   (token++) */
char *token_terminator(char *token){ 
  while(*token != '\0'){
    if(*token == ' '){
      return NULL;
    }
    token++;
  } 
}

/* Counts the number of tokens in the string argument. */

/* The variable count was created to keep track of how many tokens there is on a string.
   Thus count is what will be returned. The while loop traverses the string using a pointer.
   count will only be updated if we find a whitespace character because it means the token ended,
   AND if the character after this whitespace is not \0. For example, (Diana) does not have any
   whitespaces so after the while loop, we return 0 + 1. However if we had (Diana ), there is a
   whitespace character. We enter the first if statement. The pointer points to the character
   after the whitespace and checks if it's \0, it is so we don't increase count. Then the
   pointer goes back to the whitespace character by str-- and continues the loop.
   We return 0 + 1. Another example, ("Diana Azul"). The string is traversed, there is a
   whitespace character, the character after the whitespace character is not \0 so we update count.
   We return 1 + 1 = 2 tokens. */

int count_tokens(char *str){
  int count = 0;
  while(*str != '\0'){
    if(*str == ' '){
      str++;
      if(*str != '\0'){
	count++;
      }
      str--;
    }
    str++;
  }
  return count + 1;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */

char *copy_str(char *inStr, short len){
  char *newString = NULL;
  newString = (char*)calloc((len + 1), sizeof(char));
  return newString;
}


/* Prints all tokens. */

void print_tokens(char **tokens){
  printf("%s\n", *tokens);
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/

/* Use the str pointer to create an array of the string. Use strcpy to copy the string
   into the array. Then use strtok function to cut the array into tokens and reference 
   each piece with split. So split is pointing at each token. Pass each token to 
   print_token so that it prints them. The program is echoing back.*/

char **tokenize(char* str){
  char *tokens;
  char tempString[strlen(str) + 1];
  strncpy(tempString, str, sizeof(tempString)-1);
  tempString[sizeof(tempString)-1] = '\0';
  char *split = strtok(tempString, " ");
  while(split != NULL){
    char **ptrSplit = &split;
    print_tokens(ptrSplit);
    split = strtok(NULL, " ");
  }
}

/* Frees all tokens and the vector containing themx. */

void free_tokens(char **tokens){
  free(*tokens);
  tokens = NULL;
}

#endif
