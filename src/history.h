#ifndef _HISTORY_
#define _HISTORY_

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;


/* Initialize the linked list to keep the history. */

/* s_List and s_Item are initialized by allocating memory.
    We attach s_Item rootHead to the head->root of the s_List
    Then return the pointer that points to the allocated memory
    of the s_List.*/

List* init_history(){
  struct s_List *head = malloc(sizeof(struct s_List));
  struct s_Item *rootHead = malloc(sizeof(struct s_Item));
  head->root = rootHead;
  return head;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/

/* Allocate memory for a new struct type s_Item. Attach the string str to
   newNode->str. Now the newNode we create has a pointer that points towards the string.
   newNode->next is NULL because we insert this newNode at the end of the list.
   If the root string is null then it means the root is null because list is the root.
   we add the newNode to the begining (root) of the list. This if statement will only
   be true when the root is empty. Create a pointer that points towards the root.
   Then traverse the list until the end. So curr is a pointer that traverses through the list
   until it finds the last node. newNode is inserted after the last node (curr->next = newNode)*/

void add_history(List *list, char *str, int id){
  struct s_Item *newNode = (struct s_Item*)malloc(sizeof(struct s_Item));
  newNode->str = str;
  newNode->id = id;
  newNode->next = NULL;
  if(list->root->str == NULL){
    list->root = newNode;
    return;
  }
  struct s_Item *curr = list->root;
  while(curr->next != NULL){
    curr = curr->next;
  }
  curr->next = newNode;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */

/* If the root is null return there are no nodes. Else point towards the
   root inside the List struct. Traverse the list and if the id matches
   with the id (the number entered by the user after '!'), then return 
   the string stored inside that Item. If no id is found then return NULL. */

char *get_history(List *list, int id){
  if(list->root == NULL){
    return NULL;
  }
  struct s_Item *curr = list->root;
  while(curr != NULL){
    if(curr->id == id){
      return curr->str;
    }
    curr = curr->next;
  }
  return NULL;
  }


/* Print the entire contents of the list. */

/* Point towards the root stored inside the List struct.
   Traverse the entire linked list and print the string. */

void print_history(List *list){
  printf("\nStrings in Linked List:\n");
  struct s_Item *curr = list->root;
  while(curr != NULL){
    printf("%s\n",curr->str);
    curr = curr->next;
  }
}

/* Free the history list and the strings it references. */
void free_history(List *list){
   free(list);
}

#endif
