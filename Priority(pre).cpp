#include <bits/stdc++.h>
using namespace std;
/***************/
void SortProcesses(int start,int end,int AT[],int PT[],int BT[],string p[],int CBT[],int ST[]){
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

					temp=CBT[j-1];
					CBT[j-1]=CBT[j];
					CBT[j]=temp;

					temp=ST[j-1];
					ST[j-1]=ST[j];
					ST[j]=temp;


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

					temp=CBT[j-1];
					CBT[j-1]=CBT[j];
					CBT[j]=temp;

					temp=ST[j-1];
					ST[j-1]=ST[j];
					ST[j]=temp;


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
		int AT[n],BT[n],CT[n],WT[n],TAT[n],j,CBT[n],temp,ST[n],PT[n];
		float sumTAT=0,sumWT=0,sumBT=0;
		int i=0;
		while(i<n){
			cout<<i+1<<".Enter Process Name, AT, BT ,PT : "; 
			cin>>p[i]>>AT[i]>>BT[i]>>PT[i];
			cout<<endl;
			sumBT+=BT[i];
			CBT[i]=BT[i];
			ST[i]=-1;
			i++;
		}
		SortProcesses(0,n,AT,PT,BT,p,CBT,ST);
		int curr_time=0;
		i=0;
		while(i!=n){
			if(BT[i]==0)
				i++;
			if(ST[i]=-1)
				ST[i]=curr_time;

			curr_time+=1;
			BT[i]-=1;

			if(BT[i]==0){
				CT[i]=curr_time;
				TAT[i]=CT[i]-AT[i];
				WT[i]=TAT[i]-CBT[i];
			}
				j=i;
				while(AT[j]<=curr_time&&j<n)
					j++;
				SortProcesses(i,j,PT,AT,BT,p,CBT,ST);
	   }
	   cout<<"Processes Name"<<'\t'<<"AT"<<'\t'<<"BT"<<'\t'<<"PT"<<'\t'<<"CT"<<'\t'<<"TAT"<<'\t'<<"WT"<<endl;
			for(int i=0;i<n;i++){
				sumTAT+=TAT[i];
				sumWT+=WT[i];
				cout<<p[i]<<"              "<<AT[i]<<'\t'<<CBT[i]<<'\t'<<PT[i]<<'\t'<<CT[i]<<'\t'<<TAT[i]<<'\t'<<WT[i]<<endl;
			}
			cout<<"Average TAT = "<<sumTAT/n<<" units"<<endl;
			cout<<"Average WT  = "<<sumWT/n<<" units";
}
