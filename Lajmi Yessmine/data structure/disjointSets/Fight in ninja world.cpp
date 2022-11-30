#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define N 20000
using namespace std;

class disjointSets{
	public:
	size_t* parent= new size_t[N];
	size_t* sz = new size_t[N];
	size_t nbrOfSets ;
	int* distance = new int[N];

	disjointSets(size_t n):nbrOfSets(n){
		for(size_t i=0 ; i<nbrOfSets;++i){
			parent[i]=i;
			sz[i]=1u;
			distance[i]=-1;
		}
	}

	size_t find(size_t x){
		stack<size_t> s;
		while(x!=parent[x]){
			s.push(x);
			x = parent[x];
		}
		size_t z;
		while(!s.empty()){
			z = s.top();
			s.pop();
			distance[z]+=distance[parent[z]];
			parent[z] = x;
		}
		return x;
	}

	bool merge(size_t x,size_t y){
		size_t px = find(x) , py = find(y);
		if(distance[x]==-1) distance[x]=0;
		if(distance[y]==-1) distance[y]=0;
		int d = ((1-distance[x]+distance[y])%2+2)%2;
		if(px==py){
			return false;
		}
		if(sz[px]>sz[py]){
			swap(px,py);
		}
		parent[px] = py;
		distance[px] = d;
		sz[py]+=sz[px];
		sz[px]=0u;
		--nbrOfSets;
		return true;
	}
};

int main(void){
	int t;
	FAST;
	cin>>t;
	for (int u=1; u<=t;++u){
		int n;
		cin>>n;
		disjointSets d(N);
		for(int i=0;i<n;++i){
			int a , b ;
			cin>>a>>b;
			d.merge(--a,--b);
		}
		map<int,pair<int,int>> m;
		for(int i=0;i<20000;++i){
			if(d.distance[i]!=-1){
			    size_t x = d.find(i);
                if(m.find(x)==m.end()){
                    m[x]={0,0};
                }
			m[x].first+=!(d.distance[i]&1);
			m[x].second+=(d.distance[i]&1);
			}
		}
		int ans =0;
		for(auto it=m.begin();it!=m.end();++it){
            ans+=max((it->second).first,(it->second).second);
		}
		cout<<"Case "<<u<<": "<< ans<<endl;
	}
	return 0;
}
