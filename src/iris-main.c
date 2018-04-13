#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>


#include "iris-main.h"
#include "iris-routes.h"
#include "iris-log.h"

/* start iris */
int iris_init(struct iris_env *env, int flags){
    printf("Starting Irisviel Version %d on port %d...\n", VERSION, PORT);

    iris_log("Starting main thread...");
    if(pthread_create(&env->mainThread, NULL, iris_run, NULL)){
        iris_fatalError("Unable to create main thread for Irisviel, exiting...");
    }
    iris_log("Main thread started."); /*this could *theoretically* print after the
                                        thread starts, but it seems fairly unlikely
                                        this would happen frequently enough to be
                                        a concern. */
    
    
    return 0;
}

/*main request handling*/
void *iris_run(){

    /*socket information*/
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t socketLength = sizeof(clientAddr);
    int server, client; /*socket descriptors*/
    /*client request buffer*/
    const int bufferSize = 1024;
    char *requestBuffer = malloc(sizeof(char) * bufferSize);
    
    int optionName = 1;
    

    /*initialize the socket */
    server = socket(AF_INET, SOCK_STREAM, 0);
    if(server < 0){
        iris_fatalError("Could not intialize a socket.");
    }

    setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &optionName, sizeof(int));
    
    /*configure the socket address struct*/
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    /*bind the server file descriptor to the address*/
    if(bind(server, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1){
        close(server);
        iris_fatalError("Could not bind the file descriptor to the address.");
    }

    /*configure the socket for listening*/
    if(listen(server, 10) == -1){
        close(server);
        iris_fatalError("Could not set the socket to listen.");
    }

    
    /*check for any requests and respond to them while handling errors in this loop*/
    iris_log("Listening for requests...");
    for(;;) {
        /*accept the first request in the queue*/
        client = accept(server, (struct sockaddr *) &clientAddr, &socketLength);

        if(client == -1){
            iris_fatalError("Connection to client failed.");
        }

        /*fork off the process for the client acceptance*/
        if(fork() == 0){ /*process is child*/
            close(server);
            memset(requestBuffer, 0, bufferSize);
            
            /*read request into the buffer*/
            read(client, requestBuffer, bufferSize - 1);
            iris_log(requestBuffer);
        }
        write(client, "test", 4);
        close(client);
        exit(0);
    }
    close(client); /*parent process*/
    
    
    return NULL;
}

/*allocate a new environment*/
struct iris_env *iris_createEnv(){
    struct iris_env *env = malloc(sizeof(struct iris_env));
    env->numRoutes = 0;

    return env;
}

/*safely exit the iris library*/
void iris_exit(struct iris_env *env){
    if(env != NULL)
        pthread_join(env->mainThread, NULL);
}
