#include <iostream>
using namespace std;
#include <ctime>


bool orientData[7][7][7][48];

int x[11][11][11][5];
// [colum...c][row...r][level...l][brick number, varianz of orientation (0...47), c base, r base, l base]
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



// End Def -------------------------------------------

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
 // orientData[3][3][3][0] = 1;   Fixpunkt (5 lines)

  orientData[3][3][3][0] = 1;
  orientData[4][3][3][0] = 1;
  orientData[5][3][3][0] = 1;
  orientData[6][3][3][0] = 1;
  orientData[4][2][3][0] = 1;

  orientData[3][3][3][1] = 1;
  orientData[4][3][3][1] = 1;
  orientData[5][3][3][1] = 1;
  orientData[6][3][3][1] = 1;
  orientData[5][2][3][1] = 1;

  orientData[3][3][3][2] = 1;
  orientData[4][3][3][2] = 1;
  orientData[5][3][3][2] = 1;
  orientData[6][3][3][2] = 1;
  orientData[4][4][3][2] = 1;

  orientData[3][3][3][3] = 1;
  orientData[4][3][3][3] = 1;
  orientData[5][3][3][3] = 1;
  orientData[6][3][3][3] = 1;
  orientData[5][4][3][3] = 1;

  orientData[3][3][3][4] = 1;
  orientData[4][3][3][4] = 1;
  orientData[5][3][3][4] = 1;
  orientData[6][3][3][4] = 1;
  orientData[4][3][2][4] = 1;

  orientData[3][3][3][5] = 1;
  orientData[4][3][3][5] = 1;
  orientData[5][3][3][5] = 1;
  orientData[6][3][3][5] = 1;
  orientData[5][3][2][5] = 1;

  orientData[3][3][3][6] = 1;
  orientData[4][3][3][6] = 1;
  orientData[5][3][3][6] = 1;
  orientData[6][3][3][6] = 1;
  orientData[4][3][4][6] = 1;

  orientData[3][3][3][7] = 1;
  orientData[4][3][3][7] = 1;
  orientData[5][3][3][7] = 1;
  orientData[6][3][3][7] = 1;
  orientData[5][3][4][7] = 1;

  orientData[3][3][3][8] = 1;
  orientData[2][3][3][8] = 1;
  orientData[1][3][3][8] = 1;
  orientData[0][3][3][8] = 1;
  orientData[2][2][3][8] = 1;

  orientData[3][3][3][9] = 1;
  orientData[2][3][3][9] = 1;
  orientData[1][3][3][9] = 1;
  orientData[0][3][3][9] = 1;
  orientData[1][2][3][9] = 1;

  orientData[3][3][3][10] = 1;
  orientData[2][3][3][10] = 1;
  orientData[1][3][3][10] = 1;
  orientData[0][3][3][10] = 1;
  orientData[2][4][3][10] = 1;

  orientData[3][3][3][11] = 1;
  orientData[2][3][3][11] = 1;
  orientData[1][3][3][11] = 1;
  orientData[0][3][3][11] = 1;
  orientData[1][4][3][11] = 1;

  orientData[3][3][3][12] = 1;
  orientData[2][3][3][12] = 1;
  orientData[1][3][3][12] = 1;
  orientData[0][3][3][12] = 1;
  orientData[2][3][2][12] = 1;

  orientData[3][3][3][13] = 1;
  orientData[2][3][3][13] = 1;
  orientData[1][3][3][13] = 1;
  orientData[0][3][3][13] = 1;
  orientData[1][3][2][13] = 1;

  orientData[3][3][3][14] = 1;
  orientData[2][3][3][14] = 1;
  orientData[1][3][3][14] = 1;
  orientData[0][3][3][14] = 1;
  orientData[2][3][4][14] = 1;

  orientData[3][3][3][15] = 1;
  orientData[2][3][3][15] = 1;
  orientData[1][3][3][15] = 1;
  orientData[0][3][3][15] = 1;
  orientData[1][3][4][15] = 1;

