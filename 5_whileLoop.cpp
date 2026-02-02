/*
While Loop
    - Loop runs while condition is true
    - updation of variable we do it inside loop at last
    - and initialization is done outside
-for loop and while loop are known as entry-level.
-do while loop known as exit-level.
*/
#include <iostream>
using namespace std;

int main(){
    int count = 1;
    while (count < 3){
        cout<<count<<" ";
        count++;
    }
    cout<<endl;
    return 0;
}