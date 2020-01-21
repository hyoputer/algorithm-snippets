ll gcd(ll a, ll b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}