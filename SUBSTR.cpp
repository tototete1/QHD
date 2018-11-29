#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;
char A[10001],B[10001];
long long n,m;
long long T[10001][10001];
int main()
{
    long long i,x,j;
    ifstream fin ("SUBSTR.INP");
    fin>>A;
    fin>>B;
    n=strlen(A);
    m=strlen(B);
    for (i=1;i<=n;i++) T[i][m]=0;
    for (i=1;i<=m;i++) T[n][i]=0;
    T[n][m]=-999;
    for (i=n-1;i>=0;i--)
    {
        for (j=m-1;j>=0;j--)
        {
            if (A[i]==B[j])
            {
                x=max(T[i+1][j],T[i][j+1]);
                T[i][j]=max(x,T[i+1][j+1]+1);
            }
            else T[i][j]=max(T[i][j+1],T[i+1][j]);
        }
    }
    ofstream fout ("SUBSTR.out");
    fout <<T[0][0]<<endl;
    i=0,j=0;
    while (i<n || j<m)
    {
        if (A[i]==B[j])
        {
            fout <<A[i];
            i++;j++;
        }
        else
        {
            if (T[i+1][j]>T[i][j+1]) i++;
            else j++;
        }
    }
    return 0;
}
