/*
#ifndef USER_LIST_H
#define USER_LIST_H

#include <stdlib.h>

#define MAX_USERS 1000

struct user {
	int fd;
};

struct user_list_ctx;

typedef struct user_list {
//	void (*add_user)(struct user_list_ctx* ctx, struct user* u);
//	void (*rm_user_by_fd)(struct user_list_ctx* ctx, int fd);
	const struct user* (*get_user_by_fd)(struct user_list_ctx* ctx, int fd);
	size_t (*current_size)(struct user_list_ctx* ctx);

	struct user_list_ctx* ctx;
} user_list;

struct user_list* create_user_list();
void delete_user_list(struct user_list* ul);

#endif //USER_LIST_H
*/
