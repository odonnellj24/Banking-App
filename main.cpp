/*main.cpp*/

//
// Banking program in modern C++.
//
// <<Jack O'Donnell>>
// U. of Illinois, Chicago
// CS 341: Spring 2018
// Project 01
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "customer.h"

using namespace std;


int main()
{
  string  customerFilename, transactionsFilename;

  cin >> customerFilename;
  cout << customerFilename << endl;
  
  cin >> transactionsFilename;
  cout << transactionsFilename << endl;

  ifstream  custFile(customerFilename);
  ifstream  txFile(transactionsFilename);
  string    line,name,id,balance;
  cout << std::fixed;
  cout << std::setprecision(2);

  if (!custFile.good())
  {
    cout << "**ERROR: cannot open customers file: '" << customerFilename << "'" << endl;
    return -1;
  }
  if (!txFile.good())
  {
    cout << "**ERROR: cannot open transactions file: '" << transactionsFilename << "'" << endl;
    return -1;
  }
    vector<Customer> customers;
    
    
    
    while (getline(custFile,line))
    {
      stringstream ss(line);
      
      getline(ss,name, ',');
      getline(ss,id,',');
      getline(ss,balance);
      
      Customer C(name,stoi(id),stod(balance));
      
      customers.push_back(C);
      
    }
    cout << std::fixed;
    cout << std::setprecision(2);
    cout << ">> Customers before:"<< endl;
    
    std::sort (customers.begin(),customers.end(),
                [](Customer c1, Customer c2)
                {
                 if (c1.getName() < c2.getName())
                 {
                   return true;
                 }
                 else if (c2.getName() < c1.getName())
                 {
                   return false;
                 }
                }
                );
    for (Customer& c : customers)
    {
      cout << " " << c.getName() << " (" << c.getId() << "): $" << c.getBalance() << endl;
    }
    
    bool match= false;
    cout << ">> Processing..." << endl;
    while (getline(txFile,line))
    {
      stringstream tt(line);
      match = false;
      
      getline(tt,id,',');
      getline(tt,balance);
      
      for (Customer& p : customers)
      {
        if (stoi(id) == p.getId())
        {
          match = true;
          if((p.getBalance() + stod(balance))>=0){
            p.setBalance(stod(balance));
           
          }
          else{
            cout << " **Rejected Tx: " << p.getId() << "," << balance << endl;
          }
          
        }
        
      }
      if (match == false)
        {
          cout << " **Invalid Tx: " << stoi(id) << "," << stod(balance) << endl;
        }
    }
    
    cout << ">> Customers after: " << endl;
    
    std::sort (customers.begin(),customers.end(),
                [](Customer c1, Customer c2)
                {
                 if (c1.getBalance() > c2.getBalance())
                 {
                   return true;
                 }
                 else if (c2.getBalance() > c1.getBalance())
                 {
                   return false;
                 }
                 if (c1.getName() < c2.getName())
                {
                  return true;
                }
                else 
                {
                  return false;
                }
                }
                );
    
    
    for (Customer& c : customers)
    {
      cout << c.getName() << " (" << c.getId() << "): $" << c.getBalance() << endl;
    }
 
 
   return 0;
}
