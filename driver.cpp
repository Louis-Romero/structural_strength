#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std; 

int main()
{
    const int SIZE = 20;
    int arrayOfInts[SIZE];
    int arrayOfIntsGraphite[SIZE];
    ifstream fin_data1, fin_data2, fin_variance;
    double counter = 0.0, sum = 0;
    int maximum = -100000, minimum = 100000;
    double sumForVariance = 0; 
    double denominatorForVariance, sampleVariance,standardDeviation, mean; 
    
    fin_data1.open("data1.txt");
    fin_data2.open("data2.txt");
    
    if(fin_data1.fail()|| fin_data2.fail())
    {
        cout << "Error opening file!" << endl;
        exit(1);
    }
    
    
    for(int ix = 0; ix < 10; ix++)
    { 
        fin_data1 >> arrayOfInts[ix];
         
        sum += arrayOfInts[ix];
        counter++;  
        
        if(arrayOfInts[ix] > maximum)
        {
            maximum = arrayOfInts[ix];
        } 
        if(arrayOfInts[ix] < minimum)
        {
            minimum = arrayOfInts[ix];
        } 
    }
    mean = sum/counter;
    cout << "Steel data:" << endl;
    cout << "The mean is " << mean << endl;
    cout << "The maximum value is " << maximum << endl; 
    cout << "The minimum value is " << minimum << endl;
    
    
    for(int jx = 0; jx < 10; jx++)
    { 
        sumForVariance += pow((arrayOfInts[jx]- mean), 2);
    }
    
    denominatorForVariance = counter - 1;
    sampleVariance = sumForVariance/denominatorForVariance;
    standardDeviation = sqrt(sampleVariance);
    cout << "The sample variance is " << sampleVariance << endl;
    cout << "The standard deviation is " << standardDeviation << endl;
    cout << endl;
    //end of steel data calculations
    
    //beginning of graphite data calculations
    
    sum = 0;
    counter = 0;
    maximum = -100000;
    minimum = 100000;
    sumForVariance = 0;
    mean = 0;
    
    for(int ix = 0; ix < 10; ix++)
    { 
        fin_data2 >> arrayOfIntsGraphite[ix];
        sum += arrayOfIntsGraphite[ix];
        counter++;  
        
        if(arrayOfIntsGraphite[ix] > maximum)
        {
            maximum = arrayOfIntsGraphite[ix];
        } 
        if(arrayOfIntsGraphite[ix] < minimum)
        {
            minimum = arrayOfIntsGraphite[ix];
        } 
    }
    
    mean = sum/counter;
    cout << "Graphite data:" << endl;
    cout << "The mean is " << mean << endl;
    cout << "The maximum value is " << maximum << endl; 
    cout << "The minimum value is " << minimum << endl;
    
    
    for(int jx = 0; jx < 10; jx++)
    { 
        sumForVariance += pow((arrayOfIntsGraphite[jx]- mean), 2);
    }
    
    denominatorForVariance = counter - 1;
    sampleVariance = sumForVariance/denominatorForVariance;
    standardDeviation = sqrt(sampleVariance);
    cout << "The sample variance is " << sampleVariance << endl;
    cout << "The standard deviation is " << standardDeviation << endl;
    cout << endl;
   
    fin_data1.close();
    fin_data2.close();
    return 0;
}


