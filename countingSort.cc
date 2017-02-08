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
 * input: vector of naturals that fit into memory
 * output: vector is sorted (<)
 * start, end and middle are always naturals. We could have used unsigend int.
 * Complexity: O(nlog(n))
 */

int get_max_index(vector<int> &A){
	int max_value = A[0];
	for (int i = 0; i < A.size(); ++i){
		if (A[i] > max_value){
			max_value = A[i];
		}
	}
	return max_value;
}

vector<int> _counting_sort(vector<int> &A, int max_value){
	vector<int> B(A.size());
	vector<int> C(max_value, 0);
	for(int i = 0; i < A.size(); ++i){
		++C[A[i]];
	}
	for(int i = 1; i < max_value; ++i){
		C[i] = C[i] + C[i-1];
	}
	for(int i = A.size()-1; i >= 0; --i){
		B[C[A[i]-1]] = A[i];
		--C[A[i]-1];
	}
	return B;
}

vector<int> counting_sort(vector<int> &A){
	int max_value = get_max_index(A);
	return _counting_sort(A, max_value);
}

