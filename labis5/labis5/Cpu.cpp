#include"Cpu.h"
#include <ctime>
Subject CPUssor::SubGen()
{
	srand((unsigned int)time(NULL));
	int pr = rand() % 9 + 1;
	if (pr < (powerQue * 10))
	{
		srand((unsigned int)time(NULL));
		int pr1 = rand() % 9 + 1;
		Subject sub;
		sub.yadr = pr1;
		return sub;
	}
	else
	{
		Subject sub = {};
		sub.yadr = 0;
		return sub;
	}
}
void CPUssor::Wait(Queue<Subject>& q2ue, CPU& cpu, int Time)
{
	for (int i = 0; i < Time; i++)
	{
		if (!q2ue.EVFull())
		{
			Subject sub1;
			sub1 = SubGen();
			if (sub1.yadr != 0)
			{
				q2ue.EVPut(sub1);
			}
		}
		else
		{
			errorque++;
		}
		if (q2ue.EVEmpty())
		{
			waitQue++;
		}
		else
		{
			for (int i = 0; i < q2ue.EVSize(); i++)
			{
				Subject sub2;
				sub2 = q2ue.EVCheck();
				if (sub2.yadr <= cpu.cpuCPU)
				{
					cpu.cpuCPU -= sub2.yadr;
					cpu.cpus.push_back(sub2);
					countTask++;
					q2ue.EVGet();
					continue;
				}
				else
				{
					if (sub2.yadr > cpu.cpuCPU)
					{
						errorcpu++;
						q2ue.EVGet();
					}
					else
						break;
				}
			}
		}

		if (cpu.cpus.size() != 0)
		{
			int i = 0;
			for (i; i < cpu.cpus.size(); i++)
			{
				cpu.cpus[i].tact++;
				srand((unsigned int)time(NULL));
				int pr = rand() % 9 + 1;
				if ((double)pr / 10 < powerCPU)
				{
					Subject sub2;
					sub2 = cpu.cpus[i];
					if (sub2.tact == 1)
					{
						continue;
					}
					done++;
					cpu.cpus.erase(cpu.cpus.begin() + i);
					cpu.cpuCPU += sub2.yadr;
					CycleCount += sub2.tact;
				}
			}
		}
		else
		{
			waitCPU++;
		}
	}
	Output(countTask, waitQue, waitCPU, Time, done, CycleCount);
}
void CPUssor::Work(int _sizeq, int _time, int _yadr, double _powercpu, double _powerque)
{
	CPU cpu;
	cpu.cpuCPU = _yadr;
	Time = _time;
	size = _sizeq;
	powerCPU = _powercpu;
	powerQue = _powerque;
	Queue<Subject> q2ue(size);
	Wait(q2ue, cpu, Time);
}
void CPUssor::Output(int countTask, int waitQue, int waitCPU, int time, int done, int CycleCount)
{
	cout << "INFO:" << endl;
	cout << "number of subjects: " << countTask << endl;
	if (countTask != 0)
		cout << "number of refuses: " << (waitQue * 100 / countTask) << "%" << endl;
	else
		cout << "number of refuses: " << 0 << endl;
	cout << "empty (without any result or actions) step: " << (waitCPU * 100 / time) << "%" << endl;
	if (done != 0)
		cout << "time of doing subject: " << (double(time - waitCPU) / double(done)) << endl;
	else
		cout << "time of doing subject: " << 0 << endl;
	cout << "subject completed: " << done << endl;
	cout << "all cycles: " << CycleCount << endl;
}