#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define FOR for(i,a,b) for(int i=a ; i<b ; i++)
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<(b))?(a):(b)

const long MAX = (1e3 + 5);

int hash_table[MAX][2];

int hash_fun(int key , int i)
{
	return ((key + (long)pow(i,2))%10);
}

int search(int key)
{
	int i = 0;
	if(hash_table[abs(hash_fun(key , i))][0] == key)
		return 1;
	else{
		while(i<MAX){
			if(hash_table[abs(hash_fun(key , ++i))][0] == key)
				return 1;	
		}
	}
	return 0;
}

int delete(int key)
{
	int i = 0;
	if(hash_table[abs(hash_fun(key , i))][0] == key){
		hash_table[abs(hash_fun(key , i))][0] = -1;
		hash_table[abs(hash_fun(key , i))][1] = -1;
		return 1;
	}
	else{
		while(i<MAX){
			if(hash_table[abs(hash_fun(key , ++i))][0] == key){
				hash_table[abs(hash_fun(key , i))][0] = -1;
				hash_table[abs(hash_fun(key , i))][1] = -1;
				return 1;
			}
		}
	}
	return 0;
}

void insert(int key , int val)
{
	int i = 0;
	if(hash_table[abs(hash_fun(key , i))][1] == -1){
		hash_table[abs(hash_fun(key , i))][0] = key;
		hash_table[abs(hash_fun(key , i))][1] = val;
	}
	else{
		while(i<MAX && hash_table[abs(hash_fun(key , ++i))][1] != -1);
		hash_table[abs(hash_fun(key , i))][0] = key;
		hash_table[abs(hash_fun(key , i))][1] = val;
	}
}

void Answer_1()
{
	printf("\n--------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\tAnswer :: 1\n");
	int i = 0;
	printf("\tThe data in the Hash Table is  ");
	printf("[ (12,10) , (122,4) , (82,5) ]\n\n");
	insert(12 , 10);
	insert(122 , 4);
	insert(82 , 5);
	printf("Printing The Complete HashTable with Key Value Pair \n");
	printf("[");
	for(int i=0 ; i<MAX ; i++){
		if(hash_table[i][0] > 0){
			printf(" (Key => %d , Value => %d) ,",hash_table[i][0] , hash_table[i][1]);
		}
	}
	printf("\b]");
	printf("\n\n");
	printf("\t\t\tDeleting The element with Key as 122  \n");
	delete(122);
	printf("\t\t\t!!! Triumph !!! Successfully Deleted\n\n");
	printf("Printing The Complete HashTable with Key Value Pair after Deletion \n");
	printf("[");
	for(int i=0 ; i<MAX ; i++){
		if(hash_table[i][0] > 0){
			printf(" (Key => %d , Value => %d) ,",hash_table[i][0] , hash_table[i][1]);
		}
	}
	printf("\b]\n");
	printf("\n");
	printf("\t\t\tSearching The element with Key as 38  \n");
	if(search(38))
		printf("\t\t\t       !!!  Found Successfully !!!\n");
	else
		printf("\t\t\t       !!!  Oops! Not Found !!!\n");
	printf("\n");
	printf("\t\t\tSearching The element with Key as 12  \n");
	if(search(12))
		printf("\t\t\t       !!! Found Successfully !!!\n");
	else
		printf("\t\t\t       !!!  Oops! Not Found !!!\n");
	printf("\n--------------------------------------------------------------------------------------");
}

typedef struct Node 
{ 
    int data; 
    struct Node *left, *right, *middle; 
}Node; 

Node* Create_Node(int data) 
{ 
    Node *temp = (Node*)malloc(sizeof(Node)); 
    temp->data = data; 
    temp->left = temp->right = temp->middle = NULL; 
    return temp; 
} 

void findMinMax(Node *node, int *min, int *max, int hd) 
{ 
    if (node == NULL) 
    	return; 
    if (hd < *min)  
    	*min = hd; 
    else if (hd > *max) 
    	*max = hd; 

    findMinMax(node->left, min, max, hd-1); 
    findMinMax(node->middle, min, max, hd); 
    findMinMax(node->right, min, max, hd+1); 
} 

void Print_Vertical_Traversal(Node *node, int line_no, int hd) 
{ 
    if (node == NULL) 
    	return; 
  
    if (hd == line_no && (node->data != 0)) 
        printf("%d ",node->data);

    Print_Vertical_Traversal(node->left, line_no, hd-1); 
    Print_Vertical_Traversal(node->middle, line_no, hd); 
    Print_Vertical_Traversal(node->right, line_no, hd+1); 
} 

