#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
using namespace std ;

const size_t N = 100000;
class disjointSets{
	size_t *parent= new size_t[N];
	size_t *sz=new size_t[N];
	size_t nbrOfSets;
	public:
	disjointSets(size_t n):nbrOfSets(n){
		for(size_t i=0;i<nbrOfSets;++i){
			parent[i] = i;
			sz[i] = 1u;
		}
	}
	
	size_t find(size_t e){
		return parent[e]==e?e:parent[e]=find(parent[e]);
	}
	
	bool merge(size_t x, size_t y){
		size_t px = find(x);
		size_t py = find(y);
		if (px==py) return false;
		if (sz[px]>sz[py]){
			swap(px,py);
		}
		parent[px] = py ;
		sz[py]+=sz[px];
		sz[px]=0u;
		--nbrOfSets;
		return true;
	}
	
	size_t sizeOfSet(size_t x){
		return sz[find(x)];
	}
	
	size_t numberOfSets(){
		return nbrOfSets;
	}
};

int main(void)
{
	FAST;
	size_t n , q , a , b ,maxx = 1,minn = 1;
	bool test=1;
	cin >> n >> q ;
	disjointSets d(n);
	while(q--)
	{
			cin >> a >> b ;
			test = (d.sizeOfSet(a-1)==minn)||(d.sizeOfSet(b-1)==minn);
			d.merge(a-1,b-1);
			maxx = max(maxx , d.sizeOfSet(a-1));
			if(test)
			{
				size_t s = d.sizeOfSet(0);
				for(int i=1 ; i<n ;++i)
				{
					s = d.sizeOfSet(i)>s ? s:d.sizeOfSet(i);
					if(s==minn) break;
				}
				minn = s ;
			}
			cout <<maxx-minn <<endl;
			
	}
	return 0;
}
	
