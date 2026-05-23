#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string accountHolderName;
    long long int accountNumber;
    string accountType;
    double balance;

public:
    void createAccount()
    {
        cout << "\nEnter Account Holder Name: ";
        cin.ignore();
        getline(cin, accountHolderName);

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Account Type (Savings/Current): ";
        cin >> accountType;

        cout << "Enter Initial Deposit Amount: ";
        cin >> balance;

        cout << "\nAccount Created Successfully!\n";
    }

    long long int getAccountNumber()
    {
        return accountNumber;
    }

    void deposit()
    {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit Successful.\n";
            cout << "Updated Balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid amount.\n";
        }
    }

    void withdraw()
    {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount.\n";
        }
        else if (amount > balance)
        {
            cout << "Insufficient Balance.\n";
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal Successful.\n";
            cout << "Remaining Balance: " << balance << endl;
        }
    }

    void displayAccount()
    {
        cout << "\n----- Account Details -----\n";
        cout << "Account Holder Name : " << accountHolderName << endl;
        cout << "Account Number      : " << accountNumber << endl;
        cout << "Account Type        : " << accountType << endl;
        cout << "Current Balance     : " << balance << endl;
    }
};

int main()
{
    BankAccount accounts[100];
    int totalAccounts = 0;
    int choice;
    long long accNo;
    bool found;

    do
    {
        cout << "\n====== BANK MANAGEMENT SYSTEM ======\n";
        cout << "1. Create New Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            accounts[totalAccounts].createAccount();
            totalAccounts++;
            break;

        case 2:
            cout << "Enter Account Number: ";
            cin >> accNo;
            found = false;

            for (int i = 0; i < totalAccounts; i++)
            {
                if (accounts[i].getAccountNumber() == accNo)
                {
                    accounts[i].deposit();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Account not found.\n";
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accNo;
            found = false;

            for (int i = 0; i < totalAccounts; i++)
            {
                if (accounts[i].getAccountNumber() == accNo)
                {
                    accounts[i].withdraw();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Account not found.\n";
            break;

        case 4:
            cout << "Enter Account Number: ";
            cin >> accNo;
            found = false;

            for (int i = 0; i < totalAccounts; i++)
            {
                if (accounts[i].getAccountNumber() == accNo)
                {
                    accounts[i].displayAccount();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Account not found.\n";
            break;

        case 5:
            cout << "Thank you for using our banking system.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
