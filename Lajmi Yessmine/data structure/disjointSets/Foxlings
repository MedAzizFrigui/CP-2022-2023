#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)

using namespace std;
class disjointSets{
	vector<size_t> parent;
	vector<size_t> sz;
	size_t nbrOfSets;
	public:
	disjointSets(size_t n):nbrOfSets(n){
		for(size_t i=0;i<nbrOfSets;++i){
			parent.push_back(i) ;
			sz.push_back(1u);
		}
	}
	
	size_t find(size_t x){
		return parent[x]==x?x:parent[x]=find(parent[x]);
	}
	
	bool merge(size_t x, size_t y){
		size_t px = find(x);
		size_t py = find(y);
		if(px==py) return false;
		if(sz[px]>sz[py]){
			swap(px,py);
		}
		parent[px] = py;
		sz[py]+=sz[px];
		sz[px]=0u;
		--nbrOfSets;
		return true;
	}
	
	size_t numberOfSets(){
		return nbrOfSets;
	}
};

int main(void){
	FAST;
	size_t m , n ,k=0;
	cin>>n>>m;
	map<size_t,size_t> ma;
	disjointSets d(2*m);
	size_t a , b;
	for(size_t i=0;i<m;++i){
		cin>>a>>b;
		if(ma.find(a)==ma.end()){
			ma[a]=k++;
		}
		if(ma.find(b)==ma.end()){
			ma[b]=k++;
		}
		d.merge(ma[a],ma[b]);
	}
	cout<<n-2*m+d.numberOfSets();
	return 0;
}
	
	
