#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers{3, 1, 4, 1, 5, 9};

    vector<int>::iterator smallest = min_element(begin(numbers), end(numbers));
    std::cout << distance(begin(numbers), smallest);
}
