
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;


const string FileName = "Bank.text";

struct stClient {

    string AccountNumber;
    string PinCode;
    string FullName;
    string Phone;
    double Balance;
    bool MarkToDelete = false;

};


short ReadNumber(string message);

string ReadString(string message);

vector<string> SplitLine(string Line, string Delim);

string ConvertRecordToLine(stClient client, string Delim);

stClient ConvertLineToRecord(string client);

vector<stClient> LoadClientsDataFromFile(string FileName);

void SaveClientsDataToFile(string FileName, vector<stClient> vClients);

void AddClientToFile(string FileName, string Data);

void PrintClientRecord(stClient client);

void PrintClient(stClient c);

bool FindClientByAccountNumber(vector<stClient> vClients, stClient &client, string AccNum);

bool ClientExistByAccountNumber(string filename, string AccNum);

stClient ReadClient();

void AddClientRecord();

void AddClients();

bool DeleteClientByAccountNumber(vector<stClient> &vClients, string AccNum);

bool UpdateClientByAccountNumber(vector<stClient> &vClients, string AccNum);

void ChangeClientData(stClient &client);

bool MarkClientForDelete(vector<stClient> &vClients, string AccNum);

void PrintCell(string data, short alignment);



void MainMenueScreen();

void TransactionsMeneuScreen();

void ShowClientsScreen();

void AddClientsScreen();

void DeleteClientScreen();

void UpdateClientScreen();

void FindClientScreen();

void ExitScreen();

void PerformOperation(short op);

void PerformTransactionOperation(short op);

void ReturnToMainMenue();

void DepositeScreen();

void WithdrawScreen();

void TransactionWithAccountNumber(string AccNum, vector<stClient>& vClients, char OP);

void TotalBalancesScreen();

void ReturnToTransactionMenue();






int main()
{
    MainMenueScreen();
}






void MainMenueScreen() {
    system("cls");

    cout << "\n=================================================\n";
    cout << "\t\t" << "Main Menue Screen" << "\t\t\n";
    cout << "=================================================\n\n";
    cout << "\t" << "[1]" << " Show Client List.\n";
    cout << "\t" << "[2]" << " Add New Client.\n";
    cout << "\t" << "[3]" << " Delete Client.\n";
    cout << "\t" << "[4]" << " Update Client Data.\n";
    cout << "\t" << "[5]" << " Find Client by Account Number.\n";
    cout << "\t" << "[6]" << " Transactions Menue Screen.\n";
    cout << "\t" << "[7]" << " Exit From App.\n\n";

    char OP = ReadNumber("Please Enter Your Choice : ");

    PerformOperation(OP);
}

void TransactionsMeneuScreen() {
    system("cls");

    cout << "\n=================================================\n";
    cout << "\t\t" << "Transactions Menue Screen" << "\t\t\n";
    cout << "=================================================\n\n";
    cout << "\t" << "[1]" << " Deposite.\n";
    cout << "\t" << "[2]" << " Withdraw.\n";
    cout << "\t" << "[3]" << " Total Balances.\n";
    cout << "\t" << "[4]" << " Main Menue.\n\n";

    char OP = ReadNumber("Please Enter Your Choice : ");

    PerformTransactionOperation(OP);
}

void ShowClientsScreen() {

    vector<stClient> vClients = LoadClientsDataFromFile(FileName);
    cout << "\n\t\t\t\tClient List(" << vClients.size() << ") Client(s)\n";
    cout << "______________________________________________________________________________________________________________________\n\n";
    PrintCell("Account Number", 20);
    PrintCell("Pin Code", 15);
    PrintCell("Client Name", 30);
    PrintCell("Phone", 20);
    PrintCell("Balance", 10);

    if (vClients.size() == 0) {
        cout << "\n\n\n\t\t\t\t\t\tThere is no clients !";
    }
    else {
        for (stClient& c : vClients) {
            PrintClientRecord(c);
        }
    }

    cout << "\n______________________________________________________________________________________________________________________\n";
}

void AddClientsScreen() {

    cout << "\n========================================================\n";
    cout << "\t\tAdd New Client Screen\t\t";
    cout << "\n========================================================\n";
    cout << "Adding New Client\n";

    AddClients();
}

