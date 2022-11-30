#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define M 100000
using namespace std;
const size_t N = 100000;
class disjointSets{
	public:
	size_t* parent = new size_t[N];
	size_t* sz = new size_t[N];
	size_t nbrOfSets;

	disjointSets(size_t n): nbrOfSets(n){
		for(size_t i=0;i<nbrOfSets;++i){
			parent[i] = i;
			sz[i]=0u;
		}
	}

	size_t find(size_t x){
		return x==parent[x]?x:x=find(parent[x]);
	}

	bool merge(size_t x,size_t y){
		size_t px = find(x) , py = find(y);
		if(px==py){
			return false;
		}
		if(sz[px]>sz[py]){
			swap(px,py);
		}
		parent[px]=py;
		sz[py]+=sz[px];
		sz[px] =0u;
		--nbrOfSets;
		return true;
	}
};

int main(void){
  FAST;
  size_t n , m;
	cin>>n>>m;
	disjointSets d(n);
	pair<size_t,size_t> t[m];
	bitset<M> b;
	b.set();
  size_t a , bb;
	for(int i=0;i<m;++i){
		cin>>a>>bb;
		t[i] = {--a , --bb};
	}
	size_t q;
	cin>>q;
	stack<size_t> s;
  size_t x;
  cin>> x;
  b[x-1]=0;
	for(int i=1;i<q;++i){
		cin>>x;
    s.push(x-1);
		b[x-1] = 0;
	}
	for(int i=0;i<m;++i){
		if(b[i]) d.merge(t[i].first,t[i].second);
	}
	vector <int> ans;
	ans.push_back(d.nbrOfSets);
	while(!s.empty()){
		size_t x = s.top();
		s.pop();
		d.merge(t[x].first,t[x].second);
		ans.push_back(d.nbrOfSets);
	}
	for(auto it=ans.rbegin();it!=ans.rend();++it){
		cout<<*it<<" ";
	}
	return 0;
}
