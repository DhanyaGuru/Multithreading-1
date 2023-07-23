//To create 2 future object Fut1 and Fut2 using std::async to find factorial of ‘n’, according connect it to a callback function, During Fut1 and Fut2 processing perform a matrix multiplication of 2 matrices A and B in main()

#include <iostream>
#include <thread>
#include<future>
using namespace std;

int fact(int n)
//The fact() function is defined, which calculates the factorial of a given integer 'n'.
{
    int f=1;
    for(int i=1;i<=n;i++)
        f=f*i;
    return f;
}

int main()
{
    //Two future objects fut1 and fut2 are created using async to calculate the factorial of 3 and 5
    //These calculations will be performed concurrently in separate threads.
    future<int>fut1=async(fact,3);
    future<int>fut2=async(fact,5);
    int m1[2][2]={{1,1},{2,2}};
    int m2[2][2]={{1,1},{2,2}};
    //Matrix m1 and m2 are defined and initialized
    int m3[2][2];
    //it performs matrix multiplication of m1 and m2, storing the result in m3.
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                m3[i][j] = m1[i][k] * m2[k][j];
            }
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<m3[i][j]<<" ";
        }
        cout<<"\n";
    }
    //The program then prints the result of matrix multiplication, which is stored in m3
    cout<<"Factorial"<<endl;
    cout<<fut1.get()<<" "<<fut2.get()<<endl;
    //It prints the results of the factorial calculations using fut1.get() and fut2.get()
    return 0;
}
