int sum(int i) {
  if (i == 0) return 0;
  return i + sum(i - 1);
}

void main() {
  int a[15];
  int *b = (int*)a;

  async works[10];
  for (int i = 0; i < 10; i ++) {
    works[i] = [b, i] {
      b[i] = sum(i);
    };
  }
  for (int i = 0; i < 10; i ++)
    run works[i];
  for (int i = 0; i < 10; i ++)
    join works[i];

  for (int i = 0; i < 10; i ++)
    print a[i];
}