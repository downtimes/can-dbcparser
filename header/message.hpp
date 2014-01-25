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
#include <iosfwd>
#include <cstdint>
#include <set>

#include "signal.hpp"


class Message {

	typedef std::vector<Signal> signals_t;
	std::string name;
	std::uint32_t id;
	std::size_t dlc;
	std::string from;
	signals_t signals;

public:
	typedef signals_t::const_iterator const_iterator;
	friend std::istream& operator>>(std::istream& in, Message& msg);

	std::string getName() const { return name; }
	std::uint32_t getId() const { return id; }
	std::size_t getDlc() const { return dlc; }
	std::string getFrom() const { return from; }
	std::set<std::string> getTo() const;

	const_iterator begin() const { return signals.begin(); }
	const_iterator end() const { return signals.end(); }

	signals_t::const_reference operator[](std::size_t elem) {
		return signals[elem];
	}

};




#endif /* MESSAGE_HPP_ */
