/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:23:21 by marvin            #+#    #+#             */
/*   Updated: 2021/05/05 14:23:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
#include <stdio.h>

int arrayLen(int num[])
{
    int cnt_1;

    cnt_1 = 0;

    while(num[cnt_1] != 0)
    {
        cnt_1++;
    }

    return cnt_1;
}

void ft_putchar(char c)
{
    write(1,&c,1);
}

void ft_bubbleSort(int num[])
{
    int cnt_1;
    int cnt_2;
    int arrLen;
    int swap;

    arrLen = arrayLen(num);
    cnt_1 = 0;
    cnt_2 = 1;
    while(cnt_1 <= arrLen)
    {
        if(num[cnt_2] == 0)
        {
            break;
        }
        if(num[cnt_1] > num[cnt_2])
        {
            swap = num[cnt_1];
            num[cnt_1] = num[cnt_2];
            num[cnt_2] = swap;
        }
        
        cnt_1++;
        cnt_2++;
    }
    
    
}

void ft_printArr(int num[])
{
    int cnt;
    int len;

    len = arrayLen(num);
    cnt = 0;

    while(cnt < len)
    {
        printf("%d ,", num[cnt]);
        cnt++;
    }
}

int main()
{
    int num[] = {3,5,4,8,6,0};

    ft_printArr(num);
    //char number;

    //number = '0' + (arrayLen(num)- 1);

   // ft_putchar(number);

    ft_bubbleSort(num);

    printf("\n");
    ft_printArr(num);

    return 0; 
}