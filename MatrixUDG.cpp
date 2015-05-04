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
   *           Zer One Two Thr Fou Fiv
   *      Zer   F   F   F   T   F   T
   *      One   F   F   T   F   T   F
   *      Two   F   T   F   T   F   T
   *      Thr   T   F   T   F   T   F
   *      Fou   F   T   F   T   F   T
   *      Fiv   T   F   T   F   T   F
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
