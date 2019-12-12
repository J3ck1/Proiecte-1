#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

char date[50][100];
char invalid[] = {".,;:!?"}, *p;
int n = 0, k = 0;

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

int main()
{
    ifstream fin ("licurici.txt");
    while (fin) {
       fin.getline(date[++n], 100);
    }

    return 0;
}
