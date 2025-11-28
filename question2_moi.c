#include <stdio.h>
#include <math.h>

int main() {
    double bf, tf, hw, bw;
    int flip;


    printf("Enter flange width b_f (mm): ");
    scanf("%lf", &bf);

    printf("Enter flange thickness t_f (mm): ");
    scanf("%lf", &tf);

    printf("Enter web height h_w (mm): ");
    scanf("%lf", &hw);

    printf("Enter web thickness b_w (mm): ");
    scanf("%lf", &bw);

    printf("Flip section? (1 = yes, 0 = no): ");
    scanf("%d", &flip);

    double A_top = bf * tf;
    double A_web = bw * hw;
    double A_bottom = bf * tf;

    double y_bottom = tf / 2.0;
    double y_web = tf + hw / 2.0;
    double y_top = tf + hw + tf / 2.0;

    double total_height = tf + hw + tf;

    if (flip == 1) {
        y_bottom = total_height - (tf / 2.0);
        y_web = total_height - (tf + hw / 2.0);
        y_top = tf / 2.0;
    }

    double A = A_top + A_web + A_bottom;
    double y_bar =
        (A_bottom * y_bottom +
         A_web * y_web +
         A_top * y_top) / A;


    double I_bottom = (bf * pow(tf, 3)) / 12.0;
    double I_web = (bw * pow(hw, 3)) / 12.0;
    double I_top = (bf * pow(tf, 3)) / 12.0;

    double d_bottom = fabs(y_bar - y_bottom);
    double d_web = fabs(y_bar - y_web);
    double d_top = fabs(y_bar - y_top);

    double Ixx =
        I_bottom + A_bottom * pow(d_bottom, 2) +
        I_web + A_web * pow(d_web, 2) +
        I_top + A_top * pow(d_top, 2);

    printf("\n----- RESULTS -----\n");

    printf("Total area A = %.3f mm^2\n", A);
    printf("Centroid ȳ = %.3f mm\n", y_bar);

    printf("I_xx about centroidal axis = %.3f mm^4\n", Ixx);

    return 0;
}
