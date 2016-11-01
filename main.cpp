#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

void CountSort(int *A, int *B, int *Order, int N, int K)
{
    int *C = new int[K+1];
    memset(C, 0, sizeof(int)*(K+1));

    int i;
    for(i = 0; i <=N; i++){
        C[A[i]]++;
    }

    for(i = 2; i <= K; i++){
        C[i] += C[i-1];
        printf("%d ",C[i]);
    }
    printf("\n");

    for(i = N; i >= 1; i--){
        B[C[A[i]]] = A[i];
        Order[C[A[i]]] = i;
        C[A[i]]--;
    }
}

void BucketSort()
{

}

void RadixSort()
{

}

int main() {
    int N=15,K=10,i;
    int *A = new int[N+1];
    int *B = new int[N+1];
    int *Order = new int[N+1];

    for(i = 1; i <=N; i++){
        A[i] = rand() % K + 1;
    }

    printf("Before CS:\n");
    for(i = 1; i <= N; i++){
        printf("%d ", A[i]);
    }

    CountSort(A,B,Order,N,K);

    printf("\nAfter CS:\n");
    for(i = 1; i <= N; i++){
        printf("%d ", B[i]);
    }

    printf("\nOrder:\n");
    for(i = 1; i <= N ;i++){
        printf("%d ", Order[i]);
    }

    return 0;
}