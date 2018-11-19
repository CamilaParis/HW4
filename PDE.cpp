#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main(){
    double k=1.62;
    double cp=820;
    double p=2.71;
    double delta_x = 0.1;
    double delta_t = 0.05;
    double t=100.;
    double v=k/(cp*p);
    double r = v*delta_t / (delta_x*delta_x);
    int pts=50;
    double Tini[pts][pts];
    double Tinir[pts][pts];
    for(int i =0; i<pts; i++){
        for(int j =0; j<pts; j++){
        Tini[i][j]=10;
        if(sqrt((i-25)^2+(j-25)^2)<=5){
            Tini[i][j]=100;
        }
    }
    }
    //for(int i =0; i<pts; i++){
    //   for(int j =0; j<pts; j++){
    //        cout<<Tini[i][j]<<endl;
     //   }}
    
    double Tfut[pts][pts];
    for (int i=1; i<pts-1; i++){
        for (int j=1; j<pts-1;j++){
            Tfut[i][j] = Tini[i][j]+ (r) * (Tini[i+1][j]+Tini[i-1][j]+Tini[i][j+1]+Tini[i][j-1]-4*Tini[i][j]);
            if(sqrt((i-25)^2+(j-25)^2)<=5){
                Tfut[i][j]=100;
            }
        }}
    double Tfut2[pts][pts];
    for (int i=0; i<pts;i++){
        for(int j=0;j<pts;j++){
        Tinir[i][j] = Tini[i][j];
        }}
    for(int dt=0; dt<t;dt++){
        for (int i=1; i<pts-1; i++){
            for(int j=1; j<pts-1;j++){
                Tfut2[i][j]= (2.0*(1.0-r))*Tfut[i][j] - Tini[i][j] + (r)*(Tfut[i+1][j]+Tfut[i-1][j]+Tfut[i][j+1] + Tfut[i][j-1]);
                if(sqrt((i-25)^2+(j-25)^2)<=5){
                    Tfut2[i][j]=100;
                }
            }}
        for (int k=0;k<pts;k++){
            for(int h=0;h<pts;h++){
            Tini[k][h] = Tfut[k][h];
            Tfut[k][h] = Tfut2[k][h];
            }}}
    //////////////////////////////////////////////////////////////////////////////////////////////
    for (int i=0; i<pts;i++){
    for (int j=0; j<pts; j++){
        cout <<Tinir[i][j]<<","<<Tfut[i][j]<<endl;}
}
}

