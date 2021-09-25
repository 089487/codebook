const int N=501;
int dp[N][N];
signed main(){
	quick
	
	int n,m,q;
	cin>>n>>m>>q;
	fill_n(dp[0],N*N,INF);
	for(int i=0;i<n;i++){
		dp[i][i]=0;
	}
	while(m--){
		int a,b,w;
		cin>>a>>b>>w;
		--a,--b;
		dp[a][b]=min(dp[a][b],w);
		dp[b][a]=min(dp[b][a],w);
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		--a,--b;
		if(dp[a][b]==INF) dp[a][b]=-1;
		cout<<dp[a][b]<<"\n";
	}
}	