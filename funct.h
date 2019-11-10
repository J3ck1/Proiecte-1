extern int n, m, cont;
extern int st[50];
extern float lat2;
extern struct punct
{
    float x, y;
}v[50];

extern struct valori
{
 int a, b, c, d;
 int nr;
}v2[50];

void citire();
float dist2(int a, int b);
bool e_patrat(int a, int b, int c, int d);
float arie(int a, int b, int c);
bool valid(int k);
void indentificator_de_valoare();
void backy();
