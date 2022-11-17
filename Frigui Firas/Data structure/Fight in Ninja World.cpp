#include <iostream>
#include <algorithm>
#include <vector>
#include<map>
#include <cstddef>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define f first
#define s second
const size_t N_MAX = 60000u;
typedef long long int ll;
 
class disjointSets{
    pair<int,int> parent[N_MAX];
    int sz[N_MAX];
	int foe[N_MAX];
    int nbrSets;
	
public:
    disjointSets(int n):nbrSets(n){
       for(int i=0;i<nbrSets;i++){
            parent[i] = make_pair(i,0);
            sz[i] = 1;
			foe[i]=0;
			
       }
    }
 
    pair<int,int> find(int e){
		// rel[e]=findR(e);
        // return parent[e]==e?e:parent[e]=find(parent[e]);
		if(parent[e].f==e) return parent[e];
		
		int tmp=parent[e].s;
		parent[e]=find(parent[e].f);
		parent[e].s=(parent[e].s+tmp)%3;
		return parent[e];
    }

    bool merge(int x , int y){
		int px = find(x).f;
        int py = find(y).f;
		int r=(parent[y].s+1-parent[x].s)%2;
        if(px==py){
            return false;
        }
        if(sz[px]>sz[py]){
            swap(px,py);
        }
		parent[px].s=r;
		if (r)
			foe[py]+=sz[px]-foe[px];
		else
			foe[py]+=foe[px];
        parent[px].f=py;
        sz[py]+=sz[px];
        sz[px]=0;
        --nbrSets;
        return true;
    }
 
    int sizeOfSet(int x){
        return sz[find(x).f];
    }
	int foes(int x){
        return foe[find(x).f];
    }
    int numberOfSets(){
        return nbrSets;
    }
 
    bool sameSet(int x,int y){
        return find(x).f==find(y).f ;
    }
};
int main(){
    FAST;
    ll u;cin>>u;
    for (int c=1;c<=u;c++){
		int rep=0,n,k,s,x,y;
		cin>>n;
		disjointSets d=disjointSets(N_MAX);
		while(n--){
			cin>>x>>y;
			d.merge(x-1,y-1);
		}
		for(int i =0;i<N_MAX;i++)
			if (d.find(i).f==i && d.sizeOfSet(i)!=1)
				rep+=max(d.foes(i),d.sizeOfSet(i)-d.foes(i));
		
		cout<<"Case "<<c<<": "<<rep<<endl;
		
	}
 
}