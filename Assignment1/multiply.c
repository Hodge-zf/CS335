#include <stdio.h>

int multiply(int input1, int input2);

int main()
{
	int int1, int2, num, buffer;
		
	printf("How many numbers do you want to multiply?\n ");
	scanf("%d", &num);

        printf("Enter first number:\n ");
        scanf("%d", &int1);
        printf("Enter next number:\n ");
	scanf("%d", &int2);
	buffer = multiply(int1, int2);
	
	for (int i=1; i<num-1; i++){
		printf("Enter next number:\n ");
        	scanf("%d", &int1);
		buffer = multiply(int1, buffer);
	}

	printf("Your product is: %d\n", buffer);
	
}

int multiply(int input1, int input2)
{
	int product = input1*input2;

	return product;
}
