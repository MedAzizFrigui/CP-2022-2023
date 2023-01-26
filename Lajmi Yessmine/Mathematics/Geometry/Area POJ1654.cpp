#include<iostream>
#include<string>
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)

using namespace std;

int main(void){
	FAST;
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		long long int x = 0 , y = 0 , a = 0 , xp , yp;
		for(int i=0;i<s.length()-1;++i){
			yp= y+(s[i]=='8')+(s[i]=='9')+(s[i]=='7')-(s[i]=='2')-(s[i]=='1')-(s[i]=='3');
			xp= x+(s[i]=='6')+(s[i]=='9')+(s[i]=='3')-(s[i]=='4')-(s[i]=='7')-(s[i]=='1');
			a+=x*yp-xp*y;
			x = xp;
			y = yp;
		}
		if(a<0) a=-a;
        if(a%2==0) cout<<a/2<<'\n';
        else cout<<a/2.0<<"\n";
	}
	return 0;
}
