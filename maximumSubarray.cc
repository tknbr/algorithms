#include <vector> //vector
#include <iostream> //couts

using namespace std;

/**
 * input: vector with dif values (integers)
 * output: maximum subarray from input vector
 * Complexity: O(nlog(n))
 */

struct result {
	int high;
	int low;
	int sum;
};

result max_crossing(vector<int> &A, int left, int right){
	int half = (left+right)/2;

	/* We first search in the left half */
	int sum_l = A[half];
	int max_l = A[half];
	int max_l_index = half;
	for(int i = half-1; i >= left; --i){
		sum_l += A[i];
		if( sum_l > max_l ){
			max_l = sum_l;
			max_l_index = i;
		}
	}

	/* Right half search */
	int sum_r = A[half+1];
	int max_r = A[half+1];
	int max_r_index = half+1;
	for (int i = half+2; i <= right; ++i){
		sum_r += A[i];
		if (sum_r > max_r){
			max_r = sum_r;
			max_r_index = i;
		}
	}

	result r;
	r.high = max_r_index;
	r.low = max_l_index;
	r.sum = max_r + max_l;
	return r;
}

result max_subarray(vector<int> &A, int left, int right){
	int half = (left+right)/2;
	if (left == half and half == right){
		result r;
		r.high = left;
		r.low = left;
		r.sum = A[left];
		return r;
	}

	result r_l = max_subarray(A, left, half);
	result r_r = max_subarray(A, half+1, right);
	result r_c = max_crossing(A, left, right);

	if (r_l.sum >= r_r.sum  and r_l.sum >= r_c.sum)
		return r_l;
	if (r_r.sum >= r_c.sum)
		return r_r;
	return r_c;
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
	vectorToSort.push_back(-22);
	vectorToSort.push_back(15);
	vectorToSort.push_back(-4);
	vectorToSort.push_back(7);
	result r = max_subarray(vectorToSort, 0, vectorToSort.size()-1);
	cout << "max sum: " << r.sum << endl;
	cout << "left index: " << r.low << endl;
	cout << "right index: " << r.high << endl;
}