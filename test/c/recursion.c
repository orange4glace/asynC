int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

void main() {
  int a;
  int b;
  input a;
  input b;
  print gcd(a, b);
}