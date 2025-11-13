#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <limits>
#include <sstream>

using namespace std;

// ANSI color codes for beautiful terminal UI
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define RED     "\033[31m"
#define BG_BLUE "\033[44m"
#define BG_CYAN "\033[46m"

// Recursive factorial function
long long factorial(int n) {
    if (n < 0) {
        throw invalid_argument("Factorial undefined for negative numbers");
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to display the calculator header
void displayHeader() {
    cout << "\n" << BOLD << BG_BLUE << "                                                    " << RESET << "\n";
    cout << BOLD << BG_BLUE << "          🔬 SCIENTIFIC CALCULATOR 🔬              " << RESET << "\n";
    cout << BOLD << BG_BLUE << "                                                    " << RESET << "\n\n";
}

// Function to display the menu with beautiful formatting
void displayMenu() {
    cout << CYAN << "╔════════════════════════════════════════════════╗\n" << RESET;
    cout << CYAN << "║" << RESET << BOLD << "           AVAILABLE OPERATIONS" << RESET << "                " << CYAN << "║\n" << RESET;
    cout << CYAN << "╠════════════════════════════════════════════════╣\n" << RESET;
    cout << CYAN << "║" << RESET << YELLOW << "  1. " << RESET << GREEN << "Addition       " << RESET << CYAN << "│" << RESET << YELLOW << "  2. " << RESET << GREEN << "Subtraction     " << RESET << CYAN << "║\n" << RESET;
    cout << CYAN << "║" << RESET << YELLOW << "  3. " << RESET << GREEN << "Multiplication " << RESET << CYAN << "│" << RESET << YELLOW << "  4. " << RESET << GREEN << "Division        " << RESET << CYAN << "║\n" << RESET;
    cout << CYAN << "║" << RESET << YELLOW << "  5. " << RESET << GREEN << "Power (x^y)    " << RESET << CYAN << "│" << RESET << YELLOW << "  6. " << RESET << GREEN << "Square Root     " << RESET << CYAN << "║\n" << RESET;
    cout << CYAN << "║" << RESET << YELLOW << "  7. " << RESET << GREEN << "Factorial (n!) " << RESET << CYAN << "│" << RESET << YELLOW << "  0. " << RESET << RED << "Exit            " << RESET << CYAN << "║\n" << RESET;
    cout << CYAN << "╚════════════════════════════════════════════════╝\n" << RESET;
}

// Function to display result beautifully
void displayResult(double result) {
    cout << "\n" << MAGENTA << "╔════════════════════════════════════════════════╗\n" << RESET;
    cout << MAGENTA << "║" << RESET << BOLD << "                   RESULT                       " << RESET << MAGENTA << "║\n" << RESET;
    cout << MAGENTA << "╠════════════════════════════════════════════════╣\n" << RESET;
    cout << MAGENTA << "║" << RESET << "  " << BOLD << GREEN << fixed << setprecision(6) << result << RESET;
    
    // Add padding to align the box
    ostringstream oss;
    oss << fixed << setprecision(6) << result;
    int padding = 44 - oss.str().length();
    for (int i = 0; i < padding; i++) cout << " ";
    
    cout << MAGENTA << "║\n" << RESET;
    cout << MAGENTA << "╚════════════════════════════════════════════════╝\n" << RESET;
}

// Function to get valid number input
double getNumber(const string& prompt) {
    double num;
    while (true) {
        cout << BLUE << prompt << RESET;
        if (cin >> num) {
            return num;
        } else {
            cout << RED << "❌ Invalid input! Please enter a valid number.\n" << RESET;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Function to get valid integer input
int getInteger(const string& prompt) {
    int num;
    while (true) {
        cout << BLUE << prompt << RESET;
        if (cin >> num) {
            return num;
        } else {
            cout << RED << "❌ Invalid input! Please enter a valid integer.\n" << RESET;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    int choice;
    double num1, num2, result;
    
    cout << fixed << setprecision(6);
    
    while (true) {
        displayHeader();
        displayMenu();
        
        choice = getInteger("\n➤ Enter your choice (0-7): ");
        
        try {
            switch (choice) {
                case 1: // Addition
                    num1 = getNumber("Enter first number: ");
                    num2 = getNumber("Enter second number: ");
                    result = num1 + num2;
                    displayResult(result);
                    break;
                    
                case 2: // Subtraction
                    num1 = getNumber("Enter first number: ");
                    num2 = getNumber("Enter second number: ");
                    result = num1 - num2;
                    displayResult(result);
                    break;
                    
                case 3: // Multiplication
                    num1 = getNumber("Enter first number: ");
                    num2 = getNumber("Enter second number: ");
                    result = num1 * num2;
                    displayResult(result);
                    break;
                    
                case 4: // Division
                    num1 = getNumber("Enter numerator: ");
                    num2 = getNumber("Enter denominator: ");
                    if (num2 == 0) {
                        cout << RED << "\n❌ Error: Division by zero is undefined!\n" << RESET;
                    } else {
                        result = num1 / num2;
                        displayResult(result);
                    }
                    break;
                    
                case 5: // Power
                    num1 = getNumber("Enter base: ");
                    num2 = getNumber("Enter exponent: ");
                    result = pow(num1, num2);
                    displayResult(result);
                    break;
                    
                case 6: // Square Root
                    num1 = getNumber("Enter number: ");
                    if (num1 < 0) {
                        cout << RED << "\n❌ Error: Square root of negative number is undefined!\n" << RESET;
                    } else {
                        result = sqrt(num1);
                        displayResult(result);
                    }
                    break;
                    
                case 7: // Factorial
                    {
                        int n = getInteger("Enter a non-negative integer: ");
                        if (n > 20) {
                            cout << RED << "\n⚠️  Warning: Result may overflow for n > 20\n" << RESET;
                        }
                        long long factResult = factorial(n);
                        displayResult(static_cast<double>(factResult));
                    }
                    break;
                    
                case 0: // Exit
                    cout << "\n" << GREEN << BOLD << "Thank you for using Scientific Calculator! 👋\n" << RESET;
                    cout << GREEN << "Goodbye! 🚀\n\n" << RESET;
                    return 0;
                    
                default:
                    cout << RED << "\n❌ Invalid choice! Please select 0-7.\n" << RESET;
            }
        } catch (const exception& e) {
            cout << RED << "\n❌ Error: " << e.what() << "\n" << RESET;
        }
        
        cout << "\n" << YELLOW << "Press Enter to continue..." << RESET;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        
        // Clear screen effect
        for (int i = 0; i < 2; i++) cout << "\n";
    }
    
    return 0;
}