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
    
    for(int i=0;i<pts-1;i++){
        
        k1x=h*f1x(t[i],x[i],y[i],dx[i],dy[i],c,m);
        l1x=h*f2x(t[i],x[i],y[i],dx[i],dy[i],c,m);
        
        k1y=h*f1y(t[i],x[i],y[i],dx[i],dy[i],c,g,m);
        l1y=h*f2y(t[i],x[i],y[i],dx[i],dy[i],c,g,m);        
        
        
        k2x=h*f1x(t[i]+0.5*h,x[i]+k1x*0.5,y[i]+k1y*0.5,dx[i]+l1x*0.5,dy[i]+l1y*0.5,c,m);
        l2x=h*f2x(t[i]+0.5*h,x[i]+k1x*0.5,y[i]+k1y*0.5,dx[i]+l1x*0.5,dy[i]+l1y*0.5,c,m);
        
        k2y=h*f1y(t[i]+0.5*h,x[i]+k1x*0.5,y[i]+k1y*0.5,dx[i]+l1x*0.5,dy[i]+l1y*0.5,c,g,m);
        l2y=h*f2y(t[i]+0.5*h,x[i]+k1x*0.5,y[i]+k1y*0.5,dx[i]+l1x*0.5,dy[i]+l1y*0.5,c,g,m);
        
        
        
        k3x=h*f1x(t[i]+0.5*h,x[i]+k2x*0.5,y[i]+k2y*0.5,dx[i]+l2x*0.5,dy[i]+l2y*0.5,c,m);
        l3x=h*f2x(t[i]+0.5*h,x[i]+k2x*0.5,y[i]+k2y*0.5,dx[i]+l2x*0.5,dy[i]+l2y*0.5,c,m);
        
        k3y=h*f1y(t[i]+0.5*h,x[i]+k2x*0.5,y[i]+k2y*0.5,dx[i]+l2x*0.5,dy[i]+l2y*0.5,c,g,m);
        l3y=h*f2y(t[i]+0.5*h,x[i]+k2x*0.5,y[i]+k2y*0.5,dx[i]+l2x*0.5,dy[i]+l2y*0.5,c,g,m);
        
        
        
        k4x=h*f1x(t[i]+h,x[i]+k3x,y[i]+k3y,dx[i]+l3x,dy[i]+l3y,c,m);
        l4x=h*f2x(t[i]+h,x[i]+k3x,y[i]+k3y,dx[i]+l3x,dy[i]+l3y,c,m);
        
        k4y=h*f1y(t[i]+h,x[i]+k3x,y[i]+k3y,dx[i]+l3x,dy[i]+l3y,c,g,m);
        l4y=h*f2y(t[i]+h,x[i]+k3x,y[i]+k3y,dx[i]+l3x,dy[i]+l3y,c,g,m);
        
        
        
        x[i+1]=(1.0/6)*(k1x+2*k2x+2*k3x+k4x)+x[i];
        dx[i+1]=(1.0/6)*(l1x+2*l2x+2*l3x+l4x)+dx[i];
        
        y[i+1]=(1.0/6)*(k1y+2*k2y+2*k3y+k4y)+y[i];
        dy[i+1]=(1.0/6)*(l1y+2*l2y+2*l3y+l4y)+dy[i];
    }
    
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
