
vector<int> primes;

int sieve[4000001];

void get_primes(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i] == 0)
        {
            sieve[i] = 1;
            primes.push_back(i);
            for (int j = i; j * i <= n; j++)
            {
                sieve[j * i] = 1;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (sieve[i] == 0)
            primes.push_back(i);
    }
}