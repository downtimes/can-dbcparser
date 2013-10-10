/*
 * dbctree.cpp
 *
 *  Created on: 04.10.2013
 *      Author: downtimes
 */

#include "header/dbciterator.hpp"

#include <limits>
#include <fstream>

DBCIterator::DBCIterator(const std::string& filePath) {
	std::ifstream file(filePath);
	init(file);
	file.close();
}

DBCIterator::DBCIterator(std::istream& stream) {
	init(stream);
}

void DBCIterator::init(std::istream& stream) {
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
}



