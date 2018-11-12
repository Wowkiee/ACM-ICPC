bool cmp(const pii &a, const pii &b) {
	int o = a > pii(0, 0), t = b > pii(0, 0);
	if(o != t) return o < t;
	return cross(a, b) > 0;
}
