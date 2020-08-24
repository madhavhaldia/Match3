// This program may misbheave for larger values for arr since it is dynamically allocated and performace will vary from machine to machine
#include <iostream>
#include<vector>
using namespace std;

class Match3 {
    int count = 0;
    int flag = 0;
    int Check(vector<vector<int>> &arr, int &row, int &column)
    {
        //cout << "\n" << row <<" "<< column<<endl;
        if (!arr.empty()&&row<arr.size() && column<arr.at(row).size())
        {
            int Rcount = 1, Ccount = 1;
            int i = 1, j = 1;
            auto key = arr.at(row).at(column);
            cout << "KEY   " << key <<endl;
            while (i < arr.at(row).size() - column && arr.at(row).at(column + i) == key)
            {
                ++Ccount;
                ++i;
            }

            while (j < arr.size() - row && arr.at(row + j).at(column) == key)
            {
                ++Rcount;
                ++j;
            }
            
            /*if (Rcount >= Ccount >= 2 || Ccount >= Rcount >= 2)
            {
                cout << "////////////////////// MATCH /////////////////\n";
                for (j; j > row; --j)
                {
                    arr.at(j - 1).erase(arr.at(j - 1).begin() + column);
                }
                for (i; i-1 > column; --i)
                {
                    arr.at(row).erase(arr.at(row).begin() + i - 1);
                }
            }*/

            if (Rcount >= Ccount && Rcount >=3)
            {
                j += row;
                cout << "////////////////////// MATCH ROW/////////////////\n";
                for (j; j > row; j--)
                {
                    arr.at(j-1).erase(arr.at(j-1).begin()+column);
                }
                show(arr);
                count += Rcount;
                cout << endl << Rcount<<endl;
                Check(arr, row, column);
                
            }
            else if (Ccount >= Rcount && Ccount >= 3)
            {   
                
                cout << "////////////////////// MATCH COLUMN/////////////////\n";
                for (i; i > column; --i)
                {
                    /*cout << "\n//////////ERASING/////////////\n";
                    cout << i << endl;*/
                    arr.at(row).erase(arr.at(row).begin()+ i-1);
                }
                show(arr);
                count += Ccount;
                cout << endl << Ccount<<endl;
                Check(arr, row, column);
               
            }
            
            return (Rcount > Ccount)?Rcount:Ccount;
        }

        return -1;
    }
public: 
    void Play(vector<vector<int>> &arr)
    {
        for (auto i = 0; i < arr.size(); i++)
        {
            for (auto j = 0; j < arr.at(i).size(); j++)
            {
                flag = Check(arr, i, j);
                if (flag == -1)
                    cout << "Empty array";
            }
        }
        cout << "\n*******************GAME OVER*******************\n";
        cout << "Your score :";
        showscore();
    }
    void showscore() { cout<<endl<<count<<endl; }

    vector<vector<int>> ShiftArray(vector<vector<int>> arr)
    {

    }
    void show(vector<vector<int>> &arr)
    {
        for (auto i = 0; i < arr.size(); i++)
        {
            for (auto j = 0; j < arr.at(i).size(); j++)
            {
                cout << arr.at(i).at(j) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    vector<vector<int>> arr = { {1,1,2,1,1},{1,1,2,1,1},{1,2,2,2,1},{1,1,2,1,1},{1,1,1,1,1} };
    Match3 game;
    game.show(arr);
    game.Play(arr);
    game.show(arr);
}

