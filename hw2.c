#include<stdio.h>
#include<math.h>
#include<stdlib.h>


void menu();
int make_a_guess (int trial, int min, int max);
void show_scores(int score_human, int score_program);
void draw_hourglass (int height);
void draw_mountain_road (int length, int max_radius);
void limits(int distance);


int main(){
	
	menu();	
}


int make_a_guess (int trial, int min, int max){
	int guess;
	printf("Trial:%d  Make a guess between %d and %d: ",trial,min,max);       scanf("%d",&guess);
	 return guess; 	
}


void show_scores(int score_human, int score_program){
	printf("YOUR SCORE: %d PROGRAM SCORE: %d\n\n",score_human,score_program);	
}


void limits(distance){
	if(distance <=1023  &&  distance >=512 )
	    printf("Distance: 10\n");
	else if(distance <=511  &&  distance >=256 )
	    printf("Distance: 9\n");
	else if(distance <=255  && distance>=128 )
	    printf("Distance: 8\n");
	else if(distance <=127  && distance >=64 )
	    printf("Distance: 7\n");
	else if(distance<=63  &&  distance >=32 )
	    printf("Distance: 6\n");
	else if(distance <=31 &&  distance >=16 )
	    printf("Distance: 5\n");
	else if(distance <=15  &&  distance >=8 )
	    printf("Distance: 4\n");
	else if(distance <=7  &&  distance>=4 )
	    printf("Distance: 3\n");
  	else if(distance<=3 &&  distance >=2 )
	    printf("Distance: 2\n");
    else if(distance==1   )
	   printf("Distance: 1\n");
}

void menu(){
	int secim,trial=5,min=1,max=1024,height,N,R,flag=1,target,guess;
	int i,human=0,program=0,distance;
	srand(time(NULL));
	
	
	  
	while(flag!=0 ){
		
	printf("***** MENU *****\n");
	printf("1. Play Lucky Number\n");		
	printf("2. Draw Hourglass\n");
    printf("3. Draw Mountain Road\n");
	printf("4. Exit\n");
	printf("Choice:\t");
	scanf("%d",&secim);
	

        switch(secim){
	    	
		case 1:
		  target=rand()%1024+1;
		  printf("target:%d\n",target);                  //sonradan çýkar
		  guess=make_a_guess (1,min,max);
		  distance=abs(guess-target);
		  limits(distance);
		  
		  for(i=1;i<=trial;i++){
			
			
			
			
	       if(target != guess   && i<trial){
		   	
		   	  if(target>guess){
		   	  	guess=make_a_guess(i+1,guess,max);
		   	  	limits(distance);
			 }
		   	    
		   	
		   	  else{
		   	  	guess=make_a_guess(i,min,guess);
		   	  	limits(distance);
		    }
		}
		   
		   
	       else if(target==guess && i<trial){
	       	printf("Distance: 0 You win!\n");
	       	human++;
	       	show_scores(human,program);
	       	break;
	       	
		   }
		  
	}
		   
		  if(target!=guess  && i>=trial){
		   	  program++;
		   	  show_scores(human,program);
			  break;		
	   }
		break;
			
			
			
		case 2:
			printf("please enter the height\n");            scanf("%d",&height);
		    draw_hourglass(height);
		    break;
		
	
		case 3:
			printf("please enter the N number:\n");         scanf("%d",&N);
			printf("please enter the R number:\n");         scanf("%d",&R);
			draw_mountain_road (N, R);	
			break;
		
		case 4:
			flag=0;
			break;
			
		default:
		   printf("This is an invalid choice. Try again!\n");
	       break;
		}		
	}
}	  	



void draw_hourglass (int height){
   int i,j,k,yildizsayisi,bosluksayisi,temp;
   
    if(height%2==0){
	   while(height%2==0){
	      printf("error!please enter the height\n");         scanf("%d",&height);
		}		
	}
	
   	temp=height;
	yildizsayisi=temp;
	bosluksayisi=0;
   	
	for(i=0; i<height; i++){

        for(j=0; j<yildizsayisi;j++)
            printf("*");        
 
        if( i < (height / 2) ){
            yildizsayisi-=2;
            bosluksayisi++;
        }
        
        else{
            yildizsayisi+=2;
            bosluksayisi--;
		}      

        printf("\n");
    	for(j=0; j<bosluksayisi;j++)    
          printf(" "); 
    }
    printf("\n");
}



void draw_mountain_road (int length, int max_radius){
	int i,j,k,bosluk,r;
	
	for(i=0;i<length;i++){                  //N  sayýsýkadar dönecek
		r=rand()%max_radius;
		
		if(i%2==0){                         //0 2 4 6 sarýrlarýnda
		  
		  bosluk=max_radius;
		  for(j=0;j<(2*r)+1;j++){			//her bir r için 2n+1 satýr
		  
		   if(j<r){                    //üst satýrlar
		  	
			for(k=0; k<bosluk;k++)
			  printf(" ");
			  
			  printf("/\n");
			  bosluk--;
		}
		 
		 
		  else if(j==r){               //orta satýr
		    
		  	for(k=0; k<bosluk;k++)
			  printf(" ");
			  
			  printf("|\n");
			  bosluk++;	
		  }	
		  
		  else{                       //alt satýrlar
		    for(k=0; k<bosluk;k++)
			  printf(" ");
			  
			  printf("\\\n");
			  bosluk++;
		  }
	   }
	}
		

		else{                              // 1 3 5 7 satýrlarýnda                    
		  bosluk=max_radius+1;
		  for(j=0;j<(2*r)+1;j++){			//her bir r için 2n+1 satýr
		  
		  
		  if(j<r){                    //üst satýrlar
		  	
			for(k=0; k<bosluk;k++)
			  printf(" ");
			  
			  printf("\\\n");
			  bosluk++;
		}
		 
		 
		  else if(j==r){               //orta satýr
		    
		  	for(k=0; k<bosluk;k++)
			  printf(" ");
			  
			  printf("|\n");
			  bosluk--;	
		  }	
		  
		  else{                       //alt satýrlar
		    for(k=0; k<bosluk;k++)
			  printf(" ");
			  
			  printf("/\n");
			  bosluk--;
		  }
	   }
	}	
  } 	
}

