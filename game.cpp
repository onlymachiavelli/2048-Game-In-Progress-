#include <bits/stdc++.h>
using namespace std;

bool CheckIn(char an) {
  char arr[4] = {'r','d','l','u'};
  int i;
  bool check = false;
  for (i= 0;i<4;i++) if (arr[i] == an) return true;
  return false;
  
}
void Show(vector <vector<int>> matr, int size) {
  int i,j;
  for (i = 0; i< size; i++){
    for (j = 0; j< size;j++) cout << matr[i][j] << "  "  ;
    cout << endl;
  }
}
void GenerateGame(vector<vector<int>>& matr, int size) {
  int i,j;
  for (i = 0; i< size; i++) for (j = 0 ; j < size; j ++ ) matr[i][j] = 0;
  srand(time(0));
  int arr[4];
  for (i = 0; i < 4;i++ ) arr[i] = rand() % size;
  while (arr[0] == arr[1]) arr[0] = rand() % size;
  while (arr[2] == arr[3]) arr[2] = rand() % size;
  matr[arr[0]][arr[2]] = 2;
  matr[arr[1]][arr[3]] = 2;

}
bool isFull (vector<vector <int>> matr , int size){
    int count = 0;
    for (int i = 0; i < size; i++) for (int j = 0; j < size; j++) if (matr[i][j] != 0) count++;
    if (count == (size * size)) return true;
    else return false;
}

void AddNum(vector<vector<int>> & matr, int size){
  // To add a number in any index IJ after sliding  !

}
void Right(vector <vector<int>> & matr, int size) {
  //Right function
  int i, j;
  for (i = 0; i<size;i++) for(j = 0; j<size-1;j++){
    if (matr[i][j] == matr[i][j+1]){
      matr[i][j] = matr[i][j] * 2 ;
      matr[i][j+1] = 0;
    }
    if (matr[i][j] == 0 && matr[i][j+1] != 0) {
      matr[i][j] = matr[i][j+1];
      matr[i][j+1] = 0;
    }
  }
}


void Left(vector <vector<int>> & matr, int size) {
  //left function
}

void Up(vector <vector<int>> & matr, int size) {
  //up function
}

void Down(vector <vector<int>> & matr, int size) {
  //down function
}
int main(){
  cout << "2048 Game C++ Version By @Machiavelli " << endl << "Enter the size ";
  int size;
  cin >> size;
  vector <vector <int>> game (size, vector<int>(size));
  GenerateGame(game, size);
  Show(game, size);
  char answer;
  while (true){
    cout << "Choose a direction : r(right), l(left), u(up), d(down) " << endl;
    cin >> answer;
    do {
      cout << "Enter the fucking answer again mother fucker ! r,u,d,l" << endl;
      cin >> answer;
    }while (!CheckIn(answer));

    switch(answer){
      case 'r':
        Right(game, size);
        break;
      case 'd':
        Down(game, size);
        break;
      case 'u':
        Up(game, size);
        break;
      case 'l' : 
        Left(game, size);
        break;
    }
    Show(game, size);
    //exiting if the game is completed
    if(isFull(game, size)){
      cout << "Game is over ! Would you like to play again ? y/n " << endl;
      char ex ; 
      cin >> ex;
      if(ex == 'n' ) break;
      else {
        cout << "Resize  ? y/n" << endl;
        char res;
        cin >> res;
        if (res == 'y') cin >> size;
        GenerateGame(game, size);
        Show(game, size);
      }
    }
  }
}


