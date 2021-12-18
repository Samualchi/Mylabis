#include <iostream>
#include <string>
#include "Cpu.h"
using namespace std;

int main()
{
	int Qsize, time, cores;
	double powerCPU, powerQue;
	Qsize = 100;//size queue
	cores = 4; //cores
	powerCPU = 2;//sposobnost/power cpu
	powerQue = 2;//power queue
	time = 2;//time
	CPUssor cpussor1;
	cpussor1.Work(Qsize, time, cores, powerCPU, powerQue);
	return 0;
}