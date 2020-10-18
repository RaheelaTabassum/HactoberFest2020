t=int(input())
for i in range(t):
    n=int(input())
    k=int(input())
    if k%n==0:
        print('0')
    else:
        base=k//n
        rem=k-(base*(n-1))
        backward=rem-base
        forward=n-backward
        if(forward>backward):
            print(2*backward)
        elif(forward<backward):
            print(2*forward)
        else:
            print(2*forward-1)
