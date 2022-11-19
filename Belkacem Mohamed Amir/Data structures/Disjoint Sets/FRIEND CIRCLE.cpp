#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>


using namespace std;
typedef unsigned int ui;

const size_t N_Max = 1<<24u;

class disjointSets{
	size_t *parent = new(size_t[N_Max]);
	size_t *sz = new(size_t[N_Max]);
	size_t nbr;
public :
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
		if(sz[x]>sz[y]){
			swap(px, py);
		}
		parent[px] = py;
		sz[py] += sz[px];
		sz[px] = 0u;
		return true;
	}
	
	size_t nbrSets(){
		return nbr;
	}
	
	size_t sizeOfSet(size_t x){
		return sz[find(x)];
	}
	size_t memeSet(size_t x, size_t y){
		return find(x) == find(y);
	}
};

int main(void){
	ui t;
	cin>>t;
	while(t--){
		ui n;
		cin>>n;
		map<string,ui> id;
		string name1,name2;
		ui k = 0u;
		vector<pair<ui,ui>> link;
		for(size_t i=0u;i<n;++i){
			cin>>name1;
			if(id.find(name1)==id.end()){
					id[name1] = k;
					++k;
			}
			cin>>name2;
			if(id.find(name2)==id.end()){
					id[name2] = k;
					++k;
			}
			link.push_back({id[name1],id[name2]});
		}
		disjointSets d = disjointSets(k);
		for(size_t i=0u;i<n;++i){
			d.merge(link[i].first,link[i].second);
			cout<<d.sizeOfSet(link[i].first)<<endl;
		}
	}
}
			
			
			
			
			
	
