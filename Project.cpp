#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::cout << "=== Coursera Learning Path Advisor ===\n\n";

    // Question 1: Interest area
    int area;
    while (true) {
        std::cout << "Choose an interest area:\n";
        std::cout << "1) Data & Analytics\n";
        std::cout << "2) IT Support & Cybersecurity\n";
        std::cout << "3) UX / Product / Design\n";
        std::cout << "4) Business & Management\n";
        std::cout << "5) Language & Personal Development\n";
        std::cout << "Enter 1-5: ";

        if (std::cin >> area && area >= 1 && area <= 5) {
            break; // valid input
        } else {
            std::cout << "Invalid choice. Please enter a number 1-5.\n\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }

    // Question 2: Hours per week
    int hours;
    while (true) {
        std::cout << "\nHours you can study per week (e.g., 3, 5, 10): ";
        if (std::cin >> hours && hours > 0) {
            break; // valid input
        } else {
            std::cout << "Invalid input. Enter a positive number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }

    std::cin.ignore(); // clear newline before getline

    // Question 3: Goal type (free / subscription / certificate)
    std::string track;
    while (true) {
        std::cout << "\nGoal type (f=free | s=subscription | c=certificate): ";
        std::getline(std::cin, track);
        std::transform(track.begin(), track.end(), track.begin(), ::tolower);

        if (track == "f" || track == "free") {
            track = "free";
            break;
        } else if (track == "s" || track == "subscription") {
            track = "subscription";
            break;
        } else if (track == "c" || track == "certificate") {
            track = "certificate";
            break;
        } else {
            std::cout << "Invalid input. Please enter f, s, c or full text.\n";
        }
    }



    