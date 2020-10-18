t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    ans=0
    for j in range(n):
        ans=ans^(2*a[j])
    print(ans)
