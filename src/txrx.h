/*
 * txrx.h
 *
 *  Created on: Mar 8, 2021
 *      Author: iskandar
 */

#ifndef INCLUDE_TXRX_H_
#define INCLUDE_TXRX_H_

#include <sys/socket.h>
#include <arpa/inet.h>
#include "logger.h"
#include "util.h"

#define LISTEN_PORT 5900
#define REMOTE_PORT 5901

struct txrx_ {
	struct sockaddr_in server_addr;
	int server_socket;


} _txrx;

//void listen(struct txrx_ *, _logger *);
void server_connect(struct txrx_ *, _logger *);




#endif /* INCLUDE_TXRX_H_ */
