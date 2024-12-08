import sys
import datetime

MONTH = {
    "January": 1,
    "February": 2,
    "March": 3,
    "April": 4,
    "May": 5,
    "June": 6,
    "July": 7,
    "August": 8,
    "September": 9,
    "October": 10,
    "November": 11,
    "December": 12
}

DAY_BY_NUMBER = {
    0: "Sunday",
    1: "Monday",
    2: "Tuesday",
    3: "Wednesday",
    4: "Thursday",
    5: "Friday",
    6: "Saturday",
}

def main():
    while True:
        try:
            day, month, year = input().split()
            result_day = datetime.date(int(year), MONTH[month], int(day))
            result_day = (result_day.weekday() + 1) % 7
            print(DAY_BY_NUMBER[result_day])
        except:
            break

if __name__ == '__main__':
	main()

