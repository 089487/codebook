vector<pii> v[N];
struct cmp{
	bool operator ()(pii a,pii b){
		return a.S>b.S;
	}
};
signed main(){
	quick
	int n,m;
	cin>>n>>m;
	priority_queue<pii,vector<pii>,cmp> pq;
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].eb(mp(b,c));
	}
	vector<int> ans;
	vector<bool> visited;
	ans.assign(n+1,INF);
	visited.assign(n+1,0);
	ans[1]=0;
	visited[1]=0;
	pq.push(mp(1,0));
	while(pq.size()){
		pii p2=pq.top();
		pq.pop();
		if(visited[p2.F]) continue;
		visited[p2.F]=true;
		for(pii p3:v[p2.F]){
			if(ans[p3.F]>p3.S+p2.S){
				ans[p3.F]=p2.S+p3.S;
				pq.push(mp(p3.F,ans[p3.F]));
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<"\n";
}