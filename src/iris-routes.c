#include <stdio.h>
#include "iris-main.h"
#include "iris-routes.h"
#include "iris-log.h"
#include "iris-html.h"

/*create a route given there is space*/
int iris_registerRoute(struct iris_env *env, char *route, char *(*callback)(char *arg)){
    /*is there space for a new route?*/
    if(env->numRoutes + 1 < MAXROUTES){
        /*create new route structure*/
        struct iris_route newRoute;
        newRoute.symbol = route;
        newRoute.callback = callback;
        /*add the new route to the route map*/
        env->routeMap[env->numRoutes++] = newRoute;
        return 0;
    }
    iris_error("could not add route");
    return 1;
}

/*call the callback for a given route and return the result*/
char *iris_getRoute(struct iris_env *env, char *route, char *args){
    for(int i=0; i<env->numRoutes; i++){
        if(env->routeMap[i].symbol == route){
            char *headers = iris_generateHTTPHeaders(200);
            char *html = env->routeMap[i].callback(args);

            return iris_generateHTTPResponse(headers, html);
        }
    }
    return "404";
}

