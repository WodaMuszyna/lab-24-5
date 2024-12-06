//Karol Jabłoński
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

void epsilon_float(){
    float epsilon = 1.0f;
    int k=0;
    while((1.0f + epsilon) != 1.0f){
        epsilon /= 2.0f;
        k++;
    }
    cout<<"Epsilon (float): "<<epsilon*2.0f<<endl;
    cout<<"k: "<<k-1<<endl;
}

void epsilon_double(){
    double epsilon = 1.0;
    int k=0;
    while((1.0 + epsilon) != 1.0){
        epsilon /= 2.0;
        k++;
    }
    cout<<"Epsilon (double): "<<epsilon*2.0<<endl;
    cout<<"k: "<<k-1<<endl;
}

void epsilon_long(){
    long double epsilon = 1.0L;
    int k=0;
    while((1.0L + epsilon) != 1.0L){
        epsilon /= 2.0L;
        k++;
    }
    cout<<"Epsilon (long double): "<<epsilon*2.0L<<endl;
    cout<<"k: "<<k-1<<endl;
}

int main(){
    cout.precision(numeric_limits<long double>::digits10 + 1);
    epsilon_float();
    epsilon_double();
    epsilon_long();
    return 0;
}
