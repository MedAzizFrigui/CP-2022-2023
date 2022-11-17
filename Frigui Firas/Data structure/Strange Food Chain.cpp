#include <iostream>
#include <algorithm>
#include <vector>
#include<map>
#include <cstddef>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
const size_t N_MAX = 60000u;
typedef long long int ll;
 
class disjointSets{
    int parent[N_MAX];
    int sz[N_MAX];
    int nbrSets;
	int rel[N_MAX];
public:
    disjointSets(int n):nbrSets(n){
       for(int i=0;i<nbrSets;i++){
            parent[i] = i;
            sz[i] = 1;
			rel[i]=0;
       }
    }
 
    int find(int e){
		rel[e]=findR(e);
        return parent[e]==e?e:parent[e]=find(parent[e]);
    }
	int findR(int e){
 
		return parent[e]==e?0:(rel[e]+findR(parent[e]))%3;
	}
    bool merge(int x , int y,int s){
    int px = find(x);
        int py = find(y);
        
		int r=(rel[y]+2*rel[x])%3;
		if(s==2) r=(r+1)%3;
                if(px==py){
            return false;
        }
        if(sz[px]>sz[py]){
            swap(px,py);
			r=(2*r)%3;
        }
		rel[px]=r;
 
        parent[px]=py;
        sz[py]+=sz[px];
        sz[px]=0;
        --nbrSets;
        return true;
    }
 
    int sizeOfSet(int x){
        return sz[find(x)];
    }
 
    int numberOfSets(){
        return nbrSets;
    }
 
    bool sameSet(int x,int y){
        return find(x)==find(y) ;
    }
};
 
int main(){
    FAST;
    ll u;cin>>u;
    while(u--){
		int rep=0,n,k,s,x,y;
		cin>>n>>k;
		disjointSets d=disjointSets(n);
		while(k--){
			cin>>s>>x>>y;
			if((x>n || y>n )||(s==2 && x==y)||(x<=0||y<=0)){
				rep++;
			}
			else
			{
				if(d.find(x-1)!=d.find(y-1))
				d.merge(x-1,y-1,s);
			else
				if(s==1&& d.findR(x-1)!=d.findR(y-1))
					rep++;
				else
					if(s==2 && (d.findR(x-1)!=(1+d.findR(y-1))%3))
						rep++;
					
			
			}
		}
		cout<<rep<<endl;
		
	}
 
}
