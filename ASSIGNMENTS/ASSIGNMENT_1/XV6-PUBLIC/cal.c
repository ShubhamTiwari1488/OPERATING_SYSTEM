#include "types.h"
#include "stat.h"
#include "user.h"
#define TRUE    1
#define FALSE   0

int d_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
	" ",
	"\nJanuary",
	"\nFebruary",
	"\nMarch",
	"\nApril",
	"\nMay",
	"\nJune",
	"\nJuly",
	"\nAugust",
	"\nSeptember",
	"\nOctober",
	"\nNovember",
	"\nDecember"
};

int find_day(int y)
{
	int day;
	int n1, n2, n3;

	n1 = (y - 1.)/ 4.0;
	n2 = (y - 1.)/ 100.;
	n3 = (y - 1.)/ 400.;
	day = (y + n1 - n2 + n3) %7;
	return day;
}

int leapyear(int y)
{
	if((y% 4 == FALSE && y%100 != FALSE) || y%400 == FALSE)
	{
		d_month[2] = 29;
		return TRUE;
	}
	else
	{
		d_month[2] = 28;
		return FALSE;
	}
}

void cal1(int y, int day)
{
	int month, d;
	for ( month = 1; month <= 12; month++ )
	{
		printf(1,"%s", months[month]);
		printf(1,"\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );

		
		for ( d = 1; d <= 1 + day * 5; d++ )
		{
			printf(1," ");
		}

		
		for ( d = 1; d <= d_month[month]; d++ )
		{
			printf(1,"%d", d);

			
			if ( ( d + day ) % 7 > 0 )
				printf(1,"   " );
			else
				printf(1,"\n " );
		}
		
		day= ( day + d_month[month] ) % 7;
	}
}

void cal2(int year, int dcode, int m)
{
	int month, day;

	for ( month = 1; month < m; month++ )
	{
		
		dcode = ( dcode + d_month[month] ) % 7;
	}

	month = m;

	printf(1,"%s", months[month]);
	printf(1,"\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );

	
	for ( day = 1; day <= 1 + dcode * 5; day++ )
	{
		printf(1," ");
	}

	
	for ( day = 1; day <= d_month[month]; day++ )
	{
		printf(1,"%d", day );
		
		if ( ( day + dcode ) % 7 > 0 )
			printf(1,"   " );
		else
			printf(1,"\n " );
	}
}

int main(int argc, char * argv[])
{
	int year, daycode;
	int month;

	if(argc == 1)
	{
		year = 2022;
		month = 1;
	    printf(1,"\nCALENDAR %d\n", year);
	    daycode = find_day(year);
	    leapyear(year);
		cal2(year, daycode,month);
	}
	else if(argc == 2)
	{
		year = atoi(argv[1]);
	    printf(1,"\nCALENDAR %d\n", year);
	    daycode = find_day(year);
	    leapyear(year);
	    cal1(year, daycode);
	}
	else if(argc == 3)
	{
		month = atoi(argv[1]);
		year = atoi(argv[2]);
		printf(1,"\nCALENDAR %d\n", year);
	    daycode = find_day(year);
	    leapyear(year);
	    cal2(year, daycode, month);
	}
	else
	{
		printf(1,"Invalid Format\n");
		return 1;
	}
	printf(1,"\n");
	exit();
}
