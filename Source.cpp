#include <iostream>
#include <math.h>

int size_base10(int num)						//	This function calculates the number of digits in the integer
{												//  passed as a parameter to this function. For example, if the
	int remainder = 1;							//  integer 1234 is passed then this function would return 4. 
	int power = 1;								//  Variables =>
	int count = 0;								//			Power: This integer is used as a power of 10 which 
	do											//			is divided to validate how many digits are left.
	{											//			Remainder: Stores the left over digits after validating
		remainder = num / power;				//			by dividing by power.
		count++;								//			Count: Keeps track of the number of digits confirmed.
		power *= 10;
	} while (remainder >= 10);
	return count;
}

int max(int num1, int num2)
{				
	if (num1 > num2)							//  Maximum Function is used to return the bigger integer among the two
		return num1;							//  integers passed as a parameter to this function.
	else
		return num2;
}

int karatsuba(int num1, int num2)
{
	int a, b, c, d;														//  These local variables are used to parse the integers passed as parameters
																		//  to this function into 4 almost equal parts later in this function. 
	if ((num1 < 10) && (num2 < 10))										//  If the integer is less than 10 or has only a unit position then both are simply multiplied .
		return num1 * num2;

	int max_num_of_digits = max(size_base10(num1), size_base10(num2));	//  This uilizes the size_base10 and max functions created above to calculate the number of digits
	int half_of_digits = 0;												//  in the larger integer.

	if (max_num_of_digits % 2 == 0)
		half_of_digits = max_num_of_digits / 2;							//  This if statement makes sure that if the number of digits in the larger integer is odd then the
	else																//  half of the max number of digits will be rounded up. (The built in round up function can also be
		half_of_digits = (max_num_of_digits / 2) + 1;					//  used here)

	a = num1 / (int)pow(10, half_of_digits);							//  Local Variables are parsed into 4 almost equal parts. For example, if the two integers are 1234 
	b = num1 % (int)pow(10, half_of_digits);							//  and 567 then they will be parsed as: a = 12, b = 34, c = 05, d = 67.
	c = num2 / (int)pow(10, half_of_digits);							//  Note: If the size of integer is not equal, the smaller integer is padded with zeros.
	d = num2 % (int)pow(10, half_of_digits);

	int step1 = karatsuba(a, c);																	// The function recursively called in these statement according to the 
	int step2 = karatsuba(b, d);																	// divide and conquer technique until the breaking condition is returned  
	int step3 = karatsuba((a + b), (c + d));														// i.e. if an integer is less than 10.
	int step4 = step3 - step2 - step1;																// This step has reduced the recursive call by 1 and thus reducing the 
	int step5 = (step1 * pow(10, 2* half_of_digits)) + step2 + (step4 * pow(10, half_of_digits));	// time complexity from O(n^2) to O(n^log3).

	return step5;
}

int main()
{
	int input1, input2;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "-           KARATSUBA MULTIPLICATION            -" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "- Please enter first integer:                   -" << std::endl;
	std::cout << "  ";
	std::cin >> input1;
	std::cout << "- Please enter second integer:                  -" << std::endl;
	std::cout << "  ";
	std::cin >> input2;
	std::cout << "- Multiplying the numbers...                    -" << std::endl;
	std::cout << "- " << input1 << " * " << input2 << " = " << karatsuba(input1, input2) << "                                 -" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	system("PAUSE");
	return 0;
}