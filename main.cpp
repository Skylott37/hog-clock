#include <iostream>
#include <ncurses.h>
#include <ctime>

int main() {
    // Initialize ncurses
    initscr();
    // Don't display typed characters
    noecho();
    // Hide the cursor
    curs_set(0);
    // Enable special key input
    keypad(stdscr, TRUE);
    // Don't wait for enter key for getch
    nodelay(stdscr, TRUE);

    // Get terminal dimensions
    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    // Loop indefinitely
    while (true) {
        // Get current time
        time_t now = time(0);
        tm *ltm = localtime(&now);

        // Move cursor to bottom left corner
        move(rows - 1, 0);
        // Clear the line
        clrtoeol();
        // Print current time
        printw("Current Time: %02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);

        // Refresh the screen
        refresh();
        // Wait for a short time
        napms(500); // Adjust the delay as needed
    }

    // End ncurses
    endwin();

    return 0;
}
