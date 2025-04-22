#include <iostream> 
#include <vector>    
#include <utility>   
#include <ctime>    
#include <cstdlib> 
#include <string> 
using namespace std;

class Account{
    int dogecoin, balance;
    int bitcoin;
    int deposit, withdraw;
    int total_equity;
    int predict;
    int dogecoin_value;
    int bitcoin_value;
    int crypto_invest;
    int crypto_return;

    vector<pair<string, int>> transactions;

    public:
        bool Deposit(int money)
        {
            deposit += money;
            balance += money;
            transactions.push_back({"Deposit", money});
            return true; 
        }

        void Get_account_information()
        {
            cout << "Money Details:\n";
            cout << "Bank Balance: " << balance << endl;
            cout << "Dogecoin: " << dogecoin << endl;
            cout << "Bitcoin: " << bitcoin << endl;
        }

        bool Withdraw(int money)
        {
            if(money > balance){
                return false;
            }
            withdraw += money;
            balance -= money;
            transactions.push_back({"Withdraw", money}); 
            return true;
        }

        bool buy_crypto()
        {
            int option;
            cout << "Want to purchase dogecoin press 1 else "
                    "for bitcoin press 2\n";
            cin >> option;

            if(total_equity != 0){
                srand(time(NULL));
                int luck = rand();

                if(luck % 251 == 0){
                    if(option == 1){
                        if(balance >= dogecoin_value) { 
                            dogecoin += 1;
                            balance -= dogecoin_value;
                            crypto_invest += dogecoin_value;
                            transactions.push_back({"Dogecoin Bought", dogecoin_value});
                            return true;
                        } else {
                            return false;
                        }
                    }
                    else{
                        if(balance >= bitcoin_value) { 
                            bitcoin += 1;
                            balance -= bitcoin_value;
                            crypto_invest += bitcoin_value;
                            transactions.push_back({"Bitcoin Bought", bitcoin_value});
                            return true;
                        } else {
                            return false;
                        }
                    }
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }

        bool sell_crypto()
        {
            int option;
            cout << "Want to sell dogecoin press 1 else for "
                    "bitcoin press 2\n";
            cin >> option;
            if(option == 2){
                if(bitcoin == 0)
                    return false;
                crypto_return += bitcoin_value;
                balance += bitcoin_value;
                transactions.push_back(
                    {"Bitcoin Sold", bitcoin_value} 
                );
                bitcoin -= 1;
            }
            else{
                if(dogecoin == 0)
                    return false;
                crypto_return += dogecoin_value;
                balance += dogecoin_value;
                transactions.push_back(
                    {"Dogecoin Sold", dogecoin_value} 
                );
                dogecoin -= 1;
            }
            return true;
        }

        void History()
        {
            cout << "Displaying All transactions\n";
            for(auto it : transactions){
                cout << it.first << ": " << it.second << endl;
            }
            char temp;
            cout << "Do you want to clear all transactions? (Y/N): ";
            cin >> temp;

            int no = transactions.size();

            if(temp == 'Y' || temp == 'y'){
                transactions.clear();
                cout << "Total transactions cleared: " << no << endl;
            } else {
                cout << "Total transactions: " << no << endl;
            }
        }

        Account()
        {
            crypto_invest = 0;
            crypto_return = 0;
            total_equity = 100;

            balance = 50000;
            dogecoin = 0;
            bitcoin = 0;
            withdraw = 0;
            deposit = 0;
            dogecoin_value = 100;
            bitcoin_value = 500; 
        }
};

int main()
{
    Account person;
    int amount, choice;
    bool check;
    while(1){
        cout << "******************************************\n";
        cout << endl;
        cout << "Press 1 to view your Account Info " << endl;
        cout << "Press 2 to Deposit money " << endl;
        cout << "Press 3 to Withdraw money " << endl;
        cout << "Press 4 to view Transaction History " << endl;
        cout << "Press 5 to Buy Crypto " << endl;
        cout << "Press 6 to Sell Crypto " << endl;
        cout << "Press any other key to exit\n" << endl;
        cout << "******************************************\n";
 
        cin >> choice;
        bool ans; 
 
        switch (choice) {
        case 1:
            person.Get_account_information();
            break;
 
        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            ans = person.Deposit(amount);
            if (ans)
                cout << "Successfully deposited money" << endl;
            else
                cout << "Failed\n";
            break;
 
        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            ans = person.Withdraw(amount); 
 
            if (ans)
                cout << "Successfully withdrawn Amount" << endl;
            else
                cout << "Not Enough Balance\n";
            break;
 
        case 4:
            person.History();
            break;
 
        case 5:
            ans = person.buy_crypto();
            if (ans)
                cout << "Successful Transaction" << endl;
            else
                cout << "Better Luck next time\n";
            break;
 
        case 6:
            ans = person.sell_crypto();
            if (ans)
                cout << "Successful Transaction" << endl;
            else
                cout << "Not Enough Cryptocoins\n";
            break;
 
        default:
            exit(0);
            break;
        }
    }
}