#include <algorithm>
#include <iostream>
#include<vector>
#include<string>
#include<map>
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
		int n,r,src,dist,y,d,x;cin>>n;
		string ch,ch1;
		map<string,int> mp;
		vector<pair<int,int> > adj[n];
		for( x=0;x<n;++x){
			cin>>ch;
			mp[ch]=x;
			cin>>m;
			for(int i=0;i<m;++i){
				cin>>y>>d;
				adj[x].push_back(make_pair(y-1,d));
			}
		}
		bool done[n];
		int path[n];
		cin>>r;
		for(int g=0;g<r;++g){
			cin>>ch>>ch1;
			src=mp[ch];dist=mp[ch1];
			for(int i=0;i<n;++i){
				done[i]=false;
				path[i]=inf;
			}
			priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
			path[src]=0;
			q.push(make_pair(0,src));
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
			if(path[dist]!=inf)
				cout<<path[dist]<<endl;
			else
				cout<<"NONE"<<endl;
		}
	}
	return 0;	
}