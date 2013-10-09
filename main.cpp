/*
 * main.cpp
 *
 *  Created on: 04.10.2013
 *      Author: downtimes
 */

#include <fstream>
#include <iostream>
#include <limits>
#include <algorithm>

#include "header/message.hpp"

const std::string usage = ""
		"This parser is meant to be used via CLI at the moment\n"
		"	./parser <FILE>\n"
		"	\n"
		"example:\n"
		"	./parser /home/downtimes/kit13.dbc\n";

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << usage << std::endl;
		return 0;
	}

	std::ifstream file(argv[1]);
	if (!file) {
		std::cout << "The file could not be opened" << std::endl;
		return 0;
	}


	std::vector<Message> messages;
	do {
		Message msg;
		file >> msg;
		if (file.fail()) {
			file.clear();
			file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} else {
			messages.push_back(msg);
		}
	} while (!file.eof());
	file.close();


	std::cout << messages[2].getName() << "\n" << messages[2].getDlc() << " " << messages[2].getId() << " " << messages[2].getFrom() << "\n";
	for_each(messages[2].begin(), messages[2].end(), [](const Signal& sig) {
		std::cout << sig.getName() << " " << sig.getUnit() << std::endl;
		std::cout << sig.getStartbit() << "," << sig.getLength() << std::endl;
		std::cout << "(" << sig.getFactor() << ", " << sig.getOffset() << ")" << std::endl;
		std::cout << "[" << sig.getMinimum() << "," << sig.getMaximum() << "]" << std::endl;
		if (sig.getMultiplexor() == Multiplexor::MULTIPLEXED) {
			std::cout << "#" << sig.getMultiplexedNumber() << "#" << std::endl;
		} else if (sig.getMultiplexor() == Multiplexor::MULTIPLEXOR) {
			std::cout << "+Multiplexor+" << std::endl;
		}
	});
	std::cout << std::endl;
//
//	std::cout << messages[30].name << std::endl;
//	for_each(messages[30].signals.begin(), messages[30].signals.end(), [](Signal& sig) {
//		std::cout << "Signal: " << sig.name << "  ";
//		std::cout << "To: ";
//		for_each(sig.to.begin(), sig.to.end(), [](const std::string& to){
//			std::cout << to << ", ";
//		});
//		std::cout << std::endl;
//	});
	return 0;
}
