#include <iostream>

using namespace std;

const int n = 6;
const int m = 15;
int countIndex = 0;
struct Student {
    char surname[50];
    int numberGroup;
    int mark;
};

void printArray(Student arr[]);

void setVariables (Student arr[]) {
    strcpy(arr[0].surname, "One");
    arr[0].numberGroup = 328506;
    arr[0].mark = 10;
    strcpy(arr[1].surname, "Two");
    arr[1].numberGroup = 328505;
    arr[1].mark = 7;
    strcpy(arr[2].surname, "Three");
    arr[2].numberGroup = 328506;
    arr[2].mark = 6;
    strcpy(arr[3].surname, "Four");
    arr[3].numberGroup = 328503;
    arr[3].mark = 4;
    strcpy(arr[4].surname, "Five");
    arr[4].numberGroup = 328502;
    arr[4].mark = 9;
    strcpy(arr[5].surname, "Six");
    arr[5].numberGroup = 328507;
    arr[5].mark = 8;
}

void addHash (Student marksH[], Student arr[], int index) {
    int i = arr[index].mark % m, p = 1;
    if (marksH[i].mark != -1) {
        while (marksH[i].mark != -1) {
            i+=p*p;
            p++;
            i >= m ? i = i-m : i;
        }
        marksH[i] = arr[index];
    }
    marksH[i] = arr[index];
}


int* searchHash (Student marksH[], int inf) {
    int i = abs(inf % m);
    int* indexes = new int[m];
    int j = 0;
    int p = 0;
    while (marksH[i].mark != -1) {
        if (marksH[i].mark == inf) {
            indexes[j++] = i;
        }
        p++;
        i+=p*p;
        i >= m ? i = i-m : i;
    }
    countIndex = j;
    return indexes;
}

void printArray(Student arr[]) {
    for (int i = 0; i < n; i++)
        cout << arr[i].surname << "\t" << arr[i].numberGroup << "\t" << arr[i].mark << " " << endl;
    cout << endl;
}

void printHash(Student arr[]) {
    for (int i = 0; i < m; i++) {
        if (arr[i].mark != -1) {
            cout.width(2);
            cout << i << " |";
            cout.width(6);
            cout << arr[i].surname << " |";
            cout.width(7);
            cout << arr[i].numberGroup << " |";
            cout.width(2);
            cout << arr[i].mark << " |" << endl;
        }
    }
    cout << endl;
}

int main() {
    Student arr[n];
    Student marksH[m];
    setVariables(arr);
    printArray(arr);

    cout << endl;

    for (int i = 0; i < m; i++) {marksH[i].mark = -1;}
    for (int i = 0; i < n; i++) {addHash(marksH, arr, i);}

    printHash(marksH);

    int ss = 0;
    while (ss != -1) {
        cout << "mark: ";
        cin >> ss;
        int* indexes = searchHash(marksH, ss);
        countIndex == 0 ? cout << "does not exist" << endl : cout;
        for (int i = 0; i < countIndex; i++) {
            Student s = marksH[indexes[i]];
            cout << s.surname << " " << s.numberGroup << " " << s.mark << endl;
        }
        delete[] indexes;
    }

    return 0;
}
