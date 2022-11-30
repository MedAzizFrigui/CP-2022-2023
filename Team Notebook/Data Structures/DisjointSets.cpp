
//Static array implementation
const size_t MAXN=1<<18;

class disjointSets{
	size_t *parent= new size_t[MAXN];
	size_t *sz=new size_t[MAXN];
	size_t nbr;
public:
	disjointSets(size_t n):nbr(n){
		for(size_t i=0u;i<n;++i){
			parent[i]=i;
			sz[i]=1u;
		}
	}

	size_t finds(size_t v){
		return parent[v]==v?v:parent[v]=finds(parent[v]);
	}

	bool merge(size_t a, size_t b){

		a=finds(a);
		b=finds(b);

		if(a!=b){
			if(sz[a]>sz[b]) swap(a,b);
			parent[a]=b;
			sz[b]+=sz[a];
			sz[a]=0u;
			--nbr;
			return true;
		}
		return false;
	}

	size_t sizeOfSets(size_t v){
		return sz[finds(v)];
	}

	bool sameSet(size_t a, size_t b){
		return finds(a)==finds(b);
	}

	size_t nbrOfSets(){
		return nbr;
	}
};


//Dynamic array implementation
class disjointSets{
	vector<size_t>parent;
	vector<size_t>sz;
	size_t nbr;
public:
	disjointSets(size_t n):nbr(n){
		parent.reserve(nbr);
		sz.reserve(nbr);
		for(size_t i=0u;i<n;++i){
			parent[i]=i;
			sz[i]=1u;
		}
	}

	size_t finds(size_t v){
		return parent[v]==v?v:parent[v]=finds(parent[v]);
	}

	bool merge(size_t a, size_t b){

		a=finds(a);
		b=finds(b);

		if(a!=b){
			if(sz[a]>sz[b]) swap(a,b);
			parent[a]=b;
			sz[b]+=sz[a];
			sz[a]=0u;
			--nbr;
			return true;
		}
		return false;
	}

	size_t sizeOfSets(size_t v){
		return sz[finds(v)];
	}

	bool sameSet(size_t a, size_t b){
		return finds(a)==finds(b);
	}

	size_t nbrOfSets(){
		return nbr;
	}
};