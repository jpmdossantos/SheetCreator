/*
 * ILoader.h
 *
 *  Created on: 2 de abr de 2020
 *      Author: joaopaulo
 */

#ifndef ILOADER_H_
#define ILOADER_H_
#include "ResultSheet.h"

class ILoader {
public:
	virtual ~ILoader(){};
	virtual void Load()=0;
};

#endif /* ILOADER_H_ */
