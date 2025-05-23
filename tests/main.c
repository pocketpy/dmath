#include <math.h>
#include <stdio.h>

int main(){
    double x = sin(0.5);

    // write to output.txt
    FILE *fp = fopen("output.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    fprintf(fp, "sin(0.5) = %f\n", x);
    fclose(fp);
    return 0;
}