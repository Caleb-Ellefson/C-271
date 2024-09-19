#include <iostream>


void error();
void output(double total_hours, double hours, int days, float wage);

int main(){
	double wage;
	int days;
	double hours;
	double total_hours = 0;

	std::cout << "What is your hourly wage?" << std::endl;
	std::cin >> wage;
	if (wage < 15.00){
		error();
		return 1;
	};

	std::cout << "How many days would you like to work?" << std::endl;
	std::cin >> days;
	if (days <= 0){
		error();
		return 1;
	};

	int* hours_worked = new int[days];

	for (int i = 0; i < days; i++){
		std::cout << "How many hours did you work day " << i + 1 << "?" << std::endl;
		std::cin >> hours;

		if (hours <= 0){
			error();
			delete [] hours_worked;
			return 1;
		};
		hours_worked[i] = hours;
		total_hours = total_hours + hours_worked[i];
	};

	output(total_hours, hours, days, wage);

	delete [] hours_worked;

	return 0;
}


void error(){
	std::cout << "Error" << std::endl;

}

void output(double total_hours, double hours, int days, float wage){
	std::cout << "You worked a total of " << total_hours << " hours." << std::endl;
	std::cout << "During this time you made $" << total_hours * wage << std::endl;
	std::cout << "On average you worked " << total_hours / days << " hours per day." << std::endl;
	std::cout << "Over the next month (30 days) you should expect to earn $" <<  30 * (wage * (total_hours / days)) << std::endl;
}