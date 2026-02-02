/*
1.2D arrays
    -int students[row][column]
    - n*m ( n-> rows, m-> cols)
2.2D arrays in Memory
    -A 2D array is represented as a contiguous block of memory cells (linearly).
    -Row Major (we will store row wise linearly in memory, like row1 followed by row2 and so on)
    -Column Major (we will store column wise linearly in memory, like col1,col2,col3... so on)
    -and memory address will be like 100,104,108.. for each int element 
3.Spriral Matrix
    -travel a matrix in spiral fasion and print it like that
    -top->right->bottom->left and repeat just covering the boundary of matrix
    -var (srow,scol,erow=n-1,ecol=m-1)
    -Top boundary
        for(scol to ecol){
            mat[srow][j]}
    -Right boundary
        for(srow+1 to erow){
            mat[i][ecol]}
    -Bottom boundary
        for(ecol-1 to scol){
            mat[erow][j]}
    -Left boundary
        for(erow-1 to srow+1){
            mat[i][scol]}
    -srow++, scol++, erow--, ecol--
    -srow <= erow {equal to because it will manage the odd no. of rows}
    -scol <= ecol {equal to because it will manage the odd no. of cols}
    -while(srow<=erow && scol <= ecol)
    -remove the repeating using if 
4.Diagonal Sum
    -Sum of both the diagonals
    -primary diagonal + secondary diagonal - common elem = DS
    -if there is any common element between both the diagonal at centre then sub it from the sum
    -PD(i,j) -> i=j
    -SD(i,j) -> j=n-i-1
    -Common Element i=1,j=1 and j= 3-1-1 = 1 therefore remove that elem
5.Search in Sorted Matrix
    -Search for a key in row wise & col wise sorted matrix
    1.Bruteforce approach
        -go to the each cell one by one and check 
        -we need to traverse on all element
        -TC: O(n*m)
    2.Row/Col wise Binary Search
        -we will search in r1 -> log m time
        -in r2 ->log m time .... 
        -therefore TC : O(n * log m) in row wise
        -similarly in col wise TC: O(m * log n)
    3.Staircase Search
        -can be applied on matrix which is sorted in both colwise and row-wise
        -cells special property
        -cell_start -> mat[0][m-1]
        -while(r<n && c>=0)
        -cell == key --> found
        -cell < key --> downward row++
        -cell > key -->left col--
        -all this will create a stair like structure
        -TC : O(m + n) -->max diagonal elem dist. in any way will me n+m
6.Matrix Pointer
    -*2D array name(mat) behaves as a row pointer and point to the entire row1.
    -if value of mat = x then value of (mat+1) = x+16 (if int mat of 4 col in r1) in hexadecimal
    -cout<< mat << " = " << &mat[0][0] <<endl; but
    -cout<< mat+1 << " != " << &mat[0][1] <<endl; not same unlike in 1D arr
    -cout<< mat+1 << " = " << &mat[1][0]; is equal to 1st elem of 2nd row
7.Matrix Pointers in Function
    -Passing Matrix Pointer to function
    -func_name(int (*ptr)[4]){. . .} ->we pass the row pointer
    -func_name(int mat[][4]){. . .} ->we pass the row pointer
    -both ways are same
    -deference for printing val *(mat) or *(mat+1)
    - ptr[i][j] = *(*(ptr + i) + j) --> another way to go there, both is same
*/

#include <bits/stdc++.h>
using namespace std;

void spiralMatrix(int mat[][4], int n, int m){
    int srow = 0, scol = 0;
    int erow = n-1, ecol = m-1;

    while(srow <= erow && scol <= ecol){ //odd matirix
    //top
        for(int j=scol; j<=ecol; j++){
            cout<<mat[srow][j]<<" ";
        }
    //right
        for(int i=srow+1; i<=erow; i++){
            cout<<mat[i][ecol]<<" ";
        }
    //bottoom
        for(int j=ecol-1; j>=scol; j--){
            if(srow == erow){ //middle
                break;
            }
            cout<<mat[erow][j]<<" ";
        }
    //left
        for(int i=erow-1; i>=srow+1; i--){
             if(scol == ecol){ 
                break;
            }
            cout<<mat[i][scol]<<" ";
        }
        srow++;scol++;
        erow--;ecol--;
    }
}

// Diagonal Sum
int diagonalSum(int mat[][4], int n){
    int sum = 0; 
    /*for(int i=0; i<n; i++){ //O(n^2)
        for(int j=0; j<n; j++){
            if(i == j){
                sum += mat[i][j];
            }else if(j == n-i-1){
                sum += mat[i][j];
            }
        }
    }*/
//    Solving it in O(n)
    for(int i=0; i<n; i++){
        sum += mat[i][i]; // pd
        if(i != n-i-1){
            sum += mat[i][n-i-1]; //sd
        }
    }
    cout<<"Sum = "<<sum<<endl;
    return sum;
}

// Search in sorted Array
bool search(int mat[][4], int n, int m, int key){
    int i = 0, j = m-1;
    // O(n+m)
    while (i < n && j >= 0){
        if(mat[i][j] == key){
            cout<<"found at cell (" << i <<","<< j <<")\n";
            return true;
        }else if(mat[i][j] > key){
            //left
            j--; //move left
        }else{
            //down
            i++; //move down
        }
    }
    cout<<"Key Not found\n";
    return false;
}

int main() {
    int students[4][4] = {{100, 100, 100, 98},
                          {85, 74, 89, 100},
                          {63, 72, 65, 99},
                          {54, 65, 32, 12}};
    cout<<students[2][2]<<endl;

    int arr[4][4];
    int n=4, m=4;
    //Taking input of the array
    // for(int i=0; i<n; i++){
    //     for(int j=0;j<m;j++){
    //         cin>>arr[i][j]; //0,0 0,1 0,2 0,3 ...
    //     }
    // } 

    for(int i=0; i<n; i++){
        for(int j=0;j<m;j++){
            cout<<students[i][j]<<" "; //0,0 0,1 0,2 0,3 ...
        }
        cout<<endl;
    } 
    cout<<endl;
    spiralMatrix(students,4,4);
    cout<<endl;
    diagonalSum(students,4);

    //Sorted matrix for search
    int matrix[4][4] = {{10, 20, 30, 40},
                        {15, 25, 35, 45},
                        {27, 29, 37, 48},
                        {32, 33, 39, 50}};
    search(matrix,4,4,33);

return 0; 
}