#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//1. PRIME RANGE ANALYZER
void prime_range_analyzer(){
    int L, R;
    printf("Enter the L: "); scanf("%d",&L);
    printf("Enter the R: "); scanf("%d",&R);
    for(int i=L; i<=R; i++){
        bool isPrime=true;
        if(i<=1) isPrime=false;
        else {
            for(int j=2; j<i; j++){
                if(i%2==0) isPrime=false;
            }
        }
        if(isPrime) printf("%d ", i);
    }
    printf("\n");
}

// 2. ARMSTRONG
void armstrong_detector(){
    int num, temp, digits = 0, sum = 0;

    printf("Enter number: "); scanf("%d", &num);

    temp = num;

    if(num == 0) digits = 1;

    while(temp != 0){ 
        digits++; 
        temp /= 10;
    }

    temp = num;

    while(temp != 0){
        int lastDigit = temp % 10;
        int power = 1;

        for(int i = 1; i <= digits; i++){
            power *= lastDigit;
        }

        sum += power;
        temp /= 10;
    }

    if(sum == num) printf("%d is an Armstrong Number\n", num);
    else printf("%d is NOT an Armstrong\n", num);
}

// 3. FIBONACCI
void fibonacci_constraints(){
    int n, limit;

    printf("Enter number of terms: "); scanf("%d", &n);
    printf("Enter number of limit: "); scanf("%d",&limit);

    int a = 0, b = 1;

    for(int i = 0; i < n; i++){
        if(a > limit) break;
        
        printf("%d ", a);

        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

// 4. PALINDROME
void palindrome_checker(){
    char str[100];

    printf("Enter string: "); scanf(" %[^\n]", str);

    int len = strlen(str);
    bool isPal = true;

    for(int i = 0; i < len / 2; i++){
        if(str[i] != str[len - i - 1]){
            isPal = false;
            break;
        }
    }

    if(isPal) printf("Palindrome\n");
    else printf("Not Palindrome\n");
}

//5. RECURSION: REMAINDER /7
int remainder7(int n){
    if(n < 7) return n;
    return remainder7(n - 7);
}

//6. RECURSION: QUOTIENT /11
int quotient11(int n){
    if(n < 11) return 0;
    return 1 + quotient11(n - 11);
}

//7. RECURSION: PRODUCT (5 ADDITIONS)
int product5(int n, int count){
    if(count == 5) return 0;
    return n + product5(n, count + 1);  
}

//8. NUMBER PATTERN
void number_pattern(){
    int n;

    printf("Enter N: "); scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++) printf("%d ", j);
        printf("\n");
    }
}

//9. SORT (BUBBLE SORT)
void sort_numbers(){
    int n, arr[100];

    printf("Enter size: "); scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//10. SECOND LARGEST
void second_largest(){
    int n, arr[100];

    printf("Enter size: "); scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int largest = arr[0];
    int second = arr[0];

    for(int i = 1; i < n; i++){
        if(arr[i] > largest){
            second = largest;
            largest = arr[i];
        }
        else if(arr[i] > second && arr[i] != largest){
            second = arr[i];
        }
    }

    if(largest == second){
        printf("No second largest\n");
    } else {
        printf("Second Largest: %d\n", second);
    }
}

//11. ANAGRAM
void anagram_checker(){
    char s1[100], s2[100];

    printf("Enter first string: "); scanf("%s", s1);
    printf("Enter second string: "); scanf("%s", s2);

    if(strlen(s1) != strlen(s2)){
        printf("Not Anagram\n");
        return;
    }

    int count[256] = {0};
    int len = strlen(s1);

    for(int i = 0; i < len; i++){
        count[s1[i]]++;
        count[s2[i]]--;
    }

    for(int i = 0; i < 256; i++){
        if(count[i] != 0){
            printf("Not Anagram\n");
            return;
        }
    }

    printf("Anagram\n");
}

/////////////////////////////////////////////////////////////
//MENU
int main(){
    int userChoice;
    int n;

    printf("11 Practice Problems in C!\n");

    do{
        printf("\n");
        printf("1. Prime Range Analyzer\n");
        printf("2. Armstrong Detector\n");
        printf("3. Fibonacci Constraints\n");
        printf("4. Palindrome Checker\n");
        printf("5. Remainder (Recursion /7)\n");
        printf("6. Quotient (Recursion /11)\n");
        printf("7. Product (5 Additions)\n");
        printf("8. Number Pattern\n");
        printf("9. Sort Numbers\n");
        printf("10. Second Largest\n");
        printf("11. Anagram Checker\n");
        printf("12. Exit\n\n");

        printf("Select option: "); scanf("%d", &userChoice);

        switch(userChoice){
            case 1: prime_range_analyzer(); break;
            case 2: armstrong_detector(); break;
            case 3: fibonacci_constraints(); break;
            case 4: palindrome_checker(); break;

            case 5:
                printf("Enter number: "); scanf("%d", &n);
                printf("Remainder: %d\n", remainder7(n));
                break;

            case 6:
                printf("Enter number: ");scanf("%d", &n);
                printf("Quotient: %d\n", quotient11(n));
                break;

            case 7:
                printf("Enter number: "); scanf("%d", &n);
                printf("Product: %d\n", product5(n, 0));
                break;

            case 8: number_pattern(); break;
            case 9: sort_numbers(); break;
            case 10: second_largest(); break;
            case 11: anagram_checker(); break;

            case 12:
                printf("Program closed.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while(userChoice != 12);
    return 0;
}
