int t;
const int N=10005;
vector<int> in;
vector<int> low;
vector<int> V[N];
map<pii,int> Mp;
vector<int> ans;
void dfs(int x,int p){
	low[x]=in[x]=t++;
	bool flag=false;
	int cnt=0;
	for(int i:V[x]){
		if(i==p) continue;
		if(!in[i]){
			cnt++;
			dfs(i,x);
			low[x]=min(low[x],low[i]);
			if(low[i]>=in[x]) flag=true;
		}
		else{
			low[x]=min(low[x],in[i]);
			
		}
	}
	if(flag&&(x!=1||cnt>1)){//x is a cut-vertex
		ans.eb(x);
	}
	return ;
}
signed main(){
	quick
	int T;
	cin>>T;
	while(T--){
		ans.clear();
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++) V[i].clear();
		while(m--){
			int a,b;
			cin>>a>>b;
			if(a==b) continue;
			V[a].eb(b);
			V[b].eb(a);
		}
		t=1;
		in.assign(n+1,0);
		low.assign(n+1,0);
		dfs(1,0);
		sort(all(ans));
		cout<<SZ(ans)<<"\n";
		if(SZ(ans)){
			for(int i:ans) cout<<i<<" ";cout<<"\n";
		}
		else cout<<0<<"\n";	
	}
	
}	