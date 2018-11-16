#include <stdlib.h>
#include <stdio.h>

int main(void) {
  int N;
  scanf("%d", &N);
  int *Mass = (int*)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++)
    scanf("%d", &Mass[i]);

  for (int i = 0; i < N; i++)
    for (int p = 0; p < N; p++)
      if (Mass[p] > Mass[p + 1]) {
        int t = Mass[p];
        Mass[p] = Mass[p + 1];
        Mass[p + 1] = t;
      }
  for (int i = N; i > 0; i--)
    printf("%d ", Mass[i]);
  return 0;
}
