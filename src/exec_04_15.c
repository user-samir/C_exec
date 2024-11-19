#include <stdio.h>

long long int ipow(long long int a, unsigned int n, unsigned int * depth);

int main()
{
    long long int a, res;
    unsigned int n, s = 100;
    unsigned int *depth = &s;
    scanf("%lld%u", &a, &n);

    res = ipow(a, n, depth);
    printf("%lld %u\n", res, *depth);
    return 0;
}

long long int ipow(long long int a, unsigned int n, unsigned int * depth)
{
    static unsigned int cnt = 0;
    cnt++;
    *depth = cnt;

    if (!n)
        return 1;
    if (n == 1)
        return a;

    long long int result;

    if (n % 2)
        result =  a * ipow(a, n - 1, depth);
    else
    {
        result = ipow(a, n /2, depth);
        result *= result;
    }

    return result;
}