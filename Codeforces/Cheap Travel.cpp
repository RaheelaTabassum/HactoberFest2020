#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,a,b,o,x,l,c;
	
	cin>>n>>m>>a>>b;
	o=n*a;
	x=n%m;
	l=n/m;
	c=min(x*a,b)+(l*b);
	
	if(c<o){
		cout<<c;
		return 0;
	}
	else{
		cout<<o;
	}

}
