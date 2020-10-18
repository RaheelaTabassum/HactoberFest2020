#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>


#define FOR(i,a,b) for(int i=a ; i<b ; i++)
#define BFOR(i,a,b) for(int i=b ; i>=a ; i--)
#define MAX 1000000
#define _max(a , b) ((a) > (b))?(a):(b)
#define _min(a , b) ((a) < (b))?(a):(b)


typedef struct node 
{
    int emp_id;
    char name[20];
    char address[30];
    char Department[30];
	struct node* next; 
	struct node* prev; 
}Node; 

void Add_Data(Node** head_ref)  
{  
    Node* new_node = (Node*)malloc(sizeof(Node));  
    p:
    printf("Inout The Emp_ID         :: ");
    scanf("%d",&new_node->emp_id);
    printf("Input The Emp Name       :: ");
    scanf("%s",new_node->name);
    printf("Input The Emp Address    :: ");
    scanf("%s",new_node->address);
    printf("Input The Emp Department :: ");
    scanf("%s",new_node->Department);
    Node* last; 
    Node *node = (*head_ref);
    while (node != NULL) {  
        if(node->emp_id == new_node->emp_id)
        {
            printf("\n\t\tAlready Registered !!!!\n\t\tInput Again\n");
            goto p;
        }
        last = node;  
        node = node->next;  
    }
    new_node->next = (*head_ref);  
    new_node->prev = NULL;  
    if ((*head_ref) != NULL)  
        (*head_ref)->prev = new_node;  
    (*head_ref) = new_node;  
}  

void Print_Data(Node* node) 
{ 
    printf("The Printing Of the List :: \n\n");
	Node* last; 
    while (node != NULL) {  
        last = node;
        printf("Inout The Emp_ID         :: %d\n" , last->emp_id);
        printf("Input The Emp Name       :: %s\n" , last->name);
        printf("Input The Emp Address    :: %s\n" , last->address);
        printf("Input The Emp Department :: %s\n" , last->Department);  
        node = node->next;  
        printf("\n");
    }
} 

int main() 
{
	Node* head = NULL; 
    int N;
    printf("Input The Number Of Employee You Want to Register :: ");
    scanf("%d",&N);
    for(int i=0 ; i<N ; i++)
    {
	    Add_Data(&head); 
        printf("\n");
    }
	Print_Data(head); 
    free(head);
	getchar(); 
	return 0; 
} 