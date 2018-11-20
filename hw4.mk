Resultados_hw4.pdf: Resultados_hw4.tex
	pdflatex Resultados_hw4.tex
Resultados_hw4.tex: Graf45.pdf Grafs.pdf CondicionesIniciales.pdf Tiempo1Caso1.pdf Tiempo2Caso1.pdf Tiempo3Caso1.pdf Tiempo1Caso2.pdf Tiempo2Caso2.pdf Tiempo3Caso2.pdf Tiempo1Caso3.pdf Tiempo2Caso3.pdf Tiempo3Caso3.pdf

Graf45.pdf: Plots_hw4.py
	python Plots_hw4.py
Grafs.pdf: Plots_hw4.py
	python Plots_hw4.py
CondicionesIniciales.pdf: Plots_hw4.py
	python Plots_hw4.py
Tiempo1Caso1.pdf: Plots_hw4.py
	python Plots_hw4.py
Tiempo2Caso1.pdf: Plots_hw4.py
	python Plots_hw4.py
Tiempo3Caso1.pdf: Plots_hw4.py
	python Plots_hw4.py
Tiempo1Caso2.pdf: Plots_hw4.py
	python Plots_hw4.py
Tiempo2Caso2.pdf: Plots_hw4.py
	python Plots_hw4.py
Tiempo3Caso2.pdf: Plots_hw4.py
	python Plots_hw4.py
Tiempo1Caso3.pdf: Plots_hw4.py
	python Plots_hw4.py
Tiempo2Caso3.pdf: Plots_hw4.py
	python Plots_hw4.py
Tiempo3Caso3.pdf: Plots_hw4.py
	python Plots_hw4.py

Plots_hw4.py: datos45.txt datos10.txt datos20.txt datos30.txt datos40.txt datos50.txt datos60.txt datos70.txt datosPDE1.txt datosPDE2.txt datosPDE3.txt datosPDEa1.txt datosPDEa2.txt datosPDEa3.txt datosPDEp1.txt datosPDEp2.txt datosPDEp3.txt
datos45.txt: ode
	./ode
datos10.txt: ode
	./ode
datos20.txt: ode
	./ode
datos30.txt: ode
	./ode
datos40.txt: ode
	./ode
datos50.txt: ode
	./ode
datos60.txt: ode
	./ode
datos70.txt: ode
	./ode
datosPDE1.txt: pde
	./pde
datosPDE2.txt: pde
	./pde
datosPDE3.txt: pde
	./pde
datosPDEa1.txt: pde
	./pde
datosPDEa2.txt: pde
	./pde
datosPDEa3.txt: pde
	./pde
datosPDEp1.txt: pde
	./pde
datosPDEp2.txt: pde
	./pde
datosPDEp3.txt: pde
	./pde
ode: ODE.cpp
	g++ -o ode ODE.cpp
pde: PDE.cpp
	g++ -o pde PDE.cpp
clean:
	
	rm *.txt
	rm *.pdf



