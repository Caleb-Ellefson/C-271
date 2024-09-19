#include <iostream>

int* sum (){
	static int summation;
	const int length = 100;
	int nums[length];

	for (int i; i < 100; i++){
		nums[i] = i+1;

		summation = summation + nums[i];
	}

	return nums;

}


int main(){
	sum();
	
	for (int i; i < 100; i++){
		std::cout << &nums[i] << std::endl;
	}

	return 1;

}
