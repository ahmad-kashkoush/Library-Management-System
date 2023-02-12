#include "Library.h"
book::book():id(0),Quantity(0){}

book::book(int id, string name, int quantity):
        id(id),name(name),Quantity(quantity){}

bool book::IsPrefix(string name) {
    if(name.size()>this->name.size())
        return false;
    for(int i=0;i<name.size();i++){
        if(name[i]!=this->name[i])
            return false;
    }
    return true;
}
string book::GetName()const{
    return name;
}

void book::UserBorrow( const user& usr) {
    if(Quantity==0){
        cout<<"Book is not here\n";
        return;
    }
    users.emplace_back(usr);
    Quantity--;
}

void book::PrintUsers() {
    cout<<"\n-----------Users Who Borrow "<<GetName()<<"-------------------\n";
    for(auto i:users)
        cout<<i.GetName()<<el;
}

void book::UserReturn(const user &usr) {
    int k=-1;
    for(int i=0;i<users.size();i++){
        if(usr.IsEqual(users[i])){
            k=i;break;
        }
    }
    if(k==-1){
        cout<<"This user don't borrow that book\n";
    }else{
        swap(users[k], users.back());
        users.pop_back();
        Quantity++;
    }
}

int book::GetId() const {
    return id;
}

void book::Print() {
    cout<<"Book "<<GetName()<<" "<< GetId()<<" "<<GetQuantity()<<el;
}

int book::GetQuantity() const {
    return Quantity;
}