#ifndef UNSORTEDMPQ_H
#define UNSORTEDMPQ_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a vector
 */
using namespace std;
template <typename T>
class UnsortedMPQ: MPQ<T> {
public:
   T remove_min(){
	   if(is_empty()){
		   throw invalid_argument("Queue is empty");
	   }
	   T minimum = v.at(0);
	   int idx = 0;
	   for(int i = 0; i < v.size(); i++) {
		   if(v.at(i) < minimum){ 
			   minimum = v.at(i); 
			   idx = i;
		   }
	   }
	   v.erase(v.begin() + idx);
	   return minimum;
   }
   T min(){
	   if(is_empty()){
		   throw invalid_argument("Queue is empty");
	   }
	   T minimum = v.at(0);
	   for(int i = 0; i < v.size(); i++) {
		   if(v.at(i) < minimum){ minimum = v.at(i); }
	   }
	   return minimum;
   }
   bool is_empty(){
	   if (v.size() == 0) {return 1;}
	   return 0;
   }
   void insert(const T& data){
	   v.push_back(data);
   }
private:
	vector<T> v;
};

#endif