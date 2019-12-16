#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <ctime>

using namespace std;

char date[50][100], date2[50][20][20];
char invalid[] = {".,;:!?"}, *p;
int n = 0, k = 0, lun[50], m = 0;

struct biblioteca
{
    char cuvant[20];
    char dmt[20];
    char sin[20];
}cuv[50];

void funct1()
{
    for (int i = 1; i <= n; i++) {
        date[i][0] = toupper(date[i][0]);
        for (int j = 1; j < strlen(date[i]); j++)
            date[i][j] = tolower(date[i][j]);
        }
}

void funct2()
{
for (int i = 0; i < strlen(invalid);  i++) {
        for (int j = 1; j <= n; j++) {
            while (strchr(date[j], invalid[i]) != NULL) {
                p = strchr(date[j], invalid[i]);
                strcpy(date[j] + (p-date[j]), p + 1);
            }
        }
}
for (int i = 1; i <= n; i++)
{
    p = date[i];
    while(p = strchr(date[i] + (p - date[i]) + 1, ' ')) {
        while (p[k] == ' ') k++;
        strcpy(date[i] + (p - date[i]), p + k - 1);
        k = 0;
    }
}
}

void funct3(int prb)
{
    int nr;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < strlen(date[i]); j++) {
            nr = (rand() % 100) + 1;
            if (nr <= prb)
                date[i][j] = toupper(date[i][j]);
            else
                date[i][j] = tolower(date[i][j]);
        }
    }
}

void funct4()
{
    int j, z;
    for (int i = 1; i <= n; i++) {
        j = 0;
        if (i % 5 != 0) {
            p = strtok(date[i], " ");
            strcpy(date2[i][++j], p);
            while (p = strtok(NULL, " "))
                strcpy(date2[i][++j], p);
        }
        lun[i] = j;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= lun[i]; j++)
            for (int z = 1; z <= m; z++)
                if (strcmp(date2[i][j], cuv[z].cuvant) == 0)
                    strcpy(date2[i][j], cuv[z].dmt);
}

int main()
{
    ifstream fin ("licurici.txt");
    while (fin) {
       fin.getline(date[++n], 100);
    }
    ifstream lib ("biblioteca.txt");
    while(lib) {
        lib >> cuv[++m].cuvant >> cuv[m].dmt;
        lib >> cuv[m].sin;
    }

    
    /*for (int i =1; i<=n; i++)
    {
        for (int j=1; j<=lun[i]; j++) cout << date2[i][j] << " ";
        cout << endl;
    }*/

    return 0;
}
