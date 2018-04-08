#include "iris-main.h"
#include "iris-routes.h"
#include "iris-log.h"

int iris_registerRoute(struct iris_env *env, char *route, char *(*callback)(char *arg)){
    /*is there space for a new route?*/
    if(env->numRoutes + 1 < MAXROUTES){
        /*create new route structure*/
        struct iris_route newRoute;
        newRoute.symbol = route;
        newRoute.callback = callback;
        /*add the new route to the route map*/
        env->routeMap[++env->numRoutes] = newRoute;
        return 0;
    }
    iris_error("could not add route");
    return 1;
}
