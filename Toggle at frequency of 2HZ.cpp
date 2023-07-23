//future object to excecute a function Fun()(with toggle logic) at frequency of 2HZ, and return a Boolean variable print the value for given n no. of times

#include <iostream>
#include <future>
#include <chrono>
#include <thread>

using namespace std;

bool toggle = false;
// Global variable for toggle logic
void Fun()
// Function to be executed at 2Hz with toggle logic
{
    while(1)
    {
        toggle = !toggle;
        // Toggle the value of 'toggle' between true and false
        this_thread::sleep_for(chrono::milliseconds(500));
        // Sleep for 500ms (2Hz frequency)
    }
}

int main() {
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    //get n value to print the toggled value
    future<void> fut = async(Fun);
    // Create a future object to execute the Fun() function asynchronously
    for(int i=0;i<n;i++)
    {
        cout<<"Value : "<<toggle<<endl;
        // Print the value of 'toggle' for n times
        this_thread::sleep_for(chrono::milliseconds(500));
        // Sleep for 100ms (optional delay between prints)
    }
    fut.wait();
    // Wait for the asynchronous Fun() function to finish
    return 0;
}
