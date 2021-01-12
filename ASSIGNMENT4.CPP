// Question 1
// Write a function “insert_any()” for inserting a node at any given position of the linked list. Assume position starts at 0.
// Solution:
/*
  Insert Node at a given position in a linked list 
  The linked list will not be empty and position will always be valid
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function.
    Node * newnode = (Node *)malloc(sizeof(Node));
    newnode->data=data;
    Node *temp=head,*prev;
    if(position==0){
        newnode->next=head;
        head=newnode;
        return head;
    }
    else{
        while(position--){
            prev=temp;
            temp=temp->next;
        }
        prev->next=newnode;
        newnode->next=temp;
        return head;
    
    }
        
}



// Question 2
// Write a function “delete_beg()” for deleting a node from the beginning of the linked list.

// Solution:
// to demonstrate deletion in  
// singly linked list 
#include <stdio.h> 
#include <stdlib.h> 
  
// A linked list node 
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  
/* Given a reference (pointer to pointer) to the head of a list 
   and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 
  
/* Given a reference (pointer to pointer) to the head of a list 
   and a key, deletes the first occurrence of key in linked list */
void deleteNode(struct Node **head_ref, int key) 
{ 
    // Store head node 
    struct Node* temp = *head_ref, *prev; 
  
    // If head node itself holds the key to be deleted 
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;   // Changed head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key was not present in linked list 
    if (temp == NULL) return; 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    free(temp);  // Free memory 
} 
  
// This function prints contents of linked list starting from  
// the given node 
void printList(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf(" %d ", node->data); 
        node = node->next; 
    } 
} 
  
// Driver code 
int main() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
  
    push(&head, 7); 
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 2); 
  
    puts("Created Linked List: "); 
    printList(head); 
    deleteNode(&head, 1); 
    puts("\nLinked List after Deletion of 1: "); 
    printList(head); 
    return 0; 
}


// Question 3
// Write a function “delete_end()” for deleting a node from the end of the linked list.
// Solution: //Function to delete a node from the end of a linked list.
void delete_end()
{
	if(header->link == NULL)
	{
		printf("\nEmpty Linked List. Deletion not possible.\n");
	}
	else
	{
		//Traverse to the end of the list.
		ptr = header;
		while(ptr->link != NULL)
		{
			ptr1 = ptr;
			ptr = ptr->link;
		}
		ptr1->link = ptr->link;
		free(ptr);
		printf("\nNode deleted from the end.\n");
	}
}


// Question 4
// In the Binary Search algorithm, it is suggested to calculate the mid as beg + (end - beg) / 2
// instead of (beg + end) / 2. Why is it so?
// Solution:
We can take a simple example to demonstrate this fact. Suppose in a certain large array, we are trying to find the midpoint of the range [1000, INT_MAX]. Now, INT_MAX is the largest value the int data type can store. Even if 1 is added to this, the final value will become negative.
Also, start = 1000 and end = INT_MAX.
Using the formula: (start + end)/2,
the mid-point will be
(1000 + INT_MAX)/2 = -(INT_MAX+999)/2, which is negative and may give segmentation fault if we try to index using this value.
But, using the formula, (start + (end-start)/2), we get:
(1000 + (INT_MAX-1000)/2) = (1000 + INT_MAX/2 - 500) = (INT_MAX/2 + 500) which will not overflow.


// Question 5
// Write the algorithm/function for Ternary Search.

// Solution:
#include<stdio.h>
int ternarySearch (int array [], int left, int right, int x)
{
     if (right>=left)
   {
     int intvl=(right-left)/3
     int leftmid=left+intvl;
     int rightmid=leftmid+intvl;
     if (array[leftmid]==x)
      return leftmid;
    if (array[rightmid]==x)
      return rightmid;
    if (x<array [leftmid])
   {
     return ternarySearch (array, leftmid, rightmid, x)
   }
   else
  {
    return ternarySearch (array, rightmid, right, x)
    }
  }
  return-1;
}
int main(void)
{
  int array[ ]={1,2,3,5,};
  int size=sizeof (array)/sizeof (array[0]);
int find=3;
printf(“ Position of %d id=s %d\n”, find,, ternarySearch (array, 0, size-1, find));
return 0;
}  
  

