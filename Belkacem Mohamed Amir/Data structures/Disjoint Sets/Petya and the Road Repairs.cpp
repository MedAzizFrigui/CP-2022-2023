#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

typedef unsigned long long ull;
typedef unsigned int ui;	

using namespace std;

const size_t N_Max = 1<<24u;

class disjointSets{
	size_t *parent = new(size_t[N_Max]);
	size_t *sz = new(size_t[N_Max]);
	size_t nbr;
public:
	disjointSets(size_t n):nbr(n){
		for(size_t i=0;i<n;++i){
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
		return(find(x)==find(y));
	}
};
	
		

int main(void){
	ui t;
	cin>>t;
	while(t--){
		priority_queue<tuple<ui,size_t,size_t>,vector<tuple<ui,size_t,size_t>>,greater<tuple<ui,size_t,size_t>>> q;
		ui n,m;
		cin>>n>>m;
		for(size_t i=1u;i<=n;++i){
			bool ismilkman;
			cin>>ismilkman;
			if(ismilkman){
				q.push({0u,i,0u});
			}
		}
		size_t u,v;
		ui w;
		for(size_t i=0u;i<m;++i){
			cin>>u>>v>>w;
			q.push({w,v,u});
		}
		ull cost = 0llu;
		++n;
		disjointSets d = disjointSets(n);
		while(!q.empty() && d.nbrSets()>1){
			tie(w,v,u) = q.top();
			q.pop();
			if(d.merge(v,u)){
				cost += w;
			}
		}
		if(d.nbrSets()==1){
			cout<<cost<<endl;
		}else{
			cout<<"impossible"<<endl;
		}
	}
		
		
	
	return 0;
}

