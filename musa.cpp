#include<stdio.h>
#include<math.h>
#define PI 3.14

//side1= k�sa kenar
//side2= uzun kenar
//Dairenin Alan�
double circle_area(double radius){
	
	
	 double area=PI*pow(radius,2);
	return area; 
}

//Hipoten�s Bulma 
double calc_hypotenuse (double side1 ,double side2){
	
		double hypotenuse;
			hypotenuse=pow(side1,2)+pow(side2,2);
			hypotenuse=sqrt(hypotenuse);
		return hypotenuse;

}
	//Daire i�in en k���k yar� �ap bulma k�sa kenar�^2+uzunkenar^2=r^2
double calc_radius_of_smallest_circle(double side1 ,double side2){
			
	double r2;
	r2=pow(side1/2,2)+pow(side2/2,2);
	r2=pow(r2,2);
	return r2;
	
}

// daire i�in en B�y�k yar� �ap K�sa kenar kadard�r.
double calc_radius_of_largest_circle(double side1 ,double side2)
{
	
	return side1;
}
//en uzun daire alan� �stte  buldu�umuz hipoten�s �apt�r yar�s� da yar� �ap oldu�u i�in
double calc_area_of_largest_circle(double side1 ,double side2){
	
	return PI*pow((calc_hypotenuse(side1,side2)/2),2);
}

//en k���k dairenin �ap� k�sa kenar kadard�r yar��ap� ise k�sa kenar�n yar�s�d�r.
double calc_area_of_smallest_circle(double side1 ,double side2){
	

	return  PI*pow(side1/2,2);
}


//Dikd�rtgen i�inde olu�turulabilecek en b�y�k alan uzun kenar kadard�r.
double calc_area_of_largest_square(double side1 ,double side2)
{
	return side2*side2;
}
// en k���k kare ise k���k  kenar kadard�r.
double calc_of_smallest_square(double side1 ,double side2)
{
	return side1*side1;
}
void display_result(double largest_cirle, double largest_square,double smallest_circle ,double smallest_square )
{
	
printf("The area of the largest circle that fits inside a rectangle:%.2f\n",largest_cirle);
printf("The area of the largest square that fits inside a rectangle:%.2f\n",largest_square);
printf("Thea area of the smallest circle that surrounds the same rectangle:%.2f\n",smallest_circle);
printf("Thea area of the smallest square that surrounds the same rectangle:%.2f\n",smallest_square);
}
int main()
{
	double ShortSide;
	double LongSide;
	
	printf("Short Edge Enter:");
	scanf("%lf",&ShortSide);
	 printf("Long Edge Enter:");
	scanf("%lf",&LongSide);
	
	if(ShortSide>LongSide)
	{
		double gecici=LongSide;
		LongSide=ShortSide,
		ShortSide=gecici;
	}
double largest_circle=calc_area_of_smallest_circle(ShortSide,LongSide);
double largest_square=calc_of_smallest_square(ShortSide,LongSide);
double smallest_circle=calc_area_of_largest_circle(ShortSide,LongSide);
double smallest_square=calc_area_of_largest_square(ShortSide,LongSide);


display_result(largest_circle,largest_square,smallest_circle,smallest_square);

/*printf("The area of the largest circle that fits inside a rectangle:%.2f\n",calc_area_of_smallest_circle(ShortSide,LongSide));
printf("The area of the largest square that fits inside a rectangle:%.2f\n",calc_of_smallest_square(ShortSide,LongSide));
printf("Thea area of the smallest circle that surrounds the same rectangle:%.2f\n",calc_area_of_largest_circle(ShortSide,LongSide));
printf("Thea area of the smallest square that surrounds the same rectangle:%.2f\n",calc_area_of_largest_square(ShortSide,LongSide));
	*/


}
