#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        if(k%n==0)
        {
            printf("0\n");
        }
        else
        {
            int base=k/n;
            int rem=k-(base*(n-1));
            int backward=rem-base;
            int forward=n-backward;
            //printf("for=%d back=%d sum=%d\n",forward,backward,forward*base+(base+1)*backward);
            if(forward>backward)
            {
                printf("%d\n",2*backward);
            }
            else if (forward<backward)
            {
                printf("%d\n",2*forward);
            }
            else
            {
                printf("%d\n",2*forward-1);
            }
        }
    }
}
