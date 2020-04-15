/*
 * ResultSheet.h
 *
 *  Created on: 2 de abr de 2020
 *      Author: joaopaulo
 */

#ifndef RESULTSHEET_H_
#define RESULTSHEET_H_

#include <queue>
#include <string>

class ResultSheet{
public:
	ResultSheet();
	void AddLine(std::string);
	bool HasNext();
	std::string NextLine();
private:
	std::queue<std::string> mSheet;

};

#endif /* RESULTSHEET_H_ */
