from datetime import datetime

y1, m1, d1 = map(int, input().split())
y2, m2, d2 = map(int, input().split())

datetime_1 = datetime(int(y1), int(m1), int(d1))
datetime_2 = datetime(int(y2), int(m2), int(d2))

delta = datetime_2 - datetime_1

if datetime_2.year - datetime_1.year > 1000:
    print("gg")

elif datetime_2.year - datetime_1.year == 1000:
    if datetime_2.month > datetime_1.month:
        print("gg")

    elif datetime_2.month == datetime_1.month and datetime_2.day >= datetime_1.day:
        print("gg")

    else: print("D-"+str(delta.days))

else: print("D-"+str(delta.days))