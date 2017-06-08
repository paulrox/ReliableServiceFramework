/*
 * client.cpp
 * Main program of the client
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <zmq.hpp>
#include <sstream>
#include "../../include/rs_api.hpp"
#include "../../include/util.hpp"
#include "../../include/communication.hpp"



int32_t main(int32_t argc, char_t* argv[])
{	
    	bool ret;
        int32_t result;
	service_type_t service;
   	zmq::context_t context(1);
   	zmq::socket_t socket(context, ZMQ_REQ);
	
	/* Parsing the arguments */
	get_arg(argc, argv, service, 1);
	
	std::cout << "Connecting to the server…" << std::endl;
	socket.connect("tcp://localhost:5559");

	for (uint8_t i = 0; i < 5; i++) {
                ret = request_service(service, &socket, result, 2);
                if (ret) 
                        std::cout << "Result " << result << std::endl;
        }
        
	return EXIT_SUCCESS;
}