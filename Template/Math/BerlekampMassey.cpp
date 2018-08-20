// O(len^2)
namespace BM {
	vi operator - (vi a, vi b) {
		vi c(max(sz(a), sz(b)));
		rep(i, 0, sz(a)) c[i] = a[i];
		rep(i, 0, sz(b)) c[i] = sub(c[i], b[i]);
		return c;
	}
	vi operator << (vi a, int b) {
		vi c(sz(a) + b);
		rep(i, 0, sz(a)) c[i + b] = a[i];
		return c;
	}
	vi operator * (vi a, vi b) {
		vi c(sz(a) + sz(b) - 1);
		rep(i, 0, sz(a)) rep(j, 0, sz(b)) c[i + j] = add(c[i + j], mul(a[i], b[j]));
		return c;
	}
	vi work(int s[], int len) {
		vi A(1, 1), B(1, 1);
		int b = 1;
		for(int i = 0, j = -1; i < len; ++i) {
			int d = 0;
			rep(k, 0, sz(A)) d = add(d, mul(A[k], s[i-k]));
			if(d) {
				vi t = A;
				vi c(1, mul(d, kpow(b, P-2)));
				A = A - ((c * B) << (i - j));
				B = t, b = d, j = i;
			}
		}
		reverse(all(A));
		rep(i, 0, sz(A)) A[i] = P - A[i];
		return vi(A.begin(), A.end()-1);
	}
}
