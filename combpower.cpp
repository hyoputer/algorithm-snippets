ll fact[200000];

ll power(ll a, ll b)
{
  if (b == 0)
    return 1;
  
  if (b == 1)
    return a;
  else if (b%2 == 0)
  {
    ll temp = power(a, b/2);
    return (temp * temp) % mod;
  }
  else
    return (power(a, b-1) * a) % mod;
}
  
ll inv(ll a) {
  return power(a, mod-2);
}

ll comb(ll a, ll b) {
  return (fact[a] * inv((fact[a-b] * fact[b]) % mod)) % mod;
}