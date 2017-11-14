
#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;
int main(int argc, const char * argv[])
{
    int a[10000] = {0};
    int N=12,K=3,M=5,seed=19,counter=0;
    cout << "pls insert N,K,M,seed" << endl;
    cin >> N >> K >> M >> seed;
    srand(seed);
    int rem = N - K;
    for (int i = 0;i < K;i++)
    {
        a[i] = 1;
    }
    while (rem != 0)
    {
        int K1 = K;
        for (int i = 0;i < K1;i++ )
        {
            int randd = rand() % N;
            if ( a[randd] == 0)
            {
                rem--;
                a[randd] = 1;
                K++;
            }
        }
        K = K1;
        counter++;
    }
    cout << counter;
}
