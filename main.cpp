#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

// ANSI escape codes for text color
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void printAsciiTime(int digit) {
    switch (digit) {
        case 0:
            std::cout << "███ ";
            break;
        case 1:
            std::cout << "█   ";
            break;
        case 2:
            std::cout << "███ ";
            break;
        case 3:
            std::cout << "███ ";
            break;
        case 4:
            std::cout << "█ █ ";
            break;
        case 5:
            std::cout << "███ ";
            break;
        case 6:
            std::cout << "███ ";
            break;
        case 7:
            std::cout << "███ ";
            break;
        case 8:
            std::cout << "███ ";
            break;
        case 9:
            std::cout << "███ ";
            break;
    }
}

int main() {
    while (true) {
        // Get current time
        auto now = std::chrono::system_clock::now();
        std::time_t current_time = std::chrono::system_clock::to_time_t(now);
        std::tm *local_time = std::localtime(&current_time);

        // Clear screen
        std::cout << "\x1b[2J\x1b[H";

        // Print time with colored background
        std::cout << ANSI_COLOR_RED;
        printAsciiTime(local_time->tm_hour / 10);
        printAsciiTime(local_time->tm_hour % 10);
        std::cout << ANSI_COLOR_RESET;

        std::cout << ANSI_COLOR_GREEN;
        printAsciiTime(local_time->tm_min / 10);
        printAsciiTime(local_time->tm_min % 10);
        std::cout << ANSI_COLOR_RESET;

        std::cout << ANSI_COLOR_YELLOW;
        printAsciiTime(local_time->tm_sec / 10);
        printAsciiTime(local_time->tm_sec % 10);
        std::cout << ANSI_COLOR_RESET;

        // Wait for a second before updating the time
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}


    return 0;
}

