#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

#define PI 3

#define SQUARE 1
#define RECTENGULAR 2
#define CIRCULAR 3
#define RED 0
#define YELLOW 1
#define BLUE 2
#define BLACK 3
#define WHITE 4

double CreateBody (int shape);
int SetColor (int color);
double LoadMoves(int shape, double size_of_body);
int SetAttackPower(int lower_bound, int upper_bound) ;
void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power);


int main(){
	int shape, color, attack_power;    
	double size_of_body, move_length;
	  
	shape = CIRCULAR;
	size_of_body = CreateBody (shape);
	color = 798;										
	color = SetColor(color);
	move_length = LoadMoves(shape, size_of_body);
	attack_power = SetAttackPower (0, 150);
	ShowPokemon(shape, size_of_body, color, move_length, attack_power);  
}


double CreateBody (int shape){
	int edge,square_area,long_edge,short_edge,rectangular_area;
	double radius,circular_area;
	
	if(shape==1){
		printf("please enter the side length for the square:\t");
		scanf("%d",&edge);
		
		square_area=edge*edge;
		return square_area;
	}
	
	if(shape==2){
		printf("please enter the long edge  for the rectangular:\t");
		scanf("%d",&long_edge);
		printf("please enter the short edge  for the rectangular:\t");
		scanf("%d",&long_edge);
		
		rectangular_area=short_edge*long_edge;
		return rectangular_area;
	}
	
	
	if(shape==3){
		printf("please enter the radius  for the circular:\t");
		scanf("%lf",&radius);
		
		circular_area= PI*radius*radius;
		return circular_area;
	}	
}


int SetColor (int color){
	
	if(color<=1000 && color>=0)
		return color%5;
	
	else
		return 1;
}


double LoadMoves(int shape, double size_of_body){
	double radius;
	
	if(shape==1){
		return 4*sqrt(size_of_body);	
	}
	
	if(shape==2){
		return 2*5+2*(size_of_body/5);
	}
	
	if(shape==3){
		radius=sqrt(size_of_body/PI);
		
		return 2*PI*radius;	
	}
}



int SetAttackPower(int lower_bound, int upper_bound){
	int power ;
	
	srand(time(NULL));
	power=lower_bound+rand()%upper_bound;
	return power;	
}



