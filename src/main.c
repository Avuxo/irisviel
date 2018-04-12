// free()
#include <stdlib.h>

// library headers
#include "iris-log.h"
#include "iris-main.h"
#include "iris-routes.h"

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
        "<p>Index page</p>\r\n"
        "</html>\r\n";
    return page;
}

int main(int argc, char **argv){
    /* allocate an environment */
    struct iris_env *env = iris_createEnv();

    /*initialize the irisviel code*/
    iris_init(env, 0);

    iris_registerRoute(env, "/", &route_index);
    iris_registerRoute(env, "/about", &route_about);

    /* no args passed.
       this would be like if i did /:whatever wherever whatever's value is an arg
       arguments are URL-encoded and separated by spaces.
       this would be called by the webserver, this is simply an example.*/
    char *page = iris_getRoute(env, "/", "");
    free(page); /* free the page because it needs to be malloc()'d for sprintf
                // to write into the buffer
                // this is only called after the response is sent to the client.*/

    /*about page*/
    char *aboutPage = iris_getRoute(env, "/about", "");
    free(aboutPage);

    iris_exit(env);

    return 0;
}
