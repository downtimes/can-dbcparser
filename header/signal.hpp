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

class Signal {

	typedef std::set<std::string> toList;
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
	toList to;

public:
	friend std::istream& operator>>(std::istream& in, Signal& sig);

	std::string getName() const { return name; }
	ByteOrder getByteOrder() const { return order; }
	unsigned short getStartbit() const { return startBit; }
	unsigned short getLength() const { return length; }
	Sign getSign() const { return sign; }
	double getMinimum() const { return minimum; }
	double getMaximum() const { return maximum; }
	double getFactor() const { return factor; }
	double getOffset() const { return offset; }
	std::string getUnit() const { return unit; }
	Multiplexor getMultiplexor() const { return multiplexor; }
	unsigned short getMultiplexedNumber() const { return multiplexNum; }
	toList getTo() const { return to; }

};


#endif /* SIGNAL_HPP_ */
