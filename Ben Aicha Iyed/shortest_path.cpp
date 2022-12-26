 int minimum_distance(int x,int y){
    if(x==y){
        return 0;
    }

    if(dis.find({x,y})==dis.end()){
        int ans=INF;
        for(auto z:graph[x]){
            ans=min(ans,minimum_distance(z[0],y)+z[1]);
        }
        dis[{x,y}]=ans;
    }
    return dis[{x,y}];
}
void floyd_warshall(){
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}
