#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    cin>>t;
    while(t--)
    {
        string b, a="";
        cin>>b;
        int n = b.length();
        if(n==2)
            a = b;
        else
        {
            int i;
            for(i=0; i<n-1; i++)
            {
                if(i%2 == 0)
                    a += b[i];
            }
            a += b[i];
        }
        cout<<a<<endl;
    }
	return 0;
}