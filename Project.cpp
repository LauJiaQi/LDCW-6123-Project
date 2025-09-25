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

    // Question 4: Preferred learning style
    std::string style;
    while (true) {
        std::cout << "\nPreferred learning style (v=video | r=reading | p=project): ";
        std::getline(std::cin, style);
        std::transform(style.begin(), style.end(), style.begin(), ::tolower);

        if (style == "v" || style == "video") {
            style = "video";
            break;
        } else if (style == "r" || style == "reading") {
            style = "reading";
            break;
        } else if (style == "p" || style == "project") {
            style = "project";
            break;
        } else {
            std::cout << "Invalid input. Please enter v, r, p or full text.\n";
        }
    }

    // Pricing references (USD)
    const double monthlyPlus = 59.0;
    const double annualPlus  = 399.0;

    std::string areaText, starterCourse, certificateHint;

    switch (area) {
        case 1:
            areaText = "Data & Analytics";
            starterCourse = "Intro to Data or Python for Everybody";
            certificateHint = "Google Data Analytics (entry-level Professional Certificate)";
            break;
        case 2:
            areaText = "IT Support & Cybersecurity";
            starterCourse = "Technical Support Fundamentals";
            certificateHint = "Google IT Support or IBM Cybersecurity Analyst";
            break;
        case 3:
            areaText = "UX / Product / Design";
            starterCourse = "Intro to UX Design";
            certificateHint = "Google UX Design (entry-level Professional Certificate)";
            break;
        case 4:
            areaText = "Business & Management";
            starterCourse = "Foundations of Project Management";
            certificateHint = "Google Project Management (entry-level Professional Certificate)";
            break;
        case 5:
            areaText = "Language & Personal Development";
            starterCourse = "Academic English or Communication Skills";
            certificateHint = "Skill-focused Specializations (no single ‘career cert’ here)";
            break;
    }

    // Recommendation output
    std::cout << "\n--- Recommendation ---\n";
    std::cout << "Area: " << areaText << "\n";

    if (track == "free") {
        std::cout << "Plan: Start by auditing a course such as \"" << starterCourse
                  << "\" and commit " << hours << " hour(s)/week.\n";
        std::cout << "Tip: You can upgrade later for graded assessments and certificates.\n";
    } else if (track == "subscription") {
        std::cout << "Plan: Use Coursera Plus to explore multiple courses/Specializations in "
                  << areaText << ".\n";
        if (hours >= 6) {
            std::cout << "Economics: With steady study (" << hours
                      << " hr/week), the annual plan (~$" << annualPlus
                      << ") is usually better value than paying $" << monthlyPlus
                      << "/month all year.\n";
        } else {
            std::cout << "Economics: If you study sporadically, the monthly plan ($"
                      << monthlyPlus << "/month) may be sufficient.\n";
        }
    } else if (track == "certificate") {
        std::cout << "Plan: Target a career pathway. A suitable option is: " << certificateHint << ".\n";
        if (hours >= 8) {
            std::cout << "Pace: At " << hours
                      << " hr/week, expect consistent progress; consider a subscription if you also want electives.\n";
        } else {
            std::cout << "Pace: At " << hours
                      << " hr/week, plan a longer timeline and focus on one course at a time.\n";
        }
    }

    if (style == "video") {
        std::cout << "Tip: Coursera video lectures are best suited for your learning style.\n";
    } else if (style == "reading") {
        std::cout << "Tip: Focus on text-based resources and readings in each course.\n";
    } else if (style == "project") {
        std::cout << "Tip: Choose courses with hands-on projects and capstones.\n";
    }

    std::cout << "\nGood luck with your learning journey!\n";

    return 0;
}





