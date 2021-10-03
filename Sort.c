#include "locals.h"

void Sort(struct Person* persons, int count, enum SortType sortType) {
    int tmp, k; // готовим начальный шаг
    int s = count;
    if (sortType == ASC) {
        while (count > 1) {
            s /= 1.247f;
            if (s < 1) s = 1; // 0 быть не может, присвоим 1
            k = 0; // нет перестановок
            for (int i = 0; i + s < count; i++) { // двигаемся, пока сравниваемый элемент (на s от текущего) в массиве
                if (CompareString(persons[i].firstName, persons[i + s].firstName) == -1) {
                    struct Person tmp = persons[i];
                    persons[i] = persons[i + s];
                    persons[i + s] = tmp;
                } else if (CompareString(persons[i].firstName, persons[i + s].firstName) == 0)
                    if (CompareString(persons[i].secondName, persons[i + s].secondName) == -1) {
                        struct Person tmp = persons[i];
                        persons[i] = persons[i + s];
                        persons[i + s] = tmp;
                    } else if (CompareString(persons[i].secondName, persons[i + s].secondName) == 0)
                        if (CompareString(persons[i].thirdName, persons[i + s].thirdName) == -1) {
                            struct Person tmp = persons[i];
                            persons[i] = persons[i + s];
                            persons[i + s] = tmp;
                        } else if (CompareString(persons[i].thirdName, persons[i + s].thirdName) == 0)
                            if (persons[i].birthYear <= persons[i + s].birthYear) {
                                struct Person tmp = persons[i];
                                persons[i] = persons[i + s];
                                persons[i + s] = tmp;
                            }
            }
            if (s == 1) // шаг 1, как в обычном пузырьке. Включаем контроль
                count = k + 1;
        }

    }
    else {
        while (count > 1) {
            s /= 1.247f;
            if (s < 1) s = 1; // 0 быть не может, присвоим 1
            k = 0; // нет перестановок
            for (int i = 0; i + s < count; i++) { // двигаемся, пока сравниваемый элемент (на s от текущего) в массиве
                if (CompareString(persons[i].firstName, persons[i + s].firstName) == 1) {
                    struct Person tmp = persons[i];
                    persons[i] = persons[i + s];
                    persons[i + s] = tmp;
                } else if (CompareString(persons[i].firstName, persons[i + s].firstName) == 0)
                    if (CompareString(persons[i].secondName, persons[i + s].secondName) == 1) {
                        struct Person tmp = persons[i];
                        persons[i] = persons[i + s];
                        persons[i + s] = tmp;
                    } else if (CompareString(persons[i].secondName, persons[i + s].secondName) == 0)
                        if (CompareString(persons[i].thirdName, persons[i + s].thirdName) == 1) {
                            struct Person tmp = persons[i];
                            persons[i] = persons[i + s];
                            persons[i + s] = tmp;
                        } else if (CompareString(persons[i].thirdName, persons[i + s].thirdName) == 0)
                            if (persons[i].birthYear >= persons[i + s].birthYear) {
                                struct Person tmp = persons[i];
                                persons[i] = persons[i + s];
                                persons[i + s] = tmp;
                            }
            }
            if (s == 1) // шаг 1, как в обычном пузырьке. Включаем контроль
                count = k + 1;
        }
    }
}
//    for (int min = 0; min < count - 1; min++) {
//        int least = min;
//        for (int j = min + 1; j < count; j++)
//            if (CompareStrings(persons[j].firstName, persons[least].firstName) == -1)
//                least = j;
//            else if (CompareStrings(persons[j].firstName, persons[least].firstName) == 0)
//                if (CompareStrings(persons[j].secondName, persons[least].secondName) == -1)
//                    least = j;
//                else if (CompareStrings(persons[j].secondName, persons[least].secondName) == 0)
//                    if (CompareStrings(persons[j].thirdName, persons[least].thirdName) == -1)
//                        least = j;
//                    else if (CompareStrings(persons[j].thirdName, persons[least].thirdName) == 0)
//                        if (persons[j].birthYear <= persons[least].birthYear)
//                            least = j;
//        struct Person tmp = persons[min];
//        persons[min] = persons[least];
//        persons[least] = tmp;
//    }


//    struct Person t;
//    if (sortType == Desc)
//        for (int i = 0; i < count / 2; i++) {
//            t = persons[i];
//            persons[i] = persons[count - i - 1];
//            persons[count - i - 1] = t;
//        }
