#include <stdio.h>
#include <string.h>

int isprime(int n)
{
    if (n == 1)
        return 0;
    else
    {
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return 0;
        return 1; 
    }
}
void Answer1()
{
    printf("Answer :: 1\n");
    int sum = 0;
    int n = 0, z = 1;
    while (1)
    {
        if (isprime(z))
        {
            sum += z;
            n++;
        }
        if (n == 20)
            break;
        z++;
    }
    printf("The Sum of first 20 prime number is :: %d\n", sum);
}

void Answer2()
{
    printf("Answer :: 2\n");
    printf("All Integer divisible by 3 but not by 2 are :: \n");
    for (int i = 1; i <= 50; i++)
    {
        if ((i % 3 == 0) && (i % 2 != 0))
            printf("%d ", i);
    }
    printf("\n");
}

long long int factorial(int n)
{
    if ((n == 1) || (n == 0))
        return 1;
    else
        return n * factorial(n - 1);
}
void Answer3()
{
    printf("Answer :: 3\n");
    int n;
    printf("Input number whose factorial is to be computed :: ");
    scanf("%d", &n);
    if (n < 0)
        printf("Ooops! The Factorail can't be computed \n");
    else
        printf("The Factorial of given number is :: %lld\n", factorial(n));
}

void Answer4()
{
    printf("Answer :: 4\n");
    int n;
    printf("Input The Number :: ");
    scanf("%d", &n);
    int odd = 0;
    while (n)
    {
        if ((n % 10) % 2 != 0)
            odd += 1;
        n /= 10;
    }
    printf("The Number of odd digits in the number are :: %d\n", odd);
}

void Answer5()
{
    printf("Answer :: 5\n");
    printf("The fabonici sequence upto 80 is :: \n");
    int a = 0, b = 1, sum = 1, c;
    printf("%d %d ", a, b);
    while (1)
    {
        c = b + a;
        if (c >= 80)
            break;
        sum += c;
        printf("%d ", c);
        a = b;
        b = c;
    }
    printf("\nThe Sum of the sequence is :: %d\n", sum);
}
int main()
{
    Answer1();
    Answer2();
    Answer3();
    Answer4();
    Answer5();
    return 0;
}