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
    printf("The address of my_char in dec is: %d\n", my_char);

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

    double minutes;
    printf("Enter the minutes: ");
    scanf("%lf", &minutes);
    printf("The minutes is: %.0lf\n", minutes);
    
    int hours, days, years;
    
    hours = (int) (minutes / 60);
    days = (int) (hours / 24);
    years = (int) (days / 365);
    printf("The hours is: %d\n", hours);
    printf("The days is: %d\n", days);
    printf("The years is: %d\n", years);

    return 0;

} 