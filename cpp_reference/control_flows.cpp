#include <iostream>

/**********************************************************************
*                              loops                                  *
***********************************************************************/
int practice_loops(int argc, char** argv)
{
    // for loop to iterate array of args with checking there is still there.
    puts("loop test");
    for (int i = 0; argv[i]; i++) {
        printf("%d: %s\n", i, argv[i]);
    }

    // for loop to iterate an array using a fixed range iterator
    int array[] = { 1, 2, 3, 4, 5 };
    for (int i = 0; i < 5; ++i) {
        printf("element %d is %d\n", i, array[i]);
    }

    // for loop to iterate an array using foreach style. available in c++11 and above
    int array2[] = { 1, 2, 3, 4, 5 }; // You can actually set the size of the array by initializing it with a set of values 
    for (int i : array2) {
        printf("i is %d\n", i);
    }
    puts("");
    return 0;

    // for loop using a pointer // get the address of each element in the array. can increment the pointer by 1 each time to get to the next element address
    int numbers[10];
    int* pInt = numbers;
    for (int i = 0; i < 10; i++) {
        std::cout << "number address" << i << " : " << pInt + i << std::endl;
    }

    // while loopvto iterate an array
    int array4[] = { 1, 2, 3, 4, 5 };
    int i = 0;
    while (i < 5) {
        printf("element %d is %d\n", i, array4[i]);
        ++i;
    }

    return 0;
}


// example of using loops to count the number of characters in a c-style string 
const char string[] = "This is a null-terminated string.";

int practice_loop_to_itarate_char_arr()
{
    // Method 1 to count the number of chars in the c-style string using a for loop with checking the avilability of item in an array.
    int count = 0;
    for (count = 0; string[count]; ++count); //  for loop to count the number of characters. the loop exit condition is simply string[count] which just check that there is still a character at this position.
    printf("The number of characters is: %d\n", count);

    // Method 2 Using while loop. and again the condition to keep on looping is to have a char at position count.. the conditon is string[count]
    count = 0;
    while (string[count]) {
        ++count;
    }
    printf("The number of characters is: %d\n", count);

    // Method 3 Using the range for loop..c-style string is terminated by a '/0' char. so it loops while the char x of string is not '/0'
    count = 0;
    for (int x : string) {
        if (x == 0) break; // have to add this to break the loop
        ++count;
    }
    printf("The number of characters is: %d\n", count);


    return 0;
}

/**********************************************************************
*                              switch                                 *
***********************************************************************/
int main_cs() {
    const int iONE = 1;
    const int iTWO = 2;
    const int iTHREE = 3;
    const int iFOUR = 4;

    int x = 3;

    switch (x) {
    case iONE:
        puts("one");
        break;
    case iTWO:
        puts("two");
        break;
    case iTHREE:
        puts("three");
        break;
    case iFOUR:
        puts("four");
        break;
    default:
        puts("default");
        break;
    }

    return 0;
}
