#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
 
const size_t N = 1000;
class disjointSets{
	public:
	size_t* parent = new size_t[N];
	size_t* sz = new size_t[N];
	size_t nbrOfSets;
	
	disjointSets(size_t n):nbrOfSets(n){
		for(size_t i=0;i<nbrOfSets;++i){
			parent[i]=i;
			sz[i]=1u;
		}
	}
	
	size_t find(size_t x){
		return parent[x]==x?x:parent[x]=find(parent[x]);
	}
	
	bool merge(size_t x, size_t y){
		size_t px = find(x) , py = find(y);
		if(px==py){
			return false;
		}
		if(sz[px]>sz[py]){
			swap(px,py);
		}
		parent[px] = py;
		sz[py]+=sz[px];
		sz[px]=0u;
		--nbrOfSets;
		return true;
	}
};
 
int main(void){
	int n , x;
	cin>>n;
	x = n;
	disjointSets d(n);
	vector <size_t> c;
	while(--n){
		size_t a , b;
		cin>>a>>b;
		--a;
		--b;
		if(!d.merge(a,b)){
			c.push_back(++a);
			c.push_back(++b);
		}
	}
	cout<<d.nbrOfSets-1<<endl;
	if(d.nbrOfSets>1){
	vector<size_t> cc;
	for(size_t i=0;i<x;++i){
		if(i==d.parent[i]) {
			cc.push_back(i+1);
			}
	}	
	for(size_t i=0; i<c.size();i+=2){
		cout<<c[i]<<" "<<c[i+1]<<" "<<cc[i/2]<<" "<<cc[i/2+1]<<endl;
	}
	}
	return 0;
}
