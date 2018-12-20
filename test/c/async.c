async async_work;

void start_work(async *work, int *ptr, int value) {
  *work = [ptr, value] {
    while (value--) {
      *ptr = *ptr + value;
    }
  };
  run *work;
  return;
}

void main() {
  int result = 0;
  start_work(&async_work, &result, 10);
  join async_work;
  print result;
}