vector<int> factorization[10000];
int reslcm[1000000];
vector<int> primes;

void prime_factors(int idx, int n)  
{  
    // Print the number of 2s that divide n  
  int temp = 0;
  while (n % 2 == 0)  
  {  
    temp++;
    n = n/2; 
    factorization[idx].push_back(2);
    if(primes.back() != 2)
      primes.push_back(2);
  }
  reslcm[2] = max(reslcm[2], temp);

  // n must be odd at this point. So we can skip  
  // one element (Note i = i +2)  
  for (int i = 3; i <= sqrt(n); i = i + 2)  
  {  
      // While i divides n, print i and divide n
    temp = 0;
    while (n % i == 0)  
    {  
      temp++;
      n = n/i;  
      factorization[idx].push_back(i);
      if(find(primes.begin(), primes.end(), i) == primes.end())
        primes.push_back(i);
    }
    reslcm[i] = max(temp, reslcm[i]);
  }  

  // This condition is to handle the case when n  
  // is a prime number greater than 2  
  if (n > 2)  
  {
    reslcm[n] = max(1, reslcm[n]);
    factorization[idx].push_back(n);
    if(find(primes.begin(), primes.end(), n) == primes.end())
      primes.push_back(n);
  }
}

ll phi(ll x)
{
  primes.clear();
  prime_factors(x);
  
  //printf("aaaa\n");
  
  ll res = x;
  
  int size = primes.size();
  
  for(int i = 0 ; i < size; i++)
    res = (res - res/primes[i]);
  
  return res;
}