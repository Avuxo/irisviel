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

/* start iris */
int iris_init(struct iris_env *env, int flags){
    int create = pthread_create(&env->mainThread, NULL, iris_run, NULL);
    
    
    return 0;
}


void *iris_run(){
    int listenError = 0;
    /*check for any requests and respond to them while handling errors in this loop*/
    while(!listenError){
        listenError = iris_listen();
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
