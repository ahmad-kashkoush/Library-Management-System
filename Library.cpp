//
// Created by ahmed-kashkoush on 2/12/23.
//

#include "Library.h"
void judge() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
}
template<typename t4>
bool cmpName(const t4 &a, const t4 &b) {
    return a.GetName()<=b.GetName();
}
template<typename t3>
bool cmpId(const t3 &a, const t3 &b) {
    return a.GetId()<=b.GetId();
}



LibraryManagementSystem::LibraryManagementSystem() {
    books.clear();
    users.clear();
}
void LibraryManagementSystem::AddBook() {
        cout<<"Enter Book id, Name and Quantity : ";
        int id, quantity;string name;
        cin>>id>>name>>quantity;
        books.emplace_back(id, name, quantity);

}
void LibraryManagementSystem::SearchBooksByPrefix() {
    cout<<"Enter Book Name :\n";
    string name;cin>>name;
    cout<<"\n---------Books Start with "<<name<<"------------\n";
    bool ok=false;
    for(auto bk:books) {
        if (bk.IsPrefix(name)) {
            ok = true;
            cout << bk.GetName() << el;
        }
    }
    if(!ok)cout<<"Invalid Book Name "<<el;
    }
void LibraryManagementSystem::menu() {
        cout << "\nLibrary Menu;\n";
        cout << "1) add_book\n";
        cout << "2) search_books_by_prefix\n";
        cout << "3) print_who_borrowed_book_by_name\n";
        cout << "4) print_library_by_id\n";
        cout << "5) print_library_by_name\n";
        cout << "6) add_user\n";
        cout << "7) user_borrow_book\n";
        cout << "8) user_return_book\n";
        cout << "9) print_users\n";
        cout << "10) Exit\n";
    int choice=0;
    while(choice!=10) {
        cout<<"Enter choice 1-10:";
        cin>>choice;
        cout<<el;
        if(choice<1||choice>10)
            cout<<"Invalid Choice\n";
        else
            Run(choice);
    }
}
void LibraryManagementSystem::Run(int choice) {
        if(choice==1)AddBook();
        else if(choice==2)SearchBooksByPrefix();
        else if(choice==3)PrintWhoBorrowedBook();
        else if(choice==4)PrintLibraryById();
        else if(choice==5)PrintLibraryByName();
        else if(choice==6)AddUser();
        else if(choice==7)UserBorrow();
        else if(choice==8)UserReturn();
        else if(choice==9)PrintUser();

}
void LibraryManagementSystem::UserBorrow() {
            cout<<"Enter Book name and user name :";
            string bk, usr;cin>>bk>>usr;
            int UserId=SearchId(usr, users);
            if(UserId==-1){
                cout<<"Invalid User name"<<el;
                return;
            }
            int BookId=SearchId(bk, books);
            if(BookId==-1){
                cout<<"Invalid Book Name"<<el;
                return;
            }
            books[BookId].UserBorrow(users[UserId]);
}
void LibraryManagementSystem::PrintWhoBorrowedBook() {
    cout<<"Enter Book Name :";
    string bk; cin>>bk;
    int BookId= SearchId(bk, books);
    if(BookId==-1)
        cout<<"Invalid Book Name\n";
    else
        books[BookId].PrintUsers();

}
void LibraryManagementSystem::AddUser() {
            user u;
            u.enter();
            users.emplace_back(u);
}
void LibraryManagementSystem::PrintLibraryById() {
    cout<<"\n----------Library Books Sorted By Id-------------\n";
            sort(books.begin(), books.end(), cmpId<book>);
            for(auto i:books)
                i.Print();
}
void LibraryManagementSystem::PrintLibraryByName() {
          cout<<"\n----------Library Books Sorted By Name-------------\n";
            sort(books.begin(), books.end(), cmpName<book>);
            for(auto i:books)
                i.Print();
}
void LibraryManagementSystem::UserReturn() {
    string bk, usr;
    cout<<"Enter Book Name and user Name: ";
    cin>>bk>>usr;
    int BookId= SearchId(bk, books);
    if(BookId==-1){
        cout<<"Invalid Book Name\n";
        return;
    }
    int  UserId=SearchId(usr, users);
    if(UserId==-1){
        cout<<"Invalid User Name\n";
        return;
    }
    books[BookId].UserReturn(users[UserId]);

}

void LibraryManagementSystem::PrintUser() {
        cout<<"\n-----------Users In Library-------------\n";
        for(auto i:users)
            i.Print();
}

template<typename  t1>
int LibraryManagementSystem::SearchId(string name, const vector<t1>& v) {
   for(int i=0;i<v.size();i++){
        if(name==v[i].GetName())
            return i;
   }
   return -1;
}



// Books


// User






