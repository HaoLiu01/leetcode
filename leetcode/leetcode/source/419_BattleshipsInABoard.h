/*
 * 419_BattleshipsInABoard.h
 *
 *  Created on: Oct 28, 2016
 *      Author: hao
 */

#ifndef LEETCODE_LEETCODE_SOURCE_419_BATTLESHIPSINABOARD_H_
#define LEETCODE_LEETCODE_SOURCE_419_BATTLESHIPSINABOARD_H_

/*
Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.

Example:
X..X
...X
...X

In the above board there are 2 battleships.
Invalid Example:
...X
XXXX
...X

This is not a valid board - as battleships will always have a cell separating between them.*/

#include "common.h"

int countBattleships(vector<vector<char>>& board) {
	if (board.empty() || board[0].empty())
		return 0;

	int count = 0;
	size_t width = board[0].size();
	vector<int> countAdjacentXVertical(width, 0);  // 记录竖直的船的长度

	for (int i = 0; i < board.size(); i++) {
		vector<char> &row = board[i];
		int countAdjacentXHorizontal = 0;  // 记录横向的船的长度

		int j = 0
		for (; j < width; j++) {
			if (row[j] == '.') {
				if (countAdjacentXHorizontal == 1) {
					countAdjacentXVertical[j - 1]++;  // 只有一个‘X’，视作竖直的船
				} else if (countAdjacentXHorizontal > 1) {
					count++;  // 横向的船终止
					countAdjacentXHorizontal = 0;
				}

				if (countAdjacentXVertical[j] > 0) {
					count++;  // 竖直的船终止
					countAdjacentXVertical[j] = 0;
				}
				continue;
			}

			countAdjacentXHorizontal++;

			// 处理每一行的最后一个'x'
			if (j == width - 1) {
				if (countAdjacentXHorizontal == 1) {
					countAdjacentXVertical[j]++;  // 视作竖直的船
				} else if (countAdjacentXHorizontal > 1) {
					count++;  // 横向的船终止
				}
			}
		}

		// 处理最后一行中的竖直的船
		if (i == board.size() - 1) {
			for (int j = 0; j < width; j++)
				if (countAdjacentXVertical[j])
					count++;  // 竖直的船
		}
	}

	return count;
}

#endif /* LEETCODE_LEETCODE_SOURCE_419_BATTLESHIPSINABOARD_H_ */
