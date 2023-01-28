#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main(void){
	int m, n;
	cin>>m>>n;
	while(m!=-1 && n!=-1){
		double a =  1.0+8.0*(double)n;
		int k = (int)(((sqrt(a))-1.0)/2.0) ;
		vector<int> t(m,0);
		for(int i=0;i<=k;++i){
			t[m-1-i] = m+i-k;
		}
		for(int i=1;i<m-k;++i){
			t[i-1] = i;
		}
		if(k*(k+1)==2*n){
			for(int i=0;i<m;++i)
				cout<<t[i]<<' ';
			cout<<'\n';
			cin>>m>>n;
			continue;
		}
		int d = n - k*(k+1)/2;
		swap(t[m-d], t[m-k-2]);
		for(int i=m-d;i<m-1;++i)
            swap(t[i],t[i+1]);
		for(int i=0;i<m;++i)
			cout<<t[i]<<' ';
		cout<<'\n';
		cin>>m>>n;
	}
	return 0;
}

// a better approach 
/*
int main()
{

    int n,m,inversion,invertSeq;
    while(cin>>n>>m){
        if(n==-1&&m==-1)
            break;

        int i;
        int invertSeq=1;
        while(invertSeq*(invertSeq-1)/2<m)
            invertSeq++;

        int first=n-(invertSeq*(invertSeq-1)/2-m);

        for(int j=1;j<=n-invertSeq;j++){
            cout<<j<<" ";
        }

        cout<<first<<" ";

        for(int j=n;j>n-invertSeq;j--){
            if(j!=first)
                cout<<j<<" ";
        }
        cout<<endl;
    }
}
*/
