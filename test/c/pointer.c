void main() {
  int *arr[10];
  int **ptr = (int**)arr;
  for (int i = 0; i < 10; i ++) {
    ptr[i] = new int();
    *ptr[i] = i;
  }
  for (int i = 0; i < 10; i ++)
    print *arr[i];
}