//1 ЗАДАНИЕ

#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <math.h>

using namespace std;

//2. Стандартными средствами OpenMP выполнить замер начального времени(в секундах) и конечного времени, а также определить точность таймера OpenMP.
void second()
{
	double start_time = omp_get_wtime();
	double end_time = omp_get_wtime();
	double tick = omp_get_wtick();
	cout << end_time - start_time << endl;
	cout << "Точность таймера " << tick << endl;
}
//Для измерения времени выполнения некоторого участка программы его нужно окружить двумя вызовами функции omp_get_wtime
//end - start - время выполнения кода между этими переменными, tick вычисляет точность таймера 


//4. С принудительной установкой нужного числа потоков.
void fourth() {
	printf("Serial region 1\n Number of OMP Threads=");
	int N;
	scanf_s("%d", &N);//задаем число потоков
	printf("\n");
	N = abs(N);
	N = N ? N : 1;
	omp_set_dynamic(0); //Запрещает динамическую установку числа 
	 //потоков в следующих параллельных областях

	omp_set_num_threads(N); //Задает нужное число потоков
	 //в следующей параллельной области

#pragma omp parallel 
	{
		printf("Parallel region 1\n");
	}
	printf("Serial region 2\n");

	omp_set_dynamic(1); //Разрешает динамическую установку числа 
	 //потоков в следующих параллельных областях
	omp_set_num_threads(N);

#pragma omp parallel 
	{
		printf("Parallel region 2\n");
	}
	printf("Serial region 3\n");
}


//6. При помощи операции редукции определить фактическое число порожденных потоков OpenMP
void six() {
	int count = 0;
#pragma omp parallel reduction (+: count)
	{
		count++;
		printf("\nCurrent value of the count: %d\n", count);
	}
	printf("Threads number: %d\n", count);
}


int main()
{
	setlocale(LC_ALL, "Russian");
	second();
	//fourth();
	six();
}


//ЗАМЕЧАНИЕ. Pragma задает нестандартные директивы для компилятора