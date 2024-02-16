#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
  char letter;
  struct node *next;
}
node;

// Returns number of nodes in the linkedList.
int
length (node * head)
{

  int size = 0;
  while (head != NULL)
	{
	  size++;
	  head = head->next;
	}
  return size;
}

 /*Parses the string in the linkedList.
 If the linked list is head->|a|->|b|->|c|,
 then tocstring function will return "abc".*/
char *
toCstring (node * head)
{

  int size = length (head); //allocate memory of such
  char *str = (char *) malloc (size + 1);
  int i = 0;
  while (head != NULL)
	{
	  str[i] = head->letter;
	  head = head->next;
	  i++;
	}

  str[size] = '\0';
  return str;					// return statement
}

/* Inserts character to the linkedlist.
 If the linked list is head->|a|->|b|->|c|,
 then insertChar(&head, 'x') will update the linked list as follows:
 head->|a|->|b|->|c|->|x|*/
void insertChar (node ** pHead, char c) {
  node *newNode = (node *) malloc (sizeof (node));
  //Configure the character to correspond with the letter of the node.
  newNode->letter = c;
  newNode->next = NULL;
  if (*pHead == NULL)
	{
	  *pHead = newNode;
	}
  //Otherwise
  else
	{
	  node *currentnode = *pHead;
	  //null statement
	  while (currentnode->next != NULL)
		{
		  currentnode = currentnode->next;	//set next node
		}
	  currentnode->next = newNode;	//set current node 
	}
}

// Delete all nodes in the linkedList.
void
deleteList (node ** pHead)
{

  node *currentnode = *pHead;
  while (currentnode != NULL)// Null statement
	{
	  node *temp = currentnode; //setting cuurent and next nodes
	  currentnode = currentnode->next;
	  free (temp);
	}
  *pHead = NULL;
}

//main
int main (void) {
  int i, strLen, numInputs;
  node *head = NULL;
  char *str;
  char c;


  FILE *inFile = fopen ("input.txt", "r");
  fscanf (inFile, " %d\n", &numInputs);
  while (numInputs-- > 0)
	{
	  fscanf (inFile, " %d\n", &strLen);

	  for (i = 0; i < strLen; i++)
		{
		  fscanf (inFile, " %c", &c);
		  insertChar (&head, c);
		}

	  str = toCstring (head);
	  printf ("String is : %s\n", str);
	  free (str);
	  deleteList (&head);
	  if (head != NULL)
		{
		  printf ("deleteList is not correct!");
		  break;
		}
	}
  fclose (inFile);
  return 0;
}
