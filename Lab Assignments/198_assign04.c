#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define FOR for(i,a,b) for(int i=a ; i<b ; i++)
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<(b))?(a):(b)
#define MAX 1e5

void swap(int *a , int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int divide_index(int Arr[] , int l , int h)
{
    int pivot = Arr[h];
    int i = l - 1;
    for(int j=l ; j<=h -1 ; j++)
    {
        if(Arr[j] < pivot)
        {
            i++;
            swap(&Arr[i] , &Arr[j]);
        }   
    }
    swap(&Arr[i+1] , &Arr[h]);
    return i+1;
}

void quick_sort(int A[] , int l  ,int h)
{
    if(l < h)
    {
        int i = divide_index(A , l , h);
        quick_sort(A , l , i-1);
        quick_sort(A , i+1 , h);
    }
}

void Answer_1()
{
    int A[] = { - 7, 3, 80, 12, -35, 28, -54, 61, 12, 3, 9, -5, 35, 52, - 96, 29, -12, 27, 37, -42, 53, 48, 63, -51, -75, 19, -11, 2, -81, 55, -14, 41, -29, 97, -245 };
    int size = sizeof(A)/sizeof(A[0]);
    quick_sort(A,0,size-1);
    for(int i=0 ; i<size ; i++)
        printf("%d ",A[i]);
    printf("\n");
    int i=0;
    while (A[i]<0)
        i++;
    int k=1;
    for(int j=i ; j<(size+i)/2 ; j++ , k++)
        swap(&A[j] , &A[size - k]);
    for(int i=0 ; i<size ; i++)
        printf("%d ",A[i]);
    printf("\n");
}

typedef struct dictionary
{
    char ch[100];
    int count;
}dict;

void Answer_2()
{
    char ch[] = {"A stochastic fractal is built out of probabilities and randomness. It is statistically self-similar. We will look at both deterministic and stochastic techniques for generating fractal patterns. A line is self-similar. A line looks the same at any scale, but it’s not a fractal. A fractal is characterized by having a fine structure at small scales, you’ll continue to find fluctuations, and cannot be described with Euclidean geometry. If you can say, it’s a line, then it’s not a fractal. Another fundamental component of fractal geometry is recursion. Fractal has a recursive definition. We’ll start with recursion before developing techniques and code examples for building fractal patterns."};

    char arr[1000][100];
    int j = 0 , k=0;

    //Storing and Printing The Words in the 2-D Array
    printf("The Words Seperated on The basis of Comma and space \n");
    for(int i=0 ; i<sizeof(ch) ; i++)
    {
        if(isalpha(ch[i]))
        {
            printf("%c",ch[i]);
            arr[j][k++] = ch[i];
        }
        else
        {
            printf("\n");
            j++;
            k = 0;
        }
    }

    //Displaying All The Words In The Paragraph and Checking The Dublicacy Of the Words
    dict counter[j];
    static int m , x;
    for(int i=0 ; i<j ; i++)
    {
        char temp[100];
        int l=0;
        for( ; k<sizeof(ch) ; m++)
        {
            if(!isalpha(ch[m]))
            {
                m++;
                temp[l++] = '\0';
                break;
            }
            else
                temp[l++] = ch[m];
        }
        //printf("%s\n",temp);
        int flag = 1;
        if(i == 0)
        {
            strcpy(counter[x].ch,temp);
            counter[x].count += 1;
            x++;
        }
        else
        {
            for(int X = x ; X>=0 ; X--)
            {
                if(strcmp(counter[X].ch , temp) == 0)
                {
                    flag = 0;
                    counter[X].count += 1;
                    break;
                }
            }
            if(flag)
            {
                strcpy(counter[x].ch,temp);
                counter[x].count += 1;
                x++;
            }   
        }
    }

    //Printing The Total Words with their Count
    printf("The Total Number Of Words With Their Count are :: \n");
    for(int i=0 ; i<x ; i++)
    {
        printf("%s :: ",counter[i].ch);
        printf("%d \n", counter[i].count);
    }

    //Sorting The Words in The Order of Their Count
    for(int i=0 ; i<x-1 ; i++)
    {
        for(int j=0 ; j<x-i-1 ; j++)
        {
            if(counter[j].count < counter[j+1].count)
            {
                dict temp = counter[j];
                counter[j] = counter[j+1];
                counter[j+1] = temp;
            }
        }
    }
    printf("\n");

    //Printing The List in The Descending Order (ie Top 5)
    printf("Printing The Top 5 Words Of The Counted List in Descending Order :-\n");
    for(int i=0 ; i<6 ; i++)
    {
        if(i == 2)
            continue;
        printf("%s :: ",counter[i].ch);
        printf("%d \n", counter[i].count);
    }
    printf("\n");

    //Printing The Words in The Sorted order Of Their Alphabet 
    printf("The Aphabetically Sorted Order Is :: \n");
    for(int i=0 ; i<x-1 ; i++)
    {
        for(int j=i+1 ; j<x ; j++)
        {
            if(strcmp(counter[i].ch , counter[j].ch) > 0)
            {
                char temp[100];
                strcpy(temp , counter[i].ch);
                strcpy(counter[i].ch , counter[j].ch);
                strcpy(counter[j].ch , temp);
            }
        }
    }

    //Displaying The Sorted Words in Alphabetical Order
    for(int i=0 ; i<x ; i++)
    {
        if(i>=1 && i<=6)
            continue;
        printf("%s :: ",counter[i].ch);
        printf("%d \n", counter[i].count);
    }
}

void Answer_3()
{
    srand(time(0));
    float a[1000],b[1000];
    FILE *f1,*f2;
    int n=0;
    f1 = fopen("198_input.txt","w");
    f2 = fopen("198_output.txt","w");
    if(f1 == NULL)
        printf("file doesnt exist");
    else
    {	
        for(int i=0;i<1000;i++)
        {
            int s=(rand()%51)+10;
            float k=(rand()%11)+1000;
            float d=s+k*0.0001;
            a[i]=d;
            fprintf(f1, "%f\n", d);
        }
        for(int i=0;i<1000;i++)
            if(a[i]>=15.000000 && a[i]<=46.999999)
                b[n++]=a[i];
    }
    if(f2==NULL)
        printf("file doesnt exist");
    else
    {
        for(int i=0;i< n;i++)
        {
            for(int j=i+1;j< n;j++)
            {
                if(b[i]< b[j])
                {
                    float temp=b[i];
                    b[i]=b[j];
                    b[j]=temp;
                }
            }
        }
        for(int i=0;i<n;i++)
            fprintf(f2, "%f\n", b[i]);
    }
    fprintf(f2,"%s","The Appended output is\n");
    for(int i=0 ; i<=631 ; i++)
    {
        b[i] *= 1000000;
        int x = (int)b[i];
        int cpy_x = x;
        int _count = 0;
        while(cpy_x > 0)
        {
            if((cpy_x%10)%2 != 0)
                _count += 1;
            cpy_x /= 10;
        }
        float y = (float)x/1000000;
        if(_count >= 3)
            fprintf(f2,"%f\n",y);
    }
}
int main()
{
    printf("Answer-1\n");
    Answer_1();
    printf("\nAnswer-2\n");
    Answer_2();
    printf("\nAnswer-3\nThe Output Is In The Required File's\n\n");
    Answer_3();
    printf("----------------------- The End -----------------------\n");
    return 0;
}