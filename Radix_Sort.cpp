#include<bits/stdc++.h>
using namespace std;

ifstream fin("radixsort.in");
ofstream fout("radixsort.out");

const int NMAX = 1e7;
const int B = 10;
long long v[NMAX + 5];
long long w[NMAX + 5];


int c[B + 5], d[B + 5];
void count_sort(long long p, long long n)
{
    memset(c, 0, sizeof(c));
    for(int i = 0; i < n; ++i)
        c[v[i] / p % B]++;

    d[0] = 0;

    for(int i = 1; i < B; ++i)
        d[i] = d[i - 1] + c[i - 1];
    
    
    for(int i = 0; i < n; ++i)
    {   
        w[d[v[i] / p % B]] = v[i];
        d[v[i] / p % B]++;
    }

    for(int i = 0; i < n; ++i)
        v[i] = w[i];
}

void radix_sort(long long n)
{
    long long maxim = 0;
    for(int i = 0; i < n; ++i)
        maxim = max(maxim , v[i]);
    
    for(long long i = 1; i <= maxim; i = i * B)
        count_sort(i, n);

}

int main()
{
    long long n, x;
    fin >> n;
    for(int i = 0; i < n; ++i)
        fin >> v[i];

    radix_sort(n);

    for(int i = 0; i < n; ++i)
        fout << v[i] << " ";

    fout << "\n";
}