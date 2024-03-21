#include <iostream>
#include <bitset>

using namespace std;
int main()
{
    double f = 2;
    cout<<bitset<sizeof f*8>(*(long unsigned int*)(&f))<<endl;
    return 0;
}