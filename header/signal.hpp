/*
 * signal.hpp
 *
 *  Created on: 04.10.2013
 *      Author: downtimes
 */

#ifndef SIGNAL_HPP_
#define SIGNAL_HPP_

#include <string>
#include <set>

enum class ByteOrder {
	MOTOROLA,
	INTEL
};

enum class Sign {
	UNSIGNED,
	SIGNED
};

enum class Multiplexor {
	NONE,
	MULTIPLEXED,
	MULTIPLEXOR
};

class Message;

class Signal {

public:
	std::string name;
	ByteOrder order;
	unsigned short startBit;
	unsigned short length;
	Sign sign;
	double minimum;
	double maximum;
	double factor;
	double offset;
	std::string unit;
	Multiplexor multiplexor;
	unsigned short multiplexNum;
	std::set<std::string> to;
	Message& owner;


	friend std::istream& operator>>(std::istream& in, Signal& sig);
	Signal(Message& owner) : name(""), order(ByteOrder::MOTOROLA),
			startBit(0), length(0), sign(Sign::UNSIGNED), minimum(0),
			maximum(0), factor(0), offset(0), unit(""), multiplexor(Multiplexor::NONE),
			multiplexNum(0), owner(owner) {}
};


#endif /* SIGNAL_HPP_ */
