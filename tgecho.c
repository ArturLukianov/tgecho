#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>


char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}


int main(int argc, char** argv) {
    CURL* curl;
    CURLcode res;

    if(argc < 3) {
        printf("Usage: %s [chat_id] [message]\n", argv[0]);
        return -1;
    }

    FILE *token_file = fopen(".tgecho", "r");
    if(token_file == NULL) {
        printf("Bot API token must be placed in .tgecho\n");
        return -1;
    }
    char token[256];
    fread(token, 256, 1, token_file);
    fclose(token_file);

    rtrim(token);

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if(curl) {
        char post_data[2048];
        char url[2048];;
        sprintf(post_data, "chat_id=%s&text=%s", argv[1], argv[2]);
        sprintf(url, "https://api.telegram.org/bot%s/sendMessage", token);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);

        FILE *devnull = fopen("/dev/null", "w+");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, devnull);
        res = curl_easy_perform(curl);
        fclose(devnull);

        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    return 0;
}
