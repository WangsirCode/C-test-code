// C++ program to illustrate the 
// capacity function in vector 
#include <iostream> 
#include <vector> 
  
using namespace std; 
  
int main() 
{ 
    vector<int> g1; 
    vector<double> g2; 
    vector<char> g3; 
  
    for (int i = 1; i <= 5; i++) 
        g1.push_back(i); 
  
    cout << "Size : " << g1.size(); 
    cout << "\nCapacity : " << g1.capacity(); 
    cout << "\nint Max_Size : " << g1.max_size(); 
    cout << "\ndouble Max_Size : " << g2.max_size(); 
    cout << "\nchar Max_Size : " << g3.max_size(); 
  
    // resizes the vector size to 4 
    g1.resize(4); 
  
    // prints the vector size after resize() 
    cout << "\nSize : " << g1.size(); 
    cout << "\nCapacity : " << g1.capacity(); 
  
    // checks if the vector is empty or not 
    if (g1.empty() == false) 
        cout << "\nVector is not empty"; 
    else
        cout << "\nVector is empty"; 
  
    // Shrinks the vector 
    g1.shrink_to_fit(); 
    cout << "\nVector elements are: "; 
    for (auto it = g1.begin(); it != g1.end(); it++) 
        cout << *it << " "; 
  
    return 0; 
} 