const int K=20;
const int N=2e5+7;
int ac[K][N];
int n;
vector<int> in;
vector<int> out;
vector<int> height;
vector<int> v[N];
int t;
void build(){
	for(int i=1;i<K;i++){
		for(int j=1;j<=n;j++){
			ac[i][j]=ac[i-1][ac[i-1][j]];
		}
	}
}
bool isanc(int a,int b){
	return in[a]<=in[b]&&out[b]<=out[a];
}
int lca(int a,int b){
	
	if(isanc(a,b)) return a;
	if(isanc(b,a)) return b;
	for(int i=K-1;i>=0;i--){
		if(!isanc(ac[i][a],b)) a=ac[i][a];
	}
	return ac[0][a];
}
void dfs(int x,int h){
	in[x]=t++;
	height[x]=h++;
	for(int i:v[x]) {
		if(!in[i]){
			ac[0][i]=x;
			dfs(i,h);
		}
	}
	out[x]=t++;
}
int dis(int a,int b){
	int w=lca(a,b);
	return height[a]+height[b]-2*height[w];
}
signed main(){
	quick
	int q;
	cin>>n>>q;
	for(int i=2;i<=n;i++){
		int a,b;
		cin>>a>>b;
		v[a].eb(b);
		v[b].eb(a);
	}
	ac[0][1]=1;
	in.resize(n+1);
	height.resize(n+1);
	out.resize(n+1);
	t=1;
	dfs(1,0);
	build();
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<dis(a,b)<<"\n";
	}
}