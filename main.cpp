#include<iostream>
#include<string>
#include<thread>
#include<cstdlib>
#include<ctime>
#include<chrono>

#define WHITE   "\033[37m"      /* White */
#define RED     "\033[31m"      /* Red */
#define CYAN    "\033[36m"      /* Cyan */
#define GREEN   "\033[32m"      /* Green */


// Width of the matrix line
const int width = 170;

// Defines the number of flips in Boolean Array 'switches'
const int flipsPerLine =5;

// Delay between two successive line print
const int sleepTime = 45;

using namespace std;

int main()
{
    int i=0, x=0;

    // srand initialized with time function
    // to get distinct rand values at runtime
    srand(time(NULL));

    // Used to decide whether to print
    // the character in that particular iteration
    bool switches[width] = {0};

    // Set of characters to print from
    const string digits = "0011 0010 1110 1011 01011 0001 == 1101 0001 0100 1110"
                          "0111 1001 1100 2 03 05 08 13 21 34/'; 55[]! @ $  &*()-=_+";
    const int s = digits.size();


    // Indefinite Loop
    while (true)
    {
        // Loop over the width
        // Increment by 2 gives better effect
        for (i=0; i<width; i+=2)
        {
            // Print character if switches[i] is 1
            // Else print a blank character
            if (switches[i])
                cout << GREEN << digits[rand() % s * 2] << " ";
            else
                cout<<"  ";
        }

        // Flip the defined amount of Boolean values
        // after each line
        for (i=0; i!=flipsPerLine; ++i)
        {
            x = rand() % width;
            switches[x] = !switches[x];
        }

         // New Line
        cout << endl;

        // Using sleep_for function to delay,
        // chrono milliseconds function to convert to milliseconds
        this_thread::sleep_for(chrono::milliseconds(sleepTime));
    }
    return 0;
}
