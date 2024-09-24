#include <iostream>
#include <iomanip>

void error();
float average(float* ptr, int assignments);


int main() {

    int assignments = 0; 
    float score = 0;
    float total_score = 0;

    std::cout << "How many assignments have you completed?" << std::endl;
    std::cin >> assignments;
    if (assignments <= 0) {
        error();

        return 1; 
    }

    float *assigment_array = new float[assignments];
    float *ptr = assigment_array;

    for (int i = 0; i < assignments; i++) { 
        std::cout << "What was your score on assignment #" << i + 1 << "?" << std::endl;
        std::cin >> score;
        if (score < 0 || score > 100) {
            error();
            delete[] assigment_array;
            return 1;
        }
        assigment_array[i] = score;
    }

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Scores: ";
    for (int i = 0; i < assignments; i++) { 

     std::cout << assigment_array[i];
     if(i < assignments - 1){
     	std::cout << ", ";
     }
    }
    std::cout << "." << std::endl;
    std::cout << "Average score was " << average(ptr, assignments) << "." << std::endl;;

    delete[] assigment_array; 

    return 0;
}


void error() {
    std::cout << "Error: Invalid input!" << std::endl;

}


float average(float* ptr, int assignments) { 
    float total_score = 0;
    for (int i = 0; i < assignments; i++) { 
        total_score += ptr[i];
    }
    return total_score / assignments; 
}
