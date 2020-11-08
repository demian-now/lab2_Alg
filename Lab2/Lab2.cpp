#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int* Get_Rand_Array_Int(size_t size)
{
	int* array = new int[size];
	int sign;
	for (size_t i = 0; i < size; i++)
	{
		sign = 1;
		if (rand() % 2 == 1)
			sign = -1;
		array[i] = rand() * sign;
	}
	return array;
}

int* Get_Rand_Array_Char(size_t size)
{
	int* array = new int[size];
	int sign;
	for (size_t i = 0; i < size; i++)
	{
		sign = 1;
		if (rand() % 2 == 1)
			sign = -1;
		array[i] = rand() * sign;
	}
	return array;
}

double CountingSort(char* array, size_t size)
{
	const size_t max_value = 256;
	clock_t time_test = clock();
	int temp_array[max_value];
	for (size_t i = 0; i < max_value; i++)
		temp_array[i] = 0;
	for (size_t i = 0; i < size; i++)
		temp_array[array[i] + 127]+=1;
	size_t control=0;
	for (size_t i = 0; i < max_value; i++)
	{
		for (int j = 0; j < temp_array[i]; j++)
		{
			array[control] = i - 127;
			control++;
		}
	}
	time_test = clock() - time_test;
	return ((double)time_test / CLOCKS_PER_SEC * 1000);
}

double InsertionSort(int* array, size_t size)
{
	clock_t time_test = clock();
	int key, temp;
	for (size_t i = 1; i < size; i++)
	{
		key = array[i];
		temp = i - 1;
		while (temp >= 0 && array[temp] > key)
		{
			array[temp + 1] = array[temp];
			array[temp] = key;
			temp--;
		}
	}
	time_test = clock() - time_test;
	return ((double)time_test / CLOCKS_PER_SEC * 1000);
}

void Print_Array(int *array, size_t size)
{
	for (size_t i = 0; i < size; i++)
		cout << array[i] << ' ';
	cout << endl;
}

double BubbleSort(int *array, size_t size)
{
	clock_t time_test = clock();
	int control;
	for (size_t i = 0; i < size; i++)
	{
		control = 0;
		for(size_t j=0; j<size-1; j++)
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
				control++;
			}
		if (control == 0)
			break;
	}
	time_test = clock() - time_test;
    return ((double)time_test*1000/CLOCKS_PER_SEC);
}

bool issorted(int* array, size_t size)
{
	for(size_t i=0; i<size-1; i++)
		if(array[i]>array[i+1])
			return false;
	return true;
}

bool issorted_char(char* array, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
		if (array[i] > array[i + 1])
			return false;
	return true;
}

double bogoSort(int* array, size_t size)
{
	clock_t time_test = clock();
	while (!issorted(array, size))
		for (size_t i = 0; i < size; i++)
			swap(array[i], array[rand() % size]);
	time_test = clock() - time_test;
	return ((double)time_test *1000 / CLOCKS_PER_SEC);
}

double QuickSort(int* array, int size) 
{
	clock_t time_test = clock();
	int i = 0, j = size - 1, mid = array[size / 2];
	do {
		while (array[i] < mid) i++;
		while (array[j] > mid) j--;
		if (i <= j) {
			swap(array[i], array[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) QuickSort(array, j + 1);
	if (i < size) QuickSort(&array[i], size - i);
	time_test = clock() - time_test;
	return ((double)time_test*1000 / CLOCKS_PER_SEC);
}

size_t BinarySearch(int* array, size_t size, int key)
{
	size_t mid = size / 2, left = 0, right = size - 1;
	if (!issorted(array, size))
		throw "This array is not sorted";
	while (array[mid] != key)
	{
		mid = (left + right) / 2;
		if (key < array[mid])
			right = mid-1;
		else if (key > array[mid])
			left = mid+1;
		else return mid;
		if (left > right)
			throw "Element not found";
	}
	return mid;
}

double average(double* array)
{
	double result = 0;
	for (int i = 0; i < 10; i++)
		result += array[i];
	return result / 10;
}

int main()
{
	srand(time(0));
	int size = 10; 
	int* test;
	cout << "Result for QuickSort: " << endl;
	double temp_array[10];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			test = Get_Rand_Array_Int(size);
			temp_array[j] =  QuickSort(test, size);
			cout << temp_array[j] <<" ";
			delete[] test;
		}
		cout << "for " << size << " elements. " << " Average: " << average(temp_array) << endl;
		size *= 10;
	}
	for (int i = 0; i < 5; i++)
	{
		size = 10;
		test = Get_Rand_Array_Char(size);
		Print_Array(test, size);
		InsertionSort(test, size);
		Print_Array(test, size);
		delete[] test;
	}
	size = 10;
	cout << "Result for BubbleSort: " << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			test = Get_Rand_Array_Int(size);
			temp_array[j] = BubbleSort(test, size);
			cout << temp_array[j] << " ";
			delete[] test;
		}
		cout << "for " << size << " elements. " << " Average: " << average(temp_array) << endl;
		size *= 10;
	}
}


