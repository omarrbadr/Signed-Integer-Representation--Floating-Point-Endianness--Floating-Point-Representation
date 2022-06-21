#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void print_binary_char(char c) {

	char array1[8];
	int i,x=128,j;
	for(i=0;i<8;i++){
		
		if((x&c)==x){
			
			array1[i]=1;
		}
		else
			array1[i]=0;
		x=x>>1;
	}
	
	for(j=0;j<8;j++){
		
		printf("%d",array1[j]); // 2 compliment
	}

}
/*
*/
void question1() {
printf("printing from -16 to 15 in binary\n");
char c;
for(c=-16; c<16; c++) {
printf("%d\t", c);
print_binary_char(c);
printf("\n");
}
}
/*
*/
void print_binary_float(float f) {

	int  j;
	union floathexa {
		
		unsigned char i[4];
		float f;	
	}number;
		
		number.f=f;
	
	for(j=3;j>=0;j--){
	
		printf("%02x",number.i[j]);
	}

}
/*
*/
void question2() {
float numbers[] = {0.0f, 1.0f, 2.0f, 0.1f};
int count = sizeof(numbers) / sizeof(numbers[0]);
int i;
for(i=0; i<count; i++) {
printf("%.2f is represented as: ", numbers[i]);
print_binary_float(numbers[i]);
printf("\n");
}
}
/*
*/
float get_smallest_positive_float() {


	int i,j;
union {
	
	float f;
	char array2[4];
	
}number;

for(i=3;i>0;i--){ // reversed loop to print the most signeficant bits first (normally it is little endian)
	
	number.array2[i]=0;
	
}

	number.array2[0]=1;
	
	return number.f;	
}
/*
*/
double get_double_epsilon() {
 
	union {
		
		long long x;
		double f;
	
	}number;
	
	number.f=1.0;
	number.x=(number.x)+1;
	
	return 	(number.f)-1;
}
/*
*/
int get_longdouble_exponent_bias() {

int i,j,count=0,bias,move;

union{
	
	unsigned char x[12];
	long double f;
}number;

	number.f=1.0;
	for(i=11;i>=0;i--){
		
		for(j=8;j>=0;j--){
			
			move=number.x[i]>>j;
			if(move&1==1){
				
				count++;
			}
		}
	}
	
	bias=pow(2,count)-1;

return bias;
}
/*
*/

void question3() {
printf("The smallest positive 'float' is: %e\n",
get_smallest_positive_float());
printf("Epsilon for 'double' is: %le\n", get_double_epsilon());
printf("'long double' has a bias of %d for its exponent\n",
get_longdouble_exponent_bias());
}
/*
*
*/
int get_command() {
int choice;
printf("\n\n");
printf("*********************************************\n");
printf("* Enter 1 for Signed Integer Representation *\n");
printf("* Enter 2 for Floating-Point Endianness *\n");
printf("* Enter 3 for Floating-Point Representation *\n");
printf("* Enter anything else to exit *\n");
printf("*********************************************\n");
printf("Your choice: ");
scanf("%d", &choice);
fseek(stdin, 0, SEEK_END);
printf("\n");
return choice;
}
/*
*
*/
main() {
int choice;
while(1) {
switch(get_command()) {
case 1:
question1();
break;
case 2:
question2();
break;
case 3:
question3();
break;
default:
printf("Invalid Choice. Exiting...\n");
exit(1);

}
}
return 0;
}
