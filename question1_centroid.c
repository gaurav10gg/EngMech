#include <stdio.h>

int main() {
    int r, triFlag;

    printf("Enter last two digits of roll number (XX): ");
    scanf("%d", &r);

    printf("Triangle orientation (1 = base up, 0 = base down): ");
    scanf("%d", &triFlag);

    int d1 = r / 10;
    int d2 = r % 10;
    int sumDigits = d1 + d2;

    int evenSum = 0;
    if (d1 % 2 == 0) evenSum += d1;
    if (d2 % 2 == 0) evenSum += d2;

    double b1 = r * 0.5;                
    double h1 = sumDigits * 2.0;         
    double b2 = b1 / 2.0;               
    double h2 = b2 / 3.0;              
    double b3 = b1 + h1 / 4.0;           
    double h3 = h1 + evenSum * 0.5;     

    double A1 = b1 * h1;               
    double A2 = b2 * h2;               
    double A3 = 0.5 * b3 * h3;        

    double y1 = h1 / 2.0;

    double y2 = h1 + h2 / 2.0;

    double y3;
    if (triFlag == 1)
        y3 = h1 + h2 + h3 - (h3 / 3.0);   
    else
        y3 = h1 + h2 + (h3 / 3.0);         

    double A_total = A1 + A2 + A3;

    double yBar = (A1 * y1 + A2 * y2 + A3 * y3) / A_total;

    double xBar = b3 / 2.0;

    printf("\n========= PARAMETERS =========\n");
    printf("Rect1: b1 = %.2f mm, h1 = %.2f mm\n", b1, h1);
    printf("Rect2: b2 = %.2f mm, h2 = %.2f mm\n", b2, h2);
    printf("Tri  : b3 = %.2f mm, h3 = %.2f mm\n", b3, h3);

    printf("\n========= AREAS =========\n");
    printf("Area A1 (Rect1) = %.2f mm^2\n", A1);
    printf("Area A2 (Rect2) = %.2f mm^2\n", A2);
    printf("Area A3 (Tri)   = %.2f mm^2\n", A3);

    printf("\n========= INDIVIDUAL CENTROIDS =========\n");
    printf("y1 (Rect1) = %.2f mm\n", y1);
    printf("y2 (Rect2) = %.2f mm\n", y2);
    printf("y3 (Tri  ) = %.2f mm\n", y3);

    printf("\n========= TOTAL CENTROID =========\n");
    printf("x̄ = %.2f mm\n", xBar);
    printf("ȳ = %.2f mm\n", yBar);
    printf("\nCentroid approx located at: (x̄ = %.2f mm, ȳ = %.2f mm)\n\n", xBar, yBar);

    return 0;
}
