/*
 * dbctree.hpp
 *
 *  Created on: 04.10.2013
 *      Author: downtimes
 */

#ifndef DBCTREE_HPP_
#define DBCTREE_HPP_

#include <vector>
#include <iosfwd>
#include "message.hpp"

class DBCIterator {

	typedef std::vector<Message> messages_t;
	messages_t messageList;

public:
	typedef messages_t::const_iterator const_iterator;
	explicit DBCIterator(const std::string& filePath);
	explicit DBCIterator(std::istream& stream);
	const_iterator begin() const { return messageList.begin(); }
	const_iterator end() const { return messageList.end(); }
	messages_t::const_reference operator[](std::size_t elem) const {
		return messageList[elem];
	}

private:
	void init(std::istream& stream);

};




#endif /* DBCTREE_HPP_ */
