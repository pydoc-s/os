//roundrobin
#include<stdio.h>
int TRUE=0;
int FALSE=-1;
int tbt[30],bt[30],tat[30],n=0,wt[30],qt=0,tqt=0,time=0,lmore,t_tat=0,t_wt=0;
void main(){
	int i,j;
	printf("\nEnter processes no.:");
	scanf("%d",&n);
	printf("\nEnter Quantum Time:");
	scanf("%d",&qt);
	for(i=0;i<n;i++){
		printf("Enter birst time of %d:",i+1);
		scanf("%d",&bt[i]);
		tbt[i]=bt[i];
		wt[i]=tat[i]=0;
	}
	lmore=TRUE;
	while(lmore==TRUE){
		lmore=FALSE;
		for(i=0;i<n;i++){
			if(bt[i]!=0)
				wt[i]=wt[i]+(time-tat[i]);
			tqt=1;
			while(tqt<=qt && bt[i]!=0){
				lmore=TRUE;
				bt[i]=bt[i]-1;
				tqt++;
				time++;
				tat[i]=time;
			}
		}
	}
	printf("\nProcsss id\tBurst time\tTurnarroundtime\t waisting\n");	
	for(i=0;i<n;i++){
		printf("Processer%d\t%d\t%d\t%d\n",i+1,tbt[i],tat[i],wt[i]);
		t_tat=t_tat+tat[i];
		t_wt=t_wt+wt[i];
	}
	printf("\nTormal true arroundtime:%d",t_tat);
	printf("\naverage true arroundtime:%d",t_tat/n);
	printf("\toral waiiting time:%d",t_wt);
	printf("\naverage waitingtime:%d",t_wt/n);
}
	
	
				
