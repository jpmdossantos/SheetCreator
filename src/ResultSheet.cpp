/*
 * ResultSheet.cpp
 *
 *  Created on: 2 de abr de 2020
 *      Author: joaopaulo
 */

#include "ResultSheet.h"

ResultSheet::ResultSheet() {
	// TODO Auto-generated constructor stub

}

void ResultSheet::AddLine(std::string line) {
	mSheet.push(line);
}

bool ResultSheet::HasNext() {
	return !mSheet.empty();
}

std::string ResultSheet::NextLine() {
	std::string next_line = mSheet.front();
	mSheet.pop();
	return next_line;
}