void DeleteClientScreen() {

    vector<stClient> vClients = LoadClientsDataFromFile(FileName);
    string AccNum;

    cout << "\n========================================================\n";
    cout << "\t\tDelete Client Screen\t\t";
    cout << "\n========================================================\n";

    cout << "\nPlease enter account number : ";
    cin >> AccNum;

    DeleteClientByAccountNumber(vClients, AccNum);

}

void UpdateClientScreen() {

    vector<stClient> vClients = LoadClientsDataFromFile(FileName);
    stClient client;
    string AccNum;

    cout << "\n========================================================\n";
    cout << "\t\tUpdate Client Screen\t\t";
    cout << "\n========================================================\n";

    cout << "\nPlease enter account number : ";
    cin >> AccNum;

    UpdateClientByAccountNumber(vClients, AccNum);
}

void FindClientScreen() {

    vector<stClient> vClients = LoadClientsDataFromFile(FileName);
    stClient client;
    string AccNum;
    char answer = 'n';

    cout << "\n========================================================\n";
    cout << "\t\Find Client Screen\t\t";
    cout << "\n========================================================\n";

    cout << "\nPlease enter account number : ";
    cin >> AccNum;

    if (!FindClientByAccountNumber(vClients, client, AccNum)) {

        cout << "\nThis Account Number Not Found.\n";
    }
    else {
        PrintClient(client);
        cout << endl;
    }
}

void ExitScreen() {

    system("cls");
    cout << "\n========================================================\n";
    cout << "\t\Program Ends  :-)\t\t";
    cout << "\n========================================================\n";

}

void PerformOperation(short op) {

    switch (op)
    {
    case 1:
        system("cls");
        ShowClientsScreen();
        ReturnToMainMenue();
        break;
    case 2:
        system("cls");
        AddClientsScreen();
        ReturnToMainMenue();
        break;
    case 3:
        system("cls");
        DeleteClientScreen();
        ReturnToMainMenue();
        break;
    case 4:
        system("cls");
        UpdateClientScreen();
        ReturnToMainMenue();
        break;
    case 5:
        system("cls");
        FindClientScreen();
        ReturnToMainMenue();
        break;
    case 6:
        TransactionsMeneuScreen();
        break;
    case 7:
        ExitScreen();
        break;
    }

}

void PerformTransactionOperation(short op) {

    switch (op)
    {
    case 1:
        system("cls");
        DepositeScreen();
        ReturnToTransactionMenue();
        break;
    case 2:
        system("cls");
        WithdrawScreen();
        ReturnToTransactionMenue();
        break;
    case 3:
        system("cls");
        TotalBalancesScreen();
        ReturnToTransactionMenue();
        break;
    case 4:
        system("cls");
        MainMenueScreen();
        break;
    }

}

void ReturnToMainMenue() {
    system("pause");
    cout << "\nPress any key to return to main menue screen .....";
    MainMenueScreen();
}




string ReadString(string message) {

    string word;
    cout << message;
    cin >> word;

    return word;
}

short ReadNumber(string message) {
    short n;
    cout << message;
    cin >> n;

    return n;
}

vector<string> SplitLine(string Line, string Delim) {

    vector<string> vStrings;
    int pos = 0;
    string word;

    while ((pos = Line.find(Delim)) != std::string::npos) {

        word = Line.substr(0, pos);
        if (word != "") {
            vStrings.push_back(word);
        }
        Line.erase(0, pos + Delim.length());
        
    }

    if (Line != "") {
        vStrings.push_back(Line);
    }

    return vStrings;
}

string ConvertRecordToLine(stClient client, string Delim) {

    string Line = "";

    Line = Line + client.AccountNumber + Delim;
    Line = Line + client.PinCode + Delim;
    Line = Line + client.FullName + Delim;
    Line = Line + client.Phone + Delim;
    Line = Line + to_string(client.Balance)+ Delim;

    return Line;
}

stClient ConvertLineToRecord(string client) {
    
    stClient c;
    vector<string> ClientData = SplitLine(client, "####");

    c.AccountNumber = ClientData[0];
    c.PinCode = ClientData[1];
    c.FullName = ClientData[2];
    c.Phone = ClientData[3];
    c.Balance = stod(ClientData[4]);

    return c;
}

