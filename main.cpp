/*
 * main.cpp
 *
 *  Created on: 04.10.2013
 *      Author: downtimes
 */

#include <iostream>
#include <stdexcept>

#include "header/dbciterator.hpp"

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

	try {
		DBCIterator dbc(argv[1]);
        for(auto message : dbc) {
            std::cout << message.getName() << " " << message.getId() << std::endl;
            for(auto sig : message) {
                std::cout << "Signal: " << sig.getName() << "  ";
                std::cout << "To: ";
                for (auto to : sig.getTo()) {
                    std::cout << to << ", ";
                }
                std::cout << sig.getStartbit() << "," << sig.getLength() << std::endl;
                std::cout << "(" << sig.getFactor() << ", " << sig.getOffset() << ")" << std::endl;
                std::cout << "[" << sig.getMinimum() << "," << sig.getMaximum() << "]" << std::endl;
                if (sig.getMultiplexor() == Multiplexor::MULTIPLEXED) {
                    std::cout << "#" << sig.getMultiplexedNumber() << "#" << std::endl;
                } else if (sig.getMultiplexor() == Multiplexor::MULTIPLEXOR) {
                    std::cout << "+Multiplexor+" << std::endl;
                }
                std::cout << std::endl;
            };
        }

	} catch (std::invalid_argument& ex) {
		std::cout << ex.what() << std::endl;
	}

//	return 0;
}
