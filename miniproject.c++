#include <iostream>
using namespace std;
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
string n1, n2;
char token = 'x';
bool tie= false;
void functionOne()
{


    cout << endl;

    cout << "    |       |   \n";
    cout << " " << space[0][0] << "  |  " << space[0][1] << "    | " << space[0][2] << "    \n";
    cout << "____|_______|___\n";
    cout << "    |       |   \n";
    cout << " " << space[1][0] << "  | " << space[1][1] << "     | " << space[1][2] << "    \n";
    cout << "____|_______|___\n";
    cout << "    |       |   \n";
    cout << " " << space[2][0] << "  | " << space[2][1] << "     | " << space[2][2] << "    \n";
    cout << "    |       |   \n";
    cout << "    |       |   \n";
}

void functionTwo()
{

    int digits;

    if (token == 'x')
    {
        cout << n1 << " PLEASE ENTER: ";
        cin >> digits;
    }

    if (token == '0')
    {
        cout << n2 << " PLEASE ENTER: ";
        cin >> digits;
    }

    if (digits == 1)
    {
        row = 0 , column = 0;
    }

    if (digits == 2)
    {
        row = 0 , column = 1;
    }

    if (digits == 3)
    {
        row = 0 , column = 2;
    }

    if (digits == 4)
    {
        row = 1 , column = 0;
    }

    if (digits == 5)
    {
        row = 1 , column = 1;
    }

    if (digits == 6)
    {
        row = 1 , column = 2;
    }

    if (digits == 7)
    {
        row = 2 , column = 0;
    }

    if (digits == 8)
    {
        row = 2 , column = 1;
    }

    if (digits == 9)
    {
        row = 2 , column = 2;
    }
    
    else if(digits<1 || digits>9)
    {
        cout << "INVALID !!!" << endl;
    }

    if (token == 'x' && space[row][column] != 'x' && space[row][column] != '0')
    {
        space[row][column] = 'x';
        token = '0';
    }

    else if (token == '0' && space[row][column] != 'x' && space[row][column] != '0')
    {
        space[row][column] = '0';
        token = 'x';
    }

    else
    {
        cout << "THERE IS NO EMPTY SPACE !!!" << endl;
        functionTwo();
    }

functionOne();
}
    bool functionThree()
    {
        for (int i = 0; i < 3; i++)
        {
            if (space[i][0] == space[i][1] && space[i][2] || space[0][i] && space[1][i] && space[0][i] == space[2][i])
            {
                return true;
            }
        }

        if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[2][0])
        {
            return true;
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (space[i][j] != '0')
                {
                    return false;
                }
            }
        }
        tie = true;
        return false;
    }


int main()
{
        cout << "\nENTER THE NAME OF FIRST PLAYER: ";
    getline(cin, n1);
    cout << "-------------------------------------------" << endl;
    cout << "\nENTER THE NAME OF SECOND PLAYER: ";
    getline(cin, n2);
    cout << "-------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << n1 << ":IS PLAYER 1 SO HE/SHE WILL PLAY FIRST\n";
    cout << endl;
    cout << "-------------------------------------------" << endl;
    cout << endl;
    cout << n2 << ":IS PLAYER 2 SO HE/SHE WILL PLAY SECOND\n";
    cout << endl;
    cout << "-------------------------------------------" << endl;

    while (! functionThree())
    {
        functionOne();
        functionTwo();
        functionThree();
    }

    if (token == 'x' && tie == false)
    {
         cout<<endl;
        cout<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout << n2 << " WINS !!!" << endl;
        cout<<"---------------------------------------------"<<endl;
    }

    else if (token == '0' && tie == false)
    {
        cout<<endl;
        cout<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout << n1 << " WINS !!!" << endl;
         cout<<"---------------------------------------------"<<endl;
    }

    else
    {
        cout << "IT'S A DRAW !!" << endl;
    }

    return 0;
}