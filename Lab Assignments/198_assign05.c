#include <stdio.h>
#include <stdlib.h>

#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2

typedef struct node {
    int data ;
} node ;

typedef struct minHeap {
    int size ;
    node *elem ;
} minHeap ;

minHeap initMinHeap(int size) {
    minHeap hp ;
    hp.size = 0 ;
    return hp ;
}

void swap(node *n1, node *n2) {
    node temp = *n1 ;
    *n1 = *n2 ;
    *n2 = temp ;
}

void swap_int(int *n1, int *n2) {
    int temp = *n1 ;
    *n1 = *n2 ;
    *n2 = temp ;
}

void heapify(minHeap *hp, int i) {

    int smallest = (LCHILD(i) < hp->size && hp->elem[LCHILD(i)].data < hp->elem[i].data) ? LCHILD(i) : i ;
    if(RCHILD(i) < hp->size && hp->elem[RCHILD(i)].data < hp->elem[smallest].data)
        smallest = RCHILD(i) ;
    if(smallest != i) {
        swap(&(hp->elem[i]), &(hp->elem[smallest])) ;
        heapify(hp, smallest) ;
    }
}

void buildMinHeap(minHeap *hp, int *arr, int size) {

    int i ;
    for(i = 0; i < size; i++) {
        if(hp->size)
            hp->elem = realloc(hp->elem, (hp->size + 1) * sizeof(node)) ;
        else
            hp->elem = malloc(sizeof(node));
        node nd ;
        nd.data = arr[i] ;
        hp->elem[(hp->size)++] = nd ;
    }
    for(i = (hp->size - 1) / 2; i >= 0; i--)
        heapify(hp, i) ;
}

void insertNode(minHeap *hp, int data) {
    if(hp->size)
        hp->elem = realloc(hp->elem, (hp->size + 1) * sizeof(node)) ;
    else 
        hp->elem = malloc(sizeof(node)) ;
    node nd ;
    nd.data = data ;
    int i = (hp->size)++ ;
    while(i && nd.data < hp->elem[PARENT(i)].data) {
        hp->elem[i] = hp->elem[PARENT(i)] ;
        i = PARENT(i) ;
    }
    hp->elem[i] = nd ;
}

void Traversal(minHeap *hp) {
    int i ;
    for(i = 0; i < hp->size; i++) 
        printf("%d ", hp->elem[i].data) ;
}

void deleteMinHeap(minHeap *hp) {
    free(hp->elem) ;
}

void maxheapify(int Arr[], int n, int i)
{
    int l, r, largest, temp;
    l = 2 * i + 1;
    r = 2 * i + 2;
    if (l < n && Arr[l] > Arr[i])
        largest = l;
    else
        largest = i;
    if (r < n && Arr[r] > Arr[largest])
        largest = r;
    if (largest != i)
    {
        swap_int(&Arr[i] , &Arr[largest]);
        maxheapify(Arr, n, largest);
    }
}
 
void Answer_2()
{
    printf("Answer_2\n");
    int n;
    printf("Input The Size of Array   :: ");
    scanf("%d", &n);
    printf("Input The array of size n :: ");
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("The Inputed Array is      :: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    for (int i = (n - 1) / 2; i >= 0; i--)
        maxheapify(arr, n, i);
    int t = n;
    int n_arr[n], inewarr = 0;
    while (t--)
    {
        int lastElement = arr[t];
        n_arr[inewarr++] = arr[0];
        arr[0] = lastElement;
        maxheapify(arr, t, 0);
    }
    printf("Deleting Max Element from The Heap itteratively :-\n");
    for (int i = 0; i < n; i++)
        printf("%d ", n_arr[i]);
    printf("\n");
}
 
int main()
{
    printf("Answer_1\n");
    minHeap hp;
    int n;
    int arr[] = {1,3,6,5,9,8};
    printf("The Inputed Array is      :: ");
    for(int i=0 ; i<6 ; i++)
        printf("%d ",arr[i]);
    printf("\n");
    buildMinHeap(&hp,arr,6);
    printf("Input number of Element(s) You want to add  :: ");
    scanf("%d",&n);
    int y;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&y);
        insertNode(&hp , y);
    }
    printf("The Array after Insertion of ele is :: ");
    Traversal(&hp);
    deleteMinHeap(&hp);
    printf("\n\n");
    Answer_2();
    return 0;
}