// free()
#include <stdlib.h>

// library headers
#include "iris-log.h"
#include "iris-main.h"
#include "iris-routes.h"


/*
  ///////////////////////
  page creation callbacks
  ///////////////////////
*/
char *route_index(char *args){
    char *page =
        "<html>\r\n"
        "<p>Index page</p>\r\n"
        "</html>\r\n";
    
    return page;
}

char *route_about(char *args){
    char *page =
        "<html>\r\n"
        "<p>About page</p>\r\n"
        "</html>\r\n";
    return page;
}

int main(int argc, char **argv){
    /* allocate an environment */
    struct iris_env *env = iris_createEnv();

    iris_registerRoute(env, "/", &route_index);
    iris_registerRoute(env, "/about", &route_about);
    
    /*initialize the irisviel code*/
    iris_init(env, 0);

    

    
    iris_exit(env);

    return 0;
}
