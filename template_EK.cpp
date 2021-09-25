#include<bits/stdc++.h>
//#define Woody
#define int long long 
#define rep(n) for(int i=0;i<n;i++)
#define mp make_pair
#define eb emplace_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define SETIO(s) ifstream cin(s+".in");ofstream cout(s+".out");
#ifdef Woody
#define quick ios::sync_with_stdio(0);cin.tie(0);
#else
#define quick
#endif
#define INF INT64_MAX
using namespace std;
typedef pair<int,int> pii;
int tt=1;
int _id=0;
int S;
int T;
struct edge{
	int y,v;
	void init(int a,int b){
		y=a;
		v=b;
	}
};
edge E[30001];
vector<int> to[50001];
vector<int> visited;
int dfs(int now,int Min){
	if(visited[now]==tt) return 0;
	visited[now]=tt;
	if(now==T) return Min;
	for(int id:to[now]){
		if(!E[id].v) continue;
		if(int v=dfs(E[id].y,min(E[id].v,Min))){
			E[id].v-=v;
			E[id^1].v+=v;
			return v;
		}
	}
	return 0;
}
void add(int a,int b,int c){
	to[a].eb(_id);
	E[_id++]={b,c};
	to[b].eb(_id);
	E[_id++]={a,0};
}
void init(int len){
	S=len+1;
	T=len+2;
	tt=1;
	_id=0;
	visited.assign(len+3,0);
	for(int i=1;i<=len+2;i++) to[i].clear();
}
signed main(){
	quick

	cout<<ans<<"\n";
}	