#include <task.h>
#include <algorithm.h>
#include <thread>
#include <string>

using namespace my;
int main()
{
    std::vector<int> rr = {8, 7, 6, 5 ,4 ,3 ,2 ,1};
    combSort(rr.begin(), rr.end());
    for(int i = 0; i < rr.size(); i++)
    {
        std::cout << rr[i] << " ";
    }
    std::vector<int> range1 = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000 };
    to_sort_helper_reverse(range1, Shell_sort<std::vector<int>::iterator>, "Shell_sort");
}