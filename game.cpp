#include <bits/stdc++.h>
using namespace std;
bool isFull(vector<vector<int>> matrix, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] != 0)
                count++;
        }
    }
    if (count == (size * size))
        return false;
    else
        return true;
}
void Show(vector<vector<int>> matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
void GenerateGame(vector<vector<int>> matrix, int size)
{
    int i, j;
    vector<int> line;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            line.push_back(0);
        matrix.push_back(line);
        line = {};
    }
    int x, y;
    int arr[4] = {0, 0};
    int checkn = 0;
    do
    {
        x = rand() % size;
        y = rand() % size;
        while (x == y)
            y = rand() % size;
        if (checkn == 0)
        {
            arr[0] = x;
            arr[1] = y;
        }
        if (checkn == 1)
        {
            do
            {
                x = rand() % size;
                y = rand() % size;
                while (x == y)
                    y = rand() % size;
            } while (arr[0] == x || arr[1] == y);
        }
        else
        {
            matrix[x][y] = 2;
        }
        checkn++;

    } while (checkn != 2);
}
int main(void)
{
    int i, j;
    int size;
    vector<vector<int>> game;
    cout << "Enter The Size : " << endl;
    cin >> size;
    GenerateGame(game, size);
    Show(game, size);
}