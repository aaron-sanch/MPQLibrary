#ifndef SORTEDMPQ_H
#define SORTEDMPQ_H

#include <stdexcept>
#include <iostream>
#include <list>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a linked list
 */
 using namespace std;
template <typename T>
class SortedMPQ: MPQ<T> {
public:
   T remove_min() {
	   if(is_empty()){
		   throw invalid_argument("Queue is empty");
	   }
	   T small = ll.front();
	   ll.erase(ll.begin());
	   return small;
   }
   T min() {
	   if(is_empty()){
		   throw invalid_argument("Queue is empty");
	   }
	   return ll.front();
   }
   bool is_empty() {
	   if (ll.size() == 0) {return 1;}
	   return 0;
   }
   void insert(const T& data) {
	   if(is_empty()) {
	      ll.push_front(data);
		  return;
	   }
	   auto ite = ll.begin();
	   for(auto const& i : ll) {
		   if(data < i) {
			   break;
		   }
		   ite++;
	   }
	   ll.insert(ite, data);
   }
private:
	list<T> ll;
};

#endif