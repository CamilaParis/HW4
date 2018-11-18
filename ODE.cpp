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
