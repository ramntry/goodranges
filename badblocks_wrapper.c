#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "badblocks_wrapper.h"

#define BADBLOCKS_NAME "badblocks"
#define IPC_FILE "badblocks.ipc"
#define COMMAND_BUF_SIZE 1024
#define INTEGER_BUF_SIZE 32
#define BADBLOCK_ERROR 64

const char *badblocks_options[] = {
	BADBLOCKS_NAME
	, " -e 2 "
	, " -c 64 "
	, " -b 1024 "
	, " -s "
	, " -v "
	, " -o "
	, IPC_FILE
	, NULL   /* end of list */
};

const char *modes[] = {
	" "      /* read-only (default) */
	, " -n " /* non-destructive read-write */
	, " -w " /* destructive read-write */
};

int cat_integer_option(char *dest, int value)
{
	return sprintf(dest + strlen(dest), " %d ", value);
}

bool was_errors()
{
	FILE *f;
	if ((f = fopen(IPC_FILE, "r")) == NULL) {
		return false;
	}
	fseek(f, 0, SEEK_END);
	bool result = ftell(f) != 0;
	fclose(f);
	return result;
}

int badblocks(const char *device, int mode, int last_block, int first_block)
{
	char command_buf[COMMAND_BUF_SIZE];
	command_buf[0] = '\0';

	int i = 0;
	for (i = 0; badblocks_options[i] != NULL; ++i) {
		strcat(command_buf, badblocks_options[i]);
	}
	strcat(command_buf, modes[mode]);
	strcat(command_buf, device);

	if (last_block != DefaultBlock) {
		cat_integer_option(command_buf, last_block);
		if (first_block != DefaultBlock) {
			cat_integer_option(command_buf, first_block);
		}
	}
	
	int ret = system(command_buf);

	return was_errors() ? (ret | BADBLOCK_ERROR) : ret;
}

