#include <stdio.h>

void main()
{
	printf("Enter the amount");
	float amt;
	scanf("%f", &amt);
	float interest;
	if(amt>2400000)
	{
		interest = ((amt-2400000)*(30.0/100)) + (400000*(25.0/100)) + (400000*(20.0/100)) + (400000*(15.0/100)) + (400000*(10.0/100)) + (400000*(5.0/100));
	}
	else if(amt>2000000 && amt<= 24000000)
	 {	
		interest = ((amt-2000000)*(25.0/100)) + (400000*(20.0/100)) + (400000*(15.0/100)) + (400000*(10.0/100)) + (400000*(5.0/100));
	 }
	 else if(amt>1600000 && amt <= 2000000)
	 {
	 	interest = ((amt-1600000)*(20.0/100)) + (400000*(15.0/100)) + (400000*(10.0/100)) + (400000*(5.0/100));
	 }
	 else if(amt>1200000 && amt<=1600000)
	 {
	 	interest = ((amt-1200000)*(15.0/100)) + (400000*(10.0/100)) + (400000*(5.0/100));
	 }
	 else if(amt>800000 && amt <=1200000)
	 {
	 	interest = ((amt-800000)*(10.0/100)) + (400000*(5.0/100));
	 }
	 else if(amt>400000 && amt <= 800000)
	 {
	 	interest = ((amt-400000)*(5.0/100));
	 }
	 else if(amt>0 && amt<=400000)
	 {
	 	printf("No interest to be paid");
	 }
	 else
	 {
	 	printf("Invalid amt");
	 }

	 if(interest>0)
	 {
	 	printf("The interest amount will be %f", interest);
	 }
}
