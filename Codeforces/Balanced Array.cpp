#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,s1,i,s2,j;
		s1=s2=j=0;
		cin>>n;
		int a[n];
		for(i=0;i<n-1;i++){
			if(i<n/2){
				a[i]=(i+1)*2;
				s1+=a[i];
			}else if(i>=n/2){
				a[i]=++j;
				++j;
				s2+=a[i];
				if(i==n-2 && (s1-s2)%2!=0){
					a[n-1]=s1-s2;
					s2+=a[n-1];
				}
			}
		}
		
		if(s1==s2){
			cout<<"YES"<<endl;
			for(i=0;i<n;i++){
				cout<<a[i]<<" ";
			}
		}else{
			cout<<"NO"<<endl;
		}
	}
}
