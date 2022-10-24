#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#include <math.h>
int bintodec(long long n) {
    int dec = 0, i = 0, rem;

    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}
int binadd(int b1, int b2) {

    int i = 0, remainder = 0, sum[20];
    int binarySum = 0;

    while (b1 != 0 || b2 != 0) {
        sum[i] = (b1 % 10 + b2 % 10 + remainder) % 2;
        remainder = (b1 % 10 + b2 % 10 + remainder) / 2;
        b1 = b1 / 10;
        b2 = b2 / 10;
        ++i;
    }
    if (remainder != 0)
        sum[i] = remainder;
    while (i >= 0)
    {
        binarySum = binarySum * 10 + sum[i];
        --i;
    }
    return binarySum;
}
void dectobin() {
    unsigned int a, b, d, c[36] = { 0 };
    int i = 0;
    printf("Enter the decimal number:");
    scanf_s("%u", &a);
    d = a;
    while (a != 0)
    {
        b = a % 2;
        a = a / 2;
        c[i] = b;
        i++;
    }
    printf("\nBinary= ");
    for (i = i - 1; i >= 0; i--)
        printf("%d", c[i]);
    printf("\n");
}
void addbin() {
    int sum[20], rem=0, i=0;
    long long int b1, b2;
    printf("Enter first binary number:");
    scanf_s("%ld", &b1);
    printf("\n");
    printf("Enter second binary number:");
    scanf_s("%ld", &b2);
    printf("\n");
    while (b1 != 0 || b2 != 0)
    {
        sum[i++] = (b1 % 10 + b2 % 10 + rem) % 2;
        rem = (b1 % 10 + b2 % 10 + rem) / 2;
        b1 = b1 / 10;
        b2 = b2 / 10;
    }
    if (rem != 0)
        sum[i++] = rem;
    i--;
    printf("Sum of the binary numbers is: ");
    while (i >= 0)
        printf("%d", sum[i--]);

}
void subbin() {
    long long int b1, b2, c1, c2;
    int i=0, diff, b,c[36] = { 0 }, d;
    printf("Enter first binary number:");
    scanf_s("%ld", &b1);
    printf("\n");
    printf("Enter second binary number:");
    scanf_s("%ld", &b2);
    printf("\n");
    c1 = bintodec(b1);
    c2 = bintodec(b2);
    diff = c1 - c2;
    d = diff;
    while (diff != 0)
    {
        b = diff % 2;
        diff = diff / 2;
        c[i] = b;
        i++;
    }
    printf("Diff of the binary numbers is:");
    for (i = i - 1; i >= 0; i--)
        printf("%d", c[i]);
    printf("\n");
}
void prodbin() {
    
    int i = 0;
    int rem = 0, digit, factor=1;
    long long int product = 0, multiply = 0;
    long long int b1, b2;
    printf("Enter first binary number:");
    scanf_s("%lld", &b1);
    printf("\n");
    printf("Enter second binary number:");
    scanf_s("%lld", &b2);
    printf("\n");
    while (b2 != 0) {
        digit = b2 % 10;

        if (digit == 1) {
            b1 = b1 * factor;
            multiply = binadd(b1, multiply);
        }
        else
        {
            b1 = b1 * factor;
        }
        b2 = b2 / 10;
        factor = 10;
    }
    printf("Product of two binary numbers: %lld", multiply);
}
void divibin() {
    long long int b1, b2, c1, c2;
    int i = 0, b, diff, c[36] = { 0 }, d;
    printf("Enter first binary number:");
    scanf_s("%lld", &b1);
    printf("\n");
    printf("Enter second binary number:");
    scanf_s("%lld", &b2);
    printf("\n");
    c1 = bintodec(b1);
    c2 = bintodec(b2);
    diff = c1 / c2;
    d = diff;
    while (diff != 0)
    {
        b = diff % 2;
        diff = diff / 2;
        c[i] = b;
        i++;
    }
    printf("Diff of the binary numbers is:");
    for (i = i - 1; i >= 0; i--)
        printf("%d", c[i]);
    printf("\n");
}
void binary(){
    int ch = 0;
    printf("1-Conversion 2-Addition 3-Subtraction 4-Multiplication 5-Division\n\n");
    printf("Choose:");
    scanf_s("%d", &ch);
    printf("\n");
    switch (ch)
    {
    case 1:
        dectobin();
        break;
    case 2:
        addbin();
        break;
    case 3:
        subbin();
        break;
    case 4:
        prodbin();
        break;
    case 5:
        divibin();
        break;
    }while (ch>5);
}
int octadec(long long octal) {
    long int decimal = 0;
    int i = 0;
    while (octal != 0)
    {
        decimal = decimal + (octal % 10) * pow(8, i++);
        octal = octal / 10;
    }
    return decimal;
}
void decocta() {
    unsigned int a, b, d, c[36] = { 0 };
    int i;
    i = 0;
    printf("Enter the decimal number:");
    scanf_s("%u", &a);
    d = a;
    while (a != 0)
    {
        b = a % 8;
        a = a / 8;
        c[i] = b;
        i++;
    }
    printf("\nOctal= ");
    for (i = i - 1; i >= 0; i--)
        printf("%d", c[i]);
    printf("\n");
}
void addocta() {
    long long int b1, b2, d;
    int sum = 0, b, c[36] = { 0 }, i = 0;
    printf("Enter first octal number:");
    scanf_s("%lld", &b1);
    printf("\n");
    printf("Enter second octal number:");
    scanf_s("%lld", &b2);
    printf("\n");
    sum = octadec(b1) + octadec(b2);
    d = sum;
    while (sum != 0)
    {
        b = sum % 8;
        sum = sum / 8;
        c[i] = b;
        i++;
    }
    printf("\nOctal= ");
    for (i = i - 1; i >= 0; i--)
        printf("%d", c[i]);
    printf("\n");
}
void subocta() {
    long long int b1, b2, d;
    int sum = 0, b, c[36] = { 0 }, i = 0;
    printf("Enter first octal number:");
    scanf_s("%lld", &b1);
    printf("\n");
    printf("Enter second octal number:");
    scanf_s("%lld", &b2);
    printf("\n");
    sum = octadec(b1) - octadec(b2);
    d = sum;
    while (sum != 0)
    {
        b = sum % 8;
        sum = sum / 8;
        c[i] = b;
        i++;
    }
    printf("\nOctal= ");
    for (i = i - 1; i >= 0; i--)
        printf("%d", c[i]);
    printf("\n");
}
void prodocta() {
    long long int b1, b2, d;
    int sum = 0, b, c[36] = { 0 }, i = 0;
    printf("Enter first octal number:");
    scanf_s("%lld", &b1);
    printf("\n");
    printf("Enter second octal number:");
    scanf_s("%lld", &b2);
    printf("\n");
    sum = octadec(b1) * octadec(b2);
    d = sum;
    while (sum != 0)
    {
        b = sum % 8;
        sum = sum / 8;
        c[i] = b;
        i++;
    }
    printf("\nOctal= ");
    for (i = i - 1; i >= 0; i--)
        printf("%d", c[i]);
    printf("\n");
}
void diviocta() {
    long long int b1, b2, d;
    int sum = 0, b, c[36] = { 0 }, i = 0;
    printf("Enter first octal number:");
    scanf_s("%lld", &b1);
    printf("\n");
    printf("Enter second octal number:");
    scanf_s("%lld", &b2);
    printf("\n");
    sum = octadec(b1) / octadec(b2);
    d = sum;
    while (sum != 0)
    {
        b = sum % 8;
        sum = sum / 8;
        c[i] = b;
        i++;
    }
    printf("\nOctal= ");
    for (i = i - 1; i >= 0; i--)
        printf("%d", c[i]);
    printf("\n");
}
void octal(){
    int ch = 0;
    printf("1-Conversion 2-Addition 3-Subtraction 4-Multiplication 5-Division\n\n");
    printf("Choose:");
    scanf_s("%d", &ch);
    printf("\n");
    switch (ch)
    {
    case 1:
        decocta();
        break;
    case 2:
        addocta();
        break;
    case 3:
        subocta();
        break;
    case 4:
        prodocta();
        break;
    case 5:
        diviocta();
        break;
    }while (ch > 5);
}
int hextodec(char hex[17]) {
    long long decimal, place;
    int i = 0, val, len;
    decimal = 0;
    place = 1;
    len = strlen(hex);
    len--;
    for (i = 0; hex[i] != '\0'; i++)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            val = hex[i] - 48;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            val = hex[i] - 97 + 10;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            val = hex[i] - 65 + 10;
        }
        decimal += val * pow(16, len);
        len--;
    }
    return decimal;
}
void dechex() {
    unsigned int  a, b, d;
    int i, j = 0;
    char c[100];
    printf("Enter decimal number:");
    scanf_s("%ld", &a);
    d = a;
    while (a != 0)
    {
        b = a % 16;
        if (b < 10)
            c[j] = 48 + b;
        else
            c[j] = 55 + b;
        a = a / 16;
        j++;
    }
    printf("\nHex= ");
    for (i = j - 1; i >= 0; i--)
        printf("%c", c[i]);
    printf("\n");
}
void addhex() {
    long long int d;
    char b1[17], b2[17];
    int sum = 0, b, c[36] = { 0 }, i = 0, j = 0;
    printf("Enter first hex number:");
    scanf_s("%c", &b1);
    printf("Enter second hex number:");
    scanf_s("%c", &b2);
    sum = hextodec(b1) + hextodec(b2);
    d = sum;
    while (sum != 0)
    {
        b = sum % 16;
        if (b < 10)
            c[j] = 48 + b;
        else
            c[j] = 55 + b;
        sum = sum / 16;
        j++;
    }
    printf("\nHex= ");
    for (i = j - 1; i >= 0; i--)
        printf("%c", c[i]);
    printf("\n");
}
void subhex() {
    long long int d;
    char b1[17], b2[17];
    int sum = 0, b, c[36] = { 0 }, i = 0, j = 0;
    printf("Enter first hex number:");
    fgets(b1,17,stdin);
    printf("Enter second hex number:");
    fgets(b2,17,stdin);
    sum = hextodec(b1) - hextodec(b2);
    d = sum;
    while (sum != 0)
    {
        b = sum % 16;
        if (b < 10)
            c[j] = 48 + b;
        else
            c[j] = 55 + b;
        sum = sum / 16;
        j++;
    }
    printf("\nHex= ");
    for (i = j - 1; i >= 0; i--)
        printf("%c", c[i]);
    printf("\n");
}
void prodhex() {
    long long int d;
    char b1[17], b2[17];
    int sum = 0, b, c[36] = { 0 }, i = 0, j = 0;
    printf("Enter first hex number:");
    scanf_s("%c", &b1);
    printf("Enter second hex number:");
    scanf_s("%c", &b2);
    sum = hextodec(b1) * hextodec(b2);
    d = sum;
    while (sum != 0)
    {
        b = sum % 16;
        if (b < 10)
            c[j] = 48 + b;
        else
            c[j] = 55 + b;
        sum = sum / 16;
        j++;
    }
    printf("\nHex= ");
    for (i = j - 1; i >= 0; i--)
        printf("%c", c[i]);
    printf("\n");
}
void divihex() {
    long long int d;
    char b1[17], b2[17];
    int  b, c[36] = { 0 }, i = 0, j = 0;
    int sum = 1;
    printf("Enter first hex number:");
    scanf_s("%c", &b1);
    printf("Enter second hex number:");
    scanf_s("%c", &b2);
    sum = hextodec(b1) / hextodec(b2);
    d = sum;
    while (sum != 0)
    {
        b = sum % 16;
        if (b < 10)
            c[j] = 48 + b;
        else
            c[j] = 55 + b;
        sum = sum / 16;
        j++;
    }
    printf("\nHex= ");
    for (i = j - 1; i >= 0; i--)
        printf("%c", c[i]);
    printf("\n");

}
void hex() {
    int ch = 0;
    printf("1-Conversion 2-Addition 3-Subtraction 4-Multiplication 5-Division\n\n");
    printf("Choose:");
    scanf_s("%d", &ch);
    printf("\n");
    switch (ch)
    {
    case 1:
        dechex();
        break;
    case 2:
        addhex();
        break;
    case 3:
        subhex();
        break;
    case 4:
        prodhex();
        break;
    case 5:
        divihex();
        break;
    }while (ch > 5);
}
void menu() {
    printf("Welcome Dragos!\n\n");
    Sleep(3000);
    time_t t = time(NULL);
    printf("Current date and time is : %s\n", ctime(&t));
    Sleep(1000);
    unsigned int a{}, c[36] = { 0 };
    int i, o;
    i = 0;
    printf("Decimal converter by Dragos\n\n");
    printf("V0.89 Alpha Testing\n\n");
    printf("Loading...\n\n");
    Sleep(3000);
    printf("1-Binary 2-Octal 3-Hex\n\n");
    printf("Choose: ");
    scanf_s("%d", &o);
    printf("\n");
    switch (o)
    {
    case 1:
        // printf("Loading...\n\n");
        Sleep(1000);
        binary();
        break;
    case 2:
        printf("Loading...\n\n");
        Sleep(1000);
        octal();
        break;
    case 3:
        printf("Loading...\n\n");
        Sleep(1000);
        hex();
        break;
    default:printf("Wrong choice.");
        break;
    }while (o > 3);
}
int main()
{
    int comp, compp, index = 0, op = 0;
    char user2[15], pass1[15] = "test", pass2[15], user1[15] = "test", c;
    printf("Enter username:");
    fgets(user2, 10, stdin);
    op = strlen(user2);
    user2[op] = '\0';
    user2[--op] = '\0';
    printf("Enter Password:");
    /* 13 is ASCII value of Enter key */
    while ((c = _getch()) != 13) {
        if (index < 0)
            index = 0;
        /* 8 is ASCII value of BACKSPACE character */
        if (c == 8) {
            _putch('\b');
            _putch(NULL);
            _putch('\b');
            index--;
            continue;
        }
        pass2[index++] = c;
        _putch('*');
    }
    pass2[index] = '\0';
    comp = strcmp(user2, user1);
    compp = strcmp(pass2, pass1);
    printf("\n\n");
    if (comp == 0 && compp == 0)
    {
        menu();
    }
    else
        printf("Incorrect username or password!\n\n");
    return 0;
}
