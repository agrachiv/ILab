#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#define mass 10240





int bstrcmp (const void* p1, const void* p2)
    {

    char** s11 = (char**) (p1);
    char** s22 = (char**) (p2);
    char* s1 = *s11;
    char* s2 = *s22;


    for (int i = 1; i != 4; i++)
        {
        if (s1[strlen (s1) - i] != s2[strlen (s2) - i])
            {
            return s1[strlen (s1) - i] - s2[strlen (s2) - i];
            }

        }

    return 0;
    }
int bstrcmp2 (char* s1, char* s2)
    {
    for (int i = 1; i != 5; i++)
        {
        if (s1[strlen (s1) - i] != s2[strlen (s2) - i])
            {
            return 1;
            }

        }

    return 0;
    }



char* vvod (long* FileSize)
    {
    FILE* RouteToFile = fopen ("eonegin.txt", "rb");
    if (RouteToFile == NULL)
        {
        printf ("wrong route");
        exit (1);
        }

    fseek (RouteToFile, 0, SEEK_END);
    *FileSize = ftell (RouteToFile);
    fseek (RouteToFile, 0, SEEK_SET);


    char* buffer = (char*) malloc (sizeof (char) * (*FileSize));

    if (buffer == NULL)
        {
        exit (2);
        }

    fread (buffer, 1, (*FileSize), RouteToFile);

    /*  ТУТ МУТЬ
    size_t len = fread (buffer, 1, FileSize, RouteToFile);
    printf("%u %li", len, FileSize);
    if (len != lSize)
    {
        printf("Ошибка чтения");
        exit (3);
    }
    */

    fclose (RouteToFile);
    return buffer;
    }

void clean (char* buffer, long* Size, char** strings)
    {

    char* String[mass] = {};
    String[0] = buffer;
    int len = 1;

    for (int i = 1; i < *Size; i++)
        {
        if (buffer[i] == '\n')
            {
            String[len] = & (buffer[i + 1]);
            buffer[i - 1] = '\0';
            buffer[i] = '\0';

            for (int j = 2; buffer[i - j] >= 0; j++)
                {

                buffer[i - j] = '\0';

                }

            len++;

            }
        }

    len--;

    int Elen = 0;
    char* EString[mass] = {};

    for (int j = 0; j <= len; j++)
        {
        if ( (*String[j] != 0) && (*String[j] == ' ') && (strlen (String[j]) >= 8))
            {
            EString[Elen] = String[j];
            Elen++;
            }
        }




    int SSize = Elen / 14;

    for (int i = 0; i < Elen; i++)
        {
        strings[ (i % 14) *SSize + i / 14] = EString[i];
        }

    *Size = SSize;
    }
int SameEnd (char* s1, char* s2)
    {
    for (int i = 1; s1[strlen (s1) - i] != ' '; i++)
        {
        if (s1[strlen (s1) - i - 1] != s2[strlen (s2) - i - 1])
            {
            return 0;
            }

        }

    return 1;
    }

char* rythm (long* Size, char** strings, char* s1, int N)
    {

    srand (time (NULL));
    int tmp = 0;
    int k = 0;
    int l = 0;
    int Rand;
    int beg = 0;
    int j = 0;



    for (k = 0; ( (bstrcmp2 (s1, strings[*Size * (N - 1) + k]) != 0)); k++)  //находим первую рифму в отсортированном
        {
        if (k == *Size - 1)
            {
            return NULL;
            }
        }

    beg = *Size * (N - 1) + k;


    for (j = 0; bstrcmp2 (s1, strings[beg + j]) == 0; j++) //создаем псевдомассив рифмованных
        {
        if (SameEnd (s1, strings[beg + j]) == 1)    //исключаем одинаковые слова в качестве рифм
            {
            l++;
            }
        }

    if (j == l)
        {
        return NULL;
        }

    return strings[beg + l + (rand() % j)];
    }

void abzac (int N, long* Size, char** strings)
    {

    char* status3 = NULL;
    char* status4 = NULL;
    char* status6 = NULL;
    char* status8 = NULL;
    char* status11 = NULL;
    char* status12 = NULL;
    char* status14 = NULL;

    int Rand1;
    int Rand2;
    int Rand5;
    int Rand7;
    int Rand9;
    int Rand10;
    int Rand13;

    int i = 0;

    for (i; status3 == NULL; i++)
        {
        srand (time (NULL) + i);
        Rand1 = (rand() % *Size);
        status3 =  rythm (Size, strings, strings[Rand1], 3);
        }

    for (i; status4 == NULL; i++)
        {
        srand (time (NULL) + i);
        Rand2 = (rand() % *Size) + *Size * 1;
        status4 =  rythm (Size, strings, strings[Rand2], 4);
        }

    for (i; status6 == NULL; i++)
        {
        srand (time (NULL) + i);
        Rand5 = (rand() % *Size) + *Size * 4;
        status6 =  rythm (Size, strings, strings[Rand5], 6);
        }

    for (i; status8 == NULL; i++)
        {
        srand (time (NULL) + i);
        Rand7 = (rand() % *Size) + *Size * 6;
        status8 =  rythm (Size, strings, strings[Rand7], 8);
        }

    for (i; status11 == NULL; i++)
        {
        srand (time (NULL) + i);
        Rand9 = (rand() % *Size) + *Size * 8;
        status11 =  rythm (Size, strings, strings[Rand9], 11);
        }

    for (int i = 0; status12 == NULL; i++)
        {
        srand (time (NULL) + i);
        Rand10 = (rand() % *Size) + *Size * 9;
        status12 =  rythm (Size, strings, strings[Rand10], 12);
        }

    for (i; status14 == NULL; i++)
        {
        srand (time (NULL) + i);
        Rand13 = (rand() % *Size) + *Size * 12;
        status14 =  rythm (Size, strings, strings[Rand13], 14);
        }

    printf ("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n", strings[Rand1], strings[Rand2], status3, status4, strings[Rand5], status6, strings[Rand7], status8, strings[Rand9], strings[Rand10], status11, status12, strings[Rand13], status14);
    }


int main()
    {
    long Size;
    setlocale (LC_ALL, "Rus");
    char* buf = vvod (&Size);
    char* strings[10240];


    clean (buf, &Size, strings);

    for (int i = 0; i < 14; i++)
        {
        qsort (strings + i * (Size), Size, sizeof (char*), bstrcmp);
        }
    abzac (1 , &Size, strings);
    }
