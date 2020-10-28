#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,t,a;
	t=0;
	cin>>n;
	vector<int> v(n);
	
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	for(auto i:v){
		if(i<v[n-1]){
			t+=v[n-1]-i;
		}
	}
	
	cout<<t;
	
}
