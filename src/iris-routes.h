struct iris_env;
int iris_registerRoute(struct iris_env *env, char *route, char *(*callback)(char *arg));