void ShowPokemon(int shape, double size_of_body, int color, double move_length, int attack_power){
	int i,j,edge,long_edge,short_edge=5;
	
	if(shape==1){
		edge=move_length/4;
		
		for(i=0;i<edge;i++){
			for(j=0;j<edge;j++){
				printf("X");	
			}
			printf("\n");
		}
		
		printf("name:square pokemon\nsize:%.0lf\n",size_of_body);
		
		if(color==0)
			printf("color:red\n");
		if(color==1)
			printf("color:yellow\n");
		if(color==2)
			printf("color:blue\n");
		if(color==3)
			printf("color:black\n");
		if(color==4)
			printf("color:white\n");
		
		printf("move:%.0lf\nattack power:%d\n",move_length,attack_power);
	}
	
	
	if(shape==2){
		long_edge=size_of_body/5;
			
		for(i=0;i<short_edge;i++){
			for(j=0;j<long_edge;j++){
				printf("X");	
			}
			printf("\n");
		}	
		
	   printf("name:rectangular pokemon\nsize:%.0lf\n",size_of_body);
		
		if(color==0)
			printf("color:red\n");
		if(color==1)
			printf("color:yellow\n");
		if(color==2)
			printf("color:blue\n");
		if(color==3)
			printf("color:black\n");
		if(color==4)
			printf("color:white\n");
		
		printf("move:%.0lf\nattack power:%d\n",move_length,attack_power);
	}
	
	
	if(shape==3){
		int i=0,j=0,k=0,t=0,satir=0,radius,tabsayisi,secondtab;
		
		radius=(move_length)/(2*PI);
		radius=(int)radius;
			
		if(radius==1){         //r=1 ise
			printf("X\n");	
		}
				
				
		else{                    //r 1 den farklýysa
			
		  if(radius%2==0){                 //r çift 
		
			for(satir=0;satir<3;satir++){
				
			  if(satir==0){                            //ilk ve son satir
				tabsayisi=(radius/2)-1;
				for(i=0;i<tabsayisi;i++) 
					printf("\t");
							
				printf("    X\n");	
				}
				
			  if(satir==1){                              //ara satýrlar
				secondtab=1;
				tabsayisi=(radius/2)-1;

				for(t=1; t< radius/2  ;t++){           //üst satýrlar
							
				  for(i=0;i<tabsayisi;i++)
					printf("\t");
			      printf("X");
							
				  for(k=0;k<secondtab;k++)
					printf("\t");
				  printf("X");
				  printf("\n");
							
				  tabsayisi--;
				  secondtab=secondtab+2;					
				}
						
						
			  if(t==radius/2){                 //orta satýr
				tabsayisi=radius-1;
				printf("X");
			    for(i=0;i<tabsayisi;i++)
					printf("\t");
				printf("X\n");	
			}
					
			  tabsayisi=1;
			  secondtab=radius-3;
							
			  for(j=(radius/2)+1; j< radius  ;j++){     //alt satýrlar
								
				for(i=0;i<tabsayisi;i++)
				  printf("\t");
				printf("X");
								
				for(k=0;k<secondtab;k++)
				  printf("\t");
				printf("X");
				printf("\n");
				
				tabsayisi++;
				secondtab=secondtab-2;		
			  }	
		  }
						
			  if(satir==2){     
				tabsayisi=(radius/2)-1;
				for(i=0;i<tabsayisi;i++) 
					printf("\t");
									
				printf("    X\n");	
		    }	  
		}			
	}
			
		  else{                             //r tek
				
		    for(satir=0;satir<3;satir++){             //satirlar 
				
			  if(satir==0){                            //r tekken   ilk ve son satir    
				tabsayisi=(radius/2);
				for(i=0;i<tabsayisi;i++) 
				   printf("\t");
						
			    printf("X\n");	
				}
				
			  if(satir==1){                              //ara satýrlar
				secondtab=2;
				tabsayisi=radius/2;
					
				for(t=1; t< radius/2  ;t++){           //üst satýrlar
						
				  for(i=1;i<tabsayisi;i++)
					printf("\t");
				  printf("X");
						
						
				  for(k=0;k<secondtab;k++)
					printf("\t");
				  printf("X");
						
				  printf("\n");
						
				  tabsayisi--;
				  secondtab=secondtab+2;					
					}
					
					
			  if(t==radius/2){                 //orta satýr
				tabsayisi=radius-1;
				printf("X");
						
				for(i=0;i<tabsayisi;i++)
			      printf("\t");
				printf("X\n");	
			}
			
			  tabsayisi=1;
			  secondtab=radius-3;
					
			  for(j=(radius/2)+2; j< radius  ;j++){     //alt satýrlar
						
				for(i=0;i<tabsayisi;i++)
				  printf("\t");
			    printf("X");
						
						
				for(k=0;k<secondtab;k++)
				  printf("\t");
				  
				printf("X\n");	
				
				tabsayisi++;
				secondtab=secondtab-2;		
				}	
			 }	
				
			  if(satir==2){                            //r tekken   ilk ve son satir    
				tabsayisi=(radius/2);
				for(i=0;i<tabsayisi;i++) 
				  printf("\t");
						
				printf("X\n");	
			 }	
		  }	
		}		
	}
		
		printf("name:circular pokemon\nsize:%.2lf\n",size_of_body);
		
		if(color==0)
			printf("color:red\n");
		if(color==1)
			printf("color:yellow\n");
		if(color==2)
			printf("color:blue\n");
		if(color==3)
			printf("color:black\n");
		if(color==4)
			printf("color:white\n");
			
		printf("move:%.2lf\nattack power:%d\n",move_length,attack_power);	
	}	
}
