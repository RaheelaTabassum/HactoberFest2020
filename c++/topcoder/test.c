#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        long long int sum=0;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if(sum%n==0)
        {
            int mean=sum/n,flag=0,lo,re=1;
            for(int i=0;i<n;i++)
            {
                if(mean==a[i])
                {
                    re=0;
                    for(int j=i+1;j<n;j++)
                    {
                        if(a[i]==a[j])
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1)
                    {
                        printf("%d\n",i+1);
                        break;
                    }
                    printf("%d\n",a[i]);
                    break;
                }
            }
            if(re==1)
            {
                printf("Impossible\n");
            }
        }
        else
        {
            printf("Impossible\n");
        }
    }
}
