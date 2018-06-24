struct Mat {
	static const int N = ::N;
	int a[N][N], n;
	Mat(){} Mat(int _n, int v) { n = _n; rep(i, 0, n) rep(j, 0, n) a[i][j] = i==j ? v : 0; }
	Mat operator * (const Mat &c) const {
		Mat res(n, 0);
		rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) res.a[i][j] = add(res.a[i][j], mul(a[i][k], c.a[k][j]));
		return res;
	}
	Mat operator ^ (int b) const {
		Mat res(n, 1), a = *this;
		while(b) {
			if(b&1) res = res*a;
			a = a*a;
			b >>= 1;
		}
		return res;
	}
};
