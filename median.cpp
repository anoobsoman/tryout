#include <iostream>
#include <vector>

double calcMedian(std::vector<double> hw)
{    
    std::vector <double>::size_type homeWorkSize = 0;
    double median = 0.0;

    homeWorkSize = hw.size();

    if(homeWorkSize)
    {
        sort (hw.begin(), hw.end());
        median = ((homeWorkSize % 2) == 0) ? \
                 (hw[homeWorkSize/2] + hw[(homeWorkSize/2)-1])/2 : hw[homeWorkSize/2];
    }
    return median;
}
