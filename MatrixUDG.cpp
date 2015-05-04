/*
 * MatrixUDG.cpp
 *
 *  Created on: 2015-4-3
 *      Author: hao
 */
#include <iostream>

#define MAX 100

class MatrixUDG {
  /*
   * Matrix is like (If NumV is 6):
   *  T   0 1 2 3 4 5
   *      0 0 0 T 0 T
   *      1 0 T 0 T 0
   *      2 T 0
   *      3 0 T
   *      4 T 0
   *  T   5
   * */

public:
  MatrixUDG(unsigned Num, bool **Edges) {
    NumV = Num;
    for (unsigned i = 0; i < NumV; i++) {
      for (unsigned j = 0; j < NumV; j++) {
        E[i][j] = Edges[i][j];
      }
    }
  }

void DFS();
void BFS();
void print();

private:
unsigned NumV;
bool E[MAX][MAX];
};

void MatrixUDG::BFS() {

  }
