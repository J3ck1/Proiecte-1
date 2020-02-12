#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin ("serii.in");
ofstream fout ("serii.out");
int N, Q;

struct matrice
{
    int n, m;
    int v[5];
}a[10000], b[10000];

int baza2(int &dms) {
    int nr = 0, n, i, x;
    if (dms <= 25)
        n = dms;
    else
        n = 25;
    dms-=n;
    for (i = n - 1; i >= 0; i--) {
        fin >> x;
        nr += x * pow(2, i);
    }
    return nr;
}
int main()
{
    fin >> N;
    int j = 0, dms, val, k = 0;

    for (int i = 0; i < N; i++) {
        j = 0;
        fin >> a[i].n >> a[i].m;
        dms = a[i].n * a[i].m;
        while(dms > 0)
            a[i].v[++j] = baza2(dms);
    }

    fin >> Q;
    for (int i = 0; i < Q; i++) {
        j = 0;
        fin >> b[i].n >> b[i].m;
        dms = b[i].n * b[i].m;
        while(dms > 0)
            b[i].v[++j] = baza2(dms);
    }

    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < N; j++) {
            if (b[i].n == a[j].n && b[i].m == a[j].m) {
                val = 1;
                for (int z = 1; z <= 4; z++) {
                    if (b[i].v[z] != a[j].v[z])
                        val = 0;
                }
                if (val) {
                    b[i].n = b[i].m = 0;
                    k++;
                }
            }
        }
    }
    cout << k;
    return 0;
}
