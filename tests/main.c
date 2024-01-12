#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
    int opt;
    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'},
        {"file", required_argument, 0, 'f'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "hvf:", long_options, NULL)) != -1) {
        switch (opt) {
            case 'h':
                printf("Help option\n");
                break;
            case 'v':
                printf("Version option\n");
                break;
            case 'f':
                printf("File option with argument '%s'\n", optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s [-h] [-v] [--file filename]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Remaining code
    return 0;
}