void Vertical_Order(Node *root) 
{ 
    int min = 0, max = 0; 
    findMinMax(root, &min, &max, 0); 
    for (int line_no = min; line_no <= max; line_no++) 
    { 
    	printf("\t\t\t\t\t");
        Print_Vertical_Traversal(root, line_no, 0); 
        printf("\n");
    } 
}

void Answer_2()
{
	printf("\n\n\t\t\t\t\tAnswer :: 2\n");
	printf("\t\tPrinting The Value Of Ternary Tree in Vertical Traversal\n");
	Node *root = Create_Node(1); 
    root->left = Create_Node(2); 
    root->middle = Create_Node(3);  
    root->right = Create_Node(4); 
    root->left->left = Create_Node(5); 
    root->left->middle = Create_Node(6); 
    root->left->right = Create_Node(7);
    root->middle->left = Create_Node(8); 
    root->middle->middle = Create_Node(9); 
    root->middle->right = Create_Node(10);
    root->right->left = Create_Node(11); 
    root->right->middle = Create_Node(12); 
    root->right->right = Create_Node(13);
    /*
    I was Passing them as NULL but it was generating warning i.e
    Implicit Conversion Of NULL to Zero
    So I Comented The Part if you want to check Then Uncomment it
    and comment the Labled Part to Check
    */
    /*
    root->left->left->left = Create_Node(NULL);
    root->left->left->middle = Create_Node(NULL);
    root->left->left->right = Create_Node(NULL);
    root->left->middle->left = Create_Node(NULL);
    root->left->middle->middle = Create_Node(NULL);
    root->left->middle->right = Create_Node(NULL);
    root->left->right->left = Create_Node(NULL);
    root->left->right->middle = Create_Node(NULL);
    root->left->right->right = Create_Node(NULL);
    root->middle->left->left = Create_Node(NULL);
    root->middle->left->middle = Create_Node(NULL);
    root->middle->left->right = Create_Node(NULL);
    root->middle->middle->left = Create_Node(NULL);
    root->middle->middle->middle = Create_Node(NULL);
    root->middle->middle->right = Create_Node(NULL);
    root->middle->right->left = Create_Node(NULL);
    root->middle->right->middle = Create_Node(NULL);
    root->middle->right->right = Create_Node(NULL);
    root->right->left->left = Create_Node(NULL);
    root->right->left->middle = Create_Node(NULL);
    root->right->left->right = Create_Node(NULL);
    root->right->middle->left = Create_Node(NULL);
    root->right->middle->middle = Create_Node(NULL);
    root->right->middle->right = Create_Node(NULL);
    */

    //This Part is to put in comment if want to check the warning 
    //To remove Warning I am simply sending Zero to the function

    root->left->left->left = Create_Node(0);
    root->left->left->middle = Create_Node(0);
    root->left->left->right = Create_Node(0);
    root->left->middle->left = Create_Node(0);
    root->left->middle->middle = Create_Node(0);
    root->left->middle->right = Create_Node(0);
    root->left->right->left = Create_Node(0);
    root->left->right->middle = Create_Node(0);
    root->left->right->right = Create_Node(0);
    root->middle->left->left = Create_Node(0);
    root->middle->left->middle = Create_Node(0);
    root->middle->left->right = Create_Node(0);
    root->middle->middle->left = Create_Node(0);
    root->middle->middle->middle = Create_Node(0);
    root->middle->middle->right = Create_Node(0);
    root->middle->right->left = Create_Node(0);
    root->middle->right->middle = Create_Node(0);
    root->middle->right->right = Create_Node(0);
    root->right->left->left = Create_Node(0);
    root->right->left->middle = Create_Node(0);
    root->right->left->right = Create_Node(0);
    root->right->middle->left = Create_Node(0);
    root->right->middle->middle = Create_Node(0);
    root->right->middle->right = Create_Node(0);
    root->right->right->left = Create_Node(14);
    root->right->right->middle = Create_Node(15);
    root->right->right->right = Create_Node(16);
    Vertical_Order(root); 
    printf("\n--------------------------------------------------------------------------------------\n");
}
int main()
{
	memset(hash_table,-1,sizeof(hash_table));
	Answer_1();
	Answer_2();
	return 0;
}
