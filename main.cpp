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


//	std::cout << messages[2].name << "\n" << messages[2].dlc << " " << messages[2].id << " " << messages[2].from << "\n";
//	for_each(messages[2].signals.begin(), messages[2].signals.end(), [](Signal& sig) {
//		std::cout << sig.name << " " << sig.unit << std::endl;
//		std::cout << sig.startBit << "," << sig.length << std::endl;
//		std::cout << "(" << sig.factor << ", " << sig.offset << ")" << std::endl;
//		std::cout << "[" << sig.minimum << "," << sig.maximum << "]" << std::endl;
//		if (sig.multiplexor == Multiplexor::MULTIPLEXED) {
//			std::cout << "#" << sig.multiplexNum << "#" << std::endl;
//		} else if (sig.multiplexor == Multiplexor::MULTIPLEXOR) {
//			std::cout << "+Multiplexor+" << std::endl;
//		}
//	});
//	std::cout << std::endl;
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
