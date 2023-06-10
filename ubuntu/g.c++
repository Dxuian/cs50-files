#include<iostream>

int main(){
    vector<int> atNum[]={1, 2, 3, 4, 5, 6, 7};

    vector<int> atMass[] = {1, 2, 4, 6, 8, 10};


    int num;
    cout<<"Enter the number of elements you want to add \n";
    cin>>num;

    while(num != 1){
        for(int i = 7; i <= num; i++){
            int _num;
            cout<<_num;
            atomicNumber[i] = _num;

        }
        num--;
    }



    for(int i = 0; i <= 10; i++){
        cout<<atomicNumber[i];
    }

    return 0;
}