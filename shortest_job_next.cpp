/*AIM
               To simulate CPU scheduling, using Shortest Job First(SJF) Scheduling algorithms.
 

Program Description:
 
              
			 Shortest Job First is a non-preemptive Scheduling discipline in which 
the waiting job with the smallest estimated run-time-to completion is run next. It depicts the 
order in which the processes are executed, calculates the turnaround time and average waiting time of the
processes based on burst time for SJF scheduling.
 

Algorithm:


1.      Start of algorithm.

2.      Declare the required variables

3.      Get the process name, and burst time for each process.

4.      Arrange the processor in ascending order according to the lowest burst time

5.      Calculate the average waiting time and average turn around time using the following formulas.
                   
	Average Waiting Time = (wt1+wt2+…+wtn) / n where 
                
	Average turn around time = ((wt1+wt2+…+wtn) + (bt1+bt2+…+btn)) / n

6.      Print the Process name, average waiting time and average turnaround time for each process.           

7.      Terminate the program.
               

//Program : Shortest Job First Scheduling Algorithm   */

#include<iostream>
using namespace std;
int main()
{
	int no_of_process , i ,j , Average_waiting_time = 0;
	float Avarage_turnaround_time = 0 ,temp;
	int brust[10], wait[10], process[10];
	cout<<"\nProcess Scheduling based on wating time : \n"<<endl;
	cout<<"Enter the number of process : ";
	cin>>no_of_process;

	for(i=0;i<no_of_process;i++)
	{   cout<<"Enter the Brust time for process "<<i+1<<" : ";
		cin>>brust[i];
		process[i] = i;
        cout<<endl;
	}
	
	for(i=0;i<no_of_process;i++)
	{
		for(j=i;j<no_of_process;j++)
		{
			if(brust[i] > brust[j] )
			{
				temp = brust[i];
				brust[i] = brust[j];
				brust[j] = temp;
				temp = process[i];
				process[i] = process[j];
				process[j] = temp;
			}
		}
	}
	
	cout<<"\n\t\tWaiting Time\t|\tTurn around Time"<<endl;
	j=0;
	for(i=0;i<no_of_process;i++)
	{
		wait[i] = j ;
		j = brust[i] + j ;
		cout<<"\nProcess "<<process[i]<<"\t\t"<<wait[i]<<"\t\t"<<wait[i] + brust[i]<<endl;
		Average_waiting_time += wait[i];
		Avarage_turnaround_time +=wait[i] + brust[i];
	}
	
	
	cout<<endl<<endl;
	cout<<"Avarage waiting time : "<<Average_waiting_time/(float)no_of_process<<endl;
	cout<<"Avarage turn around time : "<<Avarage_turnaround_time/(float)no_of_process;
	
}

