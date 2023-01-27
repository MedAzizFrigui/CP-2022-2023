#include <algorithm>
#include <iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
const size_t N=100000,inf=1e9;

int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
int n,m;
pair<int,int> e;
bool getDir(int x,int y,int k,int& nx,int& ny){
	nx=x+dx[k];
	ny=y+dy[k];
	return nx>=0 && nx<n && ny<m && ny>=0;
}

int main(void){
	ios::sync_with_stdio(false);  cin.tie(0);
	int u;cin>>u;
	while(u--){
		int n,m,src,dist,x,y,d;cin>>n>>m>>src>>dist;
		vector<pair<int,int> > adj[n];
		bool done[n];
		int path[n];
		for(int i=0;i<n;++i){
			done[i]=false;
			path[i]=inf;
		}
		for(int i=0;i<m;++i){
			cin>>x>>y>>d;
			adj[x-1].push_back(make_pair(y-1,d));
			adj[y-1].push_back(make_pair(x-1,d));
		}
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
		path[src-1]=0;
		q.push(make_pair(0,src-1));
		while(!q.empty()){
			e=q.top();
			q.pop();
			x=e.second;
			if(done[x]) continue;
			done[x]=true;
			for(auto u:adj[x]){
				y=u.first;
				if(path[y]>path[x]+u.second){
					path[y]=path[x]+u.second;
					q.push(make_pair(path[y],y));
				}
			}
		}

		if(path[dist-1]!=inf)
			cout<<path[dist-1]<<endl;
		else
			cout<<"NONE"<<endl;
	}
	return 0;	
}