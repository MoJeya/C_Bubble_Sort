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



void ft_putchar(char c)
{
    write(1,&c,1);
}

void ft_bubbleSort(int num[], int len)
{
    int cnt_1;
    int cnt_2;
    int swap;

    
    cnt_1 = 0;
    cnt_2 = 1;
    while(cnt_1 <= len)
    {
        
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

void ft_printArr(int num[], int len)
{
    int cnt;

    cnt = 0;

    while(cnt <= len)
    {
        printf("%d ,", num[cnt]);
        cnt++;
    }
}

int main()
{
    
    int num[] = {3,5,4,8,6};

    ft_printArr(num,4);
    //char number;

    //number = '0' + (arrayLen(num)- 1);

   // ft_putchar(number);

    ft_bubbleSort(num,4);

    printf("\n");
    ft_printArr(num,4);

    return 0; 
}