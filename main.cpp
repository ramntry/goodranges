/**
 * @file main.cpp Experimental utility for quick search of continuous non-damaged
 * ranges of HDD based on badblocks
 *
 * @copy Copyright (C) 2012 @author Roman Tereshin. This file may be
 * redistributed under the terms of the GNU Public License.
 */

#include <cstdlib>
#include <cstdio>

#include "goodranges.h"

using namespace std;

void checkCommandLineArgs(int argc, char **argv)
{
	if (argc < 7) {
		fprintf(stderr, "Usage: goodranges device last_block first_block"
				" min_range_size precision test_size\n");
		fprintf(stderr, "                  (all in Mb, but test_size in"
				" blocks (default block size - 1Kb))\n");
		fprintf(stderr, "\n(see README and goodranges.h for details)\n");
		exit(1);
	}
}

void showWarning()
{
	printf("\nWARNING! This is an experimental tool, use it at your own risk.\n"
			"I do not take any responsibility for possible consequences"
			" of its use.\n\n");
}

int main(int argc, char **argv)
{
	showWarning();
	checkCommandLineArgs(argc, argv);
	int lastBlock = 0;
	int firstBlock = 0;
	int minRangeSize = 0;
	int precision = 0;
	int testSize = 0;
	sscanf(argv[2], "%d", &lastBlock);
	sscanf(argv[3], "%d", &firstBlock);
	sscanf(argv[4], "%d", &minRangeSize);
	sscanf(argv[5], "%d", &precision);
	sscanf(argv[6], "%d", &testSize);

	const int blocksInMb = 1024;
	vector<Range> results = findGoodRanges(argv[1], lastBlock * blocksInMb, firstBlock * blocksInMb
			, minRangeSize * blocksInMb, precision * blocksInMb, testSize);

	printf("\n\nDONE! Good ranges are:\n");
	vector<Range>::const_iterator it = results.begin();
	for (; it != results.end(); ++it) {
		printf("%8d - %8d\n", it->first, it->second);
	}

	return 0;
}

