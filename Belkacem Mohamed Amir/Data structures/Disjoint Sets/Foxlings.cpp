#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef unsigned int ui;

const size_t N_Max = 1u<<24u;

class disjointSets{
	size_t *parent = new(size_t[N_Max]);
	size_t *sz = new(size_t[N_Max]);
	size_t nbr;
public:
	disjointSets(size_t n):nbr(n){
		for(size_t i=0u;i<nbr;++i){
			parent[i] = i;
			sz[i] = 1u;
		}
	}
	
	size_t find(size_t x){
		return parent[x]==x?x:parent[x]=find(parent[x]);
	}
	
	bool merge(size_t x, size_t y){
			size_t px = find(x);
			size_t py = find(y);
			if(px==py){
				return false;
			}
			if(sz[px]>sz[py]){
				swap(px,py);
			}
			parent[px]=py;
			sz[py] += sz[px];
			sz[px] = 0u;
			--nbr;
			return true;
	}
	
	size_t sizeOfSet(size_t x){
		return sz[find(x)];
	}
	
	size_t nbrSets(){
		return nbr;
	}
	
	bool sameSet(size_t x, size_t y){
			return find(x)==find(y);
	}
};




int main(void){
	ui n,m;
	cin>>n>>m;
	ui a,b;
	map<ui,ui> id;
	vector<pair<ui,ui>> v;
	ui k=0u;
	for(ui i=0u;i<m;++i){
		cin>>a>>b;
		if(id.find(a)==id.end()){
			id[a] = k;
			++k;
		}
		if(id.find(b)==id.end()){
			id[b] = k;
			++k;
		}
		v.push_back({id[a],id[b]});
	}
	disjointSets d = disjointSets(id.size());	
	for(ui i=0u;i<m;++i){
		d.merge(v[i].first,v[i].second);
	}
	cout<<d.nbrSets()+n-id.size()<<endl;

}
