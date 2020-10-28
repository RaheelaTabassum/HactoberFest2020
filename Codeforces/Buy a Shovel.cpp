#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll k, r, res=1;
    cin>>k>>r;
    
    int i=1;
    while(true)
    {
        res = k*i;
        if(res%10 == 0 || res%10 == r)
            break;
        i++;
    }
    cout<<i;
    
	return 0;
}