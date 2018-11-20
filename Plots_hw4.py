import numpy as np
np.set_printoptions(threshold=np.nan)
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import cm
##Para ODE.cpp
data45=np.genfromtxt("datos45.txt", delimiter=",")
data10=np.genfromtxt("datos10.txt", delimiter=",")
data20=np.genfromtxt("datos20.txt", delimiter=",")
data30=np.genfromtxt("datos30.txt", delimiter=",")
data40=np.genfromtxt("datos40.txt", delimiter=",")
data50=np.genfromtxt("datos50.txt", delimiter=",")
data60=np.genfromtxt("datos60.txt", delimiter=",")
data70=np.genfromtxt("datos70.txt", delimiter=",")

x45=data45[:,1]
y45=data45[:,2]

x10=data10[:,1]
y10=data10[:,2]

x20=data20[:,1]
y20=data20[:,2]

x30=data30[:,1]
y30=data30[:,2]

x40=data40[:,1]
y40=data40[:,2]

x50=data50[:,1]
y50=data50[:,2]

x60=data60[:,1]
y60=data60[:,2]

x70=data70[:,1]
y70=data70[:,2]

plt.figure()
plt.ylim(0,6)
plt.xlim(0,6)
plt.xlabel("x")
plt.ylabel("y")
plt.plot(x45,y45)
plt.savefig("Graf45.pdf")
plt.close()
plt.figure()
plt.ylim(0,6)
plt.xlim(0,6)
plt.xlabel("x")
plt.ylabel("y")
plt.plot(x10,y10,label="10")
plt.plot(x20,y20,label="20")
plt.plot(x30,y30,label="30")
plt.plot(x40,y40,label="40")
plt.plot(x50,y50,label="50")
plt.plot(x60,y60,label="60")
plt.plot(x70,y70,label="70")
plt.legend(loc="best")
plt.savefig("Grafs.pdf")
plt.close()
mayor=[]
angulo=[]
for i in range(len(y45)):
    if(y45[i]<0 and x45[i]>0.4):
        mayor.append(x45[i])
        print("Para el angulo de 45 el proyectil recorre una distancia de ", x45[i])
        angulo.append(45)
        break
for i in range(len(y10)):
    if(y10[i]<0 and x10[i]>0.4):
        mayor.append(x10[i])
        angulo.append(10)
        break
for i in range(len(y20)):
    if(y20[i]<0 and x20[i]>0.4):
        mayor.append(x20[i])
        angulo.append(20)
        break
for i in range(len(y30)):
    if(y30[i]<0 and x30[i]>0.4):
        mayor.append(x30[i])
        angulo.append(30)
        break
for i in range(len(y40)):
    if(y40[i]<0 and x40[i]>0.4):
        mayor.append(x40[i])
        angulo.append(40)
        break
for i in range(len(y50)):
    if(y50[i]<0 and x50[i]>0.4):
        mayor.append(x50[i])
        angulo.append(50)
        break
for i in range(len(y60)):
    if(y60[i]<0 and x60[i]>0.4):
        mayor.append(x60[i])
        angulo.append(60)
        break
for i in range(len(y70)):
    if(y70[i]<0 and x70[i]>0.4):
        mayor.append(x70[i])
        angulo.append(70)
        break
print("La distancia recorrida es mayor para un angulo de", angulo[np.argmax(mayor)])


#Para PDE.cpp
dataPDE1=np.genfromtxt("datosPDE1.txt",delimiter=",")
dataPDE2=np.genfromtxt("datosPDE2.txt",delimiter=",")
dataPDE3=np.genfromtxt("datosPDE3.txt",delimiter=",")
dataPDEa1=np.genfromtxt("datosPDEa1.txt",delimiter=",")
dataPDEa2=np.genfromtxt("datosPDEa2.txt",delimiter=",")
dataPDEa3=np.genfromtxt("datosPDEa3.txt",delimiter=",")
dataPDEp1=np.genfromtxt("datosPDEp1.txt",delimiter=",")
dataPDEp2=np.genfromtxt("datosPDEp2.txt",delimiter=",")
dataPDEp3=np.genfromtxt("datosPDEp3.txt",delimiter=",")

i=dataPDE1[:,0]
j=dataPDE1[:,1]

Tini1=dataPDE1[:,2]
Tfut1=dataPDE1[:,3]
Tini2=dataPDE2[:,2]
Tfut2=dataPDE2[:,3]
Tini3=dataPDE3[:,2]
Tfut3=dataPDE3[:,3]

Tinip1=dataPDEp1[:,2]
Tfutp1=dataPDEp1[:,3]
Tinip2=dataPDEp2[:,2]
Tfutp2=dataPDEp2[:,3]
Tinip3=dataPDEp3[:,2]
Tfutp3=dataPDEp3[:,3]


Tinia1=dataPDEa1[:,2]
Tfuta1=dataPDEa1[:,3]
Tinia2=dataPDEa2[:,2]
Tfuta2=dataPDEa2[:,3]
Tinia3=dataPDEa3[:,2]
Tfuta3=dataPDEa3[:,3]

m=np.zeros((50, 50))
m1=np.zeros((50, 50))
m2=np.zeros((50, 50))
m3=np.zeros((50, 50))
ma1=np.zeros((50, 50))
ma2=np.zeros((50, 50))
ma3=np.zeros((50, 50))
mp1=np.zeros((50, 50))
mp2=np.zeros((50, 50))
mp3=np.zeros((50, 50))
for k in range(len(Tini1)):
    m[int(i[k]),int(j[k])]=Tini1[k]
    m1[int(i[k]),int(j[k])]=Tfut1[k]
    m2[int(i[k]),int(j[k])]=Tfut2[k]
    m3[int(i[k]),int(j[k])]=Tfut3[k]
    ma1[int(i[k]),int(j[k])]=Tfuta1[k]
    ma2[int(i[k]),int(j[k])]=Tfuta2[k]
    ma3[int(i[k]),int(j[k])]=Tfuta3[k]
    mp1[int(i[k]),int(j[k])]=Tfutp1[k]
    mp2[int(i[k]),int(j[k])]=Tfutp2[k]
    mp3[int(i[k]),int(j[k])]=Tfutp3[k]


