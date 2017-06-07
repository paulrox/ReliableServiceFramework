/* 
 * communication.hpp
 * In this file some useful macro for the communication are defined
 */

#ifndef INCLUDE_COMMUNICATION_HPP_
#define INCLUDE_COMMUNICATION_HPP_

#include "service.hpp"
#include <string>

#define TCP_PROTOCOL "tcp://"
#define IPC_PROTOCOL "ipc://"
#define LOCALHOST "localhost"
#define ANY_ADDRESS "*"
#define BIND 0
#define CONNECT 1
#define REG_PORT_BROKER 5555
#define ROUTER_PORT_BROKER 5559
#define DEALER_START_PORT 6000
#define MAX_LENGTH_STRING_PORT 6
#define EMPTY_MSG (void*)""

#define NUM_FRAMES 3
#define ID_FRAME 0
#define EMPTY_FRAME 1
#define DATA_FRAME 2
#define LENGTH_ID_FRAME 5
#define ENVELOPE 3

#define HEARTBEAT_INTERVAL 2000
#define HC_HEARTBEAT_INTERVAL 5000
#define TIMEOUT_RCV 500
#define REQUEST_TIMEOUT 2000
#define LIVENESS 3
#define WCDPING 500
#define NO_PONG -1

#define SERVER_PONG_PORT 7000
#define BROKER_PONG_PORT 8000

#define MAX_NMR 3

/**
 * @brief      client request module for the service
 */
 
struct request_module {
	service_type_t service;
	char_t parameters[100];
//	int32_t parameter;
};

/**
 * @brief      It's the service status
 */
 
enum service_status_t {
	SERVICE_AVAILABLE, SERVICE_NOT_AVAILABLE, SERVICE_NOT_RELIABLE
};

/**
 * @brief      broker response module for the service
 */
 
struct response_module {
	service_status_t service_status;
	int32_t result;
};

/*
 * @brief      Service module that the broker sends to a server for a service
 */
 
struct service_module {
	bool heartbeat;	 /* If true it is a ping, otherwise it's a service 
			  * request */
	uint64_t seq_id;
	char_t parameters[100];
};

/**
 * @class server reply
 * @file communication.hpp
 * @brief data response from a server
 */
 
struct server_reply_t {
	bool heartbeat;
	bool duplicated;
	int32_t result;
	service_type_t service;
	uint8_t id; 
};

inline void serialize(std::string &str) {}

template<typename head, typename... tail>
void serialize(std::string &str, head h, tail... t)
{
	str.append(std::to_string(h) + " ");
	serialize(str, t...);
}

#endif /* INCLUDE_COMMUNICATION_HPP_ */