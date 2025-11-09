#include<iostream>
#include<string>
using namespace std;
class BankAccount{
    string number;
    string name;
    double balance=0;
public:
     BankAccount(){
        number="\0";
        name="\0";
        balance=0;
     }
    void addAccount(string number, string name){
        this->number=number;
        this->name=name;
    }
    void setname(string name){
    this->name=name;
    }
     void setbalance(double balance){
    this->balance=balance;
    }
     void setnumber(string number){
    this->number=number;
    }
    void display(){
    cout<<"number"number<<endl;
    cout<<"name"<<name<<endl;
    cout<<"balance"<<balance<<endl;
    }
    void deposit(string number,double balance){
    this->balance=this->balance+balance;
    }

    void withdraw(string number,double balance){
    this->balance=this->balance-balance;
    }
    void remove(string number){
        if(this->number==number){
        number="\0";
        name="\0";
        balance=0;
        }
    }

    ~BankAccount(){
        this->number="\0";
        this->name="\0";
        this->balance=0;
    }
};

class Bank{
     BankAccount *acc;
     int user;
public:
    Bank(){
    acc= new  BankAccount[50];
    user=0;
    }

    void addAccount(string number, string name){
    acc[user].addAccount(number, name);
    user++;
    }
    void deposit(double balance){
    acc[user].deposit( balance);
    }

    void withdraw(double balance){
    acc[user].withdraw(balance);
    }
    void displayAllAccounts(){
    for(int i=0;i<user;i++){
        acc[i].display();
    }
    }
    void remove(string num){
        for(int i=0;i<user;i++){
                    acc[i].remove(num);
        }
    }
    ~Bank(){
    delete[] acc;
    user=0;
    }
};


int main(){

    Bank bank;
// Add new bank accounts
bank.addAccount("12345", "John Doe");
bank.addAccount("67890", "Jane Smith");
// Perform transactions
bank.deposit("12345", 1000.0);
bank.deposit("67890", 500.0);
// Display account details
bank.displayAllAccounts();
// Perform transactions
bank.withdraw("12345", 200.0);
bank.withdraw("67890", 500.0);
// Display account details after transaction
bank.displayAllAccounts();
// Remove an account
bank.removeAccount("67890");
// Display account details after removal
bank.displayAllAccounts();
// Add more accounts
bank.addAccount("24680", "Sarah Adams");
bank.addAccount("13579", "Michael Lee");
// Perform transactions on the newly added accounts
bank.deposit("24680", 1500.0);
bank.deposit("13579", 200.0);
bank.withdraw("13579", 100.0);
bank.withdraw("24680", 300.0);
// Display all accounts
bank.displayAllAccounts();

return 0;
}
