#include<bits/stdc++.h>
//#define Woody
#define int long long 
#define lowbit(x) (x&-x)
#define rep(n) for(int i=0;i<n;i++)
#define mp make_pair
#define eb emplace_back
#define F first
#define S second
#define SZ(a) (int)(a.size())
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
struct odt{
	struct Node{
		int l,r;
		mutable int v;
		Node (int l,int r,int v) : l(l),r(r),v(v){}
		bool operator < (const Node &o) const{
			return l<o.l;
		}
	};
	set<Node> tree;
	auto split(int pos){
		auto it=tree.lower_bound(Node(pos,0,0));
		if(it!=tree.end()&&it->l==pos) return it;
		--it;
		int l=it->l;
		int r=it->r;
		int v=it->v;
		tree.erase(it);
		tree.insert(Node(l,pos-1,v));
		return tree.insert(Node(pos,r,v)).F;
	}
	void assign(int l,int r,int v){
		auto ir=split(r);
		auto il=split(l);
		tree.erase(il,ir);
		tree.insert(Node(l,r,v));
	}
};
signed main(){
	quick
}