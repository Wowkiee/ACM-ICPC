// 枚举子集 
for(int i=x;i;i=(i-1)&x) {  
    // 
}
// 统计子集的答案 
rep(i,0,n) {
    rep(j,0,(1<<n)) if(j>>i&1) {
        upd(s[j], s[j^(1<<i)]);
    }
}
// 统计超集的答案 
rep(i,0,n) {
    for(int j=(1<<n)-1;~j;--j) if(!(j>>i&1)) {
        upd(s[j], s[j|(1<<i)]);
    }
}
