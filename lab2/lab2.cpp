//Karol Jabłoński
#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

double fx0 = 2.0;
double fx1 = 1.9;
double gx0 = 0.0;
double gx1 = 0.1;
double hx0 = 0.5;
double hx1 = 0.52;
double ix0 = -5.0;
double ix1 = -4.95;

double f(double x)
{
    return (x * x) - 3;
}

double g(double x)
{
    return (x * x * x) + 3 * (x * x) - x - 3;
}

double h(double x)
{
    return pow(3, x) - 2;
}

double i(double x)
{
    return (x*x + 5*x + 4)/(x*x + 1);
}

double fp(double x)
{
    return 2 * x;
}

double gp(double x)
{
    return 3 * x * x + 6 * x - 1;
}

double hp(double x)
{
    return pow(3, x) * log(3);
}

double ip(double x)
{
    return (-5*x*x - 6*x + 5)/(x*x*x*x + 2*x*x + 1);
}

double newton(int m, int n)
{
    switch (m)
    {
    case 0:
        if (n == 0) return fx0;
        return newton(m, n - 1) - f(newton(m, n - 1)) / fp(newton(m, n - 1));
    case 1:
        if (n == 0) return gx0;
        return newton(m, n - 1) - g(newton(m, n - 1)) / gp(newton(m, n - 1));
    case 2:
        if (n == 0) return hx0;
        return newton(m, n - 1) - h(newton(m, n - 1)) / hp(newton(m, n - 1));
    case 3:
        if (n == 0) return ix0;
        return newton(m, n - 1) - i(newton(m, n - 1)) / ip(newton(m, n - 1));
    default:
        return 0.0;
    }

}

double sieczne(int m,int n){
    switch (m)
    {
    case 0:
    {
        if(n == 0) return fx0;
        if(n == 1) return fx1;
        return sieczne(m, n-1) - (f(sieczne(m, n-1)) * (sieczne(m, n-1) - sieczne(m, n-2)) / (f(sieczne(m, n-1)) - f(sieczne(m, n-2))));
    }
    case 1:
        if(n == 0) return gx0;
        if(n == 1) return gx1;
        return sieczne(m, n-1) - (g(sieczne(m, n-1)) * (sieczne(m, n-1) - sieczne(m, n-2)) / (g(sieczne(m, n-1)) - g(sieczne(m, n-2))));
    case 2:
        if(n == 0) return hx0;
        if(n == 1) return hx1;
        return sieczne(m, n-1) - (h(sieczne(m, n-1)) * (sieczne(m, n-1) - sieczne(m, n-2)) / (h(sieczne(m, n-1)) - h(sieczne(m, n-2))));
    case 3:
        if(n == 0) return ix0;
        if(n == 1) return ix1;
        return sieczne(m, n-1) - (i(sieczne(m, n-1)) * (sieczne(m, n-1) - sieczne(m, n-2)) / (i(sieczne(m, n-1)) - i(sieczne(m, n-2))));
    default:
        return 0.0;
    }
}

void bisekcja(int m, int n, double a, double b, double delta, double epsilon){
    switch (m)
    {
    case 0:
    {
        double fa = f(a);
        double fb = f(b);
        if(fa * fb > 0){
            cout<<"Niespelnione zalozenia bisekcji"<<endl;
            return;
        }
        double dl = b - a;
        for(int j=0; j<n; j++){
            dl = dl / 2.0;
            double x0 = a + dl;
            double fx0 = f(x0);
            cout<<x0<<endl;
            if(fabs(dl) < delta || fabs(fx0) < epsilon){
                return;
            }
            if(fx0 * fa < 0){
                b = x0;
                fb = fx0;
            }else{
                a = x0;
                fa = fx0;
            }
        }
    }
    case 1:
    {
        double ga = g(a);
        double gb = g(b);
        if(ga * gb > 0){
            cout<<"Niespelnione zalozenia bisekcji"<<endl;
            return;
        }
        double dl = b - a;
        for(int j=0; j<n; j++){
            dl = dl / 2.0;
            double x0 = a + dl;
            double gx0 = g(x0);
            cout<<x0<<endl;
            if(fabs(dl) < delta || fabs(gx0) < epsilon){
                return;
            }
            if(gx0 * ga < 0){
                b = x0;
                gb = gx0;
            }else{
                a = x0;
                ga = gx0;
            }
        }
    }
    case 2:
    {
        double ha = h(a);
        double hb = h(b);
        if(ha * hb > 0){
            cout<<"Niespelnione zalozenia bisekcji"<<endl;
            return;
        }
        double dl = b - a;
        for(int j=0; j<n; j++){
            dl = dl / 2.0;
            double x0 = a + dl;
            double hx0 = h(x0);
            cout<<x0<<endl;
            if(fabs(dl) < delta || fabs(hx0) < epsilon){
                return;
            }
            if(hx0 * ha < 0){
                b = x0;
                hb = hx0;
            }else{
                a = x0;
                ha = hx0;
            }
        }
    }
    case 3:
    {
        double ia = i(a);
        double ib = i(b);
        if(ia * ib > 0){
            cout<<"Niespelnione zalozenia bisekcji"<<endl;
            return;
        }
        double dl = b - a;
        for(int j=0; j<n; j++){
            dl = dl / 2.0;
            double x0 = a + dl;
            double ix0 = i(x0);
            cout<<x0<<endl;
            if(fabs(dl) < delta || fabs(ix0) < epsilon){
                return;
            }
            if(ix0 * ia < 0){
                b = x0;
                ib = ix0;
            }else{
                a = x0;
                ia = ix0;
            }
        }
    }
    default:
        return;
    }
}

int main()
{
    double v = 8962482.0;
    cout<<setprecision(15);
    for (int i = 0; i < 4; i++)
    {
        cout<<"************************************"<<endl;
        cout<<"           Funkcja "<<char(102+i)<<endl;
        cout<<"************************************"<<endl;
        cout << "============================"<<endl;
        cout << "NEWTON" << endl;
        for(int j=0; j<10; j++){
            if(v == newton(i,j)) break;
            v = newton(i,j);
            cout << newton(i,j) << endl;
        }
        cout << "============================"<<endl;
        cout << "SIECZNE"<<endl;
        for(int k=0; k<9; k++){
            if(v == sieczne(i,k)) break;
            v = sieczne(i,k);
            cout << sieczne(i,k)<<endl;
        }
        cout << "============================"<<endl;
        cout << "BISEKCJA"<<endl;
        switch (i)
        {
        case 0:
            bisekcja(i, 50, 0, 2, 0.0001, 0.0001);
            break;
        case 1:
            bisekcja(i, 50, 0, 2.5, 0.0001, 0.0001);
            break;
        case 2:
            bisekcja(i, 50, 0.5, 1, 0.0001, 0.0001);
            break;
        case 3:
            bisekcja(i, 50, -5, -2, 0.0001, 0.0001);
            break;
        default:
            break;
        }
        cout << "============================"<<endl;

    }
}
