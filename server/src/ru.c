#include "ru.h"
#include <unistd.h>
#include <string.h>

#include <stdio.h>

static int send_bytes(int fd, const char* msg, size_t len)
{
	int result = -1;
	if (write(fd, &len, sizeof(size_t)) > 0)
		if (write(fd, msg, len) == len)
			result = 0;

	return result;
}

int send_test(int fd)
{
    char* msg = "Funkcja testowa dziala.";
    size_t len = 23;

    return send_bytes(fd, msg, len);
}

struct message* receive_message(int fd)
{
	size_t len = 0;
	char* msg = 0;
	struct message* m = 0;

	if (read(fd, &len, sizeof(size_t)) < 1)
		return 0;

	msg = malloc(len * sizeof(char));
	if (read(fd, msg, len) != len) {
		return 0;
	}

	m = malloc(sizeof(struct message));
	switch (msg[0]) {

		case '1':
            m->x = TEST;
			m->y = 0;
			m->z = 0;
			break;
		default:
			free(m);
			m = 0;
	}

	free(msg);
	return m;
}

void delete_message(struct message* m)
{
	if (m->y)
		free(m->y);

	if (m->z)
		free(m->z);

	free(m);
}

