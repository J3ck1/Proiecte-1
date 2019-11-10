#include <iostream>
#include "funct.h"
using namespace std;

int st[50], nr_sol;

void backy()
{
  int k = 1;
  st[k] = 0;
  while (k>0)
    if (st[k]<n)
    {
      st[k]++;
      if (valid(k))
        if(k == n) {
                k = 4;
                indentificator_de_valoare();
        }
        else st[++k]=0;
    }
    else k--;
}

int main()
{
    citire();
    backy();
    for (int i=1; i<=cont; i++)
    {
        if (v2[i].nr == m) {
        cout << "P1: " << v[v2[i].a].x << " " << v[v2[i].a].y << endl;
        cout << "P2: " << v[v2[i].b].x << " " << v[v2[i].b].y << endl;
        cout << "P3: " << v[v2[i].c].x << " " << v[v2[i].c].y << endl;
        cout << "P4: " << v[v2[i].d].x << " " << v[v2[i].d].y << endl;
        }
        cout << endl;
    }
    cout << v2[cont].nr;
    return 0;
}
