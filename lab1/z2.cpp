//Karol Jabłoński
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x){
    return sqrt(x * x + 1) - 1;
}

double g(double x){
    return (x * x ) / (sqrt(x * x + 1) + 1);
}

int main(){
    cout<<setprecision(15)<<fixed;
    for(int i=0; i <= 10; ++i){
        double x = pow(8, -i);
        double f_res = f(x);
        double g_res = g(x);

        cout<<"x=8^-"<<i<<endl;
        cout<<"f(x) = "<<f_res<<endl;
        cout<<"g(x) = "<<g_res<<endl;
    }
    cout<<"Wynik g(x) jest bardziej wiarygodny i stabilny numerycznie, szczegolnie dla malych wartosci x, poniewaz unika problemow zwiazanych z odejmowaniem bardzo bliskich sobie liczb."<<endl;
    return 0;
}