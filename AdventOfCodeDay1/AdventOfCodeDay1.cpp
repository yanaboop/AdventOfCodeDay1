// AdventOfCodeDay1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int currentCount = 0; 
    int currentLine;
    vector<int> elfCalorieTotals;
    string line;
    ifstream elfCaloriesFile;
    elfCaloriesFile.open("elfCalories.txt");
    
    while (getline(elfCaloriesFile,line))
    {
        if (line.empty())
        {
            elfCalorieTotals.push_back(currentCount);
            currentCount = 0;
        }
        else
        {
            istringstream tmp(line);
            tmp >> currentLine;
            currentCount += currentLine;
        }
    }

    int max = *max_element(elfCalorieTotals.begin(), elfCalorieTotals.end());
    cout << "Max value is: ";
    cout << max;
    cout << "\n";

    int maxThreeSum = 0;
    for (int i = 0; i < 3; i ++)
    {
        int max = *max_element(elfCalorieTotals.begin(), elfCalorieTotals.end());
        maxThreeSum += max;
        elfCalorieTotals.erase(max_element(elfCalorieTotals.begin(), elfCalorieTotals.end()));
    }

    cout << "Max sum from top three is: ";
    cout << maxThreeSum;
}

