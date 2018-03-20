#include <iostream>
using namespace std;

int Partition(int*A, int start, int end)
{
	int pivot = A[end];

	int pIndex = start;

	for (int i = start; i < end; ++i)
	{
		if (A[i] <= pivot)
		{
			int temp = A[i];
			A[i] = A[pIndex];
			A[pIndex] = temp;

			++pIndex;
		}
	}

	int temp = A[pIndex];
	A[pIndex] = A[end];
	A[end] = temp;

	return pIndex;
}

void quickSort(int* A, int start, int end)
{
	if (start < end)
	{
		int pIndex = Partition(A, start, end);

		quickSort(A, start, pIndex - 1);

		quickSort(A, pIndex + 1, end);
	}
}

void QuickSort(int* A, int n)
{
	quickSort(A, 0, n - 1);
}

int main()
{
	int n;

	cout << "Enter size of array \n";
	cin >> n;

	int* A = new int[n];

	cout << "Enter elements of array \n";
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}

	QuickSort(A, n);

	cout << "Array after sort \n";
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << "  ";
	}

	return 0;
}