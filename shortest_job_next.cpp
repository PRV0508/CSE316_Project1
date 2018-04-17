/*AIM
               To simulate CPU scheduling, using Shortest Job First(SJF) Scheduling algorithms.

               

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

