#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main(){
    double k=1.62;
    double cp=820;
    double p=2.71;
    double v=k/(cp*p);
    int pts=50;
    double Tini[pts][pts];
    for(int i =0; i<pts; i++){
        for(int j =0; j<pts; j++){
        Tini[i][j]=10;
        if(sqrt((i-25)^2+(j-25)^2)<=5){
            Tini[i][j]=100;
        }
    }
    }
    for(int i =0; i<pts; i++){
        for(int j =0; j<pts; j++){
            cout<<T[i][j]<<endl;
        }}
}
