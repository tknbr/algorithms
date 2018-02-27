/**
 * Implemented by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github collection: https://github.com/tknbr/algorithms
 */

#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int> &A, int pos1, int pos2){
    int aux = A[pos1];
    A[pos1] = A[pos2];
    A[pos2] = aux;
}

/**
 * input: vector of integers that fit into memory
 * output: vector is sorted (<)
 * Complexity: O(n^2)
 */

void bubble_sort(vector<int> &v){
    int n = v.size();
    for(int i=0; i<n-1; ++i){
        for(int k=0; k<n-1-i; ++k){
            if(v[k]>v[k+1]){
                swap(v, k, k+1);
            }
        }
    }
}