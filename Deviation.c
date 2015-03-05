/*
Igor Lopes    March 5, 2015
*/
#include <stdio.h>
#include <stdlib.h>

/*  readData Function:
    Open the file to read the numbers.
    The function receives a pointer to the file through
    the parameters and reads the entire file, adding the
    numbers into a array, and returning a dynamic array
    with all the numbers.
*/

double* readData(FILE *ptr_file, char filename[20]){
    int lastindex = 0;
    double data[100];
    char buf[1000];
    if (!ptr_file){
    printf("Error ! File could not be found\n");
  } else {
    while (fgets(buf,1000, ptr_file)!=NULL){
        data[lastindex] = atof(buf);  
        lastindex++;    
    }
		fclose(ptr_file);
  };
  return data;
}

/* getLastIndex function:
   It is basically the same process of readData,
   but this function will just return the last element
   stored in the list, since the maximum is 100
   and the program needs to know the quantity
   of valid numbers stored in the list in order
   to do the correct calculations.
*/

int getLastIndex(FILE *ptr_file, char filename[20]){
    char buf[1000];
    int lastindex = 0;
    if (!ptr_file){
    printf("Error ! File could not be found\n");
  } else {
    while (fgets(buf,1000, ptr_file)!=NULL){    
        lastindex++;
    }
		fclose(ptr_file);
  };
  
  return lastindex;
}

/* findDev function:
   This function will calculate the deviation
   for the numbers read from the file. It will
   calculate the difference between each element
   and the average value and will calculate the
   sum of the squares of each difference divided
   by the number of elements in the list. The
   result will be the deviation.
*/


double findDev(double* data, int num_elements, double mean){
    double sub = 0;
    double sum = 0;
    int index  = 0;
    double aux = 0;
    double dev;
    for(index = 0; index < num_elements;index++){
        sub = mean - data[index];
        sum = sum + sub * sub;
        sub = 0;
        aux++;
    }
    dev = sum /aux;
    return dev;
}

/* findMin function:
   This function will find the maximum element
   used in the deviation formula. It runs the entire
   data list checking and replacing the variable
   min if an element it is minimum
*/

double findMin(double* data, int num_elements){
    int index = 0;
    double min  = 0;
      for(index = 0 ; index < num_elements; index++){
        if(index == 0){
            min = data[0];
        } else {
            if(data[index] < min){
                min = data[index];
            }
       }
    } 
   return min;
}

/* findMax function:
   This function will calculate the deviation
   for the numbers read from the file. It will
   calculate the difference between each element
   and the average value and will calculate the
   sum of the squares of each difference divided
   by the number of elements in the list. The
   result will be the deviation.
*/

double findMax(double* data, int num_elements){
      int index = 0;
    double max  = 0;
      for(index = 0 ; index < num_elements; index++){
        if(index == 0){
            max = data[0];
        } else {
            if(data[index] > max){
                max = data[index];
            }
       }
    } 
   return max;
 
}

/* findAvg function:
   This function will find the "mean" used in the
   deviation formula. It runs the entire data list
   adding all the values and dividing by the number
   of elements.
*/

double findAvg(double* data, int num_elements){
    int index = 0;
    double aux = 0 ;
    double avg = 0;
    double sum = 0;
    for(index = 0 ; index < num_elements; index++){
        sum = sum + data[index];
        aux++;
    }
    avg = sum /aux;
    return avg;
}

/* showHeader function:
   Receives a file pointer to the output file and writes
   all the results line per line.
*/

void showHeader(FILE* ptr_file, double min, double max, double mean, double dev){
    //ptr_file = fopen("output.txt", "w+");
    printf("%s\n %f\n %s\n %f\n %s\n %f\n %s\n %f\n", " Minimum value: ", min, "Maximum value: ", max,  "Average value: ", mean, "Deviation value: ", dev);
    fprintf(ptr_file, "%s\n %f\n %s\n %f\n %s\n %f\n %s\n %f\n", " Minimum value: ", min, "Maximum value: ", max,  "Average value: ", mean, "Deviation value: ", dev);
    fclose(ptr_file);
}

int main(int argc, char *argv[])
{ 
  double* data; //Pointer to the dynamic array
  //Initialize some variables.
  double max = 0;
  double min = 0;
  double avg = 0;
  double dev  = 0;
  int lastindex = 0;
  char filename[20];
  char filename_output[20];
  FILE *ptr_file;
  FILE *ptr_file2;
  FILE *ptr_output;
  printf("Type the file name to be read:");
  scanf("%s",&filename);
  printf("Type the output file name:");
  scanf("%s",&filename_output);  //Gets the file for the output file, where the results will be written. Note that the compiler will look for this file in the same directory
  ptr_file = fopen(filename, "r");
  ptr_file2 = fopen(filename, "r");
  ptr_output = fopen(filename_output, "w+"); //Open outputfile with the argument "w" to write
  data = readData(ptr_file,filename); //Get the array with number and stores it in a dynamic array. (C does not allow functions to return entire static arrays)
  lastindex = getLastIndex(ptr_file2,filename);
  min = findMin(data,lastindex);
  max  = findMax(data,lastindex);
  avg = findAvg(data,lastindex);
  dev = findDev(data,lastindex,avg);
  showHeader(ptr_output,min,max,avg,dev);
  
  system("PAUSE");
  getchar();	
  return 0;

}
