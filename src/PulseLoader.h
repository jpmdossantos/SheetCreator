/*
 * PulseLoader.h
 *
 *  Created on: 2 de abr de 2020
 *      Author: joaopaulo
 */

#ifndef PULSELOADER_H_
#define PULSELOADER_H_

#include "ILoader.h"
#include <string>
#include <vector>
#include <map>

using Pulses = std::vector<std::map<std::string, std::string>>;

class PulseLoader: public ILoader {
public:
	PulseLoader(std::string);
	void Load() override;
	const std::string& getMPath() const {return mPath;}
	void setMPath(const std::string &mPath) {this->mPath = mPath;}
	const Pulses& getMPulses() const {return mPulses;}

private:
	std::vector<std::string> ParseFilenames(std::string&, const char);
	std::string ReadFilenames();

//////////////////////////////////////////////////////////////////////

	std::string mPath;
	Pulses mPulses;
};

#endif /* PULSELOADER_H_ */
