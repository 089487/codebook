#include<bits/stdc++.h>
//#define Woody
#define int long long 
#define lowbit(x) (x&-x)
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
struct BIT2D{
	vector<vector<int> > bit;
	int n;
	void init(int a){
		n=a;
		bit.assign(n+1,vector<int>(n+1,0));
	}
	void add(int x,int y,int val){
		for(int i=x;i<=n;i+=lowbit(i)){
			for(int j=y;j<=n;j+=lowbit(j)){
				bit[i][j]+=val;
			}
		}
	}
	int query(int x,int y){
		int sum=0;
		for(int i=x;i>0;i-=lowbit(i)){
			for(int j=y;j>0;j-=lowbit(j)){
				sum+=bit[i][j];
			}
		}
		return sum;
	}
}tree;
bool f[1002][1002];
signed main(){
	quick
	int n,q;
	cin>>n>>q;
	tree.init(n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) {
			char c;
			cin>>c;
			if(c=='*') f[i][j]=1,tree.add(i,j,1);
			else f[i][j]=0;
		}
	}
	rep(q){
		int r;
		cin>>r;
		if(r==1) {
			int x,y;
			cin>>x>>y;
			if(f[x][y])tree.add(x,y,-1);
			else tree.add(x,y,1);
			f[x][y]=1-f[x][y];
		}
		else{
			int x1,y1;
			int x2,y2;
			cin>>x1>>y1>>x2>>y2;
			x1--,y1--;
			cout<<tree.query(x2,y2)-tree.query(x1,y2)-tree.query(x2,y1)+tree.query(x1,y1)<<"\n";
		}
	}
}