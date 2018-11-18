#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f1x(double t,double x, double y,double dx, double dy, double c, double m);
double f2x(double t,double x,double y,double dx, double dy, double c, double m);
double f1y(double t,double x,double y, double dx,double dy, double c, double g, double m);
double f2y(double t,double x,double y, double dx, double dy, double c, double g, double m);
double nv(double vy,double vx);

int main(){
    double g=10.0;
    double c=0.2;
    double m=0.2;
    int pts=45000;
    double h=0.00001;
    double t[pts],x[pts],dx[pts],y[pts],dy[pts];
    double x0=0.0;
    double y0=0.0;
    double dx0=150.*sqrt(2);
    double dy0=150.*sqrt(2);
    double k1x,k1y,k2x,k2y,k3x,k3y,k4x,k4y,l1x,l1y,l2x,l2y,l3x,l3y,l4x,l4y;
    for(int i=0;i<pts;i++){
        t[i]=h*i;
    }
    x[0]=x0;
    dx[0]=dx0;
    y[0]=y0;
    dy[0]=dy0;
}

double f1x(double t,double x,double y, double dx, double dy, double c, double m){
    return dx;
}
double f2x(double t,double x,double y, double dx, double dy, double c, double m){
    return -c*nv(dx,dy)*dx/m;
}
double f1y(double t,double x, double y, double dx,double dy, double c, double g, double m){
    return dy;
}
double f2y(double t,double x, double y, double dx, double dy, double c, double g, double m){
    return -g-c*nv(dy,dx)*dy/m;
}
double nv(double vy,double vx){
    return sqrt(vy*vy+vx*vx)*sqrt(vy*vy+vx*vx);
}
