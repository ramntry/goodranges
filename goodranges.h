#pragma once
#include <vector>
#include <string>

typedef std::pair<int, int> Range;

std::vector<Range> findGoodRanges(std::string const &deviceName, int lastBlock, int firstBlock
		, int minRangeSize, int precision, int testSize);
