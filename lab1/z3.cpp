//Karol Jabłoński
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

long double calc(long double x){
    if (x>0.1 || x<-0.1) {
        return x - sin(x);
    }else{
        return x*x*x/6.0*(1.0-x*x/20.0*(1.0-x*x/42.0));
    }
}

int main(){
    cout<<setprecision(18)<<fixed;

    long double test_vals[] = {1.0L, 0.1L, 0.01L, 0.001L, 0.0001L, 1e-7L};

    for(long double x : test_vals){
        long double val = calc(x);
        cout<<"x = "<<x<<" y = "<<val<<endl;
    }

    return 0;
}