#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    float a,b;
    cin>>n;

    if(n%2==0){
        a=(pow(n,2)-1)/4;
        b=a+2;
        if(a>floor(a)){
            cout<<-1<<endl;
            return 0;
        }

        if(a==0||b==0){
        cout<<-1<<endl;
        return 0;
        }
        else{
            cout<<a<<" "<<b<<endl;
            return 0;
        }
    }
    else{
        a=(pow(n,2)-1)/2;
        b=a+1;
        if(a>floor(a)){
            cout<<-1<<endl;
            return 0;
        }
         if(a==0||b==0){
        cout<<-1<<endl;
        return 0;
        }
        else{
            cout<<a<<" "<<b<<endl;
            return 0;
        }
    }

cout<<-1<<endl;
return 0;
}