// ---

  orientData[3][3][3][16] = 1;
  orientData[3][4][3][16] = 1;
  orientData[3][5][3][16] = 1;
  orientData[3][6][3][16] = 1;
  orientData[2][4][3][16] = 1;
            
  orientData[3][3][3][17] = 1;
  orientData[3][4][3][17] = 1;
  orientData[3][5][3][17] = 1;
  orientData[3][6][3][17] = 1;
  orientData[2][5][3][17] = 1;
            
  orientData[3][3][3][18] = 1;
  orientData[3][4][3][18] = 1;
  orientData[3][5][3][18] = 1;
  orientData[3][6][3][18] = 1;
  orientData[4][4][3][18] = 1;
            
  orientData[3][3][3][19] = 1;
  orientData[3][4][3][19] = 1;
  orientData[3][5][3][19] = 1;
  orientData[3][6][3][19] = 1;
  orientData[4][5][3][19] = 1;
            
  orientData[3][3][3][20] = 1;
  orientData[3][4][3][20] = 1;
  orientData[3][5][3][20] = 1;
  orientData[3][6][3][20] = 1;
  orientData[3][4][2][20] = 1;
            
  orientData[3][3][3][21] = 1;
  orientData[3][4][3][21] = 1;
  orientData[3][5][3][21] = 1;
  orientData[3][6][3][21] = 1;
  orientData[3][5][2][21] = 1;
            
  orientData[3][3][3][22] = 1;
  orientData[3][4][3][22] = 1;
  orientData[3][5][3][22] = 1;
  orientData[3][6][3][22] = 1;
  orientData[3][4][4][22] = 1;
            
  orientData[3][3][3][23] = 1;
  orientData[3][4][3][23] = 1;
  orientData[3][5][3][23] = 1;
  orientData[3][6][3][23] = 1;
  orientData[3][5][4][23] = 1;
            
  orientData[3][3][3][24] = 1;
  orientData[3][2][3][24] = 1;
  orientData[3][1][3][24] = 1;
  orientData[3][0][3][24] = 1;
  orientData[2][2][3][24] = 1;
            
  orientData[3][3][3][25] = 1;
  orientData[3][2][3][25] = 1;
  orientData[3][1][3][25] = 1;
  orientData[3][0][3][25] = 1;
  orientData[2][1][3][25] = 1;
            
  orientData[3][3][3][26] = 1;
  orientData[3][2][3][26] = 1;
  orientData[3][1][3][26] = 1;
  orientData[3][0][3][26] = 1;
  orientData[4][2][3][26] = 1;
            
  orientData[3][3][3][27] = 1;
  orientData[3][2][3][27] = 1;
  orientData[3][1][3][27] = 1;
  orientData[3][0][3][27] = 1;
  orientData[4][1][3][27] = 1;
            
  orientData[3][3][3][28] = 1;
  orientData[3][2][3][28] = 1;
  orientData[3][1][3][28] = 1;
  orientData[3][0][3][28] = 1;
  orientData[3][2][2][28] = 1;
            
  orientData[3][3][3][29] = 1;
  orientData[3][2][3][29] = 1;
  orientData[3][1][3][29] = 1;
  orientData[3][0][3][29] = 1;
  orientData[3][1][2][29] = 1;
            
  orientData[3][3][3][30] = 1;
  orientData[3][2][3][30] = 1;
  orientData[3][1][3][30] = 1;
  orientData[3][0][3][30] = 1;
  orientData[3][2][4][30] = 1;
            
  orientData[3][3][3][31] = 1;
  orientData[3][2][3][31] = 1;
  orientData[3][1][3][31] = 1;
  orientData[3][0][3][31] = 1;
  orientData[3][1][4][31] = 1;

