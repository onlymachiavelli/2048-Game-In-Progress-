#include <bits/stdc++.h>
using namespace std;
void Show(vector<vector<int>> mt, int size)
{
  int i, j;
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
      cout << mt[i][j] << " ";
    cout << endl;
  }
}

void GenerateGame(vector<vector<int>> &matr, int size)
{
  int i, j;
  for (i = 0; i < size; i++)
    for (j = 0; j < size; j++)
      matr[i][j] = 0;
  srand(time(0));
  int arr[4];
  for (i = 0; i < 4; i++)
    arr[i] = rand() % size;
  while (arr[0] == arr[1])
    arr[0] = rand() % size;
  while (arr[2] == arr[3])
    arr[2] = rand() % size;
  matr[arr[0]][arr[2]] = 2;
  matr[arr[1]][arr[3]] = 2;
}
void Left(vector<vector<int>> &mt, int size)
{
  int i, j;
  bool nready = true;
  for (i = 0; j < size; j++)
  {
    for (j = 0; i < size; i++)
    {
      if (mt[i][j] == mt[i][j + 1])
      {
        mt[i][j] *= 2;
        mt[i][j + 1] = 0;
      }
    }
  }
  while (nready)
  {
    nready = false; //means its ready no zeros
    for (i = 0; i < size; i++)
    {
      for (j = 0; j < size; j++)
      {
        if (mt[i][j] == 0 && mt[i][j + 1] != 0)
        {
          mt[i][j] = mt[i][j + 1];
          mt[i][j + 1] = 0;
          nready = true;
        }
      }
    }
  }
}

void Right(vector<vector<int>> &mt, int size)
{
  int i, j;
  bool nready = true;
  for (i = 0; i < size; i++)
  {
    for (j = size - 1; j >= 1; j--)
    {
      if (mt[i][j] == mt[i][j - 1])
      {
        mt[i][j] *= 2;
        mt[i][j - 1] = 0;
      }
    }
  }

  while (nready)
  {
    nready = false; //means its ready no zeros
    for (i = 0; i < size; i++)
    {
      for (j = size - 1; j >= 1; j--)
      {
        if (mt[i][j] == 0 && mt[i][j - 1] != 0)
        {
          mt[i][j] = mt[i][j - 1];
          mt[i][j - 1] = 0;
          nready = true;
        }
      }
    }
  }
}

void Bottom(vector<vector<int>> &mt, int size)
{
  int i, j; //i rows , j elements
  bool nready = true;
  for (j = 0; j < size; j++)
  {
    for (i = size - 1; i >= 1; i--)
    {
      if (mt[i][j] == mt[i - 1][j])
      {
        mt[i][j] *= 2;
        mt[i - 1][j] = 0;
      }
    }
  }
  while (nready)
  {
    nready = false;
    for (j = 0; j < size; j++)
    {
      for (i = size - 1; i >= 1; i--)
      {
        if (mt[i][j] == 0 && mt[i - 1][j] != 0)
        {
          mt[i][j] = mt[i - 1][j];
          mt[i - 1][j] = 0;
          nready = true;
        }
      }
    }
  }
}

/*
        mt[i][j] *= 2;
        mt[i][j + 1] = 0;
*/
void Top(vector<vector<int>> &mt, int size)
{
  int i, j;
  bool nready = true;
  for (j = 0; j < size; j++)
  {
    for (i = 0; i < size - 1; i++)
    {
      if (mt[i][j] == mt[i + 1][j])
      {
        mt[i][j] *= 2;
        mt[i + 1][j] = 0;
      }
    }
  }

  while (nready)
  {
    nready = false;
    for (j = 0; j < size; j++)
    {
      for (i = 0; i < size - 1; i++)
      {
        if (mt[i][j] == 0 && mt[i + 1][j] != 0)
        {
          mt[i][j] = mt[i + 1][j];
          mt[i + 1][j] = 0;
          nready = true;
        }
      }
    }
  }
}
bool isFull(vector<vector<int>> mt, int size)
{
  int i, j;
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      if (mt[i][j] == 0)
        return false;
    }
  }
  for (i = 0; i < size - 1; i++)
  {
    for (j = 0; j < size - 1; j++)
    {
      if (mt[i][j] == mt[i][j + 1] || mt[i][j] == mt[i][j + 1])
        return false;
    }
  }
  return true;
}
void RandomAdd(vector<vector<int>> &mt, int size)
{
  srand(time(0));
  int x = rand() % size, y = rand() % size;
  while (mt[x][y] != 0)
  {
    x = rand() % size;
    y = rand() % size;
  }
  mt[x][y] = 2;
}
int main()
{
  cout << "Enter size " << endl;
  int size;
  cin >> size;
  vector<vector<int>> Game(size, vector<int>(size));
  GenerateGame(Game, size);
  Show(Game, size);
  RandomAdd(Game, size);
  cout << endl;
  Show(Game, size);
  RandomAdd(Game, size);
  Show(Game, size);
  Right(Game, size);
  Show(Game, size);
}