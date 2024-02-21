#include <iostream>
#include <ctime>
#include <vector>
#include <unistd.h> // For usleep function

// Function to clear the screen
void clearScreen() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape codes to clear screen
}

// Function to get current system time
std::tm getCurrentTime() {
    std::time_t now = std::time(nullptr);
    return *std::localtime(&now);
}

// ASCII representation of numbers with colored background
const std::vector<std::vector<std::string>> asciiNumbers = {
    {
        "       ",
        " ##### ",
        "#     #",
        "#     #",
        "#     #",
        "#     #",
        " ##### ",
        "       "
    },
    {
        "     ",
        "  ## ",
        " #  #",
        "    #",
        "    #",
        "  ## ",
        "     "
    },
    {
        "       ",
        " ##### ",
        "#     #",
        "      #",
        " ##### ",
        "#      ",
        " ##### ",
        "       "
    },
    {
        "       ",
        " ##### ",
        "#     #",
        "     # ",
        " ####  ",
        "     # ",
        " ##### ",
        "       "
    },
    {
        "       ",
        " #   # ",
        "#   ## ",
        "#  # # ",
        "#####  ",
        "    #  ",
        "    #  ",
        "       "
    },
    {
        "       ",
        " ##### ",
        "#      ",
        " ##### ",
        "      #",
        "#     #",
        " ##### ",
        "       "
    },
    {
        "       ",
        " ##### ",
        "#      ",
        " ##### ",
        "#     #",
        "#     #",
        " ##### ",
        "       "
    },
    {
        "       ",
        " ######",
        "     # ",
        "    #  ",
        "   #   ",
        "  #    ",
        " #     ",
        "       "
    },
    {
        "       ",
        " ##### ",
        "#     #",
        "#     #",
        " ##### ",
        "#     #",
        " ##### ",
        "       "
    },
    {
        "       ",
        " ##### ",
        "#     #",
        "#     #",
        " ######",
        "      #",
        " ##### ",
        "       "
    }
};

// Function to print the clock
void printClock() {
    std::tm currentTime = getCurrentTime();
    std::string hourStr = std::to_string(currentTime.tm_hour);
    std::string minuteStr = std::to_string(currentTime.tm_min);
    std::string secondStr = std::to_string(currentTime.tm_sec);

    // Pad single digit numbers with a leading zero
    if (hourStr.size() == 1) hourStr = "0" + hourStr;
    if (minuteStr.size() == 1) minuteStr = "0" + minuteStr;
    if (secondStr.size() == 1) secondStr = "0" + secondStr;

    // Display the time using ASCII art numbers with colored background
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 7; ++j) {
            std::cout << "\033[48;2;0;0;0m" << "\033[38;2;255;255;255m"; // Black background, White text
            std::cout << asciiNumbers[hourStr[0] - '0'][i][j] << " ";
            std::cout << asciiNumbers[hourStr[1] - '0'][i][j] << " ";
            std::cout << "   "; // Colon separator
            std::cout << asciiNumbers[minuteStr[0] - '0'][i][j] << " ";
            std::cout << asciiNumbers[minuteStr[1] - '0'][i][j] << " ";
            std::cout << "   "; // Colon separator
            std::cout << asciiNumbers[secondStr[0] - '0'][i][j] << " ";
            std::cout << asciiNumbers[secondStr[1] - '0'][i][j] << " ";
            std::cout << "\033[0m"; // Reset color
            std::cout << std::endl;
        }
    }
}

int main() {
    // Clear the screen initially
    clearScreen();

    // Loop to continuously update and display the clock
    while (true) {
        // Clear the screen before printing the clock to avoid flickering
        clearScreen();
        
        // Print the clock
        printClock();

        // Sleep for 1 second before updating the clock again
        usleep(1000000); // Sleep for 1 second (1000000 microseconds)
    }

    return 0;
}
