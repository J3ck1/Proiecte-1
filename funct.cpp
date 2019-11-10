#include <iostream>
#include <fstream>
#include "funct.h"
using namespace std;

punct v[50];
valori v2[50];
int n, m=0, cont=0;
float lat2;

void citire()
{
    ifstream f ("patrat.in");
    f >> n;
    for (int i=1; i<=n; i++) {
            f >> v[i].x >> v[i].y;
    }
}

float dist2(int a, int b)
{
    return (v[a].x - v[b].x) * (v[a].x - v[b].x) + (v[a].y - v[b].y) * (v[a].y - v[b].y);
}

bool e_patrat(int a, int b, int c, int d)
{
    int vec[6];
    vec[0] = dist2(a, b);
    vec[1] = dist2(a, c);
    vec[2] = dist2(a, d);
    vec[3] = dist2(b, c);
    vec[4] = dist2(b, d);
    vec[5] = dist2(c, d);
    for (int i=0; i<5; i++) {
    for (int j=i+1; j<=5; j++)
        if (vec[i] > vec[j]) swap(vec[i], vec[j]);
    }
    lat2 = vec[0];

    if (vec[0]==vec[1] && vec[1]==vec[2] && vec[2]==vec[3] && vec[4]==vec[5] && vec[0]*2==vec[5]) return 1;
    return 0;
}

float arie(int a, int b, int c)
{
    float det = v[a].x * (v[b].y - v[c].y) + v[b].x * (v[c].y - v[a].y) + v[c].x * (v[a].y - v[b].y);
    if (det < 0) return -det/2;
    return det/2;
}

void indentificator_de_valoare()
{
    int val=0;
    int aux[5] = {0, st[1], st[2], st[3], st[4]};

    if (dist2(aux[1], aux[2]) != lat2) swap(aux[2], aux[3]);
    if (dist2(aux[1], aux[3]) != lat2) swap(aux[3], aux[4]);
    for (int i=5; i<=n; i++) {
      if (arie(aux[1], aux[2], st[i]) + arie(aux[1], aux[3], st[i])
          + arie(aux[4], aux[3], st[i]) + arie(aux[4], aux[2], st[i]) == lat2) val++;
    }

    if (val >= m) {
        m = val;
        v2[++cont].a = st[1];
        v2[cont].b = st[2];
        v2[cont].c = st[3];
        v2[cont].d = st[4];
        v2[cont].nr = m;
    }
}

bool valid(int k)
{
    for (int i=1; i<k; i++)
        if (st[k] == st[i]) return 0;

    if (k <=4 and k > 1) {
        if (st[k]<st[k-1]) return 0;
    }
    if (k == 4) if (!e_patrat(st[1], st[2], st[3], st[4])) return 0;

    return 1;
}







