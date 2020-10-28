#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)  cin>>v[i];
    int c_untreat = 0, c_cops = 0;
    
    for(int i=0; i<n; i++)
    {
        if(v[i] < 0 && c_cops == 0)
            c_untreat++;
        else
        {
            if(v[i] > 0)
                c_cops += v[i];
            else if(c_cops > 0)
                c_cops--;
        }
    }
    cout<<c_untreat;
	return 0;
}