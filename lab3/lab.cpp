//Karol Jabłoński
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

//===== normalny przyklad =====
double A[3][4] = {{-1,2,1,-1},{1,-3,-2,-1},{3,-1,-1,4}};
double B[3][3] = {{-1,2,1},{1,-3,-2},{3,-1,-1}};
double b[3] = {-1,-1,4};

//===== 0 na przekatnej =====
//double A[3][4] = {{0,2,1,4},{1,-1,0,1},{3,-1,2,6}};
//double B[3][3] = {{0,2,1},{1,-1,0},{3,-1,2}};
//double b[3] = {4,1,6};

//===== zaokraglenie zmieniajace wynik =====
//double A[3][4] = {{2,10e-15,1,10e-15},{1,10e-15,2,1},{2,3,4,7}};
//double B[3][3] = {{2,10e-15,1},{1,10e-15,2},{2,3,4}};
//double b[3] = {10e-15,1,7};

double x[3];
int p[3];
double s[3];
int n = 3;


int main(){
    cout<<"Macierz poczatkowa"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Wektor poczatkowy"<<endl;
    cout<<"b[";
    for(int i=0; i<n; i++){
        cout<<b[i]<<" ";
    }
    cout<<"]"<<endl;
    cout<<endl;
    cout<<"Eliminacja Gaussa"<<endl;
 for(int i=0; i<n; i++){
     double r = A[i][i];
     for(int j=0; j<=n; j++){
         A[i][j] = A[i][j] / r;
        }
         for(int k=i+1; k<n; k++){
             double s = A[k][i];
             for(int l=0; l<=n; l++){
                A[k][l] = A[k][l] - s*A[i][l];
             }
         }
        for (int i = n - 1; i >= 0; i--) {
            double sum = 0;
            for (int j = i + 1; j < n; j++) {
                sum += A[i][j] * x[j];
            }
            x[i] = (A[i][3] - sum) / A[i][i];
    }
     }
    A[1][0] = 0;
    A[2][0] = 0;
    A[2][1] = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }
    cout<<endl;
for (int i=0; i<n; i++) {
    p[i] = i;
    s[i] = 0;
    for (int j=0; j<n; j++) {
        s[i] = max(s[i], fabs(B[i][j]));
    }
}
for (int k=0; k<n-1; k++) {
    int maxRow = k;
    double maxRatio = fabs(B[p[k]][k]) / s[p[k]];
    for (int i=k+1; i<n; i++) {
        double ratio = fabs(B[p[i]][k]) / s[p[i]];
        if (ratio > maxRatio) {
            maxRatio = ratio;
            maxRow = i;
        }
    }
    int temp = p[k];
    p[k] = p[maxRow];
    p[maxRow] = temp;
    for (int i=k+1; i<n; i++) {
        double z = B[p[i]][k] / B[p[k]][k];
        B[p[i]][k] = z;
        b[p[i]] -= z * b[p[k]];
        for (int j=k+1; j<n; j++) {
            B[p[i]][j] -= z * B[p[k]][j];
        }
    }
}
    cout << "L (Macierz dolnotrojkatna):" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > j)
                    cout << B[p[i]][j] << " ";
                else if (i == j)
                    cout << "1 ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    cout<<endl;
    cout << "U (Macierz gornotrojkatna):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j)
                cout << B[p[i]][j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    cout<<endl;
    cout << "Skalowany wybor wierszy glownych" << endl;
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += B[p[i]][j] * x[j];
        }
        x[i] = (b[p[i]] - sum) / B[p[i]][i];
    }
        for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

return 0;
}
