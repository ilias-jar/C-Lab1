#include <iostream>
#include "Container.h"
#include <fstream>
#include <list>

Container currContainer;

int Menu(bool fileIsFilled = false, bool listIsFilled = false) {
    system("cls");
    std::cout << "1. File fill" << '\n';
    if (fileIsFilled)
        std::cout << "2. List from File" << '\n';
    if (listIsFilled) {
        std::cout << "3. Modify List" << '\n';
        std::cout << "4. Modify List with Iterators" << '\n';
        std::cout << "5. Modify  Transform" << '\n';
        std::cout << "6. Modify For_each" << '\n';
        std::cout << "7. Sum and MidArif" << '\n';
        std::cout << "8. Print List" << '\n';
    }
    std::cout << "0. Exit" << '\n';
    int choise;
    std::cin >> choise;
    return choise;
}

void FileFill() {
    system("cls");
    std::cout << "Input Filename: ";
    std::string filename;
    std::string filename = "hello";
    std::cin >> filename;
    std::cout << "Input M (-M <= num <= M): ";
    int M;
    int M = 20;
    std::cin >> M;
    std::cout << "Input count of numbers: ";
    int N;
    int N = 20;
    std::cin >> N;
    std::cout << "Loop/Generate (1/2): ";
    int input;
    int input = 2;
    std::cin >> input;
    if (input == 1)
        currContainer.f_curr = &currContainer.GenerateRandomFileLoop(filename, M, N);
    else
        currContainer.f_curr = &currContainer.GenerateRandomFile(filename, M, N);
    currContainer.isFilledFile = true;
}

void ListFill() {
    currContainer.l_curr = currContainer.FillListFromFile(*(currContainer.f_curr));
    currContainer.isFilledList = true;
    system("cls");

    std::cout << "List filled";
    std::cin;
}

void PrintList() {
    system("cls");
    std::cout << "File or Console (1/2): ";
    int choise;
    std::cin >> choise;
    if (choise == 1) {
        std::cout << "Input Filename: ";
        std::string filename;
        std::cin >> filename;
        currContainer.Print(filename);
    }
    else {
        currContainer.Print();
    }
}

void ModifyList() {
    currContainer.l_curr = currContainer.ModifyContainer(*(currContainer.l_curr));
    std::cout << "Correctly modified";
    system("pause");
}

void ModifyListWithIterators() {
    std::cout << "Input begin: ";
    double begin;
    std::cin >> begin;
    std::cout << "Input end: ";
    double end;
    std::cin >> end;

    std::list<double>::iterator beginIter = std::find(currContainer.l_curr->begin(), currContainer.l_curr->end(), begin);
    std::list<double>::iterator endIter = std::find(currContainer.l_curr->begin(), currContainer.l_curr->end(), end);

    if (beginIter != endIter) {
        currContainer.l_curr = currContainer.ModifyContainer(*(currContainer.l_curr), beginIter, endIter);
        std::cout << "Correctly modified";
    }
    else {
        std::cout << "Error";
    }
    system("pause");
}

void ModifyWithTransform() {
    currContainer.l_curr = currContainer.ModifyContainerTransform(*(currContainer.l_curr));
    std::cout << "Correctly modified";
    system("pause");
}

void ModifyWithFor_Each() {
    std::cout << "Input begin: ";
    double begin;
    std::cin >> begin;
    std::cout << "Input end: ";
    double end;
    std::cin >> end;

    std::list<double>::iterator beginIter = std::find(currContainer.l_curr->begin(), currContainer.l_curr->end(), begin);
    std::list<double>::iterator endIter = std::find(currContainer.l_curr->begin(), currContainer.l_curr->end(), end);

    if (beginIter != endIter) {
        currContainer.l_curr = currContainer.ModifyContainerFor_Each(*(currContainer.l_curr), beginIter, endIter);
        std::cout << "Correctly modified";
    }
    else {
        std::cout << "Error";
    }
    system("pause");
}

void Sum_MidArifm() {
    system("cls");
    std::cout << "Sum or MidArifm (1/2): ";
    int choise;
    std::cin >> choise;
    if (choise == 1) {
        std::cout << currContainer.Sum(*(currContainer.l_curr));
    }
    else {
        std::cout << currContainer.MidArifm(*(currContainer.l_curr));
    }
    system("pause");
}

int main()
{
    int choise = -1;
    while (choise != 0) {
        choise = Menu(currContainer.isFilledFile, currContainer.isFilledList);
        switch (choise) {
        case 1: FileFill();
            break;
        case 2: ListFill();
            break;
        case 3: ModifyList();
            break;
        case 4: ModifyListWithIterators();
            break;
        case 5: ModifyWithTransform();
            break;
        case 6: ModifyWithFor_Each();
            break;
        case 7: Sum_MidArifm();
            break;
        case 8: PrintList();
            break;
        }
    }
    if (currContainer.f_curr->is_open())
        currContainer.f_curr->close();
}
