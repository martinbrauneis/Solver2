#include <iostream>
using namespace std;


bool orientData[7][7][7][48];

int x[11][11][11][5];
// [colum...c][row...r][level...l][brick number, varianz of orientation (0...47), c base, rbase, l base]
// x[c][r][l][i]

//   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 
// 0 | 0   0   0   0   0   0   0   0   0   0   0
// 1 | 0   0   0   0   0   0   0   0   0   0   0
// 2 | 0   0   0   0   0   0   0   0   0   0   0
// 3 | 0   0   0   1   1   1   1   1   0   0   0 
// 4 | 0   0   0   1   1   1   1   1   0   0   0 
// 5 | 0   0   0   1   1   1   1   1   0   0   0
// 6 | 0   0   0   1   1   1   1   1   0   0   0
// 7 | 0   0   0   1   1   1   1   1   0   0   0
// 8 | 0   0   0   0   0   0   0   0   0   0   0
// 9 | 0   0   0   0   0   0   0   0   0   0   0
// 10| 0   0   0   0   0   0   0   0   0   0   0



struct RetValCRL {
  int c;
  int r;
  int l;
};


void printArrayAll() {
  cout << " --- Start Print Array All --- " << endl << endl << " --- 0 ---" << endl;
  for (int i=0; i<5; i++) {
    for (int l=0; l<11; l++) {
      for (int r=0; r<11; r++) {
        for (int c=0; c<11; c++) {
          cout << x[c][r][l][i] + 10 << " ";
        }
	cout << endl;
      }
      cout << endl;
    }
    cout << " --- " << i++ << " --- " << endl;
  }
  cout << endl << " --- End Print Array All ---" << endl;
}



void printArraySmall() {
  cout << " --- Start Print Array Small --- " << endl;
  for (int l=3; l<8;l++) {
    for (int r=3; r<8;r++) {
      for (int c=3; c<8;c++) {
        cout << x[c][r][l][0] + 10 << " ";
      }
      cout << "| ";
    } 
    cout << endl;
  }
  cout << " --- End Print Array Small --- " << endl;
}



void iniArray() {
  for (int l=0; l<11;l++) {
    for (int r=0; r<11;r++) {
      for (int c=0; c<11;c++) {
        x[c][r][l][0] = 1;
        x[c][r][l][1] = 0;
      }
    } 
  }
  for (int l=3; l<8;l++) {
    for (int r=3; r<8;r++) {
      for (int c=3; c<8;c++) {
        x[c][r][l][0] = 0;
      }
    } 
  }
}



int missingBrick() {
  int n = 0;
  for (int l=3; l<8;l++) {
    for (int r=3; r<8;r++) {
      for (int c=3; c<8;c++) {
        if (x[c][r][l][0] == 0) {n++;}
      }
    } 
  }
  return n/5;
}


RetValCRL nextFree() {
  bool stop = 0;
  int l = 3, r, c;
  while(l < 8 and stop == 0) {
    r = 3;
    while(r < 8 and stop == 0) {
      c = 3;
      while(c < 8 and stop == 0) {
         if (x[c][r][l][0] == 0) {stop = 1;} 
        c++;
      }
      r++;
    }
    l++;
  }
  return {c-1,r-1,l-1};
}


void iniOrientDataArray() {
  for (int i=0; i<7; i++) {
    for (int j=0; j<7; j++) {
      for (int k=0; k<7; k++) {
        for (int l=0; l<48; l++) {
          x[i][j][k][l] = 0;
	}
      }
    }
  }
  // -- define orientations --
  orientData[3][3][3][0] = 1;  // Fixpunkt
  orientData[3][3][3][0] = 1;
  orientData[3][3][3][0] = 1;
  orientData[3][3][3][0] = 1;
  orientData[3][3][3][0] = 1;
  orientData[3][3][3][1] = 1;  // Fixpunkt
  orientData[3][3][3][1] = 1;
  orientData[3][3][3][1] = 1;
  orientData[3][3][3][1] = 1;
  orientData[3][3][3][1] = 1;
  orientData[3][3][3][2] = 1;  // Fixpunkt
  orientData[3][3][3][2] = 1;
  orientData[3][3][3][2] = 1;
  orientData[3][3][3][2] = 1;
  orientData[3][3][3][2] = 1;
//add missing 45
}



int main()
{
  RetValCRL retvalcrl_data;
  
  iniOrientDataArray();
  iniArray();
  printArrayAll();
  printArraySmall();
  cout << missingBrick() << endl;
  retvalcrl_data = nextFree();
  cout << "next Free c: " << retvalcrl_data.c << " r: " << retvalcrl_data.r << " l: " << retvalcrl_data.l << endl;
  
  
  
  return 0;
}
