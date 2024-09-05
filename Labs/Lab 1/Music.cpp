#include <iostream>
#include <string>

std::string title;
std::string artist;
int year;
float rating;
char explicit_input;
bool is_explicit;

void error();
bool is_title_valid(std::string title);
bool is_artist_valid(std::string artist);
bool is_release_year_valid(int year);
bool is_rating_valid(float rating);
bool check(char explicit_input, bool& is_explicit); 

int main() {
    std::cout << "Welcome! Please tell me about your favorite album: \n" << std::endl;

    std::cout << "What's the title?" << std::endl;
    std::getline(std::cin, title);
    if (!is_title_valid(title)) return 1;

    std::cout << "Who's the artist? " << std::endl;
    std::getline(std::cin, artist);
    if (!is_artist_valid(artist)) return 1;

    std::cout << "What year did it come out?" << std::endl;
    std::cin >> year;
    if (!is_release_year_valid(year)) return 1;

    std::cout << "What's your rating of the album? (0.0 to 5.0)" << std::endl;
    std::cin >> rating;
    if (!is_rating_valid(rating)) return 1;

    std::cout << "Is it explicit? (Y/N)" << std::endl;
    std::cin >> explicit_input;
    if (!check(explicit_input, is_explicit)) return 1;  // Pass is_explicit by reference

    std::cout << "Your favorite album is '" << title << "' by '" << artist << "' (" << year << "). Rated " << rating << " out of 5.0 by critics." << std::endl;

    if (is_explicit) {
        std::cout << "Parental Advisory - Contains Explicit Content" << std::endl;
    }

    return 0;
}

void error() {
    std::cout << "An error has occurred. Invalid input." << std::endl;
}

bool is_title_valid(std::string title) {
    if (title.length() <= 0) {
        error();
        return false;
    }
    return true;
}

bool is_artist_valid(std::string artist) {
    if (artist.length() <= 0) {
        error();
        return false;
    }
    return true;
}

bool is_release_year_valid(int year) {
    if (year < 1900 || year > 2024) {
        error();
        return false;
    }
    return true;
}

bool is_rating_valid(float rating) {
    if (rating < 0.0 || rating > 5.0) {
        error();
        return false;
    }
    return true;
}


bool check(char explicit_input, bool& is_explicit) {
    if (explicit_input == 'Y' || explicit_input == 'y') {
        is_explicit = true;
    } else if (explicit_input == 'N' || explicit_input == 'n') {
        is_explicit = false;
    } else {
        error();
        return false;
    }
    return true;
}
