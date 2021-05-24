#include <iostream>
#include <myList.h>
using namespace std;

int main()
{
    myList<int> temp;
    myList<int>::Iterator iter = temp.Begin();
    for(int i = 1; i < 25; i*=2)
    {
        temp.Insert(i,iter);
        ++iter;
    }
    myList<int> temp1;
    temp1 = temp;
    myList<int>::Iterator iter1 = temp1.Begin();
    temp1.Erase(iter1);
    while(iter1 != temp1.End())
    {
        cout<<*iter1<<endl;
        ++iter1;
    }
    return 0;
}
