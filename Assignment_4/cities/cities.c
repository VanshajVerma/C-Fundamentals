#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 300
char buf[N];

/* We store cities, country and population */
typedef struct {
    char* city;
    char* country;
    int population;
} City;

/* Read a record from a buf and store it in c */
void readRecord(char* buf, City* c);

/* Output the data in a City record */
void printRecord(FILE*f, const City* c);

/* Compare for qsort */
int compare(const void* a, const void* b)
{
    const City *i = a, *j = b;
    // if same country
    // if (strcmp(i->country, j ->country) == 0)
      return -(i->population - j->population);
      //    return strcmp(i->country, j ->country);
}

int main()
{
    char* file_name = "cities.csv";

    FILE* f = fopen(file_name, "r");
    if (f == NULL) {
        fprintf(stderr, "Cannot open file %s\n", file_name);
        return 1;
    }

    /* count how many lines in the file */
    // skip the first line
    fgets(buf, N, f);
    int num_records = 0;
    while (fgets(buf, N, f) != NULL)
        num_records++;

    /* allocate memory */
    City* c = malloc(num_records * sizeof(City));
    if (c == NULL) {
        fprintf(stderr, "Cannot allocate memory for %d records \n", num_records);
        return 0;
    }

    /* Rewind so reading starts from the beginning */
    rewind(f);

    /* Read the header line to skip it */
    fgets(buf, N, f);

    int i = 0;
    while (fgets(buf, N, f) != NULL) {
        readRecord(buf, c + i);
        i++;
    }

    qsort(c, num_records, sizeof(City), compare);
    fclose(f);
    
    f = fopen("sorted.csv", "w");
    for (int i = 0; i < num_records; i++)
        printRecord(f,c + i);
    fclose(f);
    free(c);
    

    return 0;
}

void readRecord(char* buf, City* c)
{
    /* Extract 
     city, country, population
  */
    char* token = buf;
    // get city
    token = strtok(buf, ",");
    c->city = malloc(strlen(token) + 1);
    strcpy(c->city, token);

    // skip 3 fields
    for (int i = 0; i < 3; i++)
        token = strtok(NULL, ",");

    // get population
    token = strtok(NULL, ",");
    c->population = atoi(token);

    // get country
    token = strtok(NULL, ",");
    c->country = malloc(strlen(token) + 1);
    strcpy(c->country, token);
}

void printRecord(FILE *f, const City* c)
{
  fprintf(f,"%s,%s,%d\n", c->country, c->city, c->population );
}
