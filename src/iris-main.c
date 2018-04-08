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

int iris_main(struct iris_env *env, int flags){
    
    free(env);
    return 0;
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
