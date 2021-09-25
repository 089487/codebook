struct segment{
	private:
		int size;
		vector<int> lazy1;//add
		vector<int> lazy2;//assign
		vector<int> sum;
		void push(int x,int lx,int rx){
			if(lx==rx-1||(!lazy1[x]&&lazy2[x]==-1)) return ;
			if(lazy2[x]!=-1){
				lazy1[2*x+1]=lazy1[x];
				lazy1[2*x+2]=lazy1[x];
				lazy2[2*x+1]=lazy2[2*x+2]=lazy2[x];
				int middle=(lx+rx)>>1;
				sum[2*x+1]=(middle-lx)*(lazy2[x]+lazy1[x]);
				sum[2*x+2]=(rx-middle)*(lazy2[x]+lazy1[x]);
				lazy2[x]=-1;
				lazy1[x]=0;
				return ;
			}
			lazy1[2*x+1]+=lazy1[x];
			lazy1[2*x+2]+=lazy1[x];
			int middle=(lx+rx)>>1;
			sum[2*x+1]+=lazy1[x]*(middle-lx);
			sum[2*x+2]+=lazy1[x]*(rx-middle);
			lazy1[x]=0;
			return ;
		}
		void add(int l,int r,int val,int x,int lx,int rx){
			if(l<=lx&&rx<=r){
				lazy1[x]+=val;
				sum[x]+=val*(rx-lx);
				return ;
			}
			if(l>=rx||lx>=r) return ;
			push(x,lx,rx);
			int middle=(lx+rx)>>1;
			add(l,r,val,2*x+1,lx,middle);
			add(l,r,val,2*x+2,middle,rx);
			sum[x]=sum[2*x+1]+sum[2*x+2];
		}
		void assign(int l,int r,int val,int x,int lx,int rx){
			if(l<=lx&&rx<=r){
				lazy1[x]=0;
				lazy2[x]=val;
				sum[x]=val*(rx-lx);
				return ;
			}
			if(l>=rx||lx>=r) return ;
			push(x,lx,rx);
			int middle=(lx+rx)>>1;
			assign(l,r,val,2*x+1,lx,middle);
			assign(l,r,val,2*x+2,middle,rx);
			sum[x]=sum[2*x+1]+sum[2*x+2];
		}
		int query(int l,int r,int x,int lx,int rx){
			if(l<=lx&&rx<=r) return sum[x];
			if(l>=rx||lx>=r) return 0;
			push(x,lx,rx);
			int middle=(lx+rx)>>1;
			int s1=query(l,r,2*x+1,lx,middle);
			int s2=query(l,r,2*x+2,middle,rx);
			return s1+s2;
		}
	public:
		void init(int n){
			size=1;
			while(size<n) size*=2;
			sum.assign(size*2,0);
			lazy2.assign(size*2,-1);
			lazy1.assign(size*2,0);
		}
		void add(int l,int r,int val){
			add(l,r,val,0,0,size);
		}
		void assign(int l,int r,int val){
			assign(l,r,val,0,0,size);
		}
		int query(int l,int r){
			return query(l,r,0,0,size);
		}
}st;
signed main(){
	quick
	
	int n,m;
	cin>>n>>m;
	st.init(n);
	while(m--){
		int k;
		cin>>k;
		if(k==1){
			int l,r,v;
			cin>>l>>r>>v;
			st.assign(l,r,v);
		}
		else if(k==2){
			int l,r,v;
			cin>>l>>r>>v;
			st.add(l,r,v);
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<st.query(l,r)<<"\n";
		}
	}
}

