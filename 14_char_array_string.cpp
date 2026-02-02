/*
1.Char Data Type
    -char takes 1byte in memory
    -ASCII {American Standard Code for Information Interchange}
    -'a'->97, 'A'->65
2.Character Arrays
    -C-String
    -similar to int array
    -{c, o, d, e, \0} ->Explicitly Terminated by null character, '\0'
    -char arr[5] = {'a', 'b', 'c', 'd', 'e'};
    -to store strings like "hello" "sunny sagar" are string literals
    -ASCII value of '\0' is 0(zero)
    -Strings are always terminate with \0n and entire string can be accessed by arr_name (arr)
    -Creating & Output
        - char work[] = "code"; //stores str literal with terminator \0
        - char work[5] = "code";    //having \0 at 5th pos
        - char work[] = {'c', 'o', 'd', 'e', '\0'};
        - char work[50] = {'c', 'o', 'd', 'e', '\0'};   //if we cant end with null value then it can give null value of rest of the position
        - all this are same
        - strlen(work) --> 4
3.Taking Input of String
    - char word[30];
      cin >> word;  //ignore white spaces
    - char sentence[50];
      cin.getline(sentence, 50, '.');   //50->size max, '*'->delimiter(optional argument which helps user to stop at this point)
4.Convert to Upper Case
    -word[] = "ApPle"; ->o/p -> word[] = "APPLE"
    -if word[i] 'A' to 'Z' -> no change
    -if 'a' to 'z' then pos = (word[i] - 'a') + 'A'
5.Reverse char
6.Valid Palindrome
    -a word which can be read from both the sides correctly like racecar, maam, madam, abba
    -2 pointers st, end
    -while (st<end){if word[st] != word[end]} --> return false  st++,end--
    -or return true;
7.<cstring> Functions
    - #include <iostream>
    - strcpy(dest, src) : to copy sting from src to dest
    - strcat(str1, str2) : to concatenate/join str1 with str2
    - strcmp( str1, str2) : compares 2 strings based on values and gives (-ve, 0, +ve)
8.Strings in C++
    - OOPs : Class, Object, Member Function & Properties
    - Class : is a blueprint, like a factory
    - Objects : it is a instance of class , like car2, car2 . . 
    - member Function : functions which are only used by obj from a particular class
    - 'String' is a class which internally occured in C++ under heading #include<string>
    - String str = "Hello" :-> str is a obj whose String is a dtype and a class for it. This String class have different methods like lenth and all
    - C++ Strings are objects of pre-defined string class in STL(Standard Template Library)
    - C++ Strings have useful member functions.
    - C++ Strings are dynamic (their size can change at run time), unlike char arr[5];
    - C++ Strings also support operators like +, ==, >, < etc
    - C++ Strings are sorted contiguously in memory.
    - getline(cin, str, '&'); -> taking input with spaces and multi word
    - we can access using index 
    - we can use comparision operator to string (=,<,>) unlike in char
9.for each loop
    - String str = "Hello";
    - for(int i = 0; i<str.length(); i++){
        cout<<str[i]<<" ";}
    - for( char ch : str){ // for using as a character
        cout<<ch<<","}
10.Member Function of string
    - str.
    - str.length(), str.at(3) -> value at index 3
    - str.substr(startIdx, size) ->Continuous part of an string is substring like a subarray, 
    - str.find(word) ->Search the word in that string and returns the index of 1st occurence of that , else -1
11.Valid Anagram
    - words can be rearranged to for other words using same character but change in arrangement
    - like 'theyes' and 'theysee'
    - using Sorting O(n log n)
    - using linear
      -(str.length != str2,lenth) return false
      -1.To store count of chars
        count[str[i]-'a']++
      -2.traverse the 2nd str
        
    */

#include <bits/stdc++.h>
using namespace std;

//To Upper case
void toUpper(char word[], int n){
  for(int i=0; i<n; i++){
    char ch = word[i];
    if(ch>='A' && ch<='Z'){ //uppercase
      continue;
    }else{
      word[i] = ch - 'a' + 'A';
    }
  }
}

// Reverse a char arr
void reverse(char word[], int n){
  int st=0, end=n-1;
  while(st<end){
    swap(word[st++],word[end--]);
    // st++;
    // end--;
  }
}

// Valid Palindrome
bool isPalindrome(char str[], int n){
  int st=0, end = n-1;
  while(st < end){
    if(str[st++] != str[end--]){
      cout<<"Is not a Palindrome!!\n";
      return false;
    }
  }
  cout<<"Valid Palindrome"<<endl;
  return true;  
}
//valid anagram
bool isAnagram(string str1, string str2){
  if(str1.length() != str2.length()){
    cout<< "not valid anagrams\n";
    return false;
  }

  int count[26] = {0};
  for(int i=0; i<str1.length(); i++){
    // int idx = str1[i]-'a';
    count[str1[i] - 'a']++;    // stores the frequency of every character like {1,0,2,. . . .of all 26 alphabet}
  }

  for(int i=0; i<str2.length(); i++){
    // int idx = str2[i] - 'a';
    if(count[str2[i] - 'a'] == 0){ 
      cout<<"not valid anagrams\n";
      return false;
    }
    count[str2[i] - 'a']--;
  }
  cout<<"valid anagrams\n";
  return true;
}

int main() {

  char word[] = "ApPle";
  toUpper(word, strlen(word));

  cout<<word<<endl;
  reverse(word, strlen(word));
  cout<<"Reverse = "<<word<<endl;

  char word2[] = "racecar";
  isPalindrome(word, strlen(word));
  isPalindrome(word2, strlen(word2));

  //Anagrams
  string str1 = "anagram";
  string str2 = "nagaram";
  isAnagram(str1, str2);
  return 0;
return 0; 
}