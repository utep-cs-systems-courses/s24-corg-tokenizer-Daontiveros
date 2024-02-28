#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main() {
  
    /* Allocate memory for two structs. One type is type s_List and the other is s_Item.
       s_List contains a struct type s_Item. Thus in init_history we initiliaze both structs.
       Pointer tempHead points to the allocated memory for the structs. This is the root of
       the linked list. Create a string. Create an idCount equals to 1. Everytime the user enters
       a string, idCount will be increased by 1. idCount is the number of the string entered
       by the user. First string is 1, second string is 2, thrid string is 3 and so on. idCount
       is stored in the s_Item type of structs. */
  
    struct s_List *tempHead = init_history();
    char userString[30];
    int idCount = 1;


    /* Goto is used three times. User enters a string read by scanf. This string is stored in
       userString. To exit the program user must enter '~'. An if statement checks whether the
       first char of the userString is '~'. If true then goto end. In end, the entire linked
       list is printed. The root (tempHead) is passed to function print_history. Then we free
       the malloc allocated memory.
       Else if the first char of the userString is not '~', then we check if user wants to see
       a string they entered. To perform this action the user must enter '!' followed by a 
       number. If they entered '!#' then # is passed to get_history as an int. Thus why 
       we pass (userString[1] - '0'). goto loop is called so we go back to loop. The loop is
       necessary because either the user wants to exit the program '~', see history '~', or
       enter a string. If the first two if statements aren't true then allocate memory for
       a pointer that will point to a string and will be stored individually in a struct of
       the linked list. Call add_history with the root, the pointer to the string, and the id.
       Tokenize the string by calling the tokenize() function. Ask again if the user wants to
       quit if userString[0] = '~'.  */
    
    loop:
    printf("\n\n& ");
    scanf("%[^\n]%*c", userString);
    if(userString[0] == '~'){
        goto end;
    }else{
    if(userString[0] == '!'){
           printf("%d. %s\n", (userString[1] - '0'), get_history(tempHead, (userString[1] - '0')));
           goto loop;
    }
    char *pointerString = (char*) malloc(100 * sizeof(char));
    strcpy(pointerString, userString);
    add_history(tempHead, pointerString, idCount++);
    printf("\nTokens:\n");
    tokenize(pointerString);
    if (userString[0] != '~')
        goto loop;
    }

    end:
        print_history(tempHead);
        free_history(tempHead);

}
