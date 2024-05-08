#include<iostream>
using namespace std;
struct account{
string name;
int account_number;
double balance;
};
void create_account(account*& accounts,int& size){
 account newaccount;
 cout<<"Enter name: ";
 cin.ignore();
 getline(cin,newaccount.name);
 cout<<"Enter Account Number: ";
 cin>>newaccount.account_number;
 cout<<"Enter initial balance: ";
 cin>>newaccount.balance;
 account* temp=new account[size+1];
 for(int i=0;i<size;i++){
    temp[i]=accounts[i];
 }
 temp[size]=newaccount;
 delete[] accounts;
 accounts=temp;
 size++;

}
void delete_account(account*& accounts,int& size,int account_number){
    int index=-1;
    for(int i=0;i<size;i++){

        if(accounts[i].account_number==account_number){
            index=i;
            break;

        }
    }
    if(index==-1){
        cout<<" accoount not found "<<endl;
        return;

    }
    account* temp=new account[size-1];
    for(int i=0,j=0;i<size;i++){
        if(i!=index){
            temp[j++]=accounts[i];
        }
    }
    delete[] accounts;
    accounts =temp;
    size--;
    cout<<" account deleted "<<endl;

}
void find_account(account* accounts, int size, int account_number) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (accounts[mid].account_number == account_number) {
            cout << "Account found:" << endl;
            cout << "Name: " << accounts[mid].name << endl;
            cout << "Account Number: " << accounts[mid].account_number << endl;
            cout << "Balance: " << accounts[mid].balance << endl;
            return;
        } else if (accounts[mid].account_number < account_number) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Account not found " << endl;
}
void deposit_money(account& account, double amount) {
    account.balance += amount;
    cout << "Deposit successful. Current balance: " << account.balance << endl;
}
void withdraw_money(account& account, double amount) {
    if (amount > account.balance) {
        cout << "Insufficient balance." << endl;
    } else {
        account.balance -= amount;
        cout << "Withdrawal successful. Current balance: " << account.balance << endl;
    }
}
void show_allaccounts(const account* accounts, int size) {
    cout << "All Accounts:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Account " << i+1 << ":" << endl;
        cout << "Name: " << accounts[i].name << endl;
        cout << "Account Number: " << accounts[i].account_number << endl;
        cout << "Balance: " << accounts[i].balance << endl;
        cout << endl;
    }
}
int main() {
    account* accounts = nullptr;
    int size = 0;
    int choice;
    char op;

    do {
        cout << "Bank Management System" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Delete Account" << endl;
        cout << "3. Find Account" << endl;
        cout << "4. Deposit Money" << endl;
        cout << "5. Withdraw Money" << endl;
        cout << "6. Show All Accounts" << endl;
        cout << "7.Exit " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                create_account(accounts, size);
                break;
            case 2: {
                int account_number;
                cout << "Enter account number to delete: ";
                cin >> account_number;
                delete_account(accounts, size, account_number);
                break;
            }
            case 3: {
                int account_number;
                cout << "Enter account number to find: ";
                cin >> account_number;
                find_account(accounts, size, account_number);
                break;
            }
            case 4: {
                int account_number;
                double amount;
                cout << "Enter account number: ";
                cin >> account_number;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                for (int i = 0; i < size; i++) {
                    if (accounts[i].account_number == account_number) {
                        deposit_money(accounts[i], amount);
                        break;
                    }
                }
break;
            }
            case 5: {
                int account_number;
                double amount;
                cout << "Enter account number: ";
                cin >> account_number;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                // Find account
                for (int i = 0; i < size; i++) {
                    if (accounts[i].account_number == account_number) {
                        withdraw_money(accounts[i], amount);
                        break;
                    }
                }
                break;
            }
            case 6:
                show_allaccounts(accounts, size);
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    }while (choice!=7);


    delete[] accounts;
    return 0;
}
