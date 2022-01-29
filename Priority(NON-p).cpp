#include <bits/stdc++.h>
using namespace std;
/***************/
void SortProcesses(int start,int end,int AT[],int PT[],int BT[],string p[]){
			int temp,k=0;
			for(int i=start;i<end;i++){
			for(int j=start+1;j<end-k;j++){
				if(AT[j-1]>AT[j]){
					temp=AT[j-1];
					AT[j-1]=AT[j];
					AT[j]=temp;

					temp=PT[j-1];
					PT[j-1]=PT[j];
					PT[j]=temp;

					temp=BT[j-1];
					BT[j-1]=BT[j];
					BT[j]=temp;

					p[j-1].swap(p[j]);
				}
				else if(AT[j-1]==AT[j]){
					if(PT[j-1]>PT[j]){
					temp=PT[j-1];
					PT[j-1]=PT[j];
					PT[j]=temp;

					temp=BT[j-1];
					BT[j-1]=BT[j];
					BT[j]=temp;

					temp=AT[j-1];
					AT[j-1]=AT[j];
					AT[j]=temp;

					p[j-1].swap(p[j]);
					}
				}
			}
			k++;
		}
}
/**************/
int main(){
		int n;
		cout<<"Enter Number of Processes : "<<endl;
		cin>>n;
		string p[n];
		int AT[n],BT[n],CT[n],WT[n],TAT[n],j,PT[n];
		float sumTAT=0,sumWT=0;
		int i=0;
		while(i<n){
			cout<<i+1<<".Enter Process Name, AT, BT, PT : "; 
			cin>>p[i]>>AT[i]>>BT[i]>>PT[i];
			cout<<endl;
			i++;
		}
		SortProcesses(0,n,AT,PT,BT,p);
			cout<<"Processes Name"<<'\t'<<"AT"<<'\t'<<"BT"<<'\t'<<"PT"<<'\t'<<"CT"<<'\t'<<"TAT"<<'\t'<<"WT"<<endl;
			CT[0]=AT[0]+BT[0];  
			TAT[0]=CT[0]-AT[0];
			WT[0]=TAT[0]-BT[0];
			for(int i=1;i<n;i++){
				j=i;
				if(AT[i]>CT[i-1]){
					while(AT[i]>=AT[j+1])
						j++;
					SortProcesses(i,j,PT,AT,BT,p);
					CT[i]=AT[i]+BT[i];
				}
				else{
					while(CT[i-1]>=AT[j]&&j<n)
						j++;
					SortProcesses(i,j,PT,AT,BT,p);
					CT[i]=CT[i-1]+BT[i];	
				}
				TAT[i]=CT[i]-AT[i];
				WT[i]=TAT[i]-BT[i];
			}
			for(int i=0;i<n;i++){
				sumTAT+=TAT[i];
				sumWT+=WT[i];
				cout<<p[i]<<"              "<<AT[i]<<'\t'<<BT[i]<<'\t'<<PT[i]<<'\t'<<CT[i]<<'\t'<<TAT[i]<<'\t'<<WT[i]<<endl;
			}
			cout<<"Average TAT = "<<sumTAT/n<<" units"<<endl;
			cout<<"Average WT  = "<<sumWT/n<<" units";
		}
