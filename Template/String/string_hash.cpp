const int mod=1e9+7;
ull base[N],ha[N];
char s[N];// s[1..len]
void init() {
	base[0]=1;
	rep(i,1,N) base[i]=base[i-1]*mod;
}
void Hash() {
	int len=strlen(s+1);
	ha[0]=0;
	rep(i,1,len+1) ha[i]=ha[i-1]*mod+s[i];
}
ull getHa(int l,int r) {
	return ha[r]-ha[l-1]*base[r-l+1];
}
