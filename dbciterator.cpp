/*
 * dbctree.cpp
 *
 *  Created on: 04.10.2013
 *      Author: downtimes
 */

#include "header/dbciterator.hpp"

#include <limits>
#include <fstream>
#include <stdexcept>

DBCIterator::DBCIterator(const std::string& filePath) {
	std::ifstream file(filePath);
	if (file) {
		init(file);
	} else {
		throw std::invalid_argument("The File could not be opened");
	}
	file.close();
}

DBCIterator::DBCIterator(std::istream& stream) {
	init(stream);
}

void DBCIterator::init(std::istream& stream) {
	messageList.clear();
	std::vector<Message> messages;
	do {
		Message msg;
		stream >> msg;
		if (stream.fail()) {
			stream.clear();
			stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} else {
			messages.push_back(msg);
		}
	} while (!stream.eof());
	messageList.insert(messageList.begin(), messages.begin(), messages.end());
}



