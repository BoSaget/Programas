import calendar

date = input("")
month = date[0] + date[1]
day = date[3] + date[4]
year = date[6] + date[7] + date[8] + date[9]

day_of_weeek = calendar.weekday(int(year), int(month), int(day))

if(day_of_weeek == 0):
    print("MONDAY")

if(day_of_weeek == 1):
    print("TUESDAY")

if(day_of_weeek == 2):
    print("WEDNESDAY")

if(day_of_weeek == 3):
    print("THURSDAY")

if(day_of_weeek == 4):
    print("FRIDAY")

if(day_of_weeek == 5):
    print("SATURDAY")

if(day_of_weeek == 6):
    print("SUNDAY")
