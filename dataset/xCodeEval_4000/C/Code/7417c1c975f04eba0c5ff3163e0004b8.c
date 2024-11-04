

#include <stdio.h>
#include <stdlib.h>

void sort_rec(int A1[], int Tmp[], unsigned n) {
    unsigned i, j, h, k = n / 2;
    int *A2 = A1 + k;
    if (n < 2)
        return;
    sort_rec(A1, Tmp, k); 

    sort_rec(A2, Tmp + k, n - k); 

    

    for (i = j = h = 0; i < n; i++) {
        if (h >= n - k || (j < k && A1[j] <= A2[h]))
            Tmp[i] = A1[j++];
        else
            Tmp[i] = A2[h++];
    }
    

    for (i = 0; i < n; i++)
        A1[i] = Tmp[i];
}

void sort(int A[], unsigned n) {
    int *Tmp = (int *) malloc(n * sizeof(int));
    sort_rec(A, Tmp, n);
    free(Tmp);
}

int main (void)
{
    int i, m, n, k, x = 0, *a;
    scanf("%d %d", &n, &k);
    m = n;
    a = (int *) malloc (n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", a+i);
    sort(a, n);
    for (i = n-1; i > 0; i--)
    {
        if(i[a]- a[i-1] && (i[a]- a[i-1] <= k))
            x = a[i]-a[i-1];
        if (x && (i[a] - a[i-1] <= k))
            m--;
        if (i[a]-a[i-1] > k)
            x = 0;
    }
    printf("%d\n", m);
    return 0;
}
