//Xiaoming Huang
//CS181 homework 6
#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <sstream>
#include <climits>
#include <algorithm>
#include <iomanip>
using namespace std;



//----------------question 1----------------
struct PayCoin(){
    long transID; //the transaction id
    vector<int> num; //sub num of each coin
    vector<double> values; //list of coin values
    vector<long> recipients; //list of recipients public key

    PayCoin* prev;

    PayCoin(long _transID, vector<double> _values, vector<long> _recipients){
        prev = nullptr;
        transID = _transID;
        for(int i=0; i<values.size(); i++){
            num[i] = i;//assigning num to be from 0 to the # of values we have
        }
        values = _values;
        recipients = _recipients;
    }

}


//----------------question 2----------------

struct blockchain(){
    long HashValue;
    PayCoin* head;

    blockchain(){
        head = nullptr;
    }

    // add a new transaction to the head of the blockchain
    void append(PayCoin* newTrans) {
        if (head == nullptr){ // if the blockchain is empty, newTrans will be the new coin
            newTrans->prev = nullptr;
            head = newTrans; // making head pointing to the new trans
        } else {
            newTrans->prev = head; // make head(most current trans in blockchain to be the prev of the new one)
            head = newTrans; // making head pointing to the new trans
        }
    }
}


//----------------question 3----------------

bool verifySignature(pubKey, message, signature);
//assuming already implemented
//verifies for the signature, return true if valid, false if invalid


//sum the values in a tran
double sum(PayCoin* trans){
    double sum = 0;
    vector<double> val = trans.values;//copy the trans' value vector to val

    for(i=0; i<val.size(); i++){
        sum = sum + val[i]; // summing the values in the trans
    }

    return sum;
}



// function needs to check the four conditions:
//input: the new transaction sending
//       the coins consumed
//       the blockchain we focus on
//       the signature signed on consumed coins
void checkValid(PayCoin* newTrans, PayCoin* consumedTrans, blockchain* chain, vector<long> sig){

    // check 1. consumed coins exist;
    if(chain.head == nullptr){
        //no coins to consume as blockchain is empty
        //so consumed coins invalid
        cout << "consumed coins invalid\n\n";
        return;
    }

    // check 2. consumed coins hasn't been consumed;
    if(consumedTrans != chain.head){
        // when consumed trans is not the most current trans in the blockchain,
        // so either it has already been consumed
        // or it doesn't belong to this block chain
        cout << "consumed coins invalid\n\n";
        return;
    }

    // check 3. total value of consumed coins = total value transacted
    if(sum(newTrans) != sum(spent)){
        //when new trans value sum not equal to sum consumed
        cout << "total value not matched\n\n";
        return;
    }


    // check 4. valid signature
    if(consumedTrans.values.size() != sigature.size()){
        cout << "number of signatures not matched\n\n";
        return;
    } else {
        if(!verifySignature(consumedTrans.recipients, newTrans, sig)){
            //calling on verifySignature(), where
            //    consumedTrans.recipients is the list of public key
            //    newTrans is the message of transaction
            //    sig is the signature input at this function
            //if the signature is invalid, then transaction fails
            cout << "signature invalid\n\n";
            return;
        }
    }

    //if all four conditions matched, we can append this into the blockchain
    chain.append(newTrans);

}




int main(){
    return 0;
}