vector<stClient> LoadClientsDataFromFile(string filename) {

    vector<stClient> vClients;
    fstream MyFile;
    MyFile.open(filename, ios::in);

    if (MyFile.is_open()) {
        string Line;
        stClient client;

        while (getline(MyFile, Line))
        {
            client = ConvertLineToRecord(Line);
            vClients.push_back(client);
        }
        MyFile.close();
    }

    return vClients;
}

void SaveClientsDataToFile(string FileName, vector<stClient> vClients) {

    fstream MyFile;
    string Line;

    MyFile.open(FileName, ios::out);

    if (MyFile.is_open()) {

        for (stClient& c : vClients) {

            if (c.MarkToDelete == false) {

                Line = ConvertRecordToLine(c, "####");
                MyFile << Line << endl;
            }
            
        }
        MyFile.close();
    }
    
}

void AddClientToFile(string FileName, string Data) {

    fstream MyFile;

    MyFile.open(FileName, ios::app);

    if (MyFile.is_open()) {
        MyFile << Data << endl;
    }

    MyFile.close();
}

void PrintClientRecord(stClient client) {

    cout << endl;

    PrintCell(client.AccountNumber, 20);
    PrintCell(client.PinCode, 15);
    PrintCell(client.FullName, 30);
    PrintCell(client.Phone, 20);
    PrintCell(to_string(client.Balance), 10);

}

void PrintClient(stClient c) {

    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccout Number: " << c.AccountNumber;
    cout << "\nPin Code : " << c.PinCode;
    cout << "\nName : " << c.FullName;
    cout << "\nPhone : " << c.Phone;
    cout << "\nAccount Balance: " << c.Balance;
    cout << "\n-----------------------------------\n";
}

bool FindClientByAccountNumber(vector<stClient> vClients, stClient& client, string AccNum) {

    for (stClient& c : vClients) {

        if (c.AccountNumber == AccNum) {
            client = c;
            return true;
        }
    }

    return false;
}

bool ClientExistByAccountNumber(string filename, string AccNum) {

    vector<stClient> vClients = LoadClientsDataFromFile(filename);

    for (stClient& c : vClients) {

        if (c.AccountNumber == AccNum) {

            return true;
        }
    }

    return false;
}

stClient ReadClient() {

    stClient c;

    cout << "\nEnter Account Number : ";
    getline(cin >> ws, c.AccountNumber);

    while (ClientExistByAccountNumber(FileName, c.AccountNumber))
    {
        cout << "\nThe client with Account Number [" << c.AccountNumber << "]" << " is already exists , Enter another Account Number : ";
        getline(cin >> ws, c.AccountNumber);
    }

    cout << "\nEnter Pin Code : ";
    getline(cin, c.PinCode);

    cout << "\nEnter Full Name : ";
    getline(cin, c.FullName);

    cout << "\nEnter Phone : ";
    getline(cin, c.Phone);

    cout << "\nEnter Balance : ";
    cin >> c.Balance;

    return c;
}

void AddClientRecord() {

    stClient c = ReadClient();
    AddClientToFile(FileName, ConvertRecordToLine(c, "####"));
}

void AddClients() {

    char answer = 'y';

    do
    {
        AddClientRecord();
        cout << "\nClient added successfully , Do you want to add another client ? y/n : ";
        cin >> answer;

    } while ('y' == tolower(answer));
}

bool DeleteClientByAccountNumber(vector<stClient>& vClients, string AccNum) {

    stClient client;
    char answer;

    if (FindClientByAccountNumber(vClients, client, AccNum)) {

        PrintClient(client);
        cout << "\nAre you sure you want to delete client ? y/n : ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y') {

            MarkClientForDelete(vClients, AccNum);
            SaveClientsDataToFile(FileName, vClients);
            cout << "\nClient deleted successfully.\n";
            
            return true;
        }
    }
    else {
        cout << "\nClient with Account Number (" << AccNum << ") is Not Found!";
    }

    return false;
}

