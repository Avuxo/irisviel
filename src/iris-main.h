#include <pthread.h>

#define PORT 8080
#define MAXROUTES 16

#define VERSION 1

/* return codes */
#define IRIS_SUCCESS 1
#define IRIS_FATAL_ERROR 2

struct iris_route{
    char *symbol;
    char *(*callback)(char *arg);
};

struct iris_env{
    struct iris_route routeMap[MAXROUTES];
    int numRoutes;
    pthread_t mainThread;
};

int iris_init(struct iris_env *env, int flags);
struct iris_env *iris_createEnv();
void *iris_run();
int iris_listen();
void iris_exit(struct iris_env *env);


