//InverseElement
// mod is a prime
int v[N];
rep(i,1,N) v[i] = Pow(i , mod - 2);
// O(nlgn)
v[1] = Pow(1,mod-2);
rep(i,2,N){
    int t = mod/i , k = (ll)v[mod-t*i] * t % mod;
    v[i] = (ll)i * k % mod * k % mod;
}
// O(n)(任意数逆元)
int pri[N] , _p , vis[N];
v[1] = Pow(1,mod-2);
rep(i,2,N) v[i] = 1;
rep(i,2,N){
    if(!vis[i]) pri[_p++] = i , v[i] = Pow(i,mod-2);
    for(int j=0,o=0;j<_p&&(o=pri[j]*i)<N;++j){
        vis[o] = true;
        v[o] = (ll)v[pri[j]] * v[i] % mod;
        if(pri[j]%i == 0) break;
    }
}
// O(n)

// Mobius
int mu[N];
// all
mu[1] = 1;
rep(i,1,N) for(int j=i+i;j<N;j+=i) mu[j] -= mu[i];
// O(nlgn)
int pri[N] , _p , vis[N];
mu[1] = 1;
rep(i,2,N){
    if(!vis[i]) pri[_p++] = i , mu[i] = -1;
    for(int j=0,o=0;j<_p&&(o=pri[j]*i)<N;++j){
        vis[o] = true;
        if(i%pri[j]) mu[o] = -mu[i];
        else{ mu[o] = 0; break; }
    }
}
// O(n)

// Phi
int pri[N] , _p , vis[N] , phi[N];
rep(i,2,N){
    if(!vis[i]) pri[_p++] = i , phi[i] = i-1;
    for(int j=0,o;j<_p&&(o=pri[j]*i)<N;++j){
        vis[o] = true;
        if(i%pri[j]) phi[o] = (pri[j] - 1) * phi[i];
        else{
            phi[o] = pri[j] * phi[i];
            break;
        }
    }
}
// O(n)
