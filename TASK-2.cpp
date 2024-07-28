#include <iostream>
using namespace std;

int main()
{
    int firstNumber,secondNumber, inputRead = 0;
    float currentResult = 0;
    int operation;
    do
    {
    cout<<endl<<"Enter first number : ";
    cin >> firstNumber; 
    cout<<"Enter second number : ";
    cin>>secondNumber;
        cout << "\nTo perform below operation enter the corresponding number" << endl << endl;
        cout << "1. To perform addition  enter (1)" << endl;
        cout << "2. To perform subtraction enter (2)" << endl;
        cout << "3. To perform multiplication enter (3)" << endl;
        cout << "4. To perform division  enter (4)" << endl;
        cin >> operation;
        switch (operation)
        {
            case 1:
               currentResult= firstNumber+secondNumber;
               cout <<"Answer: "<<currentResult;
                break;
            case 2:
                currentResult= firstNumber-secondNumber;
                cout <<"Answer: "<<currentResult;
                break;
            case 3:
                currentResult= firstNumber*secondNumber;
                cout <<"Answer: "<<currentResult;
                break;
            case 4:
               if(secondNumber!=0){
               currentResult= firstNumber/secondNumber;
               cout <<"Answer: "<<currentResult;}
               else
               cout<<"Can't divided by zero ";
               break;
            }
        }while(1);
    }