#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define forn(i,a,b) for(int i=a ; i<b ; i++)
#define fore(i,a,b) for(int i=b ; i>=a ; i--)
#define forb(k,a,b) for(int k=b ; k>=a ; k--)
#define MAX 100
#define _max(a , b) ((a) > (b))?(a):(b)
#define _min(a , b) ((a) < (b))?(a):(b)

int SIZE;

char Stack[MAX];
int front_2 = -1;

struct stack 
{ 
    int top; 
    int items[MAX]; 
}; 

void push_prefix(char c)
{
    if(front_2 >= MAX-1)
    	printf("\n Stack Overflow.");
    else
    {
        front_2++;
        Stack[front_2] = c;
    }
}
int check_isoperator(char symbol)
{
    if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

int precedence(char symbol)
{
    if(symbol == '^')
        return(5);
    else if(symbol == '/')
        return(4);
    else if(symbol == '*')
        return(3);
    else if(symbol == '+')
        return(2);
    else if(symbol == '-')
        return(1);
    else
        return(0);
}

char pop_out()
{
    char c;
    c='\0';
    if(front_2 < 0)
    	printf("\n The given Stack is Underflowed.");
    else
    {
        c = Stack[front_2];
        front_2--;
    }
    return c;
}

void Infix(char infix_exp[], char prefix_exp[])
{
    int i, j, position=0, len;
    char item, x, rev[MAX];
    len = strlen(infix_exp);
    forb(k,0,len-1)
    {
        rev[position]=infix_exp[k];
        position++;
    }
    rev[position]='\0';
    strcpy(infix_exp,rev);
    for(i=0; infix_exp[i]!='\0'; i++)
    {
        if(infix_exp[i] == ')')
            infix_exp[i] = '(';
        else if(infix_exp[i] == '(')
            infix_exp[i] = ')';
    }
    push_prefix('(');
    strcat(infix_exp,")");
    i=0;j=0;
    item=infix_exp[i];
    while(item != '\0')
    {
        if(item == '(')
            push_prefix(item);
    	else if( isdigit(item) || isalpha(item))
    	{
        	prefix_exp[j] = item;
        	j++;
    	}
    	else if(check_isoperator(item) == 1)
    	{
        	x=pop_out();
        	while(check_isoperator(x) == 1 && precedence(x)>= precedence(item))
        	{
            	prefix_exp[j] = x;
            	j++;
            	x = pop_out();  
       		}
        	push_prefix(x);
        	push_prefix(item);
    	}
    	else if(item == ')')
    	{
        	x = pop_out();
        	while(x != '(')
        	{
            	prefix_exp[j] = x;
            	j++;
            	x = pop_out();
        	}
    	}
    	else
    	{
        	printf("\nOpps! the Invalid infix Expression is given.\n");
        	break;
    	}
    	i++;
    	item = infix_exp[i]; 
	}
    if(front_2 > 0)
        printf("\nOpps! the Invalid infix Expression is given.");
    prefix_exp[j] = '\0';
    position=0;
    len=strlen(prefix_exp);
    for(int k=len-1 ; k>=0 ; k--)
    {
        rev[position]=prefix_exp[k];
        position++;
    }
    rev[position]='\0';
    strcpy(prefix_exp,rev);
}

void Answer_3()
{
	printf("\nAnswer 3\n");
    char infix[MAX], prefix[MAX];
    printf("Enter Infix expression and u will get the postfix :: ");
    scanf("%s",infix);
    Infix(infix,prefix);
    if(strlen(prefix) >= 1)
        printf("The expression is :: %s\n",prefix);
}

void push(struct stack *STACK, int x) 
{ 
    if (STACK->top == MAX-1) 
    { 
        printf("Error: stack overflown"); 
        getchar(); 
        exit(0); 
    } 
    else
    { 
        STACK->top += 1; 
        int top = STACK->top; 
        STACK->items [top] = x; 
    } 
} 
  
int isEmpty(struct stack *STACK) 
{ 
    return (STACK->top == -1)? 1 : 0; 
} 
  
int pop(struct stack *STACK) 
{ 
    int temp; 
    if (STACK->top == -1) 
    { 
        printf("Error: stack underflow n"); 
        getchar(); 
        exit(0); 
    } 
    else
    { 
        int top = STACK->top; 
        temp = STACK->items [top]; 
        STACK->top -= 1; 
        return temp; 
    } 
} 

void push_stack(int arr[] , int N)
{
    int i = 0; 
    struct stack s; 
    s.top = -1; 
    int element, next; 
    push(&s, arr[0]); 
    for (i=1; i<N; i++) 
    { 
        next = arr[i]; 
  
        if (isEmpty(&s) == 0) 
        { 
            element = pop(&s); 
            while (element < next) 
            { 
                printf("%d --> %d\n", element, next); 
                if(isEmpty(&s) == 1) 
                   break; 
                element = pop(&s); 
            } 
            if (element > next) 
                push(&s, element); 
        } 
        push(&s, next); 
    } 
    while (isEmpty(&s) == 0) 
    { 
        element = pop(&s); 
        next = -1; 
        printf("%d --> %d\n", element, next); 
    } 
}
void Answer_1()
{
    int N;
    printf("Input the MAX of the array :: ");
    scanf("%d",&N);
    int arr[N];
    printf("Input The Array :: ");
    forn(i,0,N)
        scanf("%d",&arr[i]);
    push_stack(arr,N);
}
struct New_Stack2 { 
    int top_2; 
    unsigned capacity; 
    int* array; 
}; 

struct Queue { 
    int front, rear, size; 
    unsigned capacity; 
    int* array; 
}; 
  

struct New_Stack2* createStack(unsigned capacity) 
{ 
    struct New_Stack2* stack = (struct New_Stack2*)malloc(sizeof(struct New_Stack2)); 
    stack->capacity = capacity; 
    stack->top_2 = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 
  

int isFull(struct New_Stack2* stack) 
{ 
    return stack->top_2 == stack->capacity - 1; 
} 

int is_empty(struct New_Stack2* stack) 
{ 
    return stack->top_2 == -1; 
} 

void push_ele(struct New_Stack2* stack, int item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top_2] = item; 
     
} 

int pop_ele(struct New_Stack2* stack) 
{ 
    if (is_empty(stack)) 
        return -1; 
    return stack->array[stack->top_2--]; 
} 
  
int peek(struct New_Stack2* stack) 
{ 
    if (is_empty(stack)) 
        return -1; 
    return stack->array[stack->top_2]; 
} 

struct Queue* createQueue(unsigned capacity) 
{ 
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0;  
    queue->rear = capacity - 1;  
    queue->array = (int*) malloc(queue->capacity * sizeof(int)); 
    return queue; 
} 
  
int QueueisFull(struct Queue* queue) 
{   return (queue->size == queue->capacity);  } 

int QueueisEmpty(struct Queue* queue) 
{   return (queue->size == 0); } 

void enqueue(struct Queue* queue, int item) 
{ 
    if (QueueisFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1)%queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
} 
  
int dequeue(struct Queue* queue) 
{ 
    if (QueueisEmpty(queue)) 
        return -1; 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1)%queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 
  
int front(struct Queue* queue) 
{ 
    if (QueueisEmpty(queue)) 
        return -1; 
    return queue->array[queue->front]; 
} 
  
int rear(struct Queue* queue) 
{ 
    if (QueueisEmpty(queue)) 
        return -1; 
    return queue->array[queue->rear]; 
} 

void Answer_2() 
{ 
    printf("\nAnswer : 2\n");
    struct New_Stack2* st= createStack(100); 
    int expected = 1; 
    int fnt; 
    struct Queue* q= createQueue(100);
    printf("Input The Size of Array :: ");
    scanf("%d",&SIZE);
    printf("Input Array elements :: ");
    int arr[SIZE];
    for(int i=0 ; i<(sizeof(arr)/sizeof(arr[0])) ; i++)
    {
        scanf("%d",&arr[i]);
        enqueue(q,arr[i]);
    }
    printf("Is this queue can be sorted -: ");
    while (!QueueisEmpty(q)) { 
        fnt = front(q); 
        dequeue(q); 
        if (fnt == expected) 
            expected++; 
        else { 
            if (is_empty(st)) 
            {    push_ele(st,fnt); } 
            else if (!is_empty(st) && peek(st) < fnt) { 
               printf("No\n");
               return;
            } 
            else
                push_ele(st,fnt); 
        } 
        while (!is_empty(st) && peek(st) == expected) { 
            pop_ele(st); 
            expected++; 
        } 
    } 
    if (expected - 1 == SIZE && is_empty(st)) 
        printf("Yes\n");
    else 
    printf("No\n"); 
} 

int main()
{
    Answer_1();
    Answer_2();
    getchar();
    Answer_3();
    printf("\n");
}