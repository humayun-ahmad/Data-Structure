//graph problem 1 & 2

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cmath>
#define pi acos(0.0)*2
#define ll long long

using namespace std;
int b[5][5];

int main()
{
    int i=0, j, k, l, m, c=0;
    cin >> m;
    int matrix[m][m][m];
    for(j=0; j<m; j++){
        for(k=0; k<m; k++){
            cin >> matrix[i][j][k];
        }
    }
    cout << endl;
    for(l=1; l<m; l++){
        for(i=0; i<m; i++){
            for(j=0; j<m; j++){
                matrix[l][i][j]=0;
                for(k=0; k<m; k++){
                    matrix[l][i][j]+=matrix[l-1][i][k]*matrix[0][k][j];
                }
            }
        }
    }

    for(i=0; i<m; i++){
        cout << "M" << i+1 << "=" << endl;
        for(j=0; j<m; j++){
            for(k=0; k<m; k++){
                 cout << matrix[i][j][k] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }

    for(i=0; i<m; i++){
        for(j=0; j<m; j++){
            for(k=0; k<m; k++){
                b[j][k]+=matrix[i][j][k];
            }
        }
    }
    cout << "B=" << endl;
    for(i=0; i<m; i++){
        for(j=0; j<m; j++){

            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
    for(i=0; i<m; i++){
        for(j=0; j<m; j++){
            if(b[i][j]>0){
                b[i][j]=1;
                c++;
            }
        }
    }
    cout << endl;
    cout << "P=" << endl;
    for(i=0; i<m; i++){
        for(j=0; j<m; j++){

            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    if(c==m*m)
        cout << "The graph is strongly connected" << endl;
    else
        cout << "The graph is not strongly connected" << endl;
    cout << endl;

    for(int i=0; i<m; i++){
        cout << "Adjacent of " << 'v' << i+1 << " is ";
        for(int j=0; j<m; j++){
            if(matrix[0][i][j]>0)
                cout << "v" << j+1 << ", ";
        }
        cout << endl;
    }
    cout << endl;

    for(i=1; i<m; i++){
        for(j=0; j<m; j++){
            for(k=0; k<m; k++){
                cout << "There are " << matrix[i][j][k] << " path(s) of lenth " << i+1 << " from v" << j+1 << " to v" << k+1 << endl;
            }
        }
        cout << endl;
        cout << endl;
    }

    return 0;
}


