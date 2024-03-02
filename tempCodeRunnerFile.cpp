#include<iostream>
using namespace std;

bool functionn(){
    if (1<2)
    {
        return false;
    }
    else{
        return true;
    }
}

int main (){
    int x = functionn();
    cout<<x;
}