// ---

  orientData[3][3][3][32] = 1;
  orientData[3][3][4][32] = 1;
  orientData[3][3][5][32] = 1;
  orientData[3][3][6][32] = 1;
  orientData[2][3][4][32] = 1;
               
  orientData[3][3][3][33] = 1;
  orientData[3][3][4][33] = 1;
  orientData[3][3][5][33] = 1;
  orientData[3][3][6][33] = 1;
  orientData[2][3][5][33] = 1;
               
  orientData[3][3][3][34] = 1;
  orientData[3][3][4][34] = 1;
  orientData[3][3][5][34] = 1;
  orientData[3][3][6][34] = 1;
  orientData[4][3][4][34] = 1;
               
  orientData[3][3][3][35] = 1;
  orientData[3][3][4][35] = 1;
  orientData[3][3][5][35] = 1;
  orientData[3][3][6][35] = 1;
  orientData[4][3][5][35] = 1;
               
  orientData[3][3][3][36] = 1;
  orientData[3][3][4][36] = 1;
  orientData[3][3][5][36] = 1;
  orientData[3][3][6][36] = 1;
  orientData[3][2][4][36] = 1;
               
  orientData[3][3][3][37] = 1;
  orientData[3][3][4][37] = 1;
  orientData[3][3][5][37] = 1;
  orientData[3][3][6][37] = 1;
  orientData[3][2][5][37] = 1;
               
  orientData[3][3][3][38] = 1;
  orientData[3][3][4][38] = 1;
  orientData[3][3][5][38] = 1;
  orientData[3][3][6][38] = 1;
  orientData[3][4][4][38] = 1;
               
  orientData[3][3][3][39] = 1;
  orientData[3][3][4][39] = 1;
  orientData[3][3][5][39] = 1;
  orientData[3][3][6][39] = 1;
  orientData[3][4][5][39] = 1;
               
  orientData[3][3][3][40] = 1;
  orientData[3][3][2][40] = 1;
  orientData[3][3][1][40] = 1;
  orientData[3][3][0][40] = 1;
  orientData[2][3][2][40] = 1;
               
  orientData[3][3][3][41] = 1;
  orientData[3][3][2][41] = 1;
  orientData[3][3][1][41] = 1;
  orientData[3][3][0][41] = 1;
  orientData[2][3][1][41] = 1;
               
  orientData[3][3][3][42] = 1;
  orientData[3][3][2][42] = 1;
  orientData[3][3][1][42] = 1;
  orientData[3][3][0][42] = 1;
  orientData[4][3][2][42] = 1;
               
  orientData[3][3][3][43] = 1;
  orientData[3][3][2][43] = 1;
  orientData[3][3][1][43] = 1;
  orientData[3][3][0][43] = 1;
  orientData[4][3][1][43] = 1;
               
  orientData[3][3][3][44] = 1;
  orientData[3][3][2][44] = 1;
  orientData[3][3][1][44] = 1;
  orientData[3][3][0][44] = 1;
  orientData[3][2][2][44] = 1;
               
  orientData[3][3][3][45] = 1;
  orientData[3][3][2][45] = 1;
  orientData[3][3][1][45] = 1;
  orientData[3][3][0][45] = 1;
  orientData[3][2][1][45] = 1;
               
  orientData[3][3][3][46] = 1;
  orientData[3][3][2][46] = 1;
  orientData[3][3][1][46] = 1;
  orientData[3][3][0][46] = 1;
  orientData[3][4][2][46] = 1;
               
  orientData[3][3][3][47] = 1;
  orientData[3][3][2][47] = 1;
  orientData[3][3][1][47] = 1;
  orientData[3][3][0][47] = 1;
  orientData[3][4][1][47] = 1;

}






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
  for (int l=3; l<8; l++) {
    for (int r=3; r<8; r++) {
      for (int c=3; c<8; c++) {
        cout << x[c][r][l][0] + 10 << " ";
      }
      cout << "| ";
    } 
    cout << endl;
  }
//  cout << " --- Start Print Array Small Alignment --- " << endl;
//  for (int l=3; l<8; l++) {
//    for (int r=3; r<8; r++) {
//      for (int c=3; c<8; c++) {
//        cout << x[c][r][l][1] + 10 << " ";
//      }
//      cout << "| ";
//    } 
//    cout << endl;
//  }
  cout << " --- End Print Array Small --- " << endl;
}



void iniArray() {
  for (int l=0; l<11; l++) {
    for (int r=0; r<11; r++) {
      for (int c=0; c<11; c++) {
        x[c][r][l][0] = 1;
        x[c][r][l][1] = 0;
        x[c][r][l][2] = 0;
        x[c][r][l][3] = 0;
        x[c][r][l][4] = 0;
      }
    } 
  }
  for (int l=3; l<8; l++) {
    for (int r=3; r<8; r++) {
      for (int c=3; c<8; c++) {
        x[c][r][l][0] = 0;
      }
    } 
  }
}



int missingBrick() {
  int n = 0;
  for (int l=3; l<8; l++) {
    for (int r=3; r<8; r++) {
      for (int c=3; c<8; c++) {
        if (x[c][r][l][0] == 0) {n++;}
      }
    } 
  }
  return n/5;
}


RetValCRL nextFree() {
  bool stop = 0;
  int l = 3, r, c;
  RetValCRL retvalcrl_data;
  while(l < 8 and stop == 0) {
    r = 3;
    while(r < 8 and stop == 0) {
      c = 3;
      while(c < 8 and stop == 0) {
        if (x[c][r][l][0] == 0) {
          stop = 1;
        } 
        c++;
      }
      r++;
    }
    l++;
  }
  retvalcrl_data.c = c-1;
  retvalcrl_data.r = r-1;
  retvalcrl_data.l = l-1;
  return retvalcrl_data;
}

bool addBrick(RetValCRL crl, int nB, int nA) {
  bool status = 0;
  int cntr = 0;
  for (int lData=0; lData<7; lData++) {
    for (int rData=0; rData<7; rData++) {
      for (int cData=0; cData<7; cData++) {
        if (orientData[cData][rData][lData][nA] == 1) {
          if (x[crl.c-3+cData][crl.r-3+rData][crl.l-3+lData][0] == 0) {
            cntr++;
          }
        }
      } 
    }
  }
  if (cntr >= 5) {
    status = 1;
    for (int lData=0; lData<7; lData++) {
      for (int rData=0; rData<7; rData++) {
        for (int cData=0; cData<7; cData++) {
          if (orientData[cData][rData][lData][nA] == 1) {
            x[crl.c-3+cData][crl.r-3+rData][crl.l-3+lData][0] = nB;
            x[crl.c-3+cData][crl.r-3+rData][crl.l-3+lData][1] = nA;
            x[crl.c-3+cData][crl.r-3+rData][crl.l-3+lData][2] = crl.c;
            x[crl.c-3+cData][crl.r-3+rData][crl.l-3+lData][3] = crl.r;
            x[crl.c-3+cData][crl.r-3+rData][crl.l-3+lData][4] = crl.l;
          }
        }
      } 
    }
  }
  return status;
}

