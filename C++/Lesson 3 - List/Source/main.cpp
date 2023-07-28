#include <iostream>
#include <list>

template <typename bien>

int main()
{
    std::list <int> array;

    array.push_back(2);

    array.push_back(5);

    array.push_back(10);

    array.push_back(7);

    std::list <int> ::iterator it; // it is present as a pointer, which mean it hold address of node in list
                                   // we use iterator because the address of every node in the list is not sequence
                                   // so we use iterator due to the library provide function to access next node of list with easy using it++

    int i = 0;

    for (it = array.begin(); it != array.end(); it++) // it hold address of first node in list, if it hold address different from address of last node, move to next node
    {
        if (i == 2)
        {
            array.insert(it, 100);
        }
        i++;
        
    }
    
    
    for (it = array.begin(); it != array.end(); it++)
    {
        std::cout << *it << '\n';
    }
    
    

    return 0;
}