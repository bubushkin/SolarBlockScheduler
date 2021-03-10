/*
 * txrx.c
 *
 *  Created on: Mar 8, 2021
 *      Author: iskandar
 */

#include "txrx.h"
/*
void listen(struct txrx_ *txrx, _logger *logger){

	int valread = 0;

	if((txrx->server_socket = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		eeprint("Unable to initiate a socket");
	}
	memset(txrx->server_addr, 0, sizeof(txrx->server_addr));
	txrx->server_addr.sin_family = AF_INET;
	txrx->server_addr.sin_addr.s_addr = INADDR_ANY;
	txrx->server_addr.sin_port = htons(LISTEN_PORT);

	if(bind(txrx->server_socket,
			(const struct sockaddr *) txrx->server_addr,
			sizeof(txrx->server_addr)) < 0){
		eeprint("Socket Bind failed");
	}

}
*/