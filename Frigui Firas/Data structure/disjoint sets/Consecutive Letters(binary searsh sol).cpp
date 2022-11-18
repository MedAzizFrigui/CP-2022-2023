#include <iostream>
#include <algorithm>
#include <vector>
#include<map>
#include <cstddef>
#include<set>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
 
const size_t N_MAX = 200000u;
typedef long long int ll;
 
int main(){
    FAST;
    int u;cin>>u;
	int n,q,m,j;
	string ch;
	set<int>::iterator it1,it2;
    for (int c=1;c<=u;++c){
		cout<<"Case "<<c<<": "<<'\n';
		cin>>ch;
		n=ch.length();
		cin>>q;
		set<int> s;
		s.insert(0);
		for (int i=1;i<n;++i)
			if (ch[i]!=ch[i-1])
				s.insert(i);
		s.insert(n);
		++q;
		while(--q){
			cin>>m>>j;
			if (!(m&1)){
				s.insert(j);
				s.insert(j+1);
			}
			else{
				it1=s.upper_bound(j);
				it2=it1--;
				cout<<*(it2)-*(it1)<<'\n';
				
			}
		}
		
	}
 
}  