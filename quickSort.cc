/**
 * Implemented by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github collection: https://github.com/tknbr/algorithms
 */

#include <vector>
#include <iostream>

using namespace std;

/**
 * input: vector of integers that fit into memory
 * output: vector is sorted (<)
 * Complexity: O(nlog(n))
 */

void swap(vector<int> &A, int pos1, int pos2){
	int aux = A[pos1];
	A[pos1] = A[pos2];
	A[pos2] = aux;
}

int partition(vector<int> &A, int left, int right){
	int partition = left;
	int pivot = A[right-1];
	for(int i = left; i < right; ++i){
		if(A[i] <= pivot){
			swap(A, i, partition);
			++partition;
		}
	}
	return partition-1;
}

void quicksort(vector<int> &A, int left, int right){
	if (left < right){
		int pivotIndex = partition(A, left, right);
		quicksort(A, left, pivotIndex);
		quicksort(A, pivotIndex+1, right);
	}
}
