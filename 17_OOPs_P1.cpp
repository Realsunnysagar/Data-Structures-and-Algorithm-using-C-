/*In pep class
1.Class and Object
    class is a blueprint of objects
    Objects are the instances of class
2.Access Modifier
    1.Private
    2.Public
    3.Protected
3.Constructor
4.this keyword
5.~Student();
6.Four pillars of OOPs
    Abstraction - hidding the irrelevant data
    Encapsulation - binding the data and methods all together like a capsule
    Inheritence - inheriting the properities of different  classes in java multiple inheritence is not there.
    Polymorphism - having different forms at different point of time. Two types compile time and runtime polymorphism.

7.Vectors-> we can declare n no. of variable in cpp
            -push_back, pop_back as the name says it will took place from the back.

8.O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(n³) < O(n!) < O(n^n)             
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
 int arr[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
int key =5;
//  int key =10;
 for (int i=0; i<4; i++){
    for(int j=0; j<3; j++){
        if(arr[i][j] == key){
            cout<<i<<","<<j;
        }
    }
 }

return 0; 
}