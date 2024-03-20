#include<iostream>
#include<iomanip>

using namespace std;

const int row = 5;
const int col = 10;

void display(bool seats[][col])
{
    system("cls");
    cout<<" ";
    for(int i = 1;i <= col; i++)
        cout<<setw(3)<<i;
    cout<<endl;

    for(int i = 0; i < row; i++)
    {
        cout<<static_cast<char>('A' + i);

        for(int j = 0; j < col; j++)
        {
            if(seats[i][j])
                cout<<setw(3)<<'X';
            else    
                cout<<setw(3)<<'-';
        }
        cout<<endl;
    }
}

void reserve(bool seats[][col], char row, int col)
{
    if(seats[row - 'A'][col - 1])
        cout<<"Already Booked, Try with another seat number"<<endl;
    else
    {
        seats[row - 'A'][col - 1] = true;
        cout<<"Seat booked!!"<<endl;
    }
}

int main()
{
    bool seats[row][col] = {false};
    display(seats);

    int col;
    char row;

    while(true)
    {
        cout<<"Enter Row : A-E "; cin>>row;
        cout<<"Enter Column : 1-10 "; cin>>col;
        if( (row < 'A' || row > 'E') || (col < 1 || col > 10 ) )
        {
            cout<<"Enter Valid Seat Number "<<endl;
            continue;
        }
        reserve(seats, row, col);
        display(seats);

        char choice;
        cout<<"Do you want to book again ? (Y/N) "; cin>>choice;
        if(choice == 'N' || choice == 'n')
            break;
    }

    return 0;
}

