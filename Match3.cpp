// This program may misbheave for larger values for arr since it is dynamically allocated and performace will vary from machine to machine
#include <iostream>
#include<vector>
using namespace std;

class Match3 {
    int count = 0;
    int flag = 0;
    int Check(vector<vector<int>> &arr, int row, int column)
    {
        if (!arr.empty()&&row<arr.size() && column<arr.at(row).size())
        {
            int Rcount = 0, Ccount = 0;
            int i = 1, j = 1;
            auto key = arr.at(row).at(column);
            cout << "KEY   " << key <<endl;
            while (i < arr.at(row).size() - column && arr.at(row).at(column + i) == key)
            {
                Ccount++;
                ++i;
            }

            while (j < arr.size() - row && arr.at(row + j).at(column) == key)
            {
                Rcount++;
                ++j;
            }
             
            if (Rcount >= Ccount && Rcount >=2)
            {
                cout << "////////////////////// MATCH /////////////////\n";
                for (j; j > row; --j)
                {
                    arr.at(j-1).erase(arr.at(j-1).begin()+column);
                }
                show(arr);
                count += Rcount;
                Check(arr, row, column);
                
            }
            else if (Ccount >= Rcount && Ccount >= 2)
            {
                cout << "////////////////////// MATCH /////////////////\n";
                for (i; i > column; --i)
                {
                    arr.at(row).erase(arr.at(row).begin() + i-1);
                }
                show(arr);
                count += Ccount;
                Check(arr, row, column);
               
            }
            
            return (Rcount > Ccount)?Rcount:Ccount;
        }

        return -1;
    }
public: 
    void Play(vector<vector<int>> arr)
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
    void show(vector<vector<int>> arr)
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
    vector<vector<int>> arr = { {1,2,3,1},{1,2,1,1},{1,2,1,1},{1,2,1,1},{1,2,1,1} };
    Match3 game;
    game.show(arr);
    game.Play(arr);
}

