#include <cstdio>

#include "goodranges.h"
#include "badblocks_wrapper.h"

using namespace std;

bool testFull(string const &deviceName, Range const &range)
{
//	printf("RUN FULL TEST: applicant %8d - %8d\n", range.second, range.first);
//	return badblocks(deviceName.c_str(), ReadOnly, range.second, range.first) == 0; 
	return true;
}

bool testChunk(string const &deviceName, int firstBlock, int chunkEnd, int testSize)
{
	int chunkBegin = chunkEnd - testSize;
	if (chunkBegin < firstBlock) {
		chunkBegin = firstBlock;
	}
	return badblocks(deviceName.c_str(), ReadOnly, chunkEnd, chunkBegin) == 0;
}

int rangeSize(Range const &range)
{
	return range.second - range.first;
}


vector<Range> findGoodRanges(string const &deviceName, int lastBlock, int firstBlock
		, int minRangeSize, int precision, int testSize)
{
	vector<Range> results;

	int rightEdge = precision + firstBlock;
	Range currentApplicant = Range(firstBlock, firstBlock);
	for (; rightEdge < lastBlock; rightEdge += precision) {
		if (testChunk(deviceName, firstBlock, rightEdge, testSize)) {
			currentApplicant.second = rightEdge;
		} else {
			if (rangeSize(currentApplicant) >= minRangeSize
					&& testFull(deviceName, currentApplicant)) {
				results.push_back(currentApplicant);
			}
			currentApplicant = Range(rightEdge, rightEdge);
		}
	}
	if (rangeSize(currentApplicant) >= minRangeSize
			&& testFull(deviceName, currentApplicant)) {
		results.push_back(currentApplicant);
	}
	return results;
}

