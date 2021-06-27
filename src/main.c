#include <stdio.h>
#include <string.h>
#include "./headers/run.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        help();
    }

    else if (argc == 2)
    {
        if (strcmp(argv[1],"-h") == 0)
            help();
        else{
            return 1;
        }
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1],"-r") == 0)
        {
            run(argv[2]);
        }
    }
    else {
        return 1;
    }

    return 0;
}