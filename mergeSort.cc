/**
 * Implemented by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github collection: https://github.com/tknbr/algorithms
 */

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/**
 * input: vector of integers that fit into memory
 * output: vector is sorted (<)
 * start, end and middle are always naturals. We could have used unsigend int.
 * Complexity: O(nlog(n))
 */

void merge(vector<int> &A, int start, int end, int middle){
	vector<int> first_half;
	vector<int> second_half;
	int iterator_A=start;
	int iterator_first_half=0;
	int iterator_second_half=0;

	for(int i=0; i<middle-start+1; ++i){
		first_half.push_back(A[start+i]);
	}
	
	for(int i=0; i<end-middle; ++i)
		second_half.push_back(A[middle+1+i]);

	while(iterator_first_half<first_half.size()){
		if(iterator_second_half==second_half.size() or first_half[iterator_first_half]<second_half[iterator_second_half]){
			A[iterator_A]=first_half[iterator_first_half];
			++iterator_first_half;
		} else {
			A[iterator_A]=second_half[iterator_second_half];
			++iterator_second_half;
		}
		++iterator_A;
	}

	while(iterator_second_half < second_half.size()){
		A[iterator_A] = second_half[iterator_second_half];
		++iterator_second_half;
		++iterator_A;
	}

}

void merge_sort(vector<int> &A, int start, int end){
	if(start<end){
		//implicit floor((start+end)/2)
		int middle=(start+end)/2;
		merge_sort(A, start, middle);
		merge_sort(A, middle+1, end);
		merge(A, start, end, middle);
	}
}

int main(){
	vector<int> vectorToSort;
	vectorToSort.push_back(23);
	vectorToSort.push_back(-2);
	vectorToSort.push_back(-99);
	vectorToSort.push_back(12);
	vectorToSort.push_back(3);
	vectorToSort.push_back(2);
	vectorToSort.push_back(-23);
	merge_sort(vectorToSort, 0, vectorToSort.size()-1);
	for(int i=0; i<vectorToSort.size(); ++i)
		cout << " " << vectorToSort[i];
	cout << endl;
}