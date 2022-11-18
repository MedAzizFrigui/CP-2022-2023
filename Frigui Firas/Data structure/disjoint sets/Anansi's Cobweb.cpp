#include <iostream>
#include <algorithm>
#include <vector>
#include<map>
#include <cstddef>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
const size_t N_MAX = 200000u;
typedef long long int ll;
 
class disjointSets{
    int parent[N_MAX];
    int sz[N_MAX];
    int nbrSets;
public:
    disjointSets(int n):nbrSets(n){
       for(int i=0u;i<nbrSets;i++){
            parent[i] = i;
            sz[i] = 1u;
       }
    }
 
    int find(int e){
        return parent[e]==e?e:parent[e]=find(parent[e]);
    }
 
    bool merge(int x , int y){
        int px = find(x);
        int py = find(y);
        if(px==py){
            return false;
        }
        if(sz[px]>sz[py]){
            swap(px,py);
        }
        parent[px]=py;
        sz[py]+=sz[px];
        sz[px]=0u;
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
	
	//freopen("30BF9242-8EAF-4EE5-BFA6-9CDC6E11FB71.means.in.txt", "r", stdin);
    //freopen("mine.txt", "w", stdout);
	FAST;
	int n,m,x,y,q;cin>>n>>m;
	pair<int,int> th[m];
	bool Ncut[m];
	vector<int> ans;
	for (int i=0;i<m;++i){
		cin>>x>>y;
		Ncut[i]=true;
		th[i]=make_pair(x-1,y-1);
	}
	cin>>q;
	int query[q];
	for (int i=0;i<q;++i){
		cin>>x;
		Ncut[x-1]=false;
		query[i]=x-1;
	}
	disjointSets d=disjointSets(n);
	for(int i=0;i<m;++i)
		if(Ncut[i])
			d.merge(th[i].first,th[i].second);
	ans.push_back(d.numberOfSets());
	for(int i=q-1;i>0;--i){
		d.merge(th[query[i]].first,th[query[i]].second);
		ans.push_back(d.numberOfSets());
	}
	for(int i=q-1;i>=0;--i){
		cout<<ans[i]<<' ';
	}
	
}    