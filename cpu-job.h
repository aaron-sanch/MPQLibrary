#ifndef CPU_JOB_H
#define CPU_JOB_H

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
/*
 * CPU_Job holds information for a process to run on the processor
 */
struct CPU_Job {
    int ID;     // process ID
    int length; // process length
    int prior;  // process priority
    CPU_Job(int a = 0, int b = 0, int c = 0) : ID(a), length(b), prior(c) {};
};

/*
 * Operator declarations
 */
bool operator<(const CPU_Job& lhs, const CPU_Job& rhs) {
	if (lhs.prior < rhs.prior) {return 1;}
	else if (lhs.prior > rhs.prior) {return 0;}
	if (lhs.length < rhs.length) {return 1;}
	else if (lhs.length > rhs.length) {return 0;}
	if (lhs.ID < rhs.ID) {return 1;}
	return 0;
}
std::istream& operator>>(std::istream& in, CPU_Job& job){
	int int1;
	int int2;
	int int3;
	in >> int1 >> int2 >> int3;
	CPU_Job job1(int1, int2, int3);
	job = job1;
	return in;
}
std::ostream& operator<<(std::ostream& out, const CPU_Job& job) {
	out << "Job " << job.ID << " with length " << job.length << " and priority " << job.prior;
	return out;
}

#endif