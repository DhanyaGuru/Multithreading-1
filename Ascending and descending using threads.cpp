//To create thread T1 to sort a vector in ascending order and T2 in descending order, print the sorted vector by T1 and T2. Both T1 and T2 are initited by main()

#include <iostream>
#include <thread>
#include<mutex>
#include<vector>
#include<algorithm>

using namespace std;

mutex m;
//A mutex m is declared globally
vector<int>V={26,45,22,7,3,1,66,4};
//The vector V is created and initialized with some integers
void Avector()
//The function Avector() is defined, which is executed by T1
{
    m.lock();
    //It locks the mutex m before sorting the vector V in ascending order using sort()
    sort(V.begin(),V.end());
    cout<<"Thread T1"<<endl;
    for(auto i:V)
        cout<<i<<" ";
    cout<<"\n";
    //it prints the sorted vector V along with a message "Thread T1". After that, it unlocks the mutex.
    m.unlock();
}

void Dvector()
//similarly the function Dvector() is defined, which is executed by T2
{
    m.lock();
    //it locks the mutex m before sorting the vector V in descending order using sort()
    sort(V.begin(),V.end(),greater<int>());
    cout<<"Thread T2"<<endl;
    for(auto i:V)
        cout<<i<<" ";
    cout<<"\n";
    //it prints the sorted vector V along with a message "Thread T2". After that, it unlocks the mutex.
    m.unlock();
}

int main()
{
    //two threads T1 and T2 are created
    thread T1(Avector);
    //T1 is associated with the function Avector()
    thread T2(Dvector);
    //T2 is associated with the function Dvector()
    //Both threads are started simultaneously to execute their respective functions.
    T1.join();
    T2.join();
    //After starting the threads, the main() function waits for both threads to finish using T1.join() and T2.join()
    return 0;
}
