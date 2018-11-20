#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main(){
    double k=1.62;
    double cp=820;
    double p=2.71;
    double delta_x = 0.1;
    double delta_t = 0.5;
    double t[3];
    t[0]=500;
    t[1]=5000;
    t[2]=50000;
    double v=k/(cp*p);
    double r = v*delta_t / (delta_x*delta_x);
    int pts=50;
    
    string name[3];
    string namea[3];
    string namep[3];
    name[0]="datosPDE1.txt";
    name[1]="datosPDE2.txt";
    name[2]="datosPDE3.txt";
    namea[0]="datosPDEa1.txt";
    namea[1]="datosPDEa2.txt";
    namea[2]="datosPDEa3.txt";
    namep[0]="datosPDEp1.txt";
    namep[1]="datosPDEp2.txt";
    namep[2]="datosPDEp3.txt";
    
    for(int m=0;m<3;m++){
    
    double Tini[pts][pts];
    double Tinir[pts][pts];
    for(int i =0; i<pts; i++){
        for(int j =0; j<pts; j++){
            Tini[i][j]=10;
            if((sqrt((i-25)*(i-25)+(j-25)*(j-25)))<=5){
                Tini[i][j]=100;}
        }
    }
    
    double Tfut[pts][pts];
    for (int i=1; i<pts-1; i++){
        for (int j=1; j<pts-1;j++){
            Tfut[i][j] = Tini[i][j]+ (r) * (Tini[i+1][j]+Tini[i-1][j]+Tini[i][j+1]+Tini[i][j-1]-4*Tini[i][j]);
            if((sqrt((i-25)*(i-25)+(j-25)*(j-25)))<=5){
                Tfut[i][j]=100;}
            
        }}
    double Tfut2[pts][pts];
    for (int i=0; i<pts;i++){
        for(int j=0;j<pts;j++){
            Tinir[i][j] = Tini[i][j];
        }}
    for(int dt=0; dt<t[m];dt++){
        for (int i=1; i<pts-1; i++){
            for(int j=1; j<pts-1;j++){
                Tfut2[i][j]= Tfut[i][j]+ (r) * (Tfut[i+1][j]+Tfut[i-1][j]+Tfut[i][j+1]+Tfut[i][j-1]-4*Tfut[i][j]);
                if((sqrt((i-25)*(i-25)+(j-25)*(j-25)))<=5){
                    Tfut2[i][j]=100;}
            }}
        for (int k=0;k<pts;k++){
            for(int h=0;h<pts;h++){
                Tfut[k][h] = Tfut2[k][h];
            }}}
    ofstream file;
    file.open(name[m]);
    for(int i=0;i<pts;i++){
        for(int j=0;j<pts;j++){
            file<<i<<","<<j<<","<<Tinir[i][j]<<","<<Tfut[i][j]<<endl;}}
    file.close();
    
////////////////////////////////////
    double Tinip[pts][pts];
    double Tinirp[pts][pts];
    for(int i =0; i<pts; i++){
        for(int j =0; j<pts; j++){
            Tinip[i][j]=10;
            if((sqrt((i-25)*(i-25)+(j-25)*(j-25)))<=5){
                Tinip[i][j]=100;}
            
            Tinip[0][j]=Tinip[pts-2][j];
            Tinip[pts-1][j]=Tinip[1][j];
            Tinip[i][0]=Tinip[i][pts-2];
            Tinip[i][pts-1]=Tinip[i][1];
            Tinip[0][0]=Tinip[pts-1][pts-1];
            Tinip[pts-1][pts-1]=Tinip[1][1];
            Tinip[0][pts-1]=Tinip[pts-1][1];
            Tinip[pts-1][0]=Tinip[1][pts-1];
        }
    }
    
    double Tfutp[pts][pts];
    for (int i=1; i<pts-1; i++){
        for (int j=1; j<pts-1;j++){
            Tfutp[i][j] = Tinip[i][j]+ (r) * (Tinip[i+1][j]+Tinip[i-1][j]+Tinip[i][j+1]+Tinip[i][j-1]-4*Tinip[i][j]);
            if((sqrt((i-25)*(i-25)+(j-25)*(j-25)))<=5){
                Tfutp[i][j]=100;}
            
            Tfutp[0][j]=Tfutp[pts-2][j];
            Tfutp[pts-1][j]=Tfutp[1][j];
            Tfutp[i][0]=Tfutp[i][pts-2];
            Tfutp[i][pts-1]=Tfutp[i][1];
            Tfutp[0][0]=Tfutp[pts-1][pts-1];
            Tfutp[pts-1][pts-1]=Tfutp[1][1];
            Tfutp[0][pts-1]=Tfutp[pts-1][1];
            Tfutp[pts-1][0]=Tfutp[1][pts-1];
        }}
    double Tfut2p[pts][pts];
    for (int i=0; i<pts;i++){
        for(int j=0;j<pts;j++){
            Tinirp[i][j] = Tinip[i][j];
        }}
    for(int dt=0; dt<t[m];dt++){
        for (int i=1; i<pts-1; i++){
            for(int j=1; j<pts-1;j++){
                Tfut2p[i][j]= Tfutp[i][j]+ (r) * (Tfutp[i+1][j]+Tfutp[i-1][j]+Tfutp[i][j+1]+Tfutp[i][j-1]-4*Tfutp[i][j]);
                if((sqrt((i-25)*(i-25)+(j-25)*(j-25)))<=5){
                    Tfut2p[i][j]=100;}
                
                Tfut2p[0][j]=Tfut2p[pts-2][j];
                Tfut2p[pts-1][j]=Tfut2p[1][j];
                Tfut2p[i][0]=Tfut2p[i][pts-2];
                Tfut2p[i][pts-1]=Tfut2p[i][1];
                Tfut2p[0][0]=Tfut2p[pts-1][pts-1];
                Tfut2p[pts-1][pts-1]=Tfut2p[1][1];
                Tfut2p[0][pts-1]=Tfut2p[pts-1][1];
                Tfut2p[pts-1][0]=Tfut2p[1][pts-1];
            }}
        for (int k=0;k<pts;k++){
            for(int h=0;h<pts;h++){
                Tfutp[k][h] = Tfut2p[k][h];
            }}}
    ofstream filep;
    filep.open(namep[m]);
    for(int i=0;i<pts;i++){
        for(int j=0;j<pts;j++){
            filep<<i<<","<<j<<","<<Tinirp[i][j]<<","<<Tfutp[i][j]<<endl;}}
    filep.close();
    
 ///////////////////////////////////////////
    
    
    double Tinia[pts][pts];
    double Tinira[pts][pts];
    for(int i =0; i<pts; i++){
        for(int j =0; j<pts; j++){
        Tinia[i][j]=10;
        if((sqrt((i-25)*(i-25)+(j-25)*(j-25)))<=5){
            Tinia[i][j]=100;}
            
            
            Tinia[0][j]=Tinia[1][j];
            Tinia[pts-1][j]=Tinia[pts-2][j];
            Tinia[i][0]=Tinia[i][1];
            Tinia[i][pts-1]=Tinia[i][pts-2];
            Tinia[0][0]=Tinia[1][1];
            Tinia[pts-1][pts-1]=Tinia[pts-2][pts-2];
            Tinia[0][pts-1]=Tinia[1][pts-2];
            Tinia[pts-1][0]=Tinia[pts-2][1];
            
    }
    }
    
    double Tfuta[pts][pts];
    for (int i=1; i<pts-1; i++){
        for (int j=1; j<pts-1;j++){
            Tfuta[i][j] = Tinia[i][j]+ (r) * (Tinia[i+1][j]+Tinia[i-1][j]+Tinia[i][j+1]+Tinia[i][j-1]-4*Tinia[i][j]);
            if((sqrt((i-25)*(i-25)+(j-25)*(j-25)))<=5){
                Tfuta[i][j]=100;}
            
            Tfuta[0][j]=Tfuta[1][j];
            Tfuta[pts-1][j]=Tfuta[pts-2][j];
            Tfuta[i][0]=Tfuta[i][1];
            Tfuta[i][pts-1]=Tfuta[i][pts-2];
            Tfuta[0][0]=Tfuta[1][1];
            Tfuta[pts-1][pts-1]=Tfuta[pts-2][pts-2];
            Tfuta[0][pts-1]=Tfuta[1][pts-2];
            Tfuta[pts-1][0]=Tfuta[pts-2][1];

        }}
    double Tfut2a[pts][pts];
    for (int i=0; i<pts;i++){
        for(int j=0;j<pts;j++){
        Tinira[i][j] = Tinia[i][j];
        }}
    for(int dt=0; dt<t[m];dt++){
        for (int i=1; i<pts-1; i++){
            for(int j=1; j<pts-1;j++){
                Tfut2a[i][j]= Tfuta[i][j]+ (r) * (Tfuta[i+1][j]+Tfuta[i-1][j]+Tfuta[i][j+1]+Tfuta[i][j-1]-4*Tfuta[i][j]);
                if((sqrt((i-25)*(i-25)+(j-25)*(j-25)))<=5){
                    Tfut2a[i][j]=100;
                }
                Tfut2a[0][j]=Tfut2a[1][j];
                Tfut2a[pts-1][j]=Tfut2a[pts-2][j];
                Tfut2a[i][0]=Tfut2a[i][1];
                Tfut2a[i][pts-1]=Tfut2a[i][pts-2];
                Tfut2a[0][0]=Tfut2a[1][1];
                Tfut2a[pts-1][pts-1]=Tfut2a[pts-2][pts-2];
                Tfut2a[0][pts-1]=Tfut2a[1][pts-2];
                Tfut2a[pts-1][0]=Tfut2a[pts-2][1];
            }}
        for (int k=0;k<pts;k++){
            for(int h=0;h<pts;h++){
            Tfuta[k][h] = Tfut2a[k][h];
            }}}
    ofstream filea;
    filea.open(namea[m]);
    for(int i=0;i<pts;i++){
        for(int j=0;j<pts;j++){
            filea<<i<<","<<j<<","<<Tinira[i][j]<<","<<Tfuta[i][j]<<endl;}}
    filea.close();
    }}

