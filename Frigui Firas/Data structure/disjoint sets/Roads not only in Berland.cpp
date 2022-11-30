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
    int nbrSets,N;
public:
    disjointSets(int n):nbrSets(n){
       for(int i=0u;i<nbrSets;i++){
            parent[i] = i;
            sz[i] = 1u;
       }
	   N=n;
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
		nbrSets--;
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
	vector<int> generateP(){
		vector<int> ans;
		for(int i = 0 ;i<N;++i)
			if(parent[i]==i)
				ans.push_back(i);
		return ans;
	}
};
 
 
int main(){
	
	//freopen("30BF9242-8EAF-4EE5-BFA6-9CDC6E11FB71.means.in.txt", "r", stdin);
    //freopen("mine.txt", "w", stdout);
	FAST;
	int n,x,y,nb=0;cin>>n;
	vector<pair<int,int> > trash;
	disjointSets d=disjointSets(n);
	for (int i=0;i<n-1;++i){
		cin>>x>>y;
		if (d.find(x-1)!=d.find(y-1))
			d.merge(x-1,y-1);
		else{
			trash.push_back(make_pair(x,y));
			++nb;
		}
	}
	cout<<nb<<endl;
	vector<int> ans=d.generateP();
	for(int i=0;i<nb;i++){
		cout<<trash[i].first<<' '<<trash[i].second<<' '<<ans[i]+1<<' '<<ans[i+1]+1<<endl;
		}
	
}  