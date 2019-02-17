/*customer.h*/

//
// Customer class for banking program in modern C++.
//
// <<Jack O'Donnell>>
// U. of Illinois, Chicago
// CS 341: Spring 2018
// Project 01
//

#pragma once

#include <iostream>
#include <string>

using namespace std;


class Customer
{
  private:
  string Name;
  int Id;
  double Balance;
  
  public:
  Customer (string name, int id, double balance)
          : Name(name), Id(id), Balance(balance)
          { }
  
  
  
  
  string getName(){
    return Name;
  }
  
  int getId(){
    return Id;
  }
  
  double getBalance(){
    return Balance;
  }
  
  double setBalance(double newBalance){
    Balance += newBalance;
    return Balance;
  }
  // 
  // TODO
  //
  
};
