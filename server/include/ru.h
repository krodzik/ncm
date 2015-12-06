#include <stdlib.h>
#include <stdbool.h>

enum message_type {
	TEST
};

struct message {
	enum message_type x;
	char* y;
	char* z;
};

int send_test(int fd);

struct message* receive_message(int fd);
void delete_message(struct message* m);

