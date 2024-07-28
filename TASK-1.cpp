#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std ;
void get(int,int,int);

int main()
{
    int find=0,flag=0;
    srand(time(0));
    int random =rand()%100+1;
    while(find!=random)
    {
        cout<<"Enter your guessing number : ";
        cin>>find;
        if(find!=random)
        {
            get(random,find,flag);
            flag++;
        }
    }
    if (find==random)
    {
        cout<<"\n"<<"GUESSING MATCHED WITH ORIGINAL VALUE ";
    }
}

void get(int random, int find, int flag)
{
    int final, remaining, num_times, calci=0;
    find>random ?cout<<"your guessing is too high"<<endl:cout<<"your guessing is too low "<<endl;
    cout<<"\n";
    if(flag==1)
    {
        if(random>=10)
        {
            cout<<"clue 1:[ it is a double digit number ]"<<endl<<endl;
        }
    }
    if(flag==1)
    {
        if(random<10)
        {
            cout<<"clue 1:[ it is a single digit number ]"<<endl<<endl;
        }
    }
    if((random%2==0)&&(flag>=2))
    {
        cout<<"clue 2"<<"\n"<<"[The number is multiple of two]"<<endl<<endl;
    }
    if((random%2!=0)&&(flag>=2))
    {
        cout<<"clue 2"<<"\n"<<"[The number is odd number]"<<endl<<endl;
    }
    if(flag>=3)
    {
        remaining=random%10;
        while(num_times!=0)
        {
            remaining+=1;calci++;
            if(remaining%10==0)
                num_times=0;
        }
        cout<<"clue 3"<<"\n"<<"[ the number in the range ( 1 to "<<random+calci;
        random % 2 == 0 ?cout<<" ) and multiple of two ":cout<<")and odd number "<<endl<<endl;
        remaining=0;calci=0;
    }
    if(flag>=5)
    {
        final =random-find;
        cout<<"[your guess near by["<<final<<" ]digit ahead or before from the original digit]"<<endl<<endl;
    }
}