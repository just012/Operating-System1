
#include<stdio.h> 
 
int main() 
{ 
      int i, N, total = 0, x, counter = 0, TIME_QUANTUM; 
      int sum=0,p;
	  
	  int WAIT = 0, TAT = 0, ART[10], BRT[10], M[10],priority[20],m[20]; 
      
	  float AVG_WAIT, AVG_TAT;
      printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &N); 
      x = N; 
      for(i = 0; i < N; i++) 
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
         
		    printf("Arrival Time:\t");
         
		    scanf("%d", &ART[i]);
         
		    printf("Burst Time:\t");
         
		    scanf("%d", &BRT[i]);
			
			printf("Priority:\t");
            
			scanf("%d",&priority[i]); 
            
            sum= sum+BRT[i];
      }   
		
     
	
		
		p = sum/N;
		printf("AVG of Burst Time : %d\n",p);
		for(i=0;i<N;i++)
		{
			M[i]=BRT[i]%p;
		}
		
		
		
		
		TIME_QUANTUM=p;
		printf("Time Quantum is : %d\n\n",TIME_QUANTUM);
	
		printf("\nProcess ID\tArrival Time\t\tBurst Time\t Priority\t\t Turnaround Time\t Waiting Time\n");
      
	
	  for(total = 0, i = 0; x != 0;) 
      { 
     
           
		    if(M[i] <= TIME_QUANTUM && M[i] > 0) 
            { 
                  total = total + M[i]; 
                  M[i] = 0; 
                  counter = 1; 
            } 
            else if(M[i] > 0) 
            { 
                  M[i] = M[i] - TIME_QUANTUM; 
                  total = total + TIME_QUANTUM; 
            } 
            if(M[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t%d\t\t\t%d\t\t %d\t\t\t %d\t\t\t%d", i + 1,ART[i], BRT[i],priority[i], total - ART[i], total - ART[i] - BRT[i]);
                  WAIT = WAIT + total - ART[i] - BRT[i]; 
                  TAT = TAT + total - ART[i]; 
                  counter = 0; 
            } 
            if(i == N - 1) 
            {
                  i = 0; 
            }
            else if(ART[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
	
      AVG_WAIT = WAIT * 1.0 / N;
      
	  AVG_TAT = TAT * 1.0 / N;
      
	  printf("\n\nAVG Waiting Time:\t%f", AVG_WAIT); 
      
	  printf("\nAvg Turnaround Time:\t%f\n", AVG_TAT); 
      return 0; 
}
