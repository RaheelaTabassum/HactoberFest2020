#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int a[n], b[n];
        for(int i=0; i<n; i++)  cin>>a[i];
        for(int i=0; i<n; i++)  cin>>b[i];
        sort(a, a+n);
        sort(b, b+n);
        int i=0, j=n-1;
        while(k>0 && i<n && j>=0)
        {
            // cout<<"#"<<a[i]<<"  "<<b[j]<<endl;
            if(b[j] > a[i])
            {
                swap(a[i], b[j]);
                i++;
                k--;
            }
            j--;
        }
        int sum = 0;
        sum = accumulate(a, a+n, sum);
        cout<<sum<<endl;
    }
	return 0;
}