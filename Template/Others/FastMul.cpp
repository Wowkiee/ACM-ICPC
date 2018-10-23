inline ll mul(ll a,ll b){ 
	return (a * b - (ll)((long double)a * b / P + 0.5) * P + P) % P;
}
