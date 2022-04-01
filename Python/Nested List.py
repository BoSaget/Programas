def get_second(grades, minimum):
    second = 1000
    for i in range (0 , len(grades)):
        #Obtiene el segundo minimo
        if grades[i] > minimum and grades[i] < second:
            second = grades[i]
    if second == 1000:
        return minimum

    return second

def positions(grades, second, students):
    names = []
    for i in range(0, len(grades)):
        if grades[i] == second:
            names.append(students[i])
    
    names.sort()
    for name in names:
        print(name)


students = int(input(""))
names = []
grades = []
for i in range (0, students):
    name = input("")
    names.append(name)

    grade = float(input(""))
    grades.append(grade)

min_score = min(grades)

second = get_second(grades, min_score)
positions(grades, second, names)