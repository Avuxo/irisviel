#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "iris-html.h"

char *iris_generateHTTPHeaders(int status){
    char *headers =
        "HTTP/1.1 200 OK\r\n"
        "Connection: close\r\n";
    return headers;
}

/*create an HT*/
char *iris_generateHTTPResponse(char *headers, char *html){
    
    /*size of buffer for the http response*/
    size_t size = strlen(html) + strlen(headers);

    /*http response*/
    char *http = malloc(sizeof(char) * size);

    /*write the response into the buffer (headers + html)*/
    snprintf(http, size, "%s%s\r\n", headers, html);
    
    return http;
}
