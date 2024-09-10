#include <iostream>


void change_value(int& x){
	x = 2;
}


void pointer(int * ptr){
	*ptr = 5;
}

int main(){
	int x = 1;
	int* ptr = &x;
	std::cout << x << std::endl;
	pointer(ptr);
	std::cout << x << std::endl;
	return 0;
}

