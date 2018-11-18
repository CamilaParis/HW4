import numpy as np
import matplotlib.pyplot as plt

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
plt.ylim(0,0.6)
plt.xlim(0,0.8)
plt.plot(x45,y45)
plt.plot(x10,y10)
plt.plot(x20,y20)
plt.plot(x30,y30)
plt.plot(x40,y40)
plt.plot(x50,y50)
plt.plot(x60,y60)
plt.show()
mayor=[]
angulo=[]
for i in range(len(y45)):
    if(y45[i]<0 and x45[i]>0.4):
        mayor.append(x45[i])
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
