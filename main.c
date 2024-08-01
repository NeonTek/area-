#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void calculate_area(float length, float width);
void calculate_width(float length, float area);
void calculate_length(float width, float area);

int main (){
    float l;
    float w;
    float area;
    char area_unit[4];
    char l_unit[3];
    char w_unit[3];
    char cm[3] = "cm";
    char scm[4] = "scm";
    int input;

    printf("What do you want to calculate\n 1.Area \n 2.Length \n 3.Width \n");
    scanf("%d", &input);
    if (input == 1) {
        printf("Input the length with the metric units e.g 10m: \n");
        scanf("%f%s", &l, l_unit);

        printf("Input the width with the metric units e.g 10m: \n");
        scanf("%f%s", &w, w_unit);

        // Convert length to meters if in cm
        if (strcmp(l_unit, cm) == 0) {
            l = l / 100;
        }

        // Convert width to meters if in cm
        if (strcmp(w_unit, cm) == 0) {
            w = w / 100;
        }

        calculate_area(l, w);
    } else if(input == 2) {
        printf("Input the area with the square metric units e.g 10sm\n(Use sm for square metres and scm for square centimetres): \n");
        scanf("%f%s", &area, area_unit);

        printf("Input the width with the metric units e.g 10m: \n");
        scanf("%f%s", &w, w_unit);

        // Convert width to meters if in cm
        if (strcmp(w_unit, cm) == 0) {
            w = w / 100;
        }

        // Convert area to square meters if in scm
        if (strcmp(area_unit, scm) == 0) {
            area = area / 10000;
        }

        calculate_length(w, area);
    } else if(input == 3) {
        printf("Input the area with the square metric units e.g 10sm\n(Use sm for square metres and scm for square centimetres): \n");
        scanf("%f%s", &area, area_unit);

        printf("Input the length with the metric units e.g 10m: \n");
        scanf("%f%s", &l, l_unit);

        // Convert length to meters if in cm
        if (strcmp(l_unit, cm) == 0) {
            l = l / 100;
        }

        // Convert area to square meters if in scm
        if (strcmp(area_unit, scm) == 0) {
            area = area / 10000;
        }

        calculate_width(l, area);
    }

    main();
    return 0;
}

void calculate_area(float length, float width) {
    float area = length * width;
    printf("Area = %.2f square metres\n", area);
}

void calculate_length(float width, float area) {
    float length = area / width;
    printf("Length = %.2fm\n", length);
}

void calculate_width(float length, float area) {
    float width = area / length;
    printf("Width = %.2fm\n", width);
}