##########
x = np.linspace(0, 50, 50)
y = np.linspace(0, 50, 50)
X, Y=np.meshgrid(x,y)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
Z=m
plt.title("Condiciones Iniciales")
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_zlabel("Temperatura")
surf = ax.plot_surface(X, Y, Z, cmap=cm.autumn,linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
plt.savefig("CondicionesIniciales.pdf")
plt.close()

fig1 = plt.figure()
ax1 = fig1.add_subplot(111, projection='3d')
Z1=m1
plt.title("Tiempo 1 Caso 1")
ax1.set_xlabel("x")
ax1.set_ylabel("y")
ax1.set_zlabel("Temperatura")
surf1 = ax1.plot_surface(X, Y, Z1, cmap=cm.autumn,linewidth=0, antialiased=False)
fig1.colorbar(surf1, shrink=0.5, aspect=5)
plt.savefig("Tiempo1Caso1.pdf")
plt.close()


fig2 = plt.figure()
ax2 = fig2.add_subplot(111, projection='3d')
Z2=m2
plt.title("Tiempo 2 Caso 1")
ax2.set_xlabel("x")
ax2.set_ylabel("y")
ax2.set_zlabel("Temperatura")
surf2 = ax2.plot_surface(X, Y, Z2, cmap=cm.autumn,linewidth=0, antialiased=False)
fig2.colorbar(surf2, shrink=0.5, aspect=5)
plt.savefig("Tiempo2Caso1.pdf")
plt.close()

fig3 = plt.figure()
ax3 = fig3.add_subplot(111, projection='3d')
Z3=m3
plt.title("Tiempo 3 Caso 1")
ax3.set_xlabel("x")
ax3.set_ylabel("y")
ax3.set_zlabel("Temperatura")
surf3 = ax3.plot_surface(X, Y, Z3, cmap=cm.autumn,linewidth=0, antialiased=False)
fig3.colorbar(surf3, shrink=0.5, aspect=5)
plt.savefig("Tiempo3Caso1.pdf")
plt.close()

figa1 = plt.figure()
axa1 = figa1.add_subplot(111, projection='3d')
Za1=ma1
plt.title("Tiempo 1 Caso 2")
axa1.set_xlabel("x")
axa1.set_ylabel("y")
axa1.set_zlabel("Temperatura")
surfa1 = axa1.plot_surface(X, Y, Za1, cmap=cm.autumn,linewidth=0, antialiased=False)
figa1.colorbar(surfa1, shrink=0.5, aspect=5)
plt.savefig("Tiempo1Caso2.pdf")
plt.close()


figa2 = plt.figure()
axa2 = figa2.add_subplot(111, projection='3d')
Za2=ma2
plt.title("Tiempo 2 Caso 2")
axa2.set_xlabel("x")
axa2.set_ylabel("y")
axa2.set_zlabel("Temperatura")
surfa2 = axa2.plot_surface(X, Y, Za2, cmap=cm.autumn,linewidth=0, antialiased=False)
figa2.colorbar(surfa2, shrink=0.5, aspect=5)
plt.savefig("Tiempo2Caso2.pdf")
plt.close()

figa3 = plt.figure()
axa3 = figa3.add_subplot(111, projection='3d')
Za3=ma3
plt.title("Tiempo 3 Caso 2")
axa3.set_xlabel("x")
axa3.set_ylabel("y")
axa3.set_zlabel("Temperatura")
surfa3 = axa3.plot_surface(X, Y, Za3, cmap=cm.autumn,linewidth=0, antialiased=False)
figa3.colorbar(surfa3, shrink=0.5, aspect=5)
plt.savefig("Tiempo3Caso2.pdf")
plt.close()

figp1 = plt.figure()
axp1 = figp1.add_subplot(111, projection='3d')
Zp1=mp1
plt.title("Tiempo 1 Caso 3")
axp1.set_xlabel("x")
axp1.set_ylabel("y")
axp1.set_zlabel("Temperatura")
surfp1 = axp1.plot_surface(X, Y, Zp1, cmap=cm.autumn,linewidth=0, antialiased=False)
figp1.colorbar(surfp1, shrink=0.5, aspect=5)
plt.savefig("Tiempo1Caso3.pdf")
plt.close()


figp2 = plt.figure()
axp2 = figp2.add_subplot(111, projection='3d')
Zp2=mp2
plt.title("Tiempo 2 Caso 3")
axp2.set_xlabel("x")
axp2.set_ylabel("y")
axp2.set_zlabel("Temperatura")
surfp2 = axp2.plot_surface(X, Y, Zp2, cmap=cm.autumn,linewidth=0, antialiased=False)
figp2.colorbar(surfp2, shrink=0.5, aspect=5)
plt.savefig("Tiempo2Caso3.pdf")
plt.close()

figp3 = plt.figure()
axp3 = figp3.add_subplot(111, projection='3d')
Zp3=mp3
plt.title("Tiempo 3 Caso 3")
axp3.set_xlabel("x")
axp3.set_ylabel("y")
axp3.set_zlabel("Temperatura")
surfp3 = axp3.plot_surface(X, Y, Zp3, cmap=cm.autumn,linewidth=0, antialiased=False)
figp3.colorbar(surfp3, shrink=0.5, aspect=5)
plt.savefig("Tiempo3Caso3.pdf")
plt.close()
