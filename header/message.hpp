/*
 * message.hpp
 *
 *  Created on: 04.10.2013
 *      Author: downtimes
 */

#ifndef MESSAGE_HPP_
#define MESSAGE_HPP_

#include <string>
#include <vector>
#include <cstdint>

#include "signal.hpp"

class Message {

public:
	std::string name;
	std::uint32_t id;
	unsigned char dlc;
	std::string from;
	std::vector<Signal> signals;


	friend std::istream& operator>>(std::istream& in, Message& msg);

};




#endif /* MESSAGE_HPP_ */
