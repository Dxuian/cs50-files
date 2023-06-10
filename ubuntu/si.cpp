#include <bits/stdc++.h>
using namespace std;

int main(){
    char s[1000];
    cin >> s;
    int ns,ew;
    char out[1000];
    int i = 0;
    while(s[i] != '\0'){
        if (s[i] == 'N'){
            ns++;
        }else if(s[i] == 'S'){
            ns--;
        }else if(s[i] == 'E'){
            ew++;
        }else if(s[i] == 'W'){
            ew--;
        }
        cout<<ns<<"\t"<<ew<<endl;
    }
    int ind = 0;
    if(ns >= 0){
        for (int j = 0; j < ns; j++){
            out[ind] = 'N';
            cout<<out<<endl;
            ind++;
        }
    }else{
        for (int j = 0; j < -1 * ns; j++){
            out[ind] = 'S';
            cout<<out<<endl;
            ind++;
        }
    }
    if(ew >= 0){
        for (int j = 0; j < ew; j++){
            out[ind] = 'E';
            cout<<out<<endl;
            ind++;
        }
    }else{
        for (int j = 0; j < -1 * ew; j++){
            out[ind] = 'W';
            cout<<out<<endl;
            ind++;
        }
    }
    out[ind] = '\0';
    cout<<out<<endl;
    return 0;
}