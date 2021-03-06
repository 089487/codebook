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