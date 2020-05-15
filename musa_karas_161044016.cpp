#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

	//class definition 
class image{
	public:
		image(){		//no parameter constructor. initiliaze data to 0 
			row=0,column=0;	
		}
		image(int Row,int Column){	//constructors that takes 2 parameter .initiliazing datas and vector
			row=Row,column=Column,numbers.resize(row*column*3);
		}
		int getRow(){		//getter function  for row
			return row;
		}
		int getColumn(){	//getter function  for column
			return column;
		}
		void setRow(int value){	 // setting to row
			row=value;
		}
		void setColumn(int value){	// setting to column
			column=value;
		}
		
		void menu();		//basic function of all code 
		bool read_ppm();	//reads the file entered by the user and saves the data file to the vector and return success of read file
		void write_ppm();	//opens a new file with the name entered by the user
		void grayscale_conversion(float c_r,float c_g,float c_b);	//apply gray conversion with received coefficients from ppm file to user
	private:
		int row;	//vector's row
		int column;	//vector's column
		int maxvalue;	//maxvalue (ascıı table) in file
		string header;	//string type in file
		vector < vector< float > > numbers;  //hold pixel numbers in file
};

int main(){
	image object;  	//creating a object from image class
	object.menu();	//invokes the  menu functıon
	return 0;
}

			//this function manages the menu and invokes other functions
void image::menu(){
	int secim,secim1,secim2,secim3,secim4; //menu selections to be taken from the user
	int returnvalue;
	float c_r,c_g,c_b;			
	do{					//stay in top menu unless user enters 0
		cout<<"MAIN MENU "<<endl;
		cout<<"0 - Exit"<<endl;
		cout<<"1 - Open An Image(D)"<<endl;
		cout<<"2 - Save Image Data(D)"<<endl;
		cout<<"3 - Scripts(D)"<<endl;
		
		cin>>secim;		//menu selection from user
		if(secim==0)
			return;
			
		switch(secim){
			case 1:
				cout<<"OPEN AN IMAGE MENU"<<endl;
				cout<<"0 - UP"<<endl;
				cout<<"1 - Enter The Name Of The Image File"<<endl;
				cin>>secim1;	//submenu selection from user
				
				if(secim1==0)		//if user enter 0,then program return top menu 
					break;
				else{	
					returnvalue=read_ppm();		//function invokes
					if(returnvalue==0)		//If the file that the user wants to open does not exist, finish the program.
						return;
					
					do{				//stay in sub menu unless user enters 0 and user enters 1
						cout<<"OPEN AN IMAGE MENU"<<endl;
						cout<<"0 - UP"<<endl;
						cout<<"1 - Enter The Name Of The Image File"<<endl;
						cin>>secim1;	//submenu selection from user
						if(secim1==0)	//if user enter 0,then program return top menu 
							break;
						
						returnvalue=read_ppm();	//function invokes
						if(returnvalue==0)	//If the file that the user wants to open does not exist, finish the program.
							return;
					}while(secim1==1);
				}			
				break;
				
			case 2:
				cout<<"SAVE IMAGE DATA MENU"<<endl;
				cout<<"0 - UP"<<endl;
				cout<<"1 - Enter A File Name"<<endl;
				cin>>secim2;	//submenu selection from user
				
				if(secim2==0)	//if user enter 0,then program return top menu 
					break;
				else{	
					write_ppm();	//function invokes
					do{		//stay in sub menu unless user enters 0 and user enters 1
						cout<<"SAVE IMAGE DATA MENU"<<endl;
						cout<<"0 - UP"<<endl;
						cout<<"1 - Enter A File Name"<<endl;
						cin>>secim2;	//submenu selection from user
						if(secim2==0)	//if user enter 0,then program return top menu 
							break;
						write_ppm();	//function invokes
					}while(secim2==1);
				}
				
				break;
				
			case 3:
				cout<<"SCRIPTS MENU"<<endl;
				cout<<"0 - UP"<<endl;
				cout<<"1 - Convert To Grayscale(D)"<<endl;
				cin>>secim3;	//submenu selection from user
				
				if(secim3==0)	//if user enter 0,then program return top menu 
					break;
				else{	
					cout<<"0 - UP"<<endl;
					cout<<"1 - Enter Coefficients For RED GREEN And BLUE Channels"<<endl;
					cin>>secim4;	//submenu selection from user
					
					if(secim4==0)	//if user enter 0,then program return top menu 
						break;
					 cin >> c_r >> c_g >> c_b ;	//take inputs from user
					if((c_r<0 || c_r>=1) || (c_g<0 || c_g>=1) || (c_b<0 || c_b>=1))			//error checking
						break;
					grayscale_conversion(c_r,c_g,c_b);	//function invokes
					do{					//stay in sub menu unless user enters 0 and user enters 1
						cout<<"0 - UP"<<endl;
						cout<<"1 - Enter Coefficients For RED GREEN And BLUE Channels"<<endl;
						cin>>secim4;	//submenu selection from user
						if(secim4==0)	//if user enter 0,then program return top menu 
							break;
						 cin >> c_r >> c_g >> c_b ;	//take inputs from user
						if((c_r<0 || c_r>=1) || (c_g<0 || c_g>=1) || (c_b<0 || c_b>=1))  	//error checking
							break;
						grayscale_conversion(c_r,c_g,c_b);   //function invokes
					}while(secim4==1);
				}
				
				break;		
		};
	}while(secim!=0);
}



