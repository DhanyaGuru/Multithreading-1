//create worker1 and worker2 thread  both the threads need to wait for a notification from main() thread, based on the notification T1 should print 1 to 100 and T2 should print 100 to 1.

#include <iostream>
#include<thread>
#include<bits/stdc++.h>
#include<future>
#include<chrono>
using namespace std;

mutex m;
condition_variable cv;
bool ready = false;
//A mutex m, a condition variable cv, and a boolean variable ready are declared globally
//The boolean variable ready acts as a flag to indicate if the threads can proceed with printing

void print(int n)
//The print() function is defined, which is executed by both T1 and T2
{
    unique_lock<mutex>lock(m);
    //Inside the function, a unique_lock is used to lock the mutex m
    cv.wait(lock,[](){ return ready;});
    //The threads then wait for a notification (ready signal) using the cv.wait() function
    //The lambda function passed to cv.wait() checks if the ready flag is set to true
    //If it is not true, the threads will wait for the notification.
    if(n==0)
    {
        for(int i=1;i<=100;i++)
            cout<<i<<" ";
        cout<<"\n";
    }
    //Once the notification is received (when ready becomes true), T1 will print the numbers from 1 to 100, and T2 will print the numbers from 100 to 1 based on the value of n
    else
    {
        for(int i=100;i>=1;i--)
            cout<<i<<" ";
        cout<<"\n";
    }
}

int main(){
    thread T1(print,0);
    thread T2(print,1);
    //two threads T1 and T2 are created, and each thread is associated with the print() function with the argument 0 and 1
    this_thread::sleep_for(chrono::seconds(5));
    //the main() thread sleeps for 5 seconds to ensure both T1 and T2 are waiting for the notification.
    {
        lock_guard<mutex>lock(m);
        ready = true;
        //the ready flag is set to true inside a lock_guard
    }
    cv.notify_all();
    //cv.notify_all() is called to notify all waiting threads.
    T1.join();
    T2.join();
    //Both T1 and T2 threads will wake up and proceed with printing their respective sequences.
    return 0;
}

