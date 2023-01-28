#include<iostream>
#include<vector>
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)

using namespace std;
vector<int> connections[101] ;

vector<int> add(vector<int> a , vector<int> b){
        if(a.size()<b.size()) return add(b,a);
        int m = a.size();
        int n = b.size();
        vector<int> res(m,0);
        int c = 0 , temp = 0;
        for(int i=0;i<n;++i){
            temp = a[i]+b[i]+c;
            res[i] = temp%10;
            c = temp/10;
        }
        for(int i=n;i<m;++i){
            temp = a[i] + c;
            res[i] = temp%10;
            c = temp / 10;
        }
        if(c!=0) res.push_back(c);
        return res;
}

vector<int> mul(vector<int> a , vector<int> b){
    vector<int> res(a.size()+b.size(),0);
    if(a.size()<b.size()){
        return mul(b,a);
    }
    int temp = 0 , c = 0;
    for(int i=0;i<b.size();++i){
        int j = 0;
        for(j;j<a.size();++j){
            temp = (a[j]*b[i])+c;
            res[i+j] += temp %10;
            c = temp/10;
        }
        if(c!=0) res[i+j]+=c;
        c = 0;
    }
    if((*res.rbegin())==0) res.erase(res.end()-1);
    return res;
}
vector<int> nbrOfConnections(int n) {
    if(connections[n].size()>0 || (connections[n].size()==1 && connections[n][0]!=0)) return connections[n];
    else if (connections[n].size()==0) connections[n].push_back(0);
    for(int i=1;i<=n;++i)
        connections[n]=add(connections[n],mul(nbrOfConnections(n-i),nbrOfConnections(i-1)));
    return connections[n];
}
int main(void){
   FAST;
   connections[0].push_back(1);
   connections[1].push_back(1);
   connections[2].push_back(2);
   int n ;
   cin>>n;
   while(n!=-1){
        connections[n] = nbrOfConnections(n);
        for(vector<int>::reverse_iterator it = connections[n].rbegin();it!=connections[n].rend();++it){
            cout<<*it;
        }
        cout<<endl;
        cin>>n;
   }
	return 0;
}
