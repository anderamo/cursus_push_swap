/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:13:22 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/02 12:17:44 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf/includes/ft_printf.h"

int	a_items(int *a)
{
	int	i;

	i = 0;
	while (*a++)
	{
		i++;
	}
	return (i);
}

void	sa(int *num)
{
	int	number;

	number = 0;
	number = num[0];
	num[0] = num[1];
	num[1] = number;
	ft_printf("sa\n");
}

void	sb(int *num)
{
	int	number;

	number = 0;
	number = num[0];
	num[0] = num[1];
	num[1] = number;
}

void	rra(int *a, int i)
{
	int	number0;

	i--;
	number0 = a[i];
	while (i)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[i] = number0;
	ft_printf("rra\n");
}

void	rra_pa(int *a, int i)
{
	int	number0;

	i--;
	number0 = a[i];
	while (i)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[i] = number0;
}

void	rrb(int *b, int i)
{
	int	number0;

	i--;
	number0 = b[i];
	while (i)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[i] = number0;
}

void	ra(int *num, int i)
{
	int	number0;
	int	count;

	count = 0;
	number0 = num[count];
	count++;
	while (i > count)
	{
		num[count - 1] = num[count];
		count++;
	}
	num[count - 1] = number0;
	ft_printf("ra\n");
}

void	ra_pb(int *num, int i)
{
	int	number0;
	int	count;

	count = 0;
	number0 = num[count];
	count++;
	while (i > count)
	{
		num[count - 1] = num[count];
		count++;
	}
	num[count - 1] = number0;
}

void	rb(int *num, int i)
{
	int	number0;
	int	count;

	count = 0;
	number0 = num[count];
	count++;
	while (i > count)
	{
		num[count - 1] = num[count];
		count++;
	}
	num[count - 1] = number0;
}

void	rb_pa(int *num, int i)
{
	int	number0;
	int	count;

	count = 0;
	number0 = num[count];
	count++;
	while (i > count)
	{
		num[count - 1] = num[count];
		count++;
	}
	num[count - 1] = number0;
}

void	sort_3(int *a, int i)
{
	if (a[0] > a[1] && a[0] < a[2] && a[1] < a[2])
		sa(a);
	if (a[0] > a[1] && a[0] > a[2] && a[1] > a[2])
	{
		sa(a);
		rra(a, i);
	}
	if (a[0] > a[1] && a[0] > a[2] && a[1] < a[2])
		ra(a, i);
	if (a[0] < a[1] && a[0] < a[2] && a[1] > a[2])
	{
		sa(a);
		ra(a, i);
	}
	if (a[0] < a[1] && a[0] > a[2] && a[1] > a[2])
		rra(a, i);
}

void	sort_2(int *a)
{
	if (a[0] > a[1])
		sa(a);
}

int	get_lower(int *a, int i)
{
	int	j;
	int	lower;

	j = 1;
	lower = 0;
	while (i > j)
	{
		if (a[lower] > a[j])
			lower = j;
		j++;
	}
	return (lower);
}

void	to_the_top(int *a, int j, int i)
{
	int	count;

	count = 0;
	if (j == 0)
	{
		return ;
	}
	if (i - j < j)
	{
		while (count++ < i - j)
			rra(a, i);
	}
	else
	{
		while (count++ < j)
			ra(a, i);
	}
}

void	pa(int *a, int *b, int count, int i)
{
	a[i - 1] = b[count];
	rra_pa(a, i);
	if (count > 0)
		rrb(b, count);
	ft_printf("pa\n");
}

void	pb(int *a, int *b, int count, int i)
{
	b[count] = a[0];
	ra_pb(a, i);
	if (count > 0)
		rrb(b, count);
	ft_printf("pb\n");
}

void	sort(int *a, int *b, int i)
{
	int	j;
	int	count;
	int	k;

	k = i;
	count = 0;
	while (k > count && k - count != 3)
	{
		j = get_lower(a, i);
		to_the_top(a, j, i);
		pb(a, b, count, i);
		count++;
		i--;
	}
	sort_3(a, 3);
	rrb(b, count);
	i = k;
	count = 0;
	while (k > count && k - count != 3)
	{
		pa(a, b, count, i);
		count++;
	}
}

int	is_sorted(int *a)
{
	int	i;

	i = 1;
	while (a[i])
	{
		if (a[i - 1] > a[i])
			return (0);
		i++;
	}
	return (1);
}

int	get_biarray_len(char **argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		i++;
		argv++;
	}
	return (i);
}

void	push_swap(char **argv)
{
	int	i;
	int	*a;
	int	*b;
	int	items;

	i = 0;
	items = get_biarray_len(argv);
	a = malloc(items * sizeof(int));
	b = malloc((items - 3) * sizeof(int));
	while (items > i)
	{
		a[i] = ft_atoi_perf(argv[i]);
		i++;
	}
	if (is_sorted(a))
		return ;
	if (i == 2)
		sort_2(a);
	else if (i == 3)
		sort_3(a, i);
	else if (i != 1)
		sort(a, b, i);
	free(b);
	free(a);
}

