    #include <bits/stdc++.h>
     
    using namespace std;
    const size_t N = int(1e5)+1;
     
    class disjointSets{
    	size_t* parent = new size_t[N];
    	size_t* sz = new size_t[N];
    	size_t nbrOfSets;
    	public:
    	disjointSets(size_t n): nbrOfSets(n){
    		for(size_t i=0;i<nbrOfSets;++i){
    			parent[i] = i;
    			sz[i] = 1u;
    		}
    	}
     
    	size_t find(size_t x){
    		return parent[x]==x?x:parent[x]=find(parent[x]);
    	}
     
    	bool merge(size_t x , size_t y){
    		size_t px = find(x);
    		size_t py = find(y);
    		if(px==py) 
    			return false;
    		if(sz[px]>sz[py])
    			swap(px,py);
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
     
    bool comp(pair<int,pair<size_t,size_t>> x , pair<int,pair<size_t,size_t>> y){
    	return x.first<=y.first;
    }
     
     
     
    int main(void){
    	int t;
    	cin>>t ;
    	while(t--){
    		size_t n , m;
    		cin>>n>>m;
    		bool milk;
    		bool ok = false;
    		vector<pair<int,pair<size_t,size_t>>> Edges;
    		for(size_t i=0;i<n;++i){
    			cin>>milk;
    			if(milk){
    				Edges.push_back({0,{i+1,0}});
    				ok = true;
    			}
    		}
    		size_t a , b ;
    		int c ;
    		for(size_t i=0;i<m;++i){
    			cin>>a>>b>>c;
    			Edges.push_back({c,{a,b}});
    		}
    		disjointSets d(n+1);
    		long long int cost = 0 ;
    		sort(Edges.begin(),Edges.end());
    		for (auto u:Edges){
    			if(d.merge(u.second.first,u.second.second))
    				cost+=u.first*1ll;
    		}
    		if(d.numberOfSets()==1 && ok)
    			cout<<cost<<endl;
    		else cout<<"impossible"<<endl;
    	}
    	return 0;
    }
