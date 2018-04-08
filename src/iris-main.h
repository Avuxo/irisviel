#define PORT 8080
#define MAXROUTES 16

struct iris_route{
    char *symbol;
    char *(*callback)(char *arg);
};

struct iris_env{
    struct iris_route routeMap[MAXROUTES];
    int numRoutes;
};

int iris_main(int flags);
struct iris_env *iris_createEnv();
int iris_listen();
