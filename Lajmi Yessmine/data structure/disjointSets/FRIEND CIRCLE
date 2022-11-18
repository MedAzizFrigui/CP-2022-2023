#include <bits/stdc++.h>
#define N 100001
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
using namespace std;

class disjointSets{
	size_t *parent= new size_t[2*N];
	size_t *sz=new size_t[2*N];
	size_t nbrOfSets;
	public:
	disjointSets(size_t n):nbrOfSets(n){
		for(size_t i=0;i<nbrOfSets;++i){
			parent[i] = i;
			sz[i] = 1u;
		}
	}
	
	size_t find(size_t e){
		return parent[e]==e?e:parent[e]=find(parent[e]);
	}
	
	bool merge(size_t x, size_t y){
		size_t px = find(x);
		size_t py = find(y);
		if (px==py) return false;
		if (sz[px]>sz[py]){
			swap(px,py);
		}
		parent[px] = py ;
		sz[py]+=sz[px];
		sz[px]=0u;
		--nbrOfSets;
		return true;
	}
	
	size_t sizeOfSet(size_t x){
		return sz[find(x)];
	}
	
	size_t numberOfSets(){
		return nbrOfSets;
	}
};


int main(void){
	int t ;
	cin>>t;
	map<string,size_t> m;
	while(t--){
		int n  ;
		size_t k=0;
		cin>>n;
		disjointSets d(2*n+1);
		for(size_t i=0;i<n;++i){
			string a , b ;
			cin>>a>>b;
			if(m.find(a)==m.end()){
				m[a] = k;
				++k;
			}
			if(m.find(b)==m.end()){
				m[b] = k;
				++k;
			}
			d.merge(m[a],m[b]);
			cout<<d.sizeOfSet(d.find(m[a]))<<endl;
		}
	}
	return 0;

}
		
