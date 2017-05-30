#include <zmq.hpp>
#include <string>
#include "types.hpp"

#ifndef INCLUDE_HEALTH_CHECKER_CLASS_HPP_
#define INCLUDE_HEALTH_CHECKER_CLASS_HPP_

#define HEARTBEAT_LIVENESS 3
#define SRV_OK 0
#define SRV_TIMEOUT 1

class  HealthChecker {
	
private:
	
	/* ZMQ context */
	zmq::context_t *ctx;
	/* ZMQ socket used to send pings */
	zmq::socket_t *hb_skt;
	zmq::pollitem_t item;
	
	/* Server information */
	uint8_t srv_id;
	pid_t srv_pid;
	uint8_t srv_service;
	uint16_t srv_port;
	/* Heartbeat liveness */
	uint8_t hb_liveness;
	
	/* Private function */
	void context_init();
	void restart_server();
public:
	HealthChecker(pid_t srv_pid, uint8_t srv_id, uint8_t srv_service, 
		uint16_t srv_port);
	void step();
	~HealthChecker();
};

#endif /* INCLUDE_HEALTH_CHECKER_CLASS_HPP_ */
