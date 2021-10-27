#include "./includes/philosophers.h"

static int *freeValue(int *value) {
    free(value);
    value = NULL;
    return NULL;
}

static int *parserValue(const int argc, char **argv) {
    int *value;
    int j;
    int i;

    value = (int *)malloc(sizeof(int) * (argc - 1));
    if (!value)
        return NULL;
    j = 0;
    i = 1;
    while (i && argv[i])
        if ((value[j++] = atoi(argv[i++])) < 0)
            i ^= i;
    if (i)
        return value;
    printf(ERROR " arg%d - \"%s\"\n", j, argv[j]);
    return freeValue(value);
}

int *ft_parser(const int argc, char **argv) {
    int flag;
    int j;
    int i;

    flag = 1;
    j = 0;
    while (flag && argv[j++] && !(i ^= i))
        while (flag && argv[j] && argv[j][i])
            if (!isdigit(argv[j][i++]) || i > INT_LEN)
                flag ^= flag;
    if (flag)
        return parserValue(argc, argv);
    printf(ERROR " arg%d - \"%s\"\n", j, argv[j]);
    return NULL;
}