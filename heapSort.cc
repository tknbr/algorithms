/**
 * Implemented by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github collection: https://github.com/tknbr/algorithms
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * input: vector of integers that fit into memory
 * output: vector is sorted (<)
 * Complexity: O(nlog(n))
 */

void swap(vector<int> &A, int first_index, int second_index){
	int aux = A[first_index];
	A[first_index] = A[second_index];
	A[second_index] = aux;
}

void max_heapify(vector<int> &A, int index, int size){
	int largest;
	int index_left = index*2;
	int index_right = index*2+1;

	if(index_left < size and A[index_left] > A[index])
		largest = index_left;
	else
		largest = index;
	if(index_right < size and A[index_right] > A[largest])
		largest = index_right;
	if(largest != index){
		swap(A, largest, index);
		max_heapify(A, largest, size);
	}
}

void build_max_heap(vector<int> &A){
	for (int i = (A.size()/2)-1; i >= 0; --i){
		max_heapify(A, i, A.size());
	}
}

void heapsort(vector<int> &A){
	build_max_heap(A);
	for(int i = A.size()-1; i > 0; --i){
		swap(A, i, 0);
		max_heapify(A, 0, i);
	}
}

int main(){
	vector<int> vectorToSort;
	vectorToSort.push_back(13);
	vectorToSort.push_back(-3);
	vectorToSort.push_back(-25);
	vectorToSort.push_back(20);
	vectorToSort.push_back(-3);
	vectorToSort.push_back(-16);
	vectorToSort.push_back(-23);
	vectorToSort.push_back(18);
	vectorToSort.push_back(20);
	vectorToSort.push_back(-7);
	vectorToSort.push_back(12);
	vectorToSort.push_back(-5);
	vectorToSort.push_back(22);
	vectorToSort.push_back(15);
	vectorToSort.push_back(-4);
	vectorToSort.push_back(7);
	heapsort(vectorToSort);
	for (int i = 0; i < vectorToSort.size(); ++i){
		cout << vectorToSort[i] << " ";
	}
	cout << endl;
}

