//**************************************************************
// Name: Sunny Rodrigues
// Course: COSC 1437 - Programming Fundamentals II
// Date: June 12, 2026
// Assignment #6 - User-Defined Functions

// Demonstrates:
// 1. Predefined functions
// 2. Value-returning functions
// 3. Void functions
// 4. Value vs. reference parameters
// 5. Scope and static variables
// 6. Function overloading
// 7. Default parameters
//**************************************************************

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

//--------------------------------------------------------------
// Function Prototypes
//--------------------------------------------------------------
void mathSummary(double x);

double calcTax(double income, double rate);

void printHeader(string courseTitle);
void displayResult(string label, double value);

void convertTime(int totalSeconds, int& minutes, int& seconds);

void countCalls();

void displayBox(int width);
void displayBox(int width, int height);

double calcShipping(double weight,
                    double ratePerPound = 1.50,
                    double baseFee = 5.00);

//--------------------------------------------------------------
// main Function
//--------------------------------------------------------------
int main()
{
    double income;
    double taxRate;
    double taxOwed;

    int totalSeconds;
    int minutes;
    int seconds;

    cout << fixed << showpoint << setprecision(2);

    //==========================================================
    // Part 1: Predefined Functions
    //==========================================================
    cout << "\nPART 1 - PREDEFINED FUNCTIONS\n";
    mathSummary(25.5);
    mathSummary(-16.8);

//==========================================================
// Part 2 & 3: Tax Calculation and Void Functions
//==========================================================
    printHeader("COSC 1437 - Tax Calculator");

    cout << "\nEnter gross income: $";
    cin >> income;

    cout << "Enter tax rate (example 0.25 for 25%): ";
    cin >> taxRate;

    taxOwed = calcTax(income, taxRate);

    displayResult("Tax Owed", taxOwed);

//==========================================================
// Part 4: Reference Parameters
//==========================================================
    cout << "\nPART 4 - TIME CONVERSION\n";

    cout << "Enter total seconds: ";
    cin >> totalSeconds;

    convertTime(totalSeconds, minutes, seconds);

    displayResult("Minutes", minutes);
    displayResult("Seconds", seconds);

//==========================================================
// Part 5: Static Variables
//==========================================================
    cout << "\nPART 5 - STATIC VARIABLES\n";

    countCalls();
    countCalls();
    countCalls();
    countCalls();

//==========================================================
// Part 6: Function Overloading
//==========================================================
    cout << "\nPART 6 - FUNCTION OVERLOADING\n";

    cout << "\nSquare Box (4 x 4)\n";
    displayBox(4);

    cout << "\nRectangle Box (6 x 3)\n";
    displayBox(6, 3);

//==========================================================
// Part 7: Default Parameters
//==========================================================
    cout << "\nPART 7 - DEFAULT PARAMETERS\n";

    displayResult("Shipping (all arguments)",
                  calcShipping(10.0, 2.00, 8.00));

    displayResult("Shipping (weight and rate)",
                  calcShipping(10.0, 2.00));

    displayResult("Shipping (weight only)",
                  calcShipping(10.0));

    return 0;
}

//--------------------------------------------------------------
// Function: mathSummary
// Purpose: Demonstrates predefined math functions.
// Parameters: x - number to process
// Return: none
//--------------------------------------------------------------
void mathSummary(double x)
{
    cout << "\nMath Summary for x = " << x << endl;

    if (x >= 0)
        cout << "Square Root: " << sqrt(x) << endl;
    else
        cout << "Square Root: Undefined for negative numbers" << endl;

    cout << "x Cubed: " << pow(x, 3) << endl;
    cout << "Ceiling: " << ceil(x) << endl;
    cout << "Floor: " << floor(x) << endl;
    cout << "Absolute Value of x * -1: "
         << fabs(x * -1) << endl;
}

//--------------------------------------------------------------
// Function: calcTax
// Purpose: Calculates tax owed.
// Parameters:
//      income - gross income
//      rate   - tax rate
// Return:
//      tax amount
//--------------------------------------------------------------
double calcTax(double income, double rate)
{
    return income * rate;
}

//--------------------------------------------------------------
// Function: printHeader
// Purpose: Prints a formatted header.
// Parameters:
//      courseTitle - title to display
// Return: none
//--------------------------------------------------------------
void printHeader(string courseTitle)
{
    cout << "\n========================================\n";
    cout << courseTitle << endl;
    cout << "========================================\n";
}

//--------------------------------------------------------------
// Function: displayResult
// Purpose: Displays a label and value.
// Parameters:
//      label - text description
//      value - numeric value
// Return: none
//--------------------------------------------------------------
void displayResult(string label, double value)
{
    cout << left << setw(30) << label
         << ": " << fixed << setprecision(2)
         << value << endl;
}

//--------------------------------------------------------------
// Function: To convertTime
// Purpose: To Converts seconds into minutes and seconds.
// Parameters:
//      totalSeconds: input seconds (value parameter)
//      minutes: output minutes (reference parameter)
//      seconds: output seconds (reference parameter)
// Return: none
//
// minutes and seconds are reference parameters because
// the function must send the calculated values back to
// the calling function (main).
//--------------------------------------------------------------
void convertTime(int totalSeconds,
                 int& minutes,
                 int& seconds)
{
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;
}

//--------------------------------------------------------------
// Function: countCalls
// Purpose: Tp count how many times the function is called.
// Return: none
//
// A static variable keeps its value between function calls.
// A regular local variable is recreated each time the
// function executes.
//--------------------------------------------------------------
void countCalls()
{
    static int count = 0;

    count++;

    cout << "countCalls has been called "
         << count
         << " time(s)." << endl;
}

//--------------------------------------------------------------
// Function: displayBox
// Purpose: draws a square box.
// Parameters:
//      width - width and height of square
// Return: none
//--------------------------------------------------------------
void displayBox(int width)
{
    for (int row = 1; row <= width; row++)
    {
        for (int col = 1; col <= width; col++)
        {
            if (row == 1 || row == width ||
                col == 1 || col == width)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }
}

//--------------------------------------------------------------
// Function: displayBox
// Purpose: Draws a rectangular box.
// Parameters:
//      width  - width of box
//      height - height of box
// Return: none
//--------------------------------------------------------------
void displayBox(int width, int height)
{
    for (int row = 1; row <= height; row++)
    {
        for (int col = 1; col <= width; col++)
        {
            if (row == 1 || row == height ||
                col == 1 || col == width)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }
}

//--------------------------------------------------------------
// Function: calcShipping
// Purpose: Calculates shipping cost.
// Parameters:
//      weight - package weight
//      ratePerPound - shipping rate
//      baseFee - base fee
// Return:
//      total shipping cost
//--------------------------------------------------------------
double calcShipping(double weight,
                    double ratePerPound,
                    double baseFee)
{
    return baseFee + (weight * ratePerPound);
}