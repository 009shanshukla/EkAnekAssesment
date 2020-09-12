#include <bits/stdc++.h>

typedef std::pair<int, int> p;

typedef std::pair<int, p> pp;

/*
finding k smallest tuple indices in both vector which has minimum sum
*/

void printCheapestFlights(std::vector<int> DelhiToMumbai, std::vector<int> MumbaiToDelhi, int k)
{
    std::sort(DelhiToMumbai.begin(), DelhiToMumbai.end());
    std::sort(MumbaiToDelhi.begin(), MumbaiToDelhi.end());

    // min_heap contains sum of DelhiToMumbai[index] and MumbaiToDelhi[index] and (index of DelhiToMumbai , index of MumbaiToDelhi)
    std::priority_queue< pp, std::vector<pp>,std::greater<pp> > min_heap;

    // indices set will be used to check if index are not repeated in min_heap
    std::set<p> indices;

    //first index sum of both vector will be smallest
    min_heap.push(std::make_pair(DelhiToMumbai[0]+MumbaiToDelhi[0], std::make_pair(0,0)));
    
    indices.insert(std::make_pair(0,0));

    // finalsets vector will be used to store final smallest value indices of both vector
    std::vector<p> finalsets;
    int local_sum = 0;

    for(int i = 0; i < k; i++)
    {
        //get the tuple of least sum
        pp temp1 = min_heap.top();
        min_heap.pop();

        int a = temp1.second.first;
        int b = temp1.second.second;
        //store it to finalsets
        finalsets.push_back(std::make_pair(a, b));

        //cross checking with sorted vector and storing it to min_heap
        local_sum = DelhiToMumbai[a+1] + MumbaiToDelhi[b];

        p temp2 = std::make_pair(a+1, b);

        // if indices not repeated
        if(indices.find(temp2) == indices.end())
        {
            min_heap.push(std::make_pair(local_sum, temp2));
            indices.insert(temp2);
        }

        local_sum = DelhiToMumbai[a] + MumbaiToDelhi[b+1];
        temp2 = std::make_pair(a, b+1);

        if(indices.find(temp2) == indices.end())
        {
            min_heap.push(std::make_pair(local_sum, temp2));
            indices.insert(temp2);
        }
    }

    // print
    for(int i = 0; i < finalsets.size(); i++)
    {
        std::cout << DelhiToMumbai[finalsets[i].first] << " " << MumbaiToDelhi[finalsets[i].second] <<std::endl; 
    }
}

int main()
{
    //input delhi to mumbai 
    std::vector<int> DelhiToMumbai = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};

    //input mumbai to delhi
    std::vector<int> MumbaiToDelhi = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75};

    //test k = 10
    int k = 10;

    printCheapestFlights(DelhiToMumbai, MumbaiToDelhi, k);
}