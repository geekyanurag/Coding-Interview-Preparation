#include <bits/stdc++.h> 
using namespace std; 

// Method to find the number of digits of factorial of a number e.g = 5! = 120 and no. of digits = 3 
long long findDigits(int n) 
{ 
    if (n < 0) 
        return 0; 
   
    if (n <= 1) 
        return 1; 
  
    // Use Kamenetsky formula to calculate 
    // the number of digits 
    double x = ((n * log10(n / M_E) +  
                 log10(2 * M_PI * n) / 
                 2.0)); 
  
    return floor(x) + 1; 
} 
  
// Driver Code 
int main() 
{ 
    cout << findDigits(1) << endl; 
    cout << findDigits(50000000) << endl; 
    cout << findDigits(1000000000) << endl; 
    cout << findDigits(120) << endl; 
    return 0; 
} 