bool UpdateClientByAccountNumber(vector<stClient>& vClients, string AccNum) {

    stClient client;
    char answer;

    if (FindClientByAccountNumber(vClients, client, AccNum)) {

        PrintClient(client);
        cout << "\nAre you sure you want to update client ? y/n : ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y') {

            for (stClient& c : vClients) {

                if (c.AccountNumber == AccNum) {

                    ChangeClientData(c);
                    break;
                }
            }
            SaveClientsDataToFile(FileName, vClients);
            cout << "\nClient updated successfully.\n";

            return true;
        }
    }
    else {
        cout << "\nClient with Account Number (" << AccNum << ") is Not Found!";
    }

    return false;
}

void ChangeClientData(stClient& client) {

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, client.PinCode);

    cout << "Enter Name? ";
    getline(cin, client.FullName);

    cout << "Enter Phone? ";
    getline(cin, client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> client.Balance;
    
}

bool MarkClientForDelete(vector<stClient>& vClients, string AccNum) {
    
    for (stClient& c : vClients) {

        if (c.AccountNumber == AccNum) {
            c.MarkToDelete = true;
            return true;
        }
    }

    return false;
}

void PrintCell(string data, short alignment) {

    cout << "| " << left << setw(alignment) << data;

}

void DepositeScreen() {

    vector<stClient> vClients = LoadClientsDataFromFile(FileName);
    string AccNum;

    cout << "\n========================================================\n";
    cout << "\t\tDeposite Screen\t\t";
    cout << "\n========================================================\n";

    cout << "\nEnter Account Number : ";
    cin >> AccNum;

    TransactionWithAccountNumber(AccNum, vClients, 'd');
}

void TransactionWithAccountNumber(string AccNum, vector<stClient>& vClients, char OP) {

    stClient client;
    char answer;
    double amount;

    if (FindClientByAccountNumber(vClients, client, AccNum)) {
        
        cout << endl;
        PrintClientRecord(client);

        cout << "\nEnter deposite amount : ";
        cin >> amount;

        cout << "\nAre you sure to perform this transaction : ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y') {

            cout << "\nThe Transaction done successfully.\n";

            for (stClient& c : vClients) {

                if (c.AccountNumber == AccNum) {

                    if (OP == 'd') {
                        c.Balance = c.Balance + amount;
                    }
                    else {

                        if (amount < c.Balance) {
                            c.Balance = c.Balance - amount;
                        }
                        else {
                            cout << "\nThere is no enough money.\n";
                        }
                    }
                    break;
                }
            }
            SaveClientsDataToFile(FileName, vClients);
        }
    }
    else {
        cout << "\nClient with Account Number (" << AccNum << ") is Not Found!";
    }

}

void WithdrawScreen() {

    vector<stClient> vClients = LoadClientsDataFromFile(FileName);
    string AccNum;

    cout << "\n========================================================\n";
    cout << "\t\tWithdraw Screen\t\t";
    cout << "\n========================================================\n";

    cout << "\nEnter Account Number : ";
    cin >> AccNum;

    TransactionWithAccountNumber(AccNum, vClients, 'w');

}

void TotalBalancesScreen() {

    vector<stClient> vClients = LoadClientsDataFromFile(FileName);
    string AccNum;
    double TotlaBalances = 0;

    for (stClient& c : vClients) {
        TotlaBalances = TotlaBalances + c.Balance;
    }

    cout << "\n\t\t\t\tBalance List(" << vClients.size() << ") Client(s)\n";
    cout << "______________________________________________________________________________________________________________________\n\n";
    PrintCell("Account Number", 20);
    PrintCell("Client Name", 45);
    PrintCell("Balance", 30);

    if (vClients.size() == 0) {
        cout << "\n\n\n\t\t\t\t\t\tThere is no clients !";
    }
    else {
        for (stClient& c : vClients) {
            PrintClientRecord(c);
        }
    }

    cout << "\n______________________________________________________________________________________________________________________\n";

    cout << "\n\t\t\t\tTotal Balances = " << TotlaBalances << endl;

}

void ReturnToTransactionMenue() {
    system("pause");
    cout << "\nPress any key to return to transaction menue screen .....";
    TransactionsMeneuScreen();
}