int	main(int items, char *argv[])
{
	if (items > 1)
	{
		argv++;
		if (items == 2)
			argv = ft_split(*argv, ' ');
		push_swap(argv);
		return (0);
	}
	ft_printf("Error\n");
	return (0);
}
/*
i = 0;
	while (items > i)
	{
		ft_printf("%d\n", a[i]);
		i++;
	}
*/
//Prueba 100 numeros//
/*
ARG="849 523 -81 -16 603 -988 601 -250 -714 -216 -628 530 431 -690 841 -110 473 217 -514 -340 -146 -97 -325 -32 -811 126 278 658 576 -262 274 -25 511 -451 309 420 -310 -102 489 -966 605 -657 897 218 -828 -764 -660 483 635 189 380 -919 790 -526 -962 261 589 -696 -443 -731 -631 -269 739 612 -630 -825 -704 -249 -796 -978 -672 235 173 758 -205 -756 514 -476 -195 -86 -848 163 -219 669 -773 -176 -637 -666 -251 797 -362 -149 197 -101 308 384 447 169 -956 -467"; ./push_swap $ARG | ./checker_Mac $ARG
*/
//Prueba 500 numeros//
/*
ARG="-2900 -1571 -2950 -2165 -1510 -1639 -2168 -2034 -2159 -2677 -2703 -1024 -2506 -1889 -2882 -1670 -1062 -2282 -1714 -1699 -2650 -2502 -1304 -2445 -2600 -1420 -1386 -1334 -1285 -2526 -2928 -2701 -1658 -2256 -2616 -1994 -1678 -1644 -1220 -1803 -2018 -1781 -2835 -1533 -1015 -2455 -2381 -2400 -1025 -2158 -2252 -1660 1443 1122 1669 1695 2782 2263 1470 2719 2918 2325 1450 1854 1279 2006 1040 2417 2356 2226 2351 2557 2407 1227 1522 2864 1832 2163 2865 2069 2813 1668 1951 1113 1861 2711 2376 1215 1895 2291 2566 1456 1980 1395 1103 1637 1712 2543 2359 2961 2412 1510 2909 2446 2203 1707 1054 1659 1465 1665 1547 1067 2004 2894 2252 1096 2036 1543 2166 1205 2275 1961 1992 1124 2185 2236 1930 1314 1056 2957 1973 2946 2393 1819 2375 2759 2854 1406 1333 1478 2490 1334 1264 1594 2869 1718 1383 2019 2308 2848 2071 1893 1752 2464 1538 2273 2469 1625 2314 1725 2926 2385 2522 2998 2234 2165 2266 2472 1713 2448 2757 2028 2332 1474 1537 1204 2642 1047 1952 2493 1419 2305 1910 2201 2792 2872 2980 1732 2677 1488 2609 2262 1533 2849 2672 1376 1826 2169 1917 2647 1831 1898 1323 2395 1464 1872 1834 2215 1014 1675 1469 1529 2027 2436 2054 2723 1407 1102 2186 2297 1744 1882 1733 2606 1413 2808 1158 2547 2259 2681 2947 2714 1540 2881 2103 1291 2900 1126 1592 1116 1870 1041 1608 1574 1108 1486 2489 2571 1260 2955 2702 2181 -2452 -1812 -1245 -1926 -1752 -1258 -1236 -1773 -2562 -1743 -1548 -2095 -2066 -1838 -1875 -2148 -2561 -2852 -1625 -1738 -2609 -2567 -2271 -2068 -1438 -2247 -1592 -2098 -1289 -2756 -2152 -1874 -2397 -2090 -2457 -2311 -1836 -1035 -2430 -2239 -2001 -2253 -2270 -1777 -1730 -2084 -1958 -1945 -1484 -1870 -2002 -1401 -2006 -2060 -1111 -2421 -2517 -1181 -1377 -1471 -1736 -2104 -1069 -2813 -1837 -1864 -2915 -2503 -2982 -2171 -1053 -1237 -1268 -1385 -1019 -2936 -1178 -1677 -2663 -1042 -1776 -1559 -1104 -1214 -2755 -2329 -2304 -1368 -1572 -2846 -1251 -2418 -1330 -1257 -1200 -2456 -1672 -1931 -1004 -1822 -2864 -1157 -1240 -2524 -2347 -2352 -2368 -1711 -2143 -2005 -1987 -2149 -1052 -1996 -1665 -2745 -2287 -1860 -1783 -1117 -1252 -1664 -2766 -2094 -2660 -2265 -2760 -1315 -2902 -2709 -2633 -2359 -2126 -2043 -2966 -1186 -1608 -1637 -2267 -1419 -1065 -1300 -2694 -2138 -1283 -2300 -1010 -1698 849 523 -81 -16 603 -988 601 -250 -714 -216 -628 530 431 -690 841 -110 473 217 -514 -340 -146 -97 -325 -32 -811 126 278 658 576 -262 274 -25 511 -451 309 420 -310 -102 489 -966 605 -657 897 218 -828 -764 -660 483 635 189 380 -919 790 -526 -962 261 589 -696 -443 -731 -631 -269 739 612 -630 -825 -704 -249 -796 -978 -672 235 173 758 -205 -756 514 -476 -195 -86 -848 163 -219 669 -773 -176 -637 -666 -251 797 -362 -149 197 -101 308 384 447 169 -956 -467"; ./push_swap $ARG | ./checker_Mac $ARG
*/
