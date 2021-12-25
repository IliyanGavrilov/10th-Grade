#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_mult_helper(int current, int k, int n)
{
    if(current <= n)
    {
        return current * find_mult_helper(current+ k, k, n);
    }

    return 1;
}

int find_mult(int k, int n)
{
    return find_mult_helper(1, k, n);
}

int is_Prime_helper(int number, int current)
{
    if(current >= number)
    {
        return 1;
    }

    if(number % current == 0)
    {
        return 0;
    }

    return is_Prime_helper(number, current+1);
}

int is_Prime(int number)
{
    return is_Prime_helper(number, 1);
}

int is_perfect(int number, int current, int sum)
{
    if(current == number)
    {
        if(sum == number)
        {
            return 1;
        }

        return 0;
    }
    if(number % current == 0)
    {
        sum += current;
    }

    return is_perfect(number, current+1, sum);
}

int num1_in_num2(int num1, int num2)
{
    if(num1 == num2)
    {
        return 1;
    }

    if(num1 == 0)
    {
        return 0;
    }
    else if(num2 == 0)
    {
        return 1;
    }

    if(num2 % 10 == num1 % 10)
    {
        num2 /= 10;
    }

    return num1_in_num2(num1/10, num2);
}

void print_arr(int *arr, int start, int end)
{
    if(start > end)
    {
        printf("\n");
        return;
    }

    printf("%d ", arr[start]);
    print_arr(arr, start+1, end);
}

void find_start_and_len(int *arr, int count, int curr_len, int curr_start, int sub_arr_found, int arr_size, int *max_len, int *max_start)
{
    if(count < arr_size)
    {
        if(arr[count] == arr[count-1])
        {
            if(curr_len == 1)
            {
                sub_arr_found = 1;
                curr_start == count-1;
            }
            curr_len++;
        }
        if(count == arr[count] || count == arr[count-1])
        {
            if(sub_arr_found == 1)
            {
                if(curr_len > *max_len)
                {
                    *max_len = curr_len;
                    *max_start = curr_start;
                    curr_len = 1;
                }
                sub_arr_found = 0;
            }
        }
        find_start_and_len(arr, count+1, curr_len, curr_start, sub_arr_found, arr_size, max_len, max_start);
    }
}

void find_longest_subarr(int *arr, int arr_size)
{
    int max_len = 1;
    int max_start = 0;

    find_start_and_len(arr, 1, 1, 0, 0, arr_size, &max_len, &max_start);

    print_arr(arr, max_start, max_start + max_len - 1);
}

int main()
{
    printf("find_mult: %d\n", find_mult(3,15));

    printf("is_Prime: %d\n", is_Prime(16));
    printf("is_Prime: %d\n", is_Prime(17));

    printf("is_perfect: %d\n", is_perfect(12, 1, 0));

    printf("num1_in_num2: %d\n", num1_in_num2(112331, 123));
    printf("num1_in_num2: %d\n", num1_in_num2(11331, 121));

    int arr[] = {1, 2, 2, 2, 2, 3, 3, 3, 3, 3};
    //print_arr(arr, 1, 3);
    find_longest_subarr(arr, 10);

    return 0;
}
