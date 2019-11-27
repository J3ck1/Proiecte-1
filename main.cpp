#include <iostream>

using namespace std;
int m, c, st[100], date[50][5];

//  1 = 1m;
//  2 = 1c;
//  3 = 2m;
//  4 = 2c;
//  5 = 1c 1m;

void afisare(int k)
{
    for(int i=1; i<=k; i++)
        cout << st[i] << endl;

}

void conv(int k, int v, int x)
{
    if(v == 1) date[k][x+1]+=1;
    if(v == 2) date[k][x+2]+=1;
    if(v == 3) date[k][x+1]+=2;
    if(v == 4) date[k][x+2]+=2;
    if(v == 5) {
            date[k][x+2]+=1;
            date[k][x+1]+=1;
    }
}

bool valid(int k)
{
    if(k%2 == 1)
        conv(k, st[k], 2);
    else
        conv(k, st[k], 0);
    if(date[k][1] < date[k][2] && date[k][1] != 0) return 0;
    if(date[k][3] < date[k][4] && date[k][3] != 0) return 0;
    return 1;
}

void backy()
{
  int k = 1;
  st[k] = 0;
  while (k > 0)
    if (st[k] < 5)
    {
      st[k]++;
      if (valid(k))
        if(date[k][1] == 0)
            afisare(k);
        else st[++k]=0;
    }
    else k--;
}
int main()
{
    cin >> m >> c;
    date[0][1] = m;
    date[0][2] = c;
    backy();
    return 0;
}
