#include <bits/stdc++.h> 
#include <string> 
#include <iostream> 
using namespace std; 
  
int main() 
{ 
    string abc,xyz; 
    float a[3];
    getline(cin, abc); 
    
    stringstream X(abc); 
    int i=0;
    while (getline(X, xyz, ' ')) {
        a[i]=stof(xyz);
        cout << a[i]<< endl; 
        i++;
    } 
  
    return 0; 
} 
