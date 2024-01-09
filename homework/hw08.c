//introduction
//16進位計算機，只有加減功能，輸出有格式化要注意

#include <stdio.h>
#include <string.h>

long int parseHexadecimal(char *expression, int *position) {
    long int num = 0;

    while ((expression[*position] >= '0' && expression[*position] <= '9') ||
           (expression[*position] >= 'A' && expression[*position] <= 'F')) {
        if (expression[*position] >= '0' && expression[*position] <= '9') {
            num = num * 16 + (expression[*position] - '0');
        } else {
            num = num * 16 + (expression[*position] - 'A' + 10);
        }
        (*position)++;
    }

    return num;
}

long int calculate(char *expression, int *position) {
    long int currentsum = 0;
    int sign = 1;

    while (expression[*position] != '\0' && expression[*position] != ')') {
        if (expression[*position] == '+' || expression[*position] == '-') {
            if (expression[*position] == '+') {
                sign = 1;
            } 
            else {
                sign = -1;
            }
            (*position)++;
        } else if (expression[*position] == '(') {
            (*position)++;
            currentsum += sign * calculate(expression, position);
        } else if ((expression[*position] >= '0' && expression[*position] <= '9') ||
                   (expression[*position] >= 'A' && expression[*position] <= 'F')) {
            currentsum += sign * parseHexadecimal(expression, position);
        } else {
            // Ignore other characters
            (*position)++;
        }
    }

    (*position)++;  // Skip ')'
    return currentsum;
}

int main() {
    char input[1000001];
    scanf("%s", input);

    int position = 0;
    long int resultsum = calculate(input, &position);

    if (resultsum < 0) {
        printf("-0x%lX\n", -resultsum);
    } else {
        printf("0x%lX\n", resultsum);
    }

    return 0;
}
