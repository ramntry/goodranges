/**
 * @file goodranges.h Methods for quick search of continuous non-damaged
 * ranges of HDD
 *
 * @copy Copyright (C) 2012 @author Roman Tereshin. This file may be
 * redistributed under the terms of the GNU Public License.
 */

#pragma once
#include <vector>
#include <string>

/** Range of disk surface in blocks */
typedef std::pair<int, int> Range;

/**
 * @brief Main method of goodranges searching
 * @param deviceName Path to file of device like /dev/sdc
 * @param lastBlock The last block to be checked
 * @param firstBlock The starting block number of the test
 * @param minRangeSize The size of minimum continuous range that will be considered
 * @param precision The step of checking
 * @param testSize Size of chunck in every step that will be really checked
 */
std::vector<Range> findGoodRanges(std::string const &deviceName, int lastBlock
		, int firstBlock, int minRangeSize, int precision, int testSize);
		
