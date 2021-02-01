#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/*
 * Binary Heap class
 */
template <typename T>
class BinaryHeap {
    public:
        void insert(const T& data){
			if(is_empty()){
				elements.push_back(data);
				size++;
				return;
			}
			elements.push_back(data);
			size++;
			if(data < elements.at(parent(size - 1))) {
				up_heap(size - 1);
			}
		}
        bool is_empty() {
			if (size == 0) {return 1;}
			return 0;
		}
        T min(){ 
			if (is_empty()) {
				throw invalid_argument("Empty Heap");
			}
			return elements.at(0);
		}
        T remove_min(){
			T minimum = min();
			if(elements.size() == 1) {
				elements.pop_back();
				size--;
				return minimum;
			}
			//swap(elements.at(0), elements.at(size - 1));
			T temp = elements.at(size - 1);
			elements.at(size - 1) = elements.at(0);
			elements.at(0) = temp;
			elements.pop_back();
			size--;
			down_heap(0);
			return minimum;
		}
		void print_heap() {
			for(int i = 0; i < size; i++) {
				cout << elements.at(i) << " ";
			}
			cout << endl;
		}
    private:
        std::vector<T> elements;
        int size = 0;
        void down_heap(int i);
        void up_heap(int i);

        //Pre-implemented helper functions
        void swap(int a, int b) { T c(elements[a]); elements[a] = elements[b]; elements[b] = c;}
        int right_child(int i) {return 2*i + 2;}
        int left_child(int i) {return 2*i + 1;}
        int parent(int i) {return floor((i-1)/2);}
        bool is_internal(int i) {return left_child(i) < size || right_child(i) < size;}
        bool is_leaf(int i) {return left_child(i) >= size && right_child(i) >= size;}
};

/*
 * Restores the binary heap property starting from a node that is smaller than its parent
 * O(log n)
 */
template <typename T>
void BinaryHeap<T>::up_heap(int i){
    int parent_index = parent(i);
	T temp;
    /*
     * Can be computed iteratively or recursively
     */
	while(elements.at(i) < elements.at(parent(i))){
		temp = elements.at(parent(i));
		elements.at(parent(i)) = elements.at(i);
		elements.at(i) = temp;
		i = parent(i);
	}
}

/*
 * Restores the binary heap property starting from an node that is larger than its children
 * O(log n)
 */
template <typename T>
void BinaryHeap<T>::down_heap(int i){
    int right_index = right_child(i);
    int left_index = left_child(i);
	if(left_index >= size || i >= size) {
		return;
	}
    /*
     * Can be computed iteratively or recursively
     */
	if (right_index < size && (elements.at(left_index) < elements.at(i) || elements.at(right_index) < elements.at(i))) {
		if(elements.at(left_index) < elements.at(right_index)) {
			T temp = elements.at(left_index);
			elements.at(left_index) = elements.at(i);
			elements.at(i) = temp;
			down_heap(left_index);
		}
		else if(elements.at(right_index) < elements.at(left_index)) {
			T temp = elements.at(right_index);
			elements.at(right_index) = elements.at(i);
			elements.at(i) = temp;
			down_heap(right_index);              
		}
	}
	else if(elements.at(left_index) < elements.at(i)) {
		T temp = elements.at(left_index);
		elements.at(left_index) = elements.at(i);
		elements.at(i) = temp;
		down_heap(left_index);
	}
}
#endif