RetValCRL lastAdd() {
  int nB=0;
  RetValCRL retvalcrl_data;
  
  for (int l=3; l<8; l++) {
    for (int r=3; r<8; r++) {
      for (int c=3; c<8; c++) {
        if (x[c][r][l][0] > nB) {
          nB = x[c][r][l][0];
            retvalcrl_data.c = x[c][r][l][2];
            retvalcrl_data.r = x[c][r][l][3];
            retvalcrl_data.l = x[c][r][l][4];
        }
      }
    } 
  }
  return retvalcrl_data;
}



void subBrick(int nB) {
  bool stop = 0;
  int i = 0, l = 3, r, c;

  while(l < 8 and stop == 0) {
    r = 3;
    while(r < 8 and stop == 0) {
      c = 3;
      while(c < 8 and stop == 0) {
        if (x[c][r][l][0] == nB) {
          i++;
          x[c][r][l][0] = 0;
          x[c][r][l][1] = 0;
          x[c][r][l][2] = 0;
          x[c][r][l][3] = 0;
          x[c][r][l][4] = 0;
          if (i >= 5) {
            stop = 1;
          }
        } 
        c++;
      }
      r++;
    }
    l++;
  }
}




int main()
{
//Def
  RetValCRL crlAct;
  int nBrick, nAlign, nMissing, nMissingLeast, tTime_s, tTime_sStart, tRunTime_s;
  bool state;

  
//Ini
  iniOrientDataArray();
  iniArray();
  crlAct = nextFree();
  nMissing = missingBrick();
  nMissingLeast = 25;
  nBrick = 1;
  nAlign = 0;
  tTime_s = clock()/CLOCKS_PER_SEC;
  tTime_sStart = tTime_s;
  
  
//Run
 while(nMissing > 0) {  // >0 is the target
   state = addBrick(crlAct, nBrick, nAlign);
   if (state == 1 && nAlign < 48) {
     nBrick++;
     nAlign = 0;
     crlAct = nextFree();
     //cout << nMissing << " // ";
     nMissing = missingBrick();
     //cout << nMissing << " // " << nMissingLeast << endl;
     if (nMissing < nMissingLeast) {
       nMissingLeast = nMissing;
       //cout << nMissing << " // " << nMissingLeast << endl;
       //cout << endl << "--------- Ergebnis based on nMissingLeast--------- Fehlende = " << nMissing << " / " << nMissingLeast << endl << endl;
       //printArraySmall();
       //getchar();
     }
    // if (((clock()/CLOCKS_PER_SEC)-tTime_s) > 600) {
    //   tTime_s = clock()/CLOCKS_PER_SEC;
    //   cout << endl << "--------- Ergebnis based on time--------- Fehlende = " << nMissing << " / " << nMissingLeast << endl << endl;
    //   printArraySmall();
       //getchar();
    // }
   }
   else {
     //cout << "vor while: nBrick = " << nBrick << " nAlign = " << nAlign << endl;
     while (nAlign > 47) {
       crlAct = lastAdd();
       nBrick = x[crlAct.c][crlAct.r][crlAct.l][0];
       nAlign = x[crlAct.c][crlAct.r][crlAct.l][1];
       subBrick(nBrick);
       //cout << "in while: nBrick = " << nBrick << " nAlign = " << nAlign << endl;
       //getchar();
     }
     nAlign++;
     //cout << "ende Else: nBrick = " << nBrick << " nAlign = " << nAlign << endl;
   }
 }

  
//Print Final
  cout << endl << "--------- Ergebnis --------- Fehlende = " << missingBrick() << endl << endl;
  printArraySmall();
  tRunTime_s = (clock()/CLOCKS_PER_SEC) - tTime_sStart;
  cout << endl << "Runtime in sec: " << tRunTime_s << endl << endl;
//functions
  //cout << missingBrick() << endl;
  
  //crlAct = nextFree();
  //cout << "next Free c: " << crlAct.c << " r: " << crlAct.r << " l: " << crlAct.l << endl;
  
  //crlAct = lastAdd();
  //cout << "lastAdd c: " << crlAct.c << " r: " << crlAct.r << " l: " << crlAct.l << endl;
  
  //printArraySmall();
  //subBrick(x[crlAct.c][crlAct.r][crlAct.l][0]);
  
//Debug functions
  //printArrayAll();
  
  return 0;
}

