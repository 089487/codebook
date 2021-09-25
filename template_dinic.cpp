#include<bits/stdc++.h>
#define Woody
#define int long long 
#define rep(n) for(int i=0;i<n;i++)
#define mp make_pair
#define eb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define SETIO(s) ifstream cin(s+".in");ofstream cout(s+".out");
#ifdef Woody
#define quick ios::sync_with_stdio(0);cin.tie(0);
#else
#define quick
#endif
#define INF 1e16
using namespace std;
typedef pair<int,int> pii;
int tt=1;
int _id=0;
int S;
int T;
int len;
struct edge{
	int y,v;
	void init(int a,int b){
		y=a;
		v=b;
	}
};
edge E[1000001];
vector<int> to[30001];
vector<int> visited;
vector<int> level;
vector<int> cur;
bool BFS(){
	visited.assign(len+1,0);
	queue<int> q;
	q.push(S);
	visited[S]=1;
	level[S]=1;
	while(q.size()){
		int x=q.front();
		q.pop();
		rep(to[x].size()){
			int id=to[x][i];
			if(!visited[E[id].y]&&E[id].v){
				q.push(E[id].y);
				visited[E[id].y]=1;
				level[E[id].y]=level[x]+1;
			}
		}
	}
	return visited[T];
}
int dfs(int now,int Min){
	if(!Min) return 0;
	int flow=0;
	if(now==T) return Min;
	for(int &i=cur[now];i<to[now].size();i++){
		int id=to[now][i];
		if(!E[id].v||level[E[id].y]!=level[now]+1) continue;
		
		if(int v=dfs(E[id].y,min(E[id].v,Min))){
			E[id].v-=v;
			E[id^1].v+=v;
			flow+=v;
			Min-=v;
		}
		if(Min<=0) break;
	}
	return flow;
}
void add(int a,int b,int c){
	edge e2;
	e2.init(b,c);
	to[a].eb(_id);
	E[_id++]=e2;
	to[b].eb(_id);
	e2.init(a,0);
	E[_id++]=e2;
}
void init(int n){
	len=n+2;
	S=n+1;
	T=n+2;
	tt=1;
	_id=0;
	visited.assign(n+3,0);
	level.resize(n+3,0);
	
	for(int i=1;i<=n+2;i++) to[i].clear();
}
signed main(){
	quick
	int n,m;
	cin>>n>>m;
	init(n);
	int ans=0;
	while(BFS()){
		cur.assign(n+3,0);
		ans+=dfs(S,INF);
		tt++;
	}
	cout<<ans<<"\n";
}	