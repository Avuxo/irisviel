struct iris_env;
int iris_registerRoute(struct iris_env *env, char *route, char *(*callback)(char *arg));
char *iris_getRoute(struct iris_env *env, char *route, char *args);