bool image::read_ppm(){			//reads the file entered by the user and saves the data file to the vector and return success of read file
	int temp_column;	
	float sayi;
	string filename;
	ifstream myfile;
	
	cin>>filename;		//get the name of the file to be read from the user
	
	myfile.open (filename);
	if (myfile.is_open()==0)	//if the file to open is not found, the program ends 
		return 0;
		
	myfile>>header>>row>>column>>maxvalue;		//reads from file
	temp_column=column*3;				//determine the number of temporary columns created
	numbers.resize(row*temp_column);		//determine the size of the vector based on the row and column from the file
	
	for(int i=0;i<row;i++){
		numbers.push_back(vector <float> ());
	
		for(int j=0;j<temp_column;j++){
			myfile>>sayi;			//read next number from file
			numbers[i].push_back(sayi);	//put the next number in the vector
		}
	}
}


void image::write_ppm(){		//opens a new file with the name entered by the user
	ofstream myfile;
	string filename;
	int temp_column=column*3;	//determine the number of temporary columns created
	
	cin>>filename;			//get the name of the file to be write from the user
	myfile.open (filename);
	myfile<<header<<endl;			//write type to file
	myfile<<row<<" "<<column<<endl;		//write row and column to file
	myfile<<maxvalue<<endl;			//write maxvalue to file
	
	for(int i=0;i<row;i++){		
		for(int j=0;j<temp_column;j++){
			myfile<<numbers[i][j];		//write next number to file
			if(j==temp_column-1)		//if the end of the line is reached
				myfile<<endl;
			else		
				myfile<<" ";
		} 
	}	
			
}


void image::grayscale_conversion(float c_r,float c_g,float c_b){	//apply gray conversion with received coefficients from ppm file to user
	int temp_column;
	float sayi;
	temp_column=column*3;			//determine the number of temporary columns created
	for(int i=0;i<row;i++){
		for(int j=0;j<temp_column;j+=3){
					 // applying formula : red =green =blue = c_r*red + c_g*green + c_b*blue ;
			sayi=(c_r * numbers[i][j]) + (c_g * numbers[i][j+1]) + (c_b * numbers[i][j+2]);	
			if(sayi>255.00)		//if reciving number greater than 255 ,number=255.00
				sayi=255.00;
			numbers[i][j]=sayi;
			numbers[i][j+1]=sayi;
			numbers[i][j+2]=sayi;
		} 
	}
}
