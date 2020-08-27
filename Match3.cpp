// This program may misbheave for larger values for arr since it is dynamically allocated and performace will vary from machine to machine
#include <iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
using namespace std;



class Match3 {
    int count = 0;
    int flag = 0;
    int Check(vector<vector<int>> &arr, int row, int column)
    {
        if (!arr.empty()&&row<arr.size() && column<arr.at(row).size())
        {
            int Rcount = 1, Ccount = 1;
            int i = 1, j = 1;
            auto key = arr.at(row).at(column);
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
            
            if (Rcount >= Ccount && Rcount >=3)
            {
                j += row; 
                /*cout << "////////////////////// MATCH ROW /////////////////\n";
                cout << "Matching Element: " << key << endl;*/
                for (j; j > row; j--)
                {
                    arr.at(j-1).erase(arr.at(j-1).begin()+column);
                    arr.at(j - 1).push_back(1 + rand() % 5);
                }
               /* cout << "Updated Array :\n";
                show(arr);*/
                count += Rcount;
                Play(arr);
                
            }
            else if (Ccount >= Rcount && Ccount >= 3)
            {   
                /*cout << "////////////////////// MATCH COLUMN /////////////////\n";
                cout << "Matching Element: " << key << endl;*/
                for (i; i > column; --i)
                {
                    arr.at(row).erase(arr.at(row).begin()+ i-1);
                    arr.at(row).push_back(1 + rand() % 5);
                }
              /*  cout << "Updated Array :\n";
                show(arr);*/
                count += Ccount;
                Play(arr);
               
            }
            
            return (Rcount > Ccount)?Rcount:Ccount;
        }

        return -1;
    }
    
public: 
    void resetScore() { count == 0; }
    bool adj(int x1, int y1, int x2, int y2)
    {
        bool xtrue = 0, ytrue = 0;

        if (x1 == x2 + 1 || x1 == x2 - 1)
        {
            xtrue = 1;
        }

        if (y1 == y2 + 1 || y1 == y2 - 1)
        {
            ytrue = 1;
        }

        if (((x1 == x2) && ytrue) || ((y1 == y2) && xtrue))  
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

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
    }
    void showscore() { cout<<endl<<count<<endl; }

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
    srand((unsigned)time(0));
    int moveCounter = 3, a, b, c, d;
    vector<vector<int>> arr = { {1,2,2,2,5},{1,3,3,4,5} ,{1,2,3,4,5} ,{1,2,3,4,5} ,{1,2,3,4,5} ,{1,2,3,4,5} ,{1,2,3,4,5} ,{1,2,3,4,5} ,{1,2,3,4,5} };
    Match3 game;
    cout << "Given Array: \n";
    game.show(arr);
    game.Play(arr);
    game.resetScore();
    cout << "CURRENT ARRAY \n\n";
    game.show(arr);
    while (moveCounter > 0)
    {
        cout << "Enter the positions to be swapped\n";
        cin >> a >> b >> c >> d;
        if (!game.adj(a, b, c, d))
        {
            cout << "\nSwap adjascent cells only \n";
            continue;
        }

        swap(arr.at(a-1).at(b-1), arr.at(c-1).at(d-1));
        moveCounter--;
        game.Play(arr);
        cout << "CURRENT ARRAY \n\n";
        game.show(arr);
    }

    cout << "\n*******************GAME OVER*******************\n";
    cout << "FINAL ARRAY \n\n";
    game.show(arr);
    cout << "Your score :";
    game.showscore();
    
}

    