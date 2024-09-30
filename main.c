#include "common.h"
#include "path_variable_scanner.h"

int main(int argc, char *argv[]) {
    // path_variable_scanner(argc, argv);
    enum companies { GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT };
    enum companies company1 = XEROX;
    enum companies company2 = GOOGLE;
    enum companies company3 = EBAY;
    
    printf("The value of XEROX is: %d\n", company1);
    printf("The value of GOOGLE is: %d\n", company2);
    printf("The value of EBAY is: %d\n\n", company3);

    char my_char = 'A';
    printf("The char value of my_char is: %c\n", my_char);
    printf("The dec value of my_char is: %d\n", my_char);
    printf("The float value of my_char is: %f\n", my_char);
    printf("The int value of my_char is: %i\n", my_char);
    printf("The oct value of my_char is: %o\n", my_char);
    printf("The hex value of my_char is: %x\n", my_char);
    printf("The address format value of my_char is: %p\n\n", my_char);

    printf("The address of my_char in hex is: %x\n", &my_char);
    printf("The address of my_char in pointer is: %p\n", &my_char);
    printf("The address of my_char in dec is: %d\n\n", my_char);

    // double perimeter, area;
    // double width = atoi(argv[1]);
    // double height = atoi(argv[2]);

    // printf("The width is: %lf and the height is: %lf\n", width, height);
    
    // perimeter = (width + height) * 2;
    // area = width * height;
    
    // printf("The perimeter is: %lf and the area is: %lf\n", perimeter, area);

    // char mychar[20];
    // fgets(mychar, 20, stdin);
    // // scanf("%s", mychar);
    // printf("The value of mychar is: %s\n", mychar);
    // for (int i = 0; i < strlen(mychar); i++) {
    //     printf("The value of mychar[%d] is: %c\n", i, mychar[i]);
    // }

    // double minutes;
    // printf("Enter the minutes: ");
    // scanf("%lf", &minutes);
    // printf("The minutes is: %.0lf\n", minutes);
    
    // int hours, days, years;
    
    // hours = (int) (minutes / 60);
    // days = (int) (hours / 24);
    // years = (int) (days / 365);
    // printf("The hours is: %d\n", hours);
    // printf("The days is: %d\n", days);
    // printf("The years is: %d\n\n", years);

    // int value_a;
    // char value_b;
    // char *value_c;
    // short value_d;
    // long value_e;
    // long long value_f;
    // double value_g;
    // long double value_h;

    // printf("The size of int is: %lu\n", sizeof(value_a));
    // printf("The size of char is: %lu\n", sizeof(value_b));
    // printf("The size of char[]: %lu\n", sizeof(value_c));
    // printf("The size of short is: %lu\n", sizeof(value_d));
    // printf("The size of long is: %lu\n", sizeof(value_e));
    // printf("The size of long long is: %lu\n", sizeof(value_f));
    // printf("The size of double is: %lu\n", sizeof(value_g));
    // printf("The size of long double is: %lu\n", sizeof(value_h));

    int hours_of_labor;
    printf("How many hours of labor: ");
    scanf("%d", &hours_of_labor);

    float pay_rate = 12.00;
    float overtime = 0;
    float overtime_pay = 0;
    float gross_pay = 0;

    if (hours_of_labor > 40) {
        overtime = (float) (hours_of_labor - 40);
        overtime_pay = overtime * (pay_rate * 1.5);

    }

    gross_pay = (float) (pay_rate * (hours_of_labor - overtime));
    float total_pay = (gross_pay + overtime_pay);
    
    printf("\tYou worked %d hours and the total pay is: $%.2f\n", hours_of_labor, total_pay);
    printf("\tNormal pay is $%.2f (%d hours) and the overtime pay is: $%.2f (%d hours)\n", gross_pay, (int) (hours_of_labor - overtime), overtime_pay, (int) overtime);

    float fifteen_percent_tax = 15;
    float twenty_percent_tax = 20;
    float twenty_five_percent_tax = 25;

    float net_pay = 0;

    if (total_pay > (float) 300) {
        net_pay += 300 - (300 * (fifteen_percent_tax / (float) 100));
        total_pay -= 300;        

        if (total_pay > (float) 150) {
            net_pay += 150 - (150 * (twenty_percent_tax / (float) 100));
            total_pay -= 150;

            if (total_pay > (float) 0) {
                net_pay += total_pay - (total_pay * (twenty_five_percent_tax / (float) 100));
                total_pay -= total_pay;
            }
        } else {
            net_pay += total_pay - (total_pay * (twenty_percent_tax / (float) 100));
        }
    } else {
        net_pay = total_pay - (total_pay * (fifteen_percent_tax / (float) 100));
    }
    
    printf("\tThe net pay is: $%.2f\n", net_pay);



    return 0;

} 