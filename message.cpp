/*
 * message.cpp
 *
 *  Created on: 04.10.2013
 *      Author: downtimes
 */
#include "header/message.hpp"

#include <istream>
#include <limits>
#include <algorithm>

std::istream& operator>>(std::istream& in, Message& msg) {
	std::string preamble;
	in >> preamble;
	//Check if we are actually reading a Message otherwise fail the stream
	if (preamble != "BO_") {
		in.setstate(std::ios_base::failbit);
		return in;
	}

	//Parse the message ID
	in >> msg.id;

	//Parse the name of the Message
	std::string name;
	in >> name;
	msg.name = name.substr(0, name.length() - 1);

	//Parse the Messages length
	in >> msg.dlc;

	//Parse the sender;
	in >> msg.from;

	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//As long as there is a Signal, parse the Signal
	while(in) {
		Signal sig;
		in >> sig;
		if (in) {
			msg.signals.push_back(sig);
		}
	}

	in.clear();
	return in;
}


std::set<std::string> Message::getTo() const {
	std::set<std::string> collection;
	for (auto sig : signals) {
		auto toList = sig.getTo();
		collection.insert(toList.begin(), toList.end());
	}
	return collection;
}
