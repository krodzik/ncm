#include "init_server.h"

int init_server(int* s, int* e, const int port, const int max_clients)
{
	int srv_fd = -1;
	int epoll_fd = -1;
	struct sockaddr_in srv_addr;
	struct epoll_event ee;

	memset(&srv_addr, 0, sizeof(struct sockaddr_in));
	memset(&ee, 0, sizeof(e));

	srv_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
	if (srv_fd < 0) {
		printf("Cannot create socket\n");
		return 1;
	}

	srv_addr.sin_family = AF_INET;
	srv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	srv_addr.sin_port = htons(port);
	if (bind(srv_fd, (struct sockaddr*) &srv_addr, sizeof(srv_addr)) < 0) {
		printf("Cannot bind socket\n");
		close(srv_fd);
		return 1;
	}

	if (listen(srv_fd, 1) < 0) {
		printf("Cannot listen\n");
		close(srv_fd);
		return 1;
	}

	epoll_fd = epoll_create(max_clients + 1);
	if (epoll_fd < 0) {
		printf("Cannot create epoll\n");
		close(srv_fd);
		return 1;
	}

	ee.events = EPOLLIN;
	ee.data.fd = srv_fd;
	if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, srv_fd, &ee) < 0) {
		printf("Cannot add server socket to epoll\n");
		close(epoll_fd);
		close(srv_fd);
		return 1;
	}

	*s = srv_fd;
	*e = epoll_fd;
	return 0;
}
