#include "Library.h"
user::user():id(0) {}

user::user(int id, string name):id(id), name(name) {}

void user::Print() {
    cout<<"user "<< GetName() << " With id " << GetId()<<el ;
}

string user::GetName()const {
    return name;
}

bool user::IsEqual(const user &usr)const {
    return name==usr.GetName() && id==usr.GetId();
}

int user::GetId()const {
    return id;
}

void user::enter() {
    cout<<"Enter id and name :";
    cin>>id>>name;
}
