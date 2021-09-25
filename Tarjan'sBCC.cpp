const int N=1e4+7;
vector<int> v[N];
vector<int> in;
vector<int> out;
vector<int> low;
stack<int> st;
map<pii,int> Mp;
vector<vector<int> > bcc;
int t;
void dfs(int x,int p){
	st.push(x);
	low[x]=in[x]=t++;
	for(int i:v[x]){
		if(i==p&&Mp[mp(i,x)]==1) continue;//judge for same edge
		if(!in[i]){
			dfs(i,x);
			low[x]=min(low[x],low[i]);
		}
		else low[x]=min(low[x],in[i]);
	}
	if(low[x]>in[p]){//there's bridge between x,p
		vector<int> v2;
		int x2=-1;
		while(st.size()&&x2!=x)x2=st.top(), v2.eb(st.top()),st.pop();
		sort(all(v2));
		bcc.eb(v2);
	}
}
bool cmp(vector<int> a,vector<int> b){
	return a[0]<b[0];
}
signed main(){
	quick
	int n,m;
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		v[b].eb(a);
		v[a].eb(b);
		Mp[mp(a,b)]++;
		Mp[mp(b,a)]++;
	}
	t=1;
	in.assign(n,0);
	out.resize(n);
	low.resize(n);
	dfs(0,0);
	int cnt=0;
	vector<int> v2;
	if(SZ(st)){
			
		while(st.size())v2.eb(st.top()),st.pop();
		sort(all(v2));
		bcc.eb(v2);
		sort(all(bcc),cmp);
	}
	for(vector<int>&v2:bcc){
		cout<<++cnt<<":";
		for(int i:v2) cout<<" "<<i;cout<<"\n";
	}
}