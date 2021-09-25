vector<int> lpf(n,1);
vector<int> prime;
for(int i=2;i<=n;i++){
	if(lpf[i]==1) {
		lpf[i]=i;
		prime.eb(i);
	}
	for(int j:prime){
		if(i*j>n) break;
		lpf[i*j]=j;
		if(j==lpf[i]) break;
	}
}
