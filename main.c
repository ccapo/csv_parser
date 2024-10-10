#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Reads CSV into a 2D double array
void read_csv(int row, int col, char *filename, double **data) {
  FILE *file;
  file = fopen(filename, "r");

  int i = 0;
  char line[4098];
  while(fgets(line, 4098, file) && (i < row)) {
    char *tmp = strdup(line);
    int j = 0;
    const char *tok;

    for(tok = strtok(line, ","); tok && *tok; j++, tok = strtok(NULL, ",\n")) {
      data[i][j] = atof(tok);
    }

    free(tmp);
    i++;
  }
}

int main(int argc, char const *argv[]) {
  if(argc < 3) {
    printf("Usage: %s nrows ncols filename\n", argv[0]);
    exit(0);
  }

  int row = atoi(argv[1]);
  int col = atoi(argv[2]);
  char fname[256] = "input.dat";
  strcpy(fname, argv[3]);

  double **data;
  data = (double **)malloc(row * sizeof(double *));
  for(int i = 0; i < row; ++i){
    data[i] = (double *)malloc(col * sizeof(double));
  }

  read_csv(row, col, fname, data);
  for(int i = 0; i < row; ++i) {
    for(int j = 0; j < col; ++j) {
      if(j < col - 1) {
        printf("%e, ", data[i][j]);
      } else {
        printf("%e", data[i][j]);
      }
    }
    printf("\n");
  }

  return 0;
}
