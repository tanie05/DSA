#include<iostream>
#include<math.h>
using namespace std;
int main(){

    cout<<"pattern1"<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<"*";
        }cout<<endl;
    }

    cout<<"pattern2"<<endl;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }cout<<endl;
    }

    cout<<"pattern3"<<endl;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }cout<<endl;
    }

    //cout<<pattern4
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout<<i;
        }cout<<endl;
    }

    //cout<<pattern5
    for(int i=5;i>=1;i--){
        for(int j=i;j>=1;j--){
            cout<<"*";
        }cout<<endl;
    }

    //cout<<pattern6
    for(int i=5;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<j;
        }cout<<endl;
    }

    //cout<<pattern7
    for(int row = 1; row<=5;row++){
        //spaces 5-row times
        for(int spaces=1;spaces<=5-row;spaces++){
            cout<<" ";
        }
        //star row times
        for(int star=1;star<=row;star++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //cout<<pattern8
    for(int row = 5; row>=1;row--){
        //spaces 5-row times
        for(int spaces=1;spaces<=5-row;spaces++){
            cout<<" ";
        }
        //star row times
        for(int star=1;star<=row;star++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //cout<<pattern9
    for(int row = 1; row<=5;row++){
        //spaces 5-row times
        for(int spaces=1;spaces<=5-row;spaces++){
            cout<<" ";
        }
        //star row times
        for(int star=1;star<=row;star++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int row = 5; row>=1;row--){
        //spaces 5-row times
        for(int spaces=1;spaces<=5-row;spaces++){
            cout<<" ";
        }
        //star row times
        for(int star=1;star<=row;star++){
            cout<<"* ";
        }
        cout<<endl;
    }

    // cout<<pattern10
    for(int row=1;row<=9;row++){
        //5 - (abs(5-row))
        int num = 5 - abs(5-row);
        for(int j=1;j<=num;j++){
            cout<<"*";

        }cout<<endl;
    }

    // cout<<pattern11
    for(int i=1;i<=5;i++){

        if(i%2==0){
            //start with 0
            for(int j=1;j<=i;j++){
                if(j%2==1){
                    cout<<"0 ";
                }
                else{
                    cout<<"1 ";
                }
            }
            cout<<endl;
        }
        else{
            //start with 1
            for(int j=1;j<=i;j++){
                if(j%2==1){
                    cout<<"1 ";
                }
                else{
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }

    }


    // cout<<pattern12
    for(int row=1;row<=4;row++){
        for(int j=1;j<=row;j++){
            cout<<j;
        }
        for(int j=1;j<=4-row;j++){
            cout<<" ";
            cout<<" ";
        }
        for(int j=row;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
    }

    // cout<<pattern13
    int count=1;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout<<count<<" ";
            count++;
        }
        cout<<endl;

    }
    
    // cout<<pattern14
    for(int i=1;i<=5;i++){
        char ch = 'A';
        for(int j=1;j<=i;j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;

    }

    // cout<<pattern15
    for(int i=5;i>=1;i--){
        char ch = 'A';
        for(int j=1;j<=i;j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;

    }

    // cout<<pattern16
    char ch = 'A';
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout<<ch;
        }
        cout<<endl;
        ch++;
    }

    // cout<<pattern17
    for(int row=1;row<=4;row++){
        //4-row spaces
        for(int j=1;j<=4-row;j++){
            cout<<" ";
        }
        //ABC row times
        char ch = 'A';
        for(int j=1;j<=row;j++){
            cout<<ch;
            ch++;
        }
        ch-=2;
        //loop row-1 times
        for(int j=1;j<=row-1;j++){
            cout<<ch;
            ch--;
        }
        cout<<endl;

    }

    // cout<<pattern18
    for(int i=1;i<=5;i++){
        char ch = 'A';
        ch += 4;//gives us E
        ch -= (i-1);//gives us start

        for(int j=1;j<=i;j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }

    // cout<<pattern19
    for(int row=5;row>=1;row--){
        //print star row times
        for(int j=1;j<=row;j++){
            cout<<"*";
        }
        //print space 10-2*row times
        for(int j=1;j<=10-2*row;j++){
            cout<<" ";
        }
        //print star row times
        for(int j=1;j<=row;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int row=1;row<=5;row++){
        //print star row times
        for(int j=1;j<=row;j++){
            cout<<"*";
        }
        //print space 10-2*row times
        for(int j=1;j<=10-2*row;j++){
            cout<<" ";
        }
        //print star row times
        for(int j=1;j<=row;j++){
            cout<<"*";
        }
        cout<<endl;
    }

    //cout<<pattern20
    for(int row=1;row<=5;row++){
        //print star row times
        for(int j=1;j<=row;j++){
            cout<<"*";
        }
        //print space 10-2*row times
        for(int j=1;j<=10-2*row;j++){
            cout<<" ";
        }
        //print star row times
        for(int j=1;j<=row;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int row=4;row>=1;row--){
        //print star row times
        for(int j=1;j<=row;j++){
            cout<<"*";
        }
        //print space 10-2*row times
        for(int j=1;j<=10-2*row;j++){
            cout<<" ";
        }
        //print star row times
        for(int j=1;j<=row;j++){
            cout<<"*";
        }
        cout<<endl;
    }

    //cout<<pattern21
    for(int i=1;i<=4;i++){
        if(i==1 || i==4){
            for(int j=1;j<=4;j++){
                cout<<"*";
            }cout<<endl;
        }
        else{
            for(int j=1;j<=4;j++){
                if(j==1 || j==4)
                cout<<"*";
                else
                cout<<" ";
            }
            cout<<endl;
        }
    }

    cout<<"pattern22"<<endl;
    for(int row=1;row<=7;row++){
        //row=1
        int arr[8];
        int count=4;
        int key = 4 - abs(4-row) - 1; 
        int low=1, high=7;
        while(low<=high){
            arr[low++] = arr[high--] = count;
            if(key-->=1){
                count--;
            }
        }
        for(int i=1;i<=7;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }



}