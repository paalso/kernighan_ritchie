// ���������� 5.7. �������� ����� ������ readlines, ������� ���������� �� ������ � �������, 
// ������������ � main, � �� ����������� ������ ����������� ��������� alloc. 
// ��������� ������� ��� ���������?

// ���������� ������, �� �� ����� �����, ��� ������� � ����
// ������ ���������
// readlines ���� �� ����������� ������, � ��������� ������ � ������� ����� char lines[][MAXLEN]
// ��� ����, �.�. � ���������� ������������, � �.�. ����������� ������� ������ ������ �� ������,
// �� ��� ����������� ����� ��� � ����������� ������ �� ��� � ��������� ������� char *lineptr[]


#include <stdio.h>
#include "sort_lines.h"

static int max_lines = 10;

int main(int argc, char const *argv[])
{
    char *lineptr[max_lines];
    char lines[max_lines][MAXLEN];
    int got_lines;

    if ((got_lines = readlines(lines, lineptr, max_lines)) > 0) {
        quicksort(lineptr, 0, got_lines - 1);
        printf("Sorted:\n\n");
        writelines(lineptr, got_lines);
    } else {
        printf("Incorrect input!\n");
        return 1;
    }

    return 0;
}