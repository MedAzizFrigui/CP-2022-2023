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
