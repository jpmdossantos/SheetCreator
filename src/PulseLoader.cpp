/*
 * PulseLoader.cpp
 *
 *  Created on: 2 de abr de 2020
 *      Author: joaopaulo
 */

#include "PulseLoader.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/algorithm/string.hpp>

PulseLoader::PulseLoader(std::string path) {
	// TODO Auto-generated constructor stub
	this->mPath = path;
	this->Load();
}

void PulseLoader::Load() {
	std::string filenames = ReadFilenames();
	const char filename_delimiter = '\n';
    auto parsed_filenames = ParseFilenames(filenames, filename_delimiter);
    std::ifstream filestream;
    std::string property, value, line;

    for(auto file : parsed_filenames)
    {
        filestream.open(file);
        if (!filestream){
        throw std::runtime_error("File not found");
        break;
        }

        property = value = line = "";
        std::map<std::string,std::string> current_file_properties;

        // Iterate through each line and split the content using delimeter
        while (getline(filestream, line))
        {
            std::istringstream ss(line);
            std::getline(ss, property, ':');
            std::getline(ss, value);
            boost::trim(property);
            boost::trim(value);
            std::pair<std::string,std::string> read_property{property, value};
            current_file_properties.insert(read_property);
        }

        mPulses.push_back(current_file_properties);
        filestream.close();
    }

}

std::vector<std::string> PulseLoader::ParseFilenames(std::string& filenames, char delimiter) {
	std::vector<std::string> results;
	boost::split(results, filenames, [delimiter](char character){return character == delimiter;});
	return results;
}

std::string PulseLoader::ReadFilenames() {
    std::array<char, 128> buffer;
    std::string result;
    std::string command = "find " + mPath +  " -name '*.dat' ";
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen( command.c_str(), "r"), pclose);

    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

	boost::trim(result);
    return result;
}
