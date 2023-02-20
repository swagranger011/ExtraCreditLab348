// extra credit lab for software engineering
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string program[5][5];
string department[5][5];
string result[5] = {"1", "0", "0", "0", "0"};

bool isTaken(string choice)
{
    for (int i = 0; i < 5; i++)
    {
        if (result[i] == choice)
        {
            return true;
        }
        
    }
    return false;
}

int getOtherDepartment(string choice, int dCol, int dRow)
{
    for(int col = dCol + 1; col < 5; col++)
    {
        for (int row = 0; row <= dRow; row++)
        {
            if(department[row][col] == choice)
            {
                return col;
            }
        }
    }
    return dCol;
}

int getProgrammerChoice(int dCol, int d1, string choice)
{
    int p1 = stoi(choice) - 1;
    for(int i = 0; i < 5; i++)
    {
        int r = stoi(program[i][p1]);
        if (r == d1+1)
        {
            return d1;
        }
        else if (r == dCol+1)
        {
            return dCol;
        }
        
    }
    return dCol;
}

void programmers(string program[5][5])
{
    cout << "Programmers and their Preferences\n";
    cout << "Programmer #1\tProgrammer #2\tProgrammer #3\tProgrammer #4\tProgrammer #5\n";

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << program[i][j] << "\t\t";
        }
        cout << endl;
    }
}

void departments(string department[5][5])
{
    cout << "\nDepartments and their Preferences\n";
    cout << "Department #1\tDepartment #2\tDepartment #3\tDepartment #4\tDepartment #5\n";

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << department[i][j] << "\t\t";
        }
        cout << endl;
    }
    cout << endl;
}

void preferences()
{
    string choice;

    for (int dCol = 1; dCol < 5; dCol++)
    {
        for (int dRow = 0; dRow < 5; dRow++)
        {
        choice = department[dRow][dCol];
            if(isTaken(choice))
            {
                continue;
            }
            int d1 = getOtherDepartment(choice, dCol, dRow);
            
            if (dCol != d1)
            {
                int d2 = getProgrammerChoice(dCol, d1, choice);
                if (dCol == d2){
                    result[dCol] = choice;
                    break;
                }
            }
            else
            {
                result[dCol] = choice;
                break;
            }
        }
    }
    for (int i = 0;i < 5; i++)
    {
        cout << "Department #" << i+1 << " will get Programmer #" << result[i] << endl; 
    }
}

int main()
{
    ifstream numbers("matching-data.txt");

    if (numbers.is_open())
    {
        while (numbers.good())
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    numbers >> department[i][j];
                }
            }
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    numbers >> program[i][j];
                }
            }
        }
        numbers.close();
    }
    else
    {
        cout << "Error reading file\n";
        exit(0);
    }

    programmers(program);
    departments(department);
    preferences();

    return 0;
}