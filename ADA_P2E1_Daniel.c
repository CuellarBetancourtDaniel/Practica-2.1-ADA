#include <stdio.h>
#include <time.h>  // Incluir para medir el tiempo

void leerNumeros(int nums[], int tam, int arregloNum) {
	printf("Digita %d numeros para el arreglo %d: \n", tam, arregloNum);
	for (int i = 0; i < tam; i++) {
		do {
		printf("Numero %d: ", i + 1);
		scanf("%d", &nums[i]);
		if (nums[i] < -106 || nums[i] > 106) {
			printf("Error: El valor debe estar entre -106 y 106.\n");
			}
		} while (nums[i] < -106 || nums[i] > 106);
	}
}

void imprimirNumeros(int nums[], int tam, const char* nombre) {
	printf("%s: \n", nombre);
	for (int i = 0; i < tam; i++) {
		printf("%d, ", nums[i]);
	}
	printf("\n");
}

void fusionarArreglos(int nums1[], int m, int nums2[], int n, int mergedarray[]) {
	for (int i = 0; i < m; i++) {
		mergedarray[i] = nums1[i];
	}
	for (int i = m; i < (m + n); i++) {
		mergedarray[i] = nums2[i - m];
	}
}
void bubbleSort(int arr[], int tam) {
	int i, j, temp;
	//Numero de veces que se pasa el arreglo
	for (i = 0; i < tam - 1; i++) {
		//recorre el arreglo comparando cada elemento
		for (j = 0; j < tam - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// Intercambiamos los elementos si estan en el orden incorrecto
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

float  mediana(int arr[],int tam){
	int lamitad= tam/2;
	float mediana;

	if(tam%2 == 0){
		mediana = (arr[lamitad-1]+arr[lamitad])/2.0;
	}else{
		mediana = arr[lamitad];
	}
	
	return mediana;
}


int main() {
	int n, m;
	// Variables para medir tiempo
	clock_t start, end;
	double time_used;
	start = clock();
	
    do{
    	printf("Digite el valor de m: ");
    	scanf("%d", &m);
    	printf("Digite el valor de n: ");
    	scanf("%d",&n);
	}while(n<0 || m<0 || n>1000 || m>1000 || m+n>2000 || m+n<1);// comprobar que n y m sean mayores que 0 y menores o igual que 1000
	
	// Crear los arreglos
	int nums1[m], nums2[n], mergedarray[m + n];
	
	// Leer los valores para nums1 y nums2
	leerNumeros(nums1, m, 1);
	leerNumeros(nums2, n, 2);
	
	// Imprimir los arreglos sin combinar
	printf("Los arreglos sin combinar son: \n");
	imprimirNumeros(nums1, m, "nums1");
	imprimirNumeros(nums2, n, "nums2");
	
	// Fusionar los arreglos nums1 y nums2 en mergedarray
	fusionarArreglos(nums1, m, nums2, n, mergedarray);
	
	// Imprimir el arreglo fusionado
	printf("\nUniendo los arreglos queda como:\n");
	imprimirNumeros(mergedarray, m + n, "mergedarray");
	// Ordenar mergedarray usando Bubble Sort
	bubbleSort(mergedarray, m + n);
	
	// Imprimir el arreglo ordenado
	printf("\nEl arreglo fusionado y ordenado es:\n");
	imprimirNumeros(mergedarray, m + n, "mergedarray");
	//sacamos la mediana del mergedarray ya ordenado
	
	printf("\nLa mediana es: %f",mediana(mergedarray,m+n));
	// Tomar el tiempo al finalizar el algoritmo
	end = clock();
	
	// Calcular el tiempo de ejecucion en segundos
	time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("\nTiempo de ejecucion: %f segundos\n", time_used);
	
	return 0;
}
