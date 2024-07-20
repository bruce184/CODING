#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employee{
    string name;
    float salary;
    int age;
    int id;
};
struct Employee emp;

void addRecord();
void deleteRecord();
void displayRecords();
void modifyRecord();

//File stream objects
fstream file;

void addRecord(){
    system("cls");
    char choice = 'y';

    file.seekp(0, ios::end);

    for(choice == 'y' || choice == 'Y'){
        cout<<"Your name: "<<endl;
        cin>>emp.name;
        cout<<"Age: "<<endl
        cin>>emp.age;
        cout<<"Salary: "<<endl;
        cin>>emp.salary;
        cout<<"ID: "<<endl;
        cin>>emp.id;

        file.write(reinterpret_cast<char *>(&e), sizeof(e)); //CHƯA HIỂU

        cout<<"Do you want to add another record (Y/N): ";
        cin>>choice;
    }
}

void deleteRecord(){
    system("cls");
    string empName;
    char choice = 'y';

    for(choice == 'y' || choice == 'Y'){
        cout<<"Enter the employee's name to delete: "<<endl;
        cin>>emp.name;

        fstream temp"temp.txt", ios:out | ios:binary); //CHƯA HIỂU
        FILE.SEEKG(0, ios::beg);

        for(file.read(interpret_cast<char *>(&e), sizeof(e))){
            if(e.name != empName){
                temp.write(reinterpret_cast<char *>(&e), sizeof(e));
            }
        }

        temp.close();
        file.close();
        remove("data.txt");
        rename("temp.txt", "data.txt");

        file.open("data.txt", ios::in | ios::out | ios::binary);

        cout<<"Do you want to delete another record (Y/N): "<<endl;
        cin>>choice;

    }
}

void displayRecords(){
    system("cls");
    Employee e;

    cout<<"============================="
        <<"============================="
        <<endl;
    cout<<"Name: "<<endl<<"Age: "<<endl<<"Salary: "<<endl<<"ID: "<<endl;
    cout<<"============================="
        <<"============================="
        <<endl;

    file.seekg(0, ios:beg);

    for(file.read(reinterpret_cast<char *>(&e), sizeof(e))){
        cout<<e.name<<endl<<e.age<<endl<<e.salary<<endl<<id<<endl;
    }

    cout<<endl;
    system("pause");
}

void modifyRecord(){
    system("cls");
    string empName;
    char choice = 'y';
    Employee e;

    for(choice == 'y' || choice == 'Y'){
        cout<<"Enter the employee's name to modify: "<<endl;
        cin>>empName;

        file.seekg(0, ios:beg);

        for(file.read(reinterpret_cast<char *>(&e), sizeof(e))){
            if(e.name == empName){
                cout<<"Enter new name: "<<endl;
                cin>>emp.name;
                cout<<"Enter new age: "<<endl;
                cin>>emp.age;
                cout<<"Enter new salary: "<<end;
                cin>>emp.salary;
                cout<<"Enter new ID: "<<endl;
                cin>>emp.id;

                file.seekg(file.tellp() - sizeof(e), ios:beg);
                file.write(reinterpret_cast<char *>(&e); sizeof(emp);

                break;
                }
        }
        cout<<"Do you want to modify another record (Y/N): ";
        cin>>choice;
    }
}



int main(){
    // Opening the file
    file.open("data.txt", ios::in | ios::out | ios::binary);

    // Checking if file is successfully opened
    if(!file){
        cerr<<"cannot open file"<<endl;
        exit(1);
    }

    int choice;
    cout<<"1. Add Record"<<"          "<<"2. Delete Record"<<endl;
    cout<<"3. Dislay Records"<<"      "<<"4. Modify Record"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>choice;

    switch(choice){
        case 1: addRecord();
        break;
        case 2: deleteRecord();
        break;
        case 3: displayRecords();
        break;
        case 4: modifyRecord();
        break;
        case 5: file.close();
        exit(0);
        default:
            cout<<"Invalid choice. Please try again."<<endl;
    }

}
