int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
	int dist[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dist[i][j]=0;
            }
            else{
                dist[i][j]=1e9;
            }
        }
    }
    for(int i=0;i<m;i++){
        int u = edges[i][0]; ///edges vector of vector e prottekta vector er tinta part
		int v = edges[i][1]; /// starting of an edge, ending of an edge and weight of an edge
		int w = edges[i][2]; /// vector traverse kore ei value gula ber kore ene amader distance vector e boshaite hobe
        dist[u][v]=w;        /// then use floyd-warshall algorithm on the distance vector as usual!
    }
    for(int k=1;k<=n;k++){ /// k value represents the intermediate nodes
        for(int i=1;i<=n;i++){ /// i value represents the source nodes
            for(int j=1;j<=n;j++){ /// j value represents the destination nodes
                if(dist[i][k]!=1e9 && dist[k][j]!=1e9){
					dist[i][j] = min(dist[i][j], (dist[i][k] + dist[k][j]) );
				}
            }
        }
    }
	return dist[src][dest];
}
