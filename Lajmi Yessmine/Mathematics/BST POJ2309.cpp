#include<iostream>
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)

using namespace std;
unsigned long long int power(unsigned long long  int  a , unsigned long long int b ){
    unsigned long long int res = 1ull;
    while(b){
        if(b&1){
            res *= a;
        }
        a*=a;
        b>>=1;
    }
    return res;
}
int main(void){
	FAST;
	int t;
	cin>>t;
	while(t--){
		unsigned long long int n;
		cin>>n;
		unsigned long long int l = 0ull;
			while(n%power(2,l)==0){
				++l;
			}
			--l;
		unsigned long long int k = power(2,l);
		unsigned long long int dist = (n - k)/(k*2);
		unsigned long long int mini = k*dist*2 + 1 ;
		unsigned long long int maxi = k*(dist+1)*2 - 1;
		cout<<mini<<" "<<maxi<<endl;
	}
	return 0;
}
