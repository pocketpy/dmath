#include <math.h>
#include <stdio.h>

int main(){
    double x = log(10);

    // write to output.txt
    FILE *fp = fopen("output.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    fprintf(fp, "log(10) = %f\n", x);
    fclose(fp);
    return 0;
}