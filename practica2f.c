#include <stdio.h>
#include <time.h> 

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    clock_t start, end;
    double time_used;

    printf("Digita el termino de la sucesion de Fibonacci que deseas conocer: ");
    scanf("%d", &n);

    start = clock();  // Mover el inicio del temporizador aquí

    int result = fibonacci(n);  // Calcular el número de Fibonacci

    end = clock();  // Finalizar el temporizador aquí
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;  // Convertir a milisegundos

    printf("El termino %d de la sucesion de Fibonacci es %d\n", n, result);
    printf("Tiempo de ejecucion: %f ms\n", time_used);  // Imprimir en ms

    return 0;
}

