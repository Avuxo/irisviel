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


void *iris_run(){
    int listenError = 0;
    /*check for any requests and respond to them while handling errors in this loop*/
    iris_log("Listening for requests...");
    while(!listenError){
        listenError = iris_listen();
    }

    switch(listenError){
    case IRIS_SUCCESS:
        iris_log("Exiting...");
    case IRIS_FATAL_ERROR:
        iris_fatalError("Error in request, exiting...");
    }
    
    return NULL;
}

/*allocate a new environment*/
struct iris_env *iris_createEnv(){
    struct iris_env *env = malloc(sizeof(struct iris_env));
    env->numRoutes = 0;

    return env;
}

int iris_listen(){
    /*TODO*/
    return 0;
}

void iris_exit(struct iris_env *env){
    pthread_join(env->mainThread, NULL);
}
