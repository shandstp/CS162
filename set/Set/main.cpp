#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
    Set<int> meh;
    meh.add(5);
    meh.add(6);
    meh.add(3);
    if(meh.contains(5)){
        cout << "meh contains 5" << endl;
    }
    else cout << "not sure what you're talking about" << endl;

    return 0;
}
