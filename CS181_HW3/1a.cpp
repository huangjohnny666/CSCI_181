//Xiaoming Huang
//CS181 homework 3 Question 1a)
#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;


  //print the array of length n
void print(int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

  //print the vector of any size
void print(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl << endl;
}

  //change int number to an array of size n, which is the binary representation of number
vector<int> DecimalToBinary(int number, int n){
    int temp = number;
    vector<int> binary(n, 0);
    int base = pow(2, n-1);
    for(int i=0; i<n; i++){
        if(temp >= base){
            binary[i] = 1;
            temp = temp-base;
        } else {
            binary[i] = 0;
        }
        base = base/2;
    }
    return binary;
}

  //ConvertBitArraytoInt()
vector<int> ConvertBitArraytoInt(vector<int> k, int n){
    //n is bit length, Ksize is # of output K
    int KSize = k.size()/n;
    vector<int> K(KSize, 0);

    //create array base[] to store each bit's value
    int base[n];
    for(int b=0; b<n; b++){
        base[b] = pow(2, n-b-1);
    }

    int sum = 0;
    for(int i=0; i<KSize; i++){
        for(int j=0; j<n; j++){
            if(k[ (i*n)+j ] == 1){
                sum = sum + base[j];
                //cout << base[j] << " ";
            }
        }
        //cout << endl;
        K[i] = sum;
        sum = 0;
    }
    return K;
}

int main(){
    cout << "Result of DecimalToBinary(100, 8): \n";
    print(DecimalToBinary(100, 8));

    //create a vector and copy value from array into it
    vector<int> bit_vec(12, 0);
    int bit_arr[] = {1,0,0,0,0,0,1,1,1,0,0,1};
    for(int i=0; i<12; i++){
        bit_vec[i] = bit_arr[i];
    }
    cout << "Result of ConvertBitArraytoInt([1,0,0,0,0,0,1,1,1,0,0,1], 3): \n";
    print(ConvertBitArraytoInt(bit_vec, 3));
    return 0;
}
