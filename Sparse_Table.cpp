const int Maxn=5e5+7;
const int K=30;
struct RMQ{
	int Size;
	int Min[Maxn][K+1];
	int Max[Maxn][K+1];
	int sum[Maxn][K+1];
	int log[Maxn];
	void init(int n,const vector<int> &v){
		Size=n;
		for(int i=0;i<Size;i++){
			Max[i][0]=Min[i][0]=sum[i][0]=v[i];
		}
		log[0]=log[1]=0;
		for(int i=2;i<=Size;i++) log[i]=log[i/2]+1;
	}
	void build_Min(){
		for(int j=1;j<=K;j++){
			for(int i=0;i+(1<<j)<=Size;i++){
				Min[i][j]=min(Min[i][j-1],Min[i+(1<<(j-1))][j-1]);
			}
		}	
	}
	void build_Max(){
		for(int j=1;j<=K;j++){
			for(int i=0;i+(1<<j)<=Size;i++){
				Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
			}
		}	
	}
	void build_sum(){
		for(int j=1;j<=K;j++){
			for(int i=0;i+(1<<j)<=Size;i++){
				sum[i][j]=sum[i][j-1]+sum[i+(1<<(j-1))][j-1];
			}
		}	
	}
	int query_sum(int l,int r){
		int Sum=0;
		for(int j=K;j>=0;j--){
			if((1<<j)<=r-l+1){
				Sum+=sum[l][j];
				l+=(1<<j);
			}
		}
		return Sum;
	}
	int query_Min(int l,int r){
		int j=log[r-l+1];
		return min(Min[l][j],Min[r-(1<<j)+1][j]);
	}
	int query_Max(int l,int r){
		int j=log[r-l+1];
		return max(Max[l][j],Max[r-(1<<j)+1][j]);
	}
}st;