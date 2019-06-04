#include<iostream>
#include<cmath>
using namespace std;
/*****************************************************************************************************************************************************************/
//                         First Come First Serve  
void FCFS_Case1(int n){
	int bst[n] , WT[n] , TA[n];
	float Wavg=0,Tavg=0,Ws=0,Ts=0;
	
	for(int i=1; i<=n; i++){
		cout<<"Burst Time["<<i<<"] = ";
		cin>>bst[i];
	}
	cout<<"\n\t<------- result------->\t\n";
	
	for(int j=0; j<n; j++){
		
		if(j<=0){
			WT[j]=0;
			TA[j]=bst[j];
		}else{
			WT[j]=WT[j-1]+bst[j-1];
			TA[j]=TA[j-1]+bst[j];
		}
		
		Ws=Ws+WT[j];  Ts=Ts+TA[j];
		Wavg=Ws/n;	Tavg=Ts/n;
	}
	cout <<"\n\nPROCESS \t\t BURST TIME \t\t\t WAIT TIME\t\t   Turnaround TIME\n";
	for (int i=0;i<n;i++){
		cout << "\nP[" << i + 1 << "]" << "\t\t" << bst[i] << "\t\t"  <<
		 "\t\t" << WT[i] << "\t\t"<< "\t" << TA[i];
	}
	
	cout<<"\n\nAvarage Waiting time = "<<(Wavg)<<"\t";
	cout<<"\n\nAvarage Turnaround time = "<<(Tavg)<<"\n";
}
/*****************************************************************************************************************************************************************/
//                                          FIRST COME FIRST SERVE SECOND CASE 
/*
void FCFS_Case2(int n){

	int bst[n] , AT[n] , WT[n] , TA[n] , ST[n];
	
	float Wavg=0,Tavg=0,Ws=0,Ts=0,tmp1=0,tmp2=0;
	
	for(int i=0; i<n; i++){
		cout<<"Process["<<i+1<<"] = ";
		cin>>bst[i]>>AT[n];
	}
	cout<<"\n\t\t<------- result------->\n\n";
		cout <<"\n\nPROCESS\t  BURST TIME \t\t\t WAIT TIME\t\t\tTurnaround TIME\n";
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(i<=0){
				WT[i]=0;
				TA[i]=bst[i];
			}	
			else if(AT[j] > AT[i]){
				tmp1=AT[i];
				AT[i]=AT[j];
				AT[j]=tmp1;
				tmp1=bst[i];
				bst[i]=bst[j];
				bst[j]=tmp1;
				}
			}
								
				WT[i]=WT[i-1]+bst[i-1];
				TA[i]=WT[i]+bst[i];
				//ST[i]=WT[i]-AT[i];
		
		Ws=Ws+WT[i];  Ts=Ts+TA[i];
		Wavg=Ws/n;	Tavg=Ts/n;
		
		cout << "\nP[" << i + 1 << "]" << "\t\t" << bst[i] << "\t\t" << "\t\t" << WT[i] << "\t\t"<< "\t" << TA[i];
	}
	
	cout<<"\n\nAvarage Waiting time = "<<(Wavg)<<"\t";
	cout<<"\n\nAvarage Turnaround time = "<<(Tavg)<<"\n";
}
*/
/*****************************************************************************************************************************************************************/
///                                             Shortest Job First nonPreemtive                           ////
void SJF_NonPreemptive(int n){
	
	int bst[n] , WT[n] , TA[n] , AT[n];
	int tmp1=0,tmp2=0;
	float Wavg=0,Tavg=0,Ws=0,Ts=0;
	
	for(int i=0; i<n; i++){
		cin>>bst[i]>>AT[i];
	}

	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(i<=0){
				WT[i]=0;
				TA[i]=bst[0];
			}
			else if(bst[i] > bst[j]){
				tmp1=bst[i];
				tmp2=AT[i];
				bst[i]=bst[j];
				AT[i]=AT[j];
				bst[j]=tmp1;
				AT[j]=tmp2;
					}
				}
				WT[i]=WT[i-1]+bst[i-1];
				TA[i]=WT[i]+bst[i];
				
				Ws+=WT[i];  Ts+=TA[i];
				Wavg=Ws/n;	Tavg=Ts/n;
			}
			
		cout <<"\n\nPROCESS\t  BURST TIME \tARRIVAL TIME\t\tWAIT TIME \t\tTurnaround TIME\n";
	 	for (int i=0;i<n;i++){
        	cout << "\nP[" << i + 1 << "]" << "\t\t" << bst[i] << "\t\t" << AT[i] << "\t\t" << WT[i] << "\t\t"<< "\t" << TA[i];
      	}
	cout<<"\n\n";
	cout<<"Avrage of Wating Time is : "<<(Wavg)<<"\n";
	cout<<"Avrage of Turnaround Time is : "<<(Tavg);
}
/*****************************************************************************************************************************************************************/
///                                             Shortest Job First Preemtive                           ////
void SJF_Preemptive(){
		int n=0,tmp1=0,tmp2=0;
	cout<<"Enter Number Process : ";
	cin>>n;
	int bst[n] , WT[n] , TA[n] , AT[n] , bst2[n];
	
		for(int i=0; i<n; i++){
		cout<<"Process["<<i+1<<"] = ";
		cin>>bst[i]>>AT[i];
	}
	cout<<"\n\t\t<------- result------->\n\n";
		cout <<"\n\nPROCESS\t  BURST TIME \t\t\t WAIT TIME\t\t\tTurnaround TIME\n";
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
	
			if(AT[j] > AT[i]){
				tmp1=bst[i];
				tmp2=AT[i];
				bst[i]=bst[j];
				AT[i]=AT[j];
				bst[j]=tmp1;
				AT[j]=tmp2;
				}
			else if(i<=0){
				WT[i]=0;
				TA[i]=AT[i+1];
				bst2[i]=abs(abs(AT[i]-AT[i+1])-bst[i]);
				}
			}
			WT[i]=TA[i-1];
			TA[i]=bst[i];
			bst2[i]=abs(abs(AT[i]-AT[i+1])-bst[i]);
			if(bst[i]==0){
				if(bst2[i]<bst[i]){
					tmp1=bst2[i]; 
					bst2[i]=bst2[i];
					bst2[i]=tmp1;
				}
			WT[i]=TA[i-1];
			TA[i]=bst[i];
			bst2[i]=abs(abs(AT[i]-AT[i+1])-bst[i]);
			}
		cout << "\nP[" << i + 1 << "]" << "\t\t" << bst[i] << "\t\t" << "\t\t" << WT[i] << "\t\t"<< "\t" << TA[i];
	}
}
/*****************************************************************************************************************************************************************/
void CPU_Schedual(){
	cout<<"if you want First Come First Job Enter 1 \n\nif you want Shortest Job First Enter 2 \n\n";
	
	int nm=0; cin>>nm; 
	int sz=0;
	int sel=0;

	if(nm==1){
		cout<<"if You Want FCFS_Case 1 -> Enter 1 \n\nif you want FCFS_Case 2 -> Enter 2 \n\n";
		cin>>sel;
		if(sel==1){
			cout<<"Enter Number of Process : ";
			cin>>sz;
			FCFS_Case1(sz);
		}
		else if(sel==2){
			cout<<"Enter Number of Process : ";
			cin>>sz;
			FCFS_Case2(sz);
			}
		else{}
	}
	
	if(nm==2){
		cout<<"if You Want Preemptive Enter 1 \n\nif you want Non_Preemptive Enter 2 \n\n";
		cin>>sel;
		if(sel==1){
			
			cout<<"Enter Number of Process : ";
			cin>>sz;
			SJF_Preemptive();
	
		}
		else if(sel==2){
			cout<<"Enter Number of Process : ";
			cin>>sz;
			SJF_NonPreemptive(sz);
		}
		else{}
	}
}

int main(){
	cout<<"\t\t\t\t\t Welcome in the CPU Scheduling Algorithms\n\n";
	CPU_Schedual();
	return 0;
}
