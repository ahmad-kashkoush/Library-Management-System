//
// Created by ahmed-kashkoush on 2/12/23.
//

#ifndef LIBRARYMANAGMENTSYSTEM_LIBRARY_H
#define LIBRARYMANAGMENTSYSTEM_LIBRARY_H
#include<bits/stdc++.h>
#define el "\n"
using namespace std;
void judge();
template<typename t3>
bool cmpId(const t3 &, const t3 &);
template<typename t4>
bool cmpName(const t4 &, const t4 &);
class user{
private:
    int id;
    string name;
public:
    user();
    user(int ,string);
    string GetName() const;
    int GetId()const;
    void Print();
    bool IsEqual(const user &) const;
    void enter();
};
class book{
private:
    int id, Quantity;
    string name;
    vector<user> users;
public:
    book();
    book(int id, string name, int quantity);
    bool IsPrefix(string);
    void UserBorrow(const user &);
    void UserReturn(const user &);
    string GetName()const;
    int    GetId()const;
    int GetQuantity()const;
    void PrintUsers();
    void Print();
};
class LibraryManagementSystem{
private:
    vector<book> books;
    vector<user> users;
    void AddBook();
    void AddUser();
    void SearchBooksByPrefix();
    void PrintWhoBorrowedBook();
    void PrintLibraryById();
    void PrintLibraryByName();
    void UserBorrow();
    void UserReturn();
    void PrintUser();
    void Run(int);
    template<typename t1>
    int SearchId(string ,  const vector<t1> & );

public:
    LibraryManagementSystem();
    void menu();

};
#endif //LIBRARYMANAGMENTSYSTEM_LIBRARY_H
