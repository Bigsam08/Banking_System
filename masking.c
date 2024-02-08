#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main() {
    char password[20]; // Assuming a maximum of 20 characters for the password

    printf("Enter password: ");
    
    // Disabling echoing of characters
    struct termios oldTerm, newTerm;
    tcgetattr(STDIN_FILENO, &oldTerm);
    newTerm = oldTerm;
    newTerm.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newTerm);

    int i = 0;
    while (1) {
        password[i] = getchar(); // Read a character
        if (password[i] == '\n') { // If Enter is pressed, terminate the loop
            password[i] = '\0'; // Add null terminator to mark the end of the string
            break;
        } else {
            printf("*"); // Print an asterisk to mask the input
            i++;
        }
    }

    // Restoring terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldTerm);

    printf("\nPassword entered: %s\n", password); // Print the entered password
    return 0;
}
