#include <algorithm>
#include <iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
const size_t N=100000,inf=1e9;

int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
int n,m;
vector<int> adj[10000]; 
multiset<int,greater<int> > branch[10000];
set<int,greater<int> > ans;
bool getDir(int x,int y,int k,int& nx,int& ny){
	nx=x+dx[k];
	ny=y+dy[k];
	return nx>=0 && nx<n && ny<m && ny>=0;
}

int dfs(int i,int s){
	int best=1;
	for(auto u:adj[i])
		if(u!=s)
			branch[i].insert(1+dfs(u,i));
	if(branch[i].size()==0)
		return 1;
	multiset<int,greater<int> >::iterator it=branch[i].begin();
	best=*(it);
	if(branch[i].size()==1)
		return best;
	ans.insert(best+*(++it)-1);
	return best;
}

int main(void){
	ios::sync_with_stdio(false);  cin.tie(0);
	int u=1;
	while(u--){
		int n,x,y,mx=-1;cin>>n;
		for(int i=0;i<n-1;++i){
			cin>>x>>y;
			adj[x-1].push_back(y-1);
			adj[y-1].push_back(x-1);
		}
		mx=dfs(0,inf);
		if(ans.size()>=1)
			cout<<max(mx,*(ans.begin()))-1<<endl;
		else
			cout<<mx-1<<endl;
	}
	return 0;	
}