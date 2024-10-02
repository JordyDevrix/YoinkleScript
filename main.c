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


    // int hours_of_labor;
    // printf("How many hours of labor: ");
    // scanf("%d", &hours_of_labor);

    // float pay_rate = 12.00;
    // float overtime = 0;
    // float overtime_pay = 0;
    // float gross_pay = 0;

    // if (hours_of_labor > 40) {
    //     overtime = (float) (hours_of_labor - 40);
    //     overtime_pay = overtime * (pay_rate * 1.5);

    // }

    // gross_pay = (float) (pay_rate * (hours_of_labor - overtime));
    // float total_pay = (gross_pay + overtime_pay);
    
    // printf("\tYou worked %d hours and the total pay is: $%.2f\n", hours_of_labor, total_pay);
    // printf("\tNormal pay is $%.2f (%d hours) and the overtime pay is: $%.2f (%d hours)\n", gross_pay, (int) (hours_of_labor - overtime), overtime_pay, (int) overtime);

    // float fifteen_percent_tax = 15;
    // float twenty_percent_tax = 20;
    // float twenty_five_percent_tax = 25;

    // float net_pay = 0;

    // if (total_pay > (float) 300) {
    //     net_pay += 300 - (300 * (fifteen_percent_tax / (float) 100));
    //     total_pay -= 300;        

    //     if (total_pay > (float) 150) {
    //         net_pay += 150 - (150 * (twenty_percent_tax / (float) 100));
    //         total_pay -= 150;

    //         if (total_pay > (float) 0) {
    //             net_pay += total_pay - (total_pay * (twenty_five_percent_tax / (float) 100));
    //             total_pay -= total_pay;
    //         }
    //     } else {
    //         net_pay += total_pay - (total_pay * (twenty_percent_tax / (float) 100));
    //     }
    // } else {
    //     net_pay = total_pay - (total_pay * (fifteen_percent_tax / (float) 100));
    // }
    
    // printf("\tThe net pay is: $%.2f\n", net_pay);


    // srand(time(NULL));
    // rand();
    // int r = rand() % 20 + 1;

    // int guesses_used = 0;
    // printf("You have 5 guesses\n");
    // while (guesses_used != 5) {
    //     int guessing_number;
    //     printf("Enter your guess: ");
    //     scanf("%d", &guessing_number);

    //     if (guessing_number == r) {
    //         printf("You guessed the number correctly\n");
    //         break;
    //     } else if (guessing_number > r) {
    //         guesses_used += 1;
    //         printf("You guessed too high\n\nYou have %d guesses left\n", (5 - guesses_used));
    //         continue;
    //     } else if (guessing_number < r) {
    //         guesses_used += 1;
    //         printf("You guessed too low\n\nYou have %d guesses left\n", (5 - guesses_used));
    //         continue;
    //     }

    // }


    // int diddy_party = 1337;
    // int *location_of_diddy_party = &diddy_party;
    // printf("The value of diddy_party is: %d\n", diddy_party);
    // printf("The location of the diddy_party is: %p\n\n", location_of_diddy_party);
    
    // int favo_variable = 1337;
    // int *p_favo_variable = &favo_variable;
    // // *p_favo_variable = 3333;
    // favo_variable = 3336;

    // int *array_of_pointers[2] = { p_favo_variable, location_of_diddy_party };
    // for (int i = 0; i < 2; i++) {
    //     printf("The value of array_of_pointers[%d] is: %p\nAnd the value %d\n", i, array_of_pointers[i], *array_of_pointers[i]);
    // }

    // // value of what the pointer is pointing to
    // printf("The value of favo_variable is: %d\n", favo_variable);
    
    // // Value of the pointer
    // printf("The location of favo_variable is: %p\n", p_favo_variable);
    
    // // Address of the pointer
    // printf("The value of favo_variable is: %p\n\n", &p_favo_variable);

    // enum bools { true=1, false=0 };
    // enum bools ast = true;
    // enum bools debug = false;
    // enum bools test = true;
    // enum bools version = false;

    // int array_of_wheels[] = { ast, debug, test, version };
    // // the length of the array
    // int array_size = (int) (sizeof(array_of_wheels) / sizeof(array_of_wheels[0]));
    // for (int i = 0; i < array_size; i++) {
    //     printf("The value of array_of_wheels[%d] is: %d\n", i, array_of_wheels[i]);
    // }

    // int a[5] = {1, 2, 3, 4, 5};
    // int *p = a;
    // printf("%d\t%d\t%d\t%d\t", *p, a[0], a, p);


    // // Creating a pointer of type string and assinging NULL to it
    // char *str = NULL;

    // // Allocating memory for 15 characters and assigning the address to str
    // str = (char *) malloc(1 * sizeof(char));

    // // Copying a string into the allocated memory and overwriting the address with another strcpy
    // char my_str[] = "0987654321";

    // // should be 11 because the string lenght is 10 and the null character will be added at the end
    // int str_len = sizeof(my_str) / sizeof(my_str[0]);
    // printf("Size of my_str: %d\n", str_len);
    // str = (char *) malloc(str_len * sizeof(char));

    // strcpy(str, my_str);

    // // Printing the string and its address
    // printf("String = %s, Address = %p\n", str, str);

    // // Freeing the memory that was allocated for the string and assigning NULL to the pointer
    // free(str);
    // str = NULL;

    // // Checking if the memory was freed
    // printf("String = %s, Address = %p\n", str, str);

    // char *new_str = (char *) malloc(20 * sizeof(char));
    // scanf("%s", new_str);
    // printf("The value of str is: %s\n", new_str);

    // for (int i = 0; i < strlen(new_str); i++) {
    //     printf("The value of new_str[%d] is: %c\n", i, new_str[i]);
    // }

    // char new_string_two[] = "helloworld";
    // for (int i = 0; i < sizeof(new_string_two); i++) {
    //     printf("The value of new_string_two[%d] is: %c\n", i, new_string_two[i]);
    // }

    // printf("POINTER\tThe sizeof new_str is: %lu and strlen of new_str is: %d\n", sizeof(new_str), strlen(new_str));
    // printf("STATIC\tThe sizeof new_string_two is: %lu and strlen of new_string_two is: %d\n\n", sizeof(new_string_two), strlen(new_string_two));
    // /* 
    // if both strings are the same, then strlen will be the same too, but sizeof will be different
    // thats because in the first case we are printing the sizeof the pointer which for the 64 bit compiler will return 8
    // and in the second case we are printing the sizeof the array which will return the length of the array plus the null character
    // */

    // free(new_str);


    // struct interior {
    //     int seats;
    //     int doors;
    //     int wheels;
    // };

    // struct statistics {
    //     int max_speed;
    //     int weight;
    //     int *gear_ratios;
    //     int gear_ratio_count;
    // };

    // struct car {
    //     struct interior car_interior;
    //     struct statistics car_statistics;
    // };
    
    // typedef struct car car_t;

    // // first car

    // car_t my_first_car;
    // my_first_car.car_interior.seats = 5;
    // my_first_car.car_interior.doors = 5;
    // my_first_car.car_interior.wheels = 4;
    // my_first_car.car_statistics.max_speed = 200;
    // my_first_car.car_statistics.weight = 2000;

    // int gear_ratios_first_car[] = {1, 2, 3, 4};
    // int size_of_gear_ratios1 = sizeof(gear_ratios_first_car) / sizeof(gear_ratios_first_car[0]);
    // my_first_car.car_statistics.gear_ratio_count = size_of_gear_ratios1;

    // my_first_car.car_statistics.gear_ratios = (int *) malloc(size_of_gear_ratios1 * sizeof(int));
    // my_first_car.car_statistics.gear_ratios = gear_ratios_first_car;

    // // second car

    // car_t my_second_car;
    // my_second_car.car_interior.seats = 2;
    // my_second_car.car_interior.doors = 3;
    // my_second_car.car_interior.wheels = 4;
    // my_first_car.car_statistics.max_speed = 200;
    // my_first_car.car_statistics.weight = 2000;

    // int gear_ratios_second_car[] = {2, 4, 6, 8, 10, 12};
    // int size_of_gear_ratios = sizeof(gear_ratios_second_car) / sizeof(gear_ratios_second_car[0]);
    // my_second_car.car_statistics.gear_ratio_count = size_of_gear_ratios;

    // my_second_car.car_statistics.gear_ratios = (int *) malloc(size_of_gear_ratios * sizeof(int));
    // my_second_car.car_statistics.gear_ratios = gear_ratios_second_car;

    // // make a list of cars

    // car_t car_list[] = { my_first_car, my_second_car };

    // for (int i = 0; i < 2; i++) {
    //     printf("The value of car_list[%d] is: %d\n", i, car_list[i].car_interior.seats);
        
    //     for (int j = 0; j < car_list[i].car_statistics.gear_ratio_count; j++) {
    //         printf("The value of car_list[%d].car_statistics.gear_ratios[%d] is: %d\n", i, j, car_list[i].car_statistics.gear_ratios[j]);
    //     }
    // }

    FILE *p_file;
    int c;
    char *filecontent = NULL;

    p_file = fopen("main.ys", "r");

    if(p_file == NULL) {
        perror("Error in opening file");
        return(-1);
    }

    int i = 0;
    filecontent = (char *) malloc(0 * sizeof(char));
    while((c = fgetc(p_file)) != EOF) {
        if (c == '\n') {
            continue;
        }
        if (c == ' ') {
            continue;
        }

        filecontent = realloc(filecontent, (i+1) * sizeof(char));
        if (filecontent == NULL) {
            perror("Error in allocating memory");
            return(-1);
        }
        filecontent[i] = c;
        i++;
    }
    fclose(p_file);

    filecontent[i] = '\0';

    printf("The content of the file is: %s\n", filecontent);
    


    return 0;

} 