/*
 * 383_ransomNote.h
 *
 *  Created on: Oct 22, 2016
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_383_RANSOMNOTE_H_
#define LEETCODE_SOURCE_383_RANSOMNOTE_H_

#include "common.h"

bool canConstruct(string ransomNote, string magazine) {
	int pos;
	for (int i = 0; i < ransomNote.length(); i++) {
		if ((pos = magazine.find(ransomNote.at(i))) < 0)
			return false;
		magazine = magazine.erase(pos, 1);
	}

	return true;
}

#endif /* LEETCODE_SOURCE_383_RANSOMNOTE_H_ */
