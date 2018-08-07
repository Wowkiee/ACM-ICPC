// 模数不是素数， 需要做除法
(a / b) % P = a % (P * b) / b 

// 矩阵乘法 
没有交换律， 有结合律。
左乘向量取行， 右乘取列。 

// desc: inv O(n)
// !!!!: P%i != 0 
inv[1] = 1;
rep(i, 2, N) inv[i] = mul(inv[P%i], P - P/i);

// p O(n)
vi p;
bool vis[N];
for(int i = 2; i < N; ++i) {
    if(!vis[i]) p.pb(i);
    for(int j = 0; j < sz(p) && i * p[j] < N; ++j) {
        vis[i * p[j]] = 1;
        if(i % p[j] == 0) break;
    }
}

// phi O(n)
int cntp, p[N], phi[N], vis[N];
phi[1]=1;
rep(i,2,N) {
    if(!vis[i]) p[cntp++]=i, phi[i]=i-1;
    for(int j=0;j<cntp&&p[j]*i<N;++j) {
        vis[p[j]*i]=1;
        if(i%p[j]==0) {
            phi[p[j]*i]=phi[i]*p[j]%P;
            break;
        } else {
            phi[p[j]*i]=phi[i]*(p[j]-1)%P;
        }
    }
}
