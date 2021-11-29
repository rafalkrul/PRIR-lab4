#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double wzorf(double x){ // Wzór
    return 4*x-6*x+5;
}

double wysokosc(double a, double b, double n){  // Potrzebne do obliczenia
    return (b - a) / n;
}


double pkt(double a, double b, double n){ // Obliczanie pktu
    double xi = 0;
        for(double i = 1; i < n; i++){
            xi += (wzorf(a + ((i / n) * (b - a)))); // Obliczanie xi
        }
        return xi;
}

void obliczenie(double a, double b, double n){ // Obliczanie sumy trapezów
    double suma = 0;

        suma = wysokosc(a,b,n) * (wzorf(a) / 2 + pkt(a,b,n) + wzorf(b)/2); // Sumowanie poszczególnych trapezów
        printf("suma trapezow = %f \n",suma);
        
    
}

double wezel(double a, double b, double wezel){ // Inicjacja węzła
    return (((b-a)/2) * wezel + (b+a)/2);  
}

void obliczenia1(double a, double b, double wagi[], double wezly[]){ // Obliczanie metodą gausa
    
    // Inicjacja zmiennych
    double wynik = (b-a)/2;
    double suma = 0;
    int dlugosc = sizeof(wagi); // długość tablic
    for(int i = 0; i < dlugosc; i++){
        suma += wagi[i]*wzorf(wezel(a,b,wezly[i])); // Sumowanie 
    }
    suma *= wynik;
    printf("suma gaussa = %f\n",suma); // Wypisanie sumy
}

void leibnizPi(float n) { // Obliczanie wartości pi ze wzoru lebniza
    double pi=1.0;
    int i;
    int N;
    for (i=3, N=2*n+1; i<=N; i+=2)
        pi += ((i&2) ? -1.0 : 1.0) / i;
    printf("Leibnz = %f \n\n", 4*pi);
    
}

void forko()
{
    // Inicjacja randomowych liczb 
    srand ( time(NULL) );
    double r = rand() % 10;
    double r1 = rand() % 10 ;
    double r2 = rand() % 5;
    double temp;

    // Inicjacja wag
double wagiW[8] = 
				{0.3626837833783620,
				0.3626837833783620,
				0.3137066458778873,
				0.3137066458778873,
				0.2223810344533745,
				0.2223810344533745,
				0.1012285362903763,
				0.1012285362903763};
 
 
	double wagiT[8] = 
				{-0.1834346424956498,
				0.1834346424956498,
				-0.5255324099163290,
				0.5255324099163290,
				-0.7966664774136267,
				0.7966664774136267,
				-0.9602898564975363,
				0.9602898564975363};

    for(r2; r2 < 12; r2++){ // for aby ustawić, ile zostać stworzonych procesów
        
	if (fork() == 0){
        if(r > r1){     // ustalamy, która z losowych liczb jest większa/mniejsza
            temp = r1;
            r1 = r;
            r = temp; 
        }
        obliczenie(r,r1,8); // Wywołanie metody
        obliczenia1(r,r1,wagiW,wagiT); // Wywołanie metody
    }
    }
}


int main()
{   
    // Losowanie do leibniza
        srand ( time(NULL) );
    double N = rand() % 5000;

     printf("--- LEIBNIZ ---\n");
    
    leibnizPi(N);// Wypisanie leibniza
    forko(); // Wypisanie trapezów/Gaussa
	return 0;
}
