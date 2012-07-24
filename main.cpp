#include <cstdlib>
#include <cstdio>

#include "goodranges.h"

using namespace std;

void checkCommandLineArgs(int argc, char **argv)
{
	if (argc < 7) {
		fprintf(stderr, "Usage: goodranges device last_block first_block min_range_size precision test_size\n");
		fprintf(stderr, "                  (all in Mb, but test_size in blocks (default block size - 1Kb))\n");
		exit(1);
	}
}

int main(int argc, char **argv)
{
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

	vector<Range> results = findGoodRanges(argv[1], lastBlock * 1024, firstBlock * 1024
			, minRangeSize * 1024, precision * 1024, testSize);

	printf("\n\nDONE! Good ranges are:\n");
	vector<Range>::const_iterator it = results.begin();
	for (; it != results.end(); ++it) {
		printf("%8d - %8d\n", it->first, it->second);
	}

	return 